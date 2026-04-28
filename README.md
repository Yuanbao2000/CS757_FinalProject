# CS757 Final Project
This project studies latency, fairness, and throughput tradeoffs in non-preemptive shared GPU scheduling on circuit task graph.

## External Code

We use the LSIM framework provided by course staff: https://github.com/Yi-Huaaa/LSIM (branch: ECE757)

This framework is used as a GPU execution backend. Our work focuses on scheduling policies and performance analysis.

## Prerequisites
- CUDA 12.x (`/usr/local/cuda`)
- GCC 13 (`/usr/bin/g++`)
- CMake 3.16+ and Ninja: `sudo apt install cmake ninja-build`

## Build & Run
```bash
make: build
make brun: build and run
make clean: clear up build artifacts
```

## Our Work
- Implement scheduling policies (FIFO, priority-based, dependency-aware)
- Add metrics:
  - For a single circuit task graph:
    - `Avg Wait (ms)`: how long a task waits from arriving at the ready queue to actually starting execution
    - `Max Wait (ms)`
    - `Avg Exec (ms)`: once a task starts running on the GPU, how long it takes on average until completion; batch service time attributed to each selected task. This is not the true execution time of each individual gate, but the unified kernel time of the batch that the gate belongs to
    - `Avg Turnaround (ms)` = wait + exec
    - `Makespan (ms)`: the total time required for all tasks in the circuit to complete
    - `Throughput (tasks/s)`: how many tasks are completed per unit time = total number of completed tasks / makespan
    - `GPU Util (%)`: the fraction of time the GPU is actually running kernels, i.e., how much of the total makespan the GPU is busy = total batch kernel busy time / makespan
  - For a group of three circuit task graphs: including all above metrics
    - Avg Slowdown = turnaround / exec
      - A more standard definition is often shared completion time / isolated completion time
    - Weighted slowdown
    - Jain's fairness: based on per-workload max completion time
- Run experiments and analyze tradeoffs:
  - In gate-level task execution, since a single gate is too small, the fixed overhead of each launch is larger than the gate computation itself, so a one-gate-per-launch approach like single-gate non-blocking can make Makespan increase instead of decrease, and throughput drops
    - By comparison: blocking batch launches one batch of gates at a time

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
  - Mark the batch as completed and record timing
    - The entire batch measures `batch_exec_ms` only once; each task in the batch is assigned the same `exec_time_ms = batch_exec_ms`
    - `finish_time_ms = batch_start + batch_exec_ms`
  - For each completed task in the batch: find the successors that depend on it and do `dep_remaining--`
    - If a successor has `dep_remaining == 0`, immediately set its `arrival_time_ms` to the current `clock_ms`, then submit it to the scheduler
  - Repeat until the scheduler is empty, i.e., there are no more ready tasks
- execution flow in simplified words
  - Find all ready tasks
  - The scheduler takes at most `batch_size` tasks from the ready queue
  - Launch this batch of tasks together
  - Wait until the whole batch finishes
  - Update dependents
  - Newly ready tasks enter the next round
- features: barriered batch execution
  - Scheduling unit: gate-level task
  - Execution unit: a batch of gates
  - Launch policy: at most `batch_size` per round
  - Synchronization mode: wait for the whole batch together
  - DAG progression: advances batch by batch

#### single-gate, non-blocking ✅
- execution flow in simplified words:
  - A ready task enters the ready queue
  - As long as there is an idle stream, one task is taken from the scheduler and launched
  - After launch, this task becomes in-flight
  - While the GPU is running these in-flight tasks, the CPU does not simply wait for the whole batch; instead, it keeps checking:
    - whether any in-flight task has already completed, and whichever task completes first updates its successors first
    - once a successor becomes ready, it can immediately be selected again by the scheduler and launched
  - Repeat until there are no ready tasks and no in-flight tasks
- features: event-driven stream execution
  - Scheduling unit: still gate-level task
  - Execution unit: one gate per launch
  - Launch policy: keep launching as long as there is a free stream
  - Synchronization mode: handled per individual task completion
  - DAG progression: event-driven

#### small-batch, non-blocking
- execution flow in simplified words:
  - batch_size = 8/16/32
- features:
  - Advantage: coarser kernels and better GPU utilization.
  - Disadvantage: less scheduling flexibility, because levels are basically serialized with respect to each other.

### level-level task execution 

#### levelization ✅
- execution flow in simplified words:
  - First perform levelization on the circuit
  - Group all gates in the same level into one level task (A task here means a level of gates)
  - All level tasks with no predecessor dependencies enter the ready queue, usually level 0
  - Each level task launches one unified gate-batch kernel over all gates in that level. All ready level tasks in the current wave are launched across streams
  - Wait until the whole ready wave finishes
  - Update dependents and unlock the next level wave
- features:
  - Scheduling unit: one level task
  - Execution unit: one level of gates
  - Launch policy: all ready levels in the current wave are launched together
  - Synchronization mode: wait for the whole level wave together
  - DAG progression: level by level
  - Advantages: gates in the same level are naturally parallel; the number of tasks is greatly reduced
  - Disadvantages: narrow levels may underutilize the GPU; deep circuits may become many small serialized levels; scheduler policy flexibility is much smaller than gate-level execution

#### small-chunk after levelization
- execution flow in simplified words:
  - First perform levelization on the circuit
  - Group gates in the same level by chunk size and build the task dependency graph
- features:
  
### partition-level task execution
- execution flow in simplified words:
  - First partition the circuit
- features:
  - Advantage: more flexible and can better balance task size
  - Disadvantage: the partitioning strategy itself is a research problem
