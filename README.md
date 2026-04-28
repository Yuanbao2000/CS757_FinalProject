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
    - `Avg Wait (ms)`：一个 task 从到达 ready queue 到真正开始执行之间等了多久
    - `Max Wait (ms)`
    - `Avg Exec (ms)`：task 一旦开始在 GPU 上跑，到完成，平均花多久；batch service time attributed to each selected task. 不是每个 gate 自己真实执行了多久，而是这个 gate 所在 batch 的统一 kernel 时间
    - `Avg Turnaround (ms)` = wait + exec
    - `Makespan (ms)`: 整个 circuit 的所有 task 全部完成所需的总时间
    - `Throughput (tasks/s)`: 单位时间完成多少个 task = 总完成 task 数 / makespan
    - `GPU Util (%)`: GPU 真正在跑 kernel 的时间比例, i.e., 在总 makespan 里有多少时间/槽位在干活 = total batch kernel busy time / makespan
  - For a group of three circuit task graphs: including all above metrics
    - Avg Slowdown = turnaround/ exec；
      - 更标准的往往是 shared completion time / isolated completion time
    - Weighted slowdown
    - Jain's fairness：基于 per-workload max completion time
- Run experiments and analyze tradeoffs:
  - 在 gate-level task execution 中，由于单个 gate 太小，每次 launch 的固定开销比 gate 计算本身还大，所以像 single-gate non-blocking 这种一个 gate 一次 launch 方式 让 Makespan 不降反升，throughput 降，
    - 对比：blocking batch 是 一批 gate 一次 launch

### gate-level task execution
#### blocking batch ✅
- execution flow:
  - benchmark 入口 (在 `src/main.cpp` 里) 有两条线:
    - 先逐个跑单独的 circuit
    - 再按原来的 GROUPS 跑 balanced_0/1 和 imbalanced_2/3/4/5。对于一个 workload group (仍然是三张图混在一起竞争，不是轮流单跑)
      - 3 个 circuit 都会先 `parse_ckt(...)`
      - 每个 circuit 都会被转成 gate-level tasks
      - 所有 task 会按 `id_offset` 平铺到同一个 tasks 数组里
      - 同时会用 `merge_circuits(...)` 把 3 张图合成一张大的 merged circuit，给统一 batch kernel 的执行器使用
  - 每次跑某个 scheduler 前，
    - 先重置 task 状态 (在 `run_scheduler(...)` 里): `arrival_time_ms = 0`, `wait_time_ms = 0`, `exec_time_ms = 0`, `finish_time_ms = 0`, `dep_remaining = dependencies.size()`
    - 把所有当前没有未完成前驱 (i.e., `dep_remaining == 0`) 的 task 放进 ready queue
      - 这一步在初始时通常就是 PI 或无前驱节点。
  - scheduler 从 ready queue 里选 task. 每一轮一直 `next()`. 直到 ready queue 空，或者取满 `batch_size` (= 32, 128 or 512)
    - 如果 ready queue 里还有更多 ready task (i.e., `batch_size` 小雨当前 ready queue 里 ready task 的数量)，不会这轮全发完，还是要等当前 batch 完成、更新依赖后，再进入下一轮。
    - 当前四种 scheduler 的选法：
      - FIFO: 谁先 submit，谁先出队
      - SJF: `param_N = 256 * max(1, fan_in)` 小的先出队, 本质上还是 fan_in 小的 gate 先跑
      - fanin_priority: priority = fan_in, fan_in 大的 gate 先跑
      - DependencyAware: 先 `precompute_downstream(...)`, 选直接 downstream dependent 数量最多的 ready task, 更准确地说是 high immediate fan-out first
  - 把这一批选出来的 task 一起 launch, 现在不是每个 gate 单独发不同 kernel, 当前逻辑 (`include/gate_batch_executor.h`, `src/gate_batch_executor.cu`)是：
    - `launch_gate_batch(...)` 把这批 gate 的 id 拷到 device
    - launch 一次统一的 gate-batch kernel
    - kernel 里很多 threads, 每个 thread 用 `tb_idx` 找到自己负责的一个 gate
    - 再根据 `gate_type` 做对应逻辑计算
  - 等待完成的方式：
    - 当前每轮 batch 只围绕这个统一 kernel 记一对 event：`batch_start_event`, `batch_end_event`; 
    - 然后 `cudaEventSynchronize(batch_end_event)`
  - 标记 batch 完成并记录时间
    - 整个 batch 只测一次 batch_exec_ms; batch 里的每个 task 都被赋同一个 exec_time_ms = batch_exec_ms
    - finish_time_ms = batch_start + batch_exec_ms
  - 对 batch 中每个完成的 task：找依赖了它的后继, `dep_remaining--`; 
    - 某个后继如果 `dep_remaining == 0`, 立刻把它的 arrival_time_ms 设成当前 `clock_ms`, 再 submit 给 scheduler
  - 重复直到 scheduler 为空, i.e., 没有 ready task 了
- execution flow in simplified words
  - 找出所有 ready task
  - scheduler 从 ready queue 里取最多 batch_size 个
  - 把这批 task 一起 launch
  - 等这整批全部完成
  - 更新 dependents
  - 新 ready 的 task 再进入下一轮
- features: barriered batch execution
  - 调度单位：gate-level task
  - 执行单位：一批 gate
  - 发射策略：每轮最多发 batch_size
  - 同步方式：整批一起等
  - DAG 推进：按批次推进

#### single-gate non-blocking ✅
- execution flow in simplified words:
  - ready task 进入 ready queue
  - 只要有空闲 stream，就从 scheduler 里拿一个 task launch
  - launch 之后这个 task 就变成 in-flight
  - GPU 在跑这些 in-flight task 时，CPU 不傻等整批, CPU 不断检查：
    - 有没有某个 in-flight task 已经完成, 哪个 task 先完成，就先更新它的后继, 
    - 某个后继一旦变 ready，就立刻可以再被 scheduler 选中发出去
  - 重复，直到没有 ready task 且没有 in-flight task 
- features: event-driven stream execution
  - 调度单位：还是 gate-level task
  - 执行单位：一个 gate 一个 launch
  - 发射策略：只要有空 stream 就继续发
  - 同步方式：按单个 task 完成来处理
  - DAG 推进：按事件驱动推进

#### small-chunk non-blocking
- execution flow in simplified words:
  - 先对 circuit 做 levelization
  - 所有没有前驱依赖的 level task 进入 ready 队列，通常就是 level 0。
  - 每一层 = 一个 CUDA task
- features:
  - 优点：kernel 更粗，GPU utilization 更好。
  - 缺点：scheduling 空间变少，因为层和层之间基本串行。

### level-level task execution
- execution flow in simplified words:
  - 先对 circuit 做 levelization
  - 同一个 level 的 gates 按 chunk size 分组，构建 task dependency graph
- features:
  - 优点: 同层天然可并行; 任务数大幅减少; 更接近 GPU 批处理
  - 缺点: 窄层会导致 GPU 吃不满; 深电路会变成很多小层串行

#### small-chunk after levelization

### partition-level task execution
- execution flow in simplified words:
  - 先对 circuit 做partition
- features:
  - 优点：更灵活,可以平衡 task size
  - 缺点：分块策略本身就是一个研究问题