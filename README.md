# CS757 Final Project
This project studies latency, fairness, and throughput tradeoffs in non-preemptive shared GPU scheduling on circuit task graphs.

Report: https://docs.google.com/document/d/1MOxm9JDT42SOu8l0D4pbyJysy6ABp9lJLKtDCHpbAY4/edit?tab=t.0

A template for the final report: https://www.overleaf.com/6359675949mvgmcrxwtwmf#b4432d

## External Code
We use the LSIM framework provided by course staff: https://github.com/Yi-Huaaa/LSIM (branch: ECE757)

This framework is used as a GPU execution backend. Our work focuses on scheduling policies and performance analysis.

- Small: `c17`, `c432`, `c499`, `c880`
- Medium: `c1355`, `c1908`, `c2670`, `c3540`
- Large: `c5315`, `c6288`, `c7552`

## Prerequisites
All can be found in Google Colab
- CUDA 12.x (`/usr/local/cuda`)
- GCC 13 (`/usr/bin/g++`)
- CMake 3.16+ and Ninja: `sudo apt install cmake ninja-build`

## Build & Run
```bash
make build        # build
make brun         # build and run
make clean        # clear build artifacts
```

## Our Work
- Implement scheduling policies:
  - `FIFO`
  - `fanin_priority`
  - `DependencyAware`
  - `SJF`
- Add metrics:
  - For a single circuit task graph:
    - All reported time metrics are normalized to per-gate values, even when the execution unit is a batch or a level. In other words, we always convert the final statistics back to gate-level units so that batch blocking, single-gate non-blocking, batch non-blocking, and level-level execution can be compared on the same scale.
    - `Avg Wait (ms)`: the average time a gate waits after becoming ready and before being dispatched.
      - For gate-level schedulers, a gate becomes ready when all predecessor gates have finished.
      - For level-level execution, a gate inherits the wait time of the level task that contains it.
    - `Max Wait (ms)`: the maximum gate wait time observed in one run. This is mainly used as a starvation indicator.
    - `Avg Exec (ms)`: the average service time attributed to each gate.
      - In all currently implemented modes, service time is reported on a host-side timeline.
      - In <u>single-gate non-blocking</u>, this is the host-side launch-to-completion service interval of that gate.
      - In <u>batch blocking</u> and <u>batch non-blocking</u>, all gates inside the same launched batch are assigned the same host-side batch service interval.
      - In <u>level-level task execution</u>, all gates inside the same level task are assigned the same host-side level service interval.
      - So `Avg Exec` is unified to per-gate reporting, but the attribution rule still depends on the execution mode.
    - `Avg Turnaround (ms)`: the average per-gate turnaround time, defined as `wait + exec`.
    - `Makespan (ms)`: the host-side wall-clock runtime of the whole scheduler run.
      - This is measured from the beginning of one scheduler execution to the point when the final GPU work has completed and the run is done.
      - We intentionally use host-side makespan instead of only using device event durations, because launch/dispatch overhead should also be reflected in end-to-end runtime.
    - `Throughput (gates/s)`: total completed gates divided by host-side makespan.
      - We use `gates/s` instead of `tasks/s` because the execution unit changes across modes: gate-level modes dispatch gates or batches of gates, while level-level execution dispatches one level task at a time.
      - Reporting `tasks/s` would not be comparable across these execution methods, but `gates/s` is.
    - `GPU Util (%)`: a stricter runtime-level GPU busy ratio, defined as:
      - `GPU Util = union of all GPU kernel active intervals on the host timeline / host-side makespan`
      - For every kernel launch, we record a host-side launch timestamp and a host-side completion timestamp.
      - We then take the union of all `[launch, completion]` intervals from that run so overlapping multi-stream execution is not double-counted.
      - This is more strict than summing per-stream durations, because summed durations can exceed makespan when streams overlap.
      - This is also more realistic than our earlier approximation, because launch/dispatch gaps are no longer hidden inside a coarse busy-window estimate.
      - This metric should be interpreted as a runtime-level busy ratio, not as low-level profiler occupancy or SM utilization.
  - For a group of three circuit task graphs: The same per-gate definitions above are used first, and then the following group-level metrics are added.
    - `Avg Slowdown = turnaround / exec`
      - In the current project this is a gate-level slowdown proxy derived from our measured per-gate turnaround and attributed execution time.
      - A more standard systems definition is often `shared completion time / isolated completion time`, but that is not what we currently report here.
    - `Weighted Slowdown`: slowdown weighted by gate priority in the current implementation.
    - `Jain's fairness`: computed from per-workload completion behavior in the mixed-workload run.
- Run experiments and analyze tradeoffs:
  - In gate-level task execution, different launch granularities create a tradeoff between dependency responsiveness and launch overhead
    - `batch blocking` launches one batch of gates at a time and advances the DAG only after the whole batch finishes
    - `single-gate non-blocking` maximizes dependency responsiveness, but can pay high launch overhead
    - `batch non-blocking` is a middle ground between coarse launch granularity and event-driven progression
    - `level-level task execution` reduces the number of scheduling units, but also reduces scheduler flexibility

### gate-level task execution
#### batch, blocking  ✅
- execution flow:
  - The benchmark entry (in `src/main.cpp`) has two paths:
    - First, run each individual circuit one by one
    - Then, run the original GROUPS for balanced_0/1 and imbalanced_2/3/4/5. For one workload group (the three graphs still compete together, not run separately in turns)
      - All 3 circuits are first passed through `parse_ckt(...)`
      - Each circuit is converted into gate-level tasks
      - All tasks are flattened into the same tasks array according to `id_offset`
      - At the same time, `merge_circuits(...)` is used to combine the 3 graphs into one large merged circuit for the unified batch-kernel executor
  - Before each scheduler is run,
    - First reset task state (in `run_scheduler(...)`): `arrival_time_ms = 0`, `wait_time_ms = 0`, `exec_time_ms = 0`, `finish_time_ms = 0`, `dep_remaining = dependencies.size()`
    - Put all tasks that currently have no unfinished predecessors (i.e., `dep_remaining == 0`) into the ready queue
      - At the beginning, these are usually PI nodes or nodes with no predecessors.
  - The scheduler selects tasks from the ready queue. In each round, it keeps calling `next()` until the ready queue is empty, or until `batch_size` is reached (= 32, 128 or 512)
    - If there are still more ready tasks in the ready queue (i.e., `batch_size` is smaller than the current number of ready tasks in the ready queue), they will not all be launched in this round. The next round only begins after the current batch finishes and dependencies are updated.
    - The current four scheduler policies select tasks as follows:
      - FIFO: whoever is submitted first is dequeued first
      - SJF: smaller `param_N = 256 * max(1, fan_in)` is dequeued first; in essence, gates with smaller fan-in run first
      - fanin_priority: priority = fan_in, and gates with larger fan-in run first
      - DependencyAware: first call `precompute_downstream(...)`, then choose the ready task with the largest number of direct downstream dependents; more accurately, this is high immediate fan-out first
  - Launch the selected tasks in this batch together. It is no longer the case that each gate launches a different kernel. The current logic (`include/gate_batch_executor.h`, `src/gate_batch_executor.cu`) is:
    - `launch_gate_batch(...)` copies the ids of this batch of gates to the device
    - launch one unified gate-batch kernel
    - inside the kernel there are many threads, and each thread uses `tb_idx` to find the gate it is responsible for
    - then performs the corresponding logic computation according to `gate_type`
  - How completion is handled:
    - Each batch records one pair of events around this unified kernel: `batch_start_event`, `batch_end_event`; 
    - Then `cudaEventSynchronize(batch_end_event)`
    - In addition, we record a host-side launch timestamp right before the batch launch and a host-side completion timestamp right after the batch finishes. These host-side intervals are later used to compute host-side makespan and GPU busy-ratio statistics.
  - Mark the batch as completed and record timing
    - The entire batch is assigned one host-side service interval; each gate in the batch receives the same attributed `exec_time_ms`
    - `finish_time_ms` is also attributed to each gate in the batch using the host-side batch completion time
    - This per-gate attributed service timing is different from host-side end-to-end makespan, which is tracked separately for the final metrics
  - For each completed gate in the batch: find the successor gates that depend on it and do `dep_remaining--`
    - If a successor gate has `dep_remaining == 0`, immediately set its `arrival_time_ms` to the current host-side batch completion time, then submit it to the scheduler
  - Repeat until the scheduler is empty, i.e., there are no more ready gates
- execution flow in simplified words:
  - Find all ready gates
  - The scheduler takes at most `batch_size` ready gates from the ready queue
  - Launch this batch of gates together
  - Wait until the whole batch finishes
  - Update dependents
  - Newly ready gates enter the next round
- features: barriered batch execution
  - Scheduling unit: gate-level task
  - Execution unit: a batch of gates
  - Launch policy: at most `batch_size` per round
  - Synchronization mode: wait for the whole batch together
  - DAG progression: advances batch by batch

#### single-gate, non-blocking ✅
- execution flow in simplified words:
  - Before each scheduler run, all task timing fields and dependency counters are reset
  - All initially ready gates are submitted to the scheduler
  - A fixed pool of CUDA streams is created
  - As long as there is an idle stream, the scheduler selects one ready gate and launches one unified single-gate kernel on that stream
  - Each launched gate records:
    - a host-side launch-to-completion service interval for per-gate execution attribution
    - a host-side `[launch, finish]` interval for makespan and GPU busy-ratio accounting
  - While the GPU is running these in-flight gates, the CPU does not simply wait for all gates; instead, it keeps checking:
    - whether any in-flight gate has already completed, and whichever gate completes first updates its successors first
    - once a successor becomes ready, it can immediately be selected again by the scheduler and launched
  - Repeat until there are no ready gates and no in-flight gates
- features: event-driven stream execution
  - Scheduling unit: still gate-level task
  - Execution unit: one gate per launch
  - Launch policy: keep launching gates as long as there is a free stream
  - Synchronization mode: handled per in-flight gate completion
  - DAG progression: event-driven

#### batch, non-blocking ✅
- execution flow:
  - Before each scheduler run, all task timing fields and dependency counters are reset
  - All initially ready gates are submitted to the scheduler
  - A fixed pool of CUDA streams is created
  - As long as there is an idle stream, the scheduler selects up to `batch_size` ready gates and launches one batch kernel on that stream
    - After launch, this batch becomes in-flight on that stream
  - Each launched batch records:
    - a host-side launch-to-completion batch service interval for per-gate execution attribution inside that batch
    - a host-side `[launch, finish]` interval for makespan and GPU busy-ratio accounting
  - While the GPU is running these in-flight batches, the CPU does not simply wait for all batches; instead, it keeps checking:
    - whether any in-flight batch has already completed, and whichever batch completes first updates the successors of all tasks in that batch first
    - once a successor gate becomes ready, it can immediately be selected again by the scheduler and placed into a later batch
  - Repeat until there are no ready gates and no in-flight batches
- features:
  - Scheduling unit: still gate-level task
  - Execution unit: one batch of gates per launch
  - Launch policy: keep launching batches as long as there is a free stream
  - Synchronization mode: handled per in-flight batch completion
  - DAG progression: event-driven
  - Advantage: coarser kernels and lower launch overhead than single-gate non-blocking
  - Disadvantage: each batch is still a local barrier, so dependency responsiveness is weaker than single-gate non-blocking

### level-level task execution 

#### levelization, blocking ✅
- execution flow:
  - Each circuit is first levelized
  - All gates in the same level are grouped into one level task
  - Level dependencies are built in order, so a later level only becomes ready after the previous level task completes
  - Each level task launches one unified gate-batch kernel over all gates in that level. All ready level tasks in the current wave are launched across streams
  - (blocking means) The whole ready wave is waited on before unlocking the next wave. 
    - Update dependents and unlock the next level wave.
  - For cross-mode comparison, the final timing is expanded back to per-gate form before metric computation
- features:
  - Scheduling unit: one level task
  - Execution unit: one level of gates
  - Launch policy: all ready levels in the current wave are launched together
  - Synchronization mode: wait for the whole level wave together
  - DAG progression: level by level
  - Advantages: gates in the same level are naturally parallel; the number of tasks is greatly reduced
  - Disadvantages: narrow levels may underutilize the GPU; deep circuits may become many small serialized levels; scheduler policy flexibility is much smaller than gate-level execution


#### fused levelization ✅
- execution flow:
  - This keeps the existing levelized task graph, but measures fused variants named `fused_level(256)`, `fused_level(1024)`, and `fused_level(2048)`.
  - When a ready level has at most the selected gate limit, the scheduler greedily collects the following consecutive levels from the same workload while each level also stays under that limit.
  - The collected segment is launched as one CUDA kernel instead of one kernel per level.
  - Inside that kernel, one block processes each level in order and uses `__syncthreads()` between levels. Threads stride through gates in a level, so levels close to 1024 gates still fit in a single block without another host-side launch.
- reporting:
  - Batch-size reports such as `report_c1355_b32.md`, `report_c1355_b128.md`, and `report_c1355_b512.md` include only the 12 non-level schedulers.
  - Levelized execution is reported separately in files such as `report_c1355_level.md`, with `levelization`, `fused_level(256)`, `fused_level(1024)`, and `fused_level(2048)`.
  - For fused levelization, makespan, throughput, and GPU utilization are still measured from the real host-side fused-kernel intervals. Per-gate execution attribution is split across the fused levels in proportion to each level's gate count, so `Avg Exec` is not inflated by assigning the whole fused segment to every level.


#### levelization, non-blocking
- Not implemented in the current codebase.
- Intended behavior:
  - once one level task finishes, its successor level in the same circuit should be unlocked immediately
  - this would allow situations such as `A:L3`, `B:L1`, `C:L2` across a mixed group of circuits
  - compared with the current blocking level-wave implementation, this would reduce cross-wave idle waiting

#### small-chunk after levelization
- execution flow in simplified words:
  - First perform levelization on the circuit
  - Group gates in the same level by chunk size and build the task dependency graph
- features:
  - Not implemented in the current codebase.
  - Intended goal: keep some of the coarse-grained efficiency of levelization while recovering more scheduling flexibility than one-level-one-task execution.

### partition-level task execution
- execution flow in simplified words:
  - First partition the circuit
- features:
  - Not implemented in the current codebase.
  - Advantage: more flexible and can better balance task size
  - Disadvantage: the partitioning strategy itself is a research problem
