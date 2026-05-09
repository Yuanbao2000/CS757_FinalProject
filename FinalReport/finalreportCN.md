**Title: GPU Scheduling and Levelization for Circuit Task Graph Execution**

# Abstract
基于 GPU 的 logic simulation 会产生大量 fine-grained operations，同时这些操作之间又存在严格的 data dependencies。虽然同一 dependency frontier 中的 gates 可以并行求值，但单个 logic operation 本身非常轻量，因此 host-side scheduling overhead 和 CUDA kernel launch overhead 可能主导总运行时间。本项目研究 circuit task graph 中 scheduling flexibility 与 execution granularity 之间的 tradeoff。我们将 benchmark circuits 解析为 directed acyclic graphs，实现多种 gate-level scheduling policies，并比较 batch blocking、batch non-blocking、levelization 和 fused levelization。实验对每个 circuit 独立运行，并报告 makespan、throughput、average wait time、average execution time、average turnaround time，以及 runtime-level GPU utilization。结果表明，对于极小的 gate operations，仅改变 ready queue 的排序通常影响有限；而通过 levelized 和 fused-level execution 减少重复的小 kernel launches，往往能带来更直接的 performance benefit。

[Figure 1: Overall system pipeline. 展示 ckt parser -> gate task graph / level task graph -> scheduler -> CUDA executor -> metrics and reports。]

# 1. Introduction
Logic simulation 是 digital circuit verification 中的核心步骤。一个 circuit 可以自然地表示为 directed acyclic graph (DAG)，其中每个 node 是一个 logic gate，每条 edge 表示一个 signal dependency。一个 gate 只有在所有 predecessor gates 都完成后才能执行。GPU 提供了大规模 parallelism，同一 dependency level 上的 gates 理论上可以并行求值。然而，单个 gate 执行的 computation 非常小。AND、OR、XOR 和 inversion 等 basic logic operations 通常只需要少量指令。因此，如果启动过多 small GPU kernels，kernel launch overhead 和 synchronization overhead 可能会超过真正的 computation。

本项目研究 scheduling policy 和 execution granularity 如何影响 GPU logic simulation。我们比较两个主要方向。第一个方向是 gate-level scheduling，即每个 gate 都是一个 schedulable task，scheduler 从 ready queue 中选择 ready gates。第二个方向是 levelized execution，即先按 topological levels 组织 circuit，然后将同一 level 中的所有 gates 作为一个更 coarse-grained task 执行。我们进一步实现 fused levelization，将连续的小 levels 合并到一个 GPU kernel 中，以减少 narrow tail levels 中的重复 launch overhead。

本文的 main contributions 如下。第一，我们实现并比较多种 gate-level scheduling policies，包括 FIFO、fanin priority、SJF 和 dependency-aware scheduling。第二，我们评估不同 execution modes，包括 batch blocking 和 batch non-blocking。第三，我们实现 levelization 和多个 fusion thresholds 下的 fused levelization。最后，我们使用 host-side timing 和 GPU busy-interval accounting，分析 benchmark circuits 上的 performance。

# 2. Background and Motivation
Circuit DAG 的 topology 决定了哪些 gates 可以并行执行。当一个 gate 的所有 predecessors 都完成后，该 gate 变为 ready。Gate-level scheduling policies 决定哪个 ready gate 应该优先执行。例如，FIFO 保持 ready queue 顺序，fanin priority 优先选择输入更多的 gates，SJF 优先选择 estimated work 更小的 gates，而 dependency-aware scheduling 优先选择具有更多 immediate downstream dependents 的 gates。这些 policies 可能影响 dependency progress 和 wait time，但它们仍然以单个 gate 作为基本 scheduling unit。

Levelization 改变了 execution structure。每个 gate 会被分配一个 topological level。Primary inputs 或 source nodes 位于较早 levels，后续每个 gate 的 level 由其 predecessors 的最大 level 决定。同一 level 中的 gates 彼此没有 dependencies，因此可以并行执行。Levelization 将多个 gates 打包为一个 level task，从而减少 scheduling units 数量。

然而，许多 circuits 包含较长的 narrow tail：后续 levels 可能只有少量 gates。如果每个 narrow level 都启动一个 GPU kernel，launch overhead 仍然可能主导 runtime。Fused levelization 通过合并 consecutive small levels 来解决这个问题。如果一段 consecutive levels 中每一层的 gate count 都不超过选定 threshold，例如 256、1024 或 2048 个 gates，则这段 levels 可以在一个 GPU kernel 内执行。该 kernel 按顺序处理 levels，并在 levels 之间使用 lightweight intra-kernel synchronization。这样既避免了重复的 host-side launches，又保留了 levels 之间的 dependency order。

[Figure 2: Levelization example. 展示一个 small circuit DAG，将 gates 按 level 组织，并突出显示若干 consecutive narrow levels 被融合进一个 kernel。]

# 3. Methodology
## 3.1. Circuit Parsing and Task Graph Construction
我们解析 benchmark `.ckt` 文件，得到 gate counts、wire connections、gate types 和 fan-in 信息。Circuit 以 adjacency list 和 inverse-adjacency list 形式存储。对于 gate-level scheduling，每个 gate 会被转换为一个 `Task` 对象。一个 task 存储其 gate id、priority、dependency list、remaining dependency count 和 timing fields。当 remaining dependency count 降为 0 时，该 task 变为 ready。

对于 levelization，同一个 circuit DAG 会被转换为 level-task graph。我们首先为每个 gate 分配 topological level。Source gates 被放在 level 0，其他每个 gate 的 level 为其所有 predecessors 最大 level 加 1。然后，所有相同 level 的 gates 被打包成一个 level task。一个 level task 存储属于该 level 的 gate id 列表，并且 level tasks 之间按顺序连接，使得 level `k + 1` 只有在 level `k` 完成后才会变为 ready。该 representation 将 scheduling unit 从 individual gate 改为 entire topological level。

## 3.2. GPU Execution Backend
GPU executor 使用统一的 gate-batch kernel。Scheduler 选出一批 gates 后，host 将这些 gate id 拷贝到 GPU，并启动一个 CUDA kernel。在 kernel 内，每个 CUDA thread 对应 selected batch 中的一个 gate id。线程读取 gate type 和 fan-in metadata，从 flattened input list 中收集 predecessor outputs，并计算该 gate output。为了让 gate cost 在 benchmark 中可观测，我们按照 fan-in 分配 synthetic work units，并相应重复 gate computation。

每次 scheduler run 前，executor 会重置 gate outputs。在每次 kernel launch 前后，host 记录 launch 和 completion timestamps。这些 timestamps 用于计算 host-side makespan 和 GPU busy intervals。GPU utilization 定义为 host-side active kernel intervals 的并集除以 makespan。该指标是 runtime-level utilization，而不是 profiler-level SM occupancy。

## 3.3. Gate-Level Scheduling Policies
我们比较四种 gate-level scheduling policies。FIFO 按 submission order 执行 ready gates，是最简单的 baseline。Fanin priority 优先选择 fan-in 更大的 gates。SJF 优先选择 estimated work 更小的 gates，目标是减少 average wait time。在我们的实现中，estimated work 与 fan-in 成正比，因此 SJF 实际上会优先选择 fan-in 最小的 ready gate。Dependency-aware scheduling 会预先计算每个 gate 的 immediate downstream dependents 数量，并优先选择可能 unlock more future work 的 gates。

这些 policies 在两种主要 gate-level execution modes 下进行评估。Batch blocking 每次最多选择 `batch_size` 个 ready gates，启动一个 gate-batch kernel，等待该 batch 完成，然后更新 dependencies。这会形成明确的 batch-level barrier：在整个 launched batch 完成之前，不会提交任何 successor gate。Batch non-blocking 则在多个 CUDA streams 上保持若干 batches in flight。只要某个 stream 空闲，scheduler 就可以启动另一个 ready batch。当任意 in-flight batch 完成时，host 会更新该 batch 中 gates 的 dependencies，并立即将 newly ready gates 提交回 scheduler。该模式减少 idle gaps 并提高 dependency responsiveness，同时仍然使用 batch kernels，而不是为每个 gate 单独启动 kernel。

## 3.4. Levelization and Fused Levelization
Levelization 将 gate-level DAG 转换为 level-task graph。每个 level task 包含同一 topological level 中的所有 gates。基础 levelization 方法为每个 level task 启动一个 gate-batch kernel，并在 level-wave barrier 处等待，然后解锁后续 levels。由于同一 level 中的 gates 互相独立，这种执行方式自然暴露 parallelism，并减少 scheduling unit 数量。

Fused levelization 进一步合并 consecutive small levels。给定 threshold `T`，如果一个 ready level 中的 gate count 不超过 `T`，scheduler 会继续检查同一 circuit 中的后续 levels。只要每一层也都低于 threshold，这些 levels 就会被放入同一个 fused segment。该 fused segment 由一个 CUDA kernel 处理。Kernel 按顺序遍历各 levels，使用一个 thread block 处理每层中的 gates，并在 levels 之间使用 `__syncthreads()`。我们评估 `fused_level(256)`、`fused_level(1024)` 和 `fused_level(2048)`。

[Figure 3: Execution mode comparison. 展示三条 timelines：batch blocking 启动 ready-gate batches，levelization 每层启动一个 kernel，fused levelization 为多个 small levels 启动一个 kernel。]

# 4. Experimental Setup and Metrics
## 4.1. Benchmarks and Parameters
实验使用 ISCAS-style benchmark circuits。Small circuits 包括 `c17`、`c432`、`c499` 和 `c880`。Medium circuits 包括 `c1355`、`c1908`、`c2670` 和 `c3540`。Large circuits 包括 `c5315`、`c6288` 和 `c7552`。每个 circuit 独立评估，因此报告结果关注 single-circuit execution behavior。

Gate-level experiments 使用 batch size 32、128 和 512。Levelized experiments 单独报告，并比较 levelization、`fused_level(256)`、`fused_level(1024)` 和 `fused_level(2048)`。每种 configuration 重复运行多次，报告中包含 averages and standard deviations。

## 4.2. Metrics
Average wait time 衡量一个 gate 从变为 ready 到被 launched 之间等待了多久。Maximum wait time 用于指示潜在 starvation。

Average execution time 是归因到每个 gate 的 host-side service interval。在 batch execution 中，同一 batch 中所有 gates 共享该 batch 的 service time。在 levelization 中，同一 level 中所有 gates 共享该 level 的 service time。在 fused levelization 中，fused segment 的 service time 会按各 level 的 gate count 比例分摊到 level 上，避免将整个 fused segment time 重复分配给每个 level。

Average turnaround time 等于 wait time 加 execution time。

Makespan 是一次 scheduler run 从开始到最后一个 GPU task 完成的 host-side 总运行时间。

Throughput 是 completed gates 数量除以 makespan。

GPU utilization 是 host-side active GPU intervals 的并集除以 makespan。

# 5. Results and Analysis
## 5.1. Gate-Level Batch Scheduling
我们首先在 batch blocking 模式下比较 gate-level scheduling policies。
(1) 不同 scheduling policies 之间的差异通常较小。这与 GPU logic simulation 的特点一致：每个 gate operation 都非常轻量，因此仅改变 ready queue 排序通常无法抵消过高的 launch overhead。Dependency-aware scheduling 在一些 circuits 中可以通过更早解锁 downstream gates 带来帮助，但当 ready set 已经较大，或 launch overhead 占主导时，其收益有限。
(2) 更大的 batch size 对性能的改善有限。较大的 batch size 会减少 launch overhead，并可能改善 makespan，但 successor gates 必须等到当前整个 batch 完成后才能执行，这最终可能增加总 makespan。

## 5.2. Blocking and Non-Blocking Execution
Batch blocking 简单，并且每次选出一个 batch 后启动一个 kernel。然而，它引入了 batch-level barrier：即使某些 gates 在概念上可以更早完成，其 dependencies 也要等到整个 batch 完成后才会更新。Batch non-blocking 通过保持多个 batches 同时执行，移除了一部分 barrier。一旦任意 batch 完成，scheduler 就会立即更新其 successors，并在可用 stream 上启动新的 ready work。

当 circuit 具有较深 dependency chain 且 ready set 较小时，non-blocking execution 可能减少 wait time。然而，如果 gate computation 极小，额外的 stream management 和更频繁的 dependency checks 可能抵消更快 dependency update 带来的收益。因此，non-blocking execution 并不总是降低 makespan，尤其是在 small circuits 或具有许多 narrow levels 的 circuits 中。

[Figure: Blocking vs. non-blocking execution.]

## 5.3. Levelization
Levelization 改变了 execution granularity。它不再选择 ready gates 组成 batch，而是按 topological level 执行 circuit。这减少了 scheduling unit 数量，并利用每层内部的 natural parallelism。
- 在我们的实验中，levelization 在 circuit graph execution 上显著优于之前的 gate-level scheduling 方法。主要原因是每个 logic operation 都极其轻量；即使少量 host-side scheduling 和 launch overhead，也会明显影响总运行时间。通过将 gates 打包为 level task，levelization 减少了 scheduling decisions 次数和 kernel launches 次数。
- 一个重要观察是，即使某个 level 的最大 gate count 不超过 batch size，较大的 gate-level batch size 仍然不等价于 levelization。例如，如果最大 level 少于 512 个 gates，那么使用 `batch_size = 512` 的 gate-level scheduler 可能启动一个包含大致相同 gate count 的 GPU kernel。但 host-side scheduling structure 仍然不同。在 gate-level scheduling 中，每个 gate 仍然是 individual task。一个 batch 完成后，runtime 需要为每个 completed gate 更新 dependencies，并且当前实现会在 gate granularity 上检查 dependency relationships。这些重复的 host-side bookkeeping 会被计入 makespan、wait time 和 turnaround time。
- 相比之下，levelization 将整个 topological level 变成一个 coarse-grained task。一个 level 完成后只需解锁下一个 level task，而不是反复把每个 gate 作为独立 schedulable unit 来处理 dependency update。因此，二者的差别不仅在于一个 CUDA kernel 中发送了多少 gates，还在于 CPU-side task granularity 和 dependency maintenance cost。某些 gate-level batch 结果中较低的 GPU utilization 也支持这一解释：GPU 在大部分 wall-clock time 中处于空闲，而 host 花时间进行 scheduling 和 dependency bookkeeping。这解释了为什么即使没有任何单独 level 宽于 512 个 gates，`batch_size = 512` 仍可能明显慢于 levelization。
- Levelization 的主要弱点是 narrow tail levels。许多 circuits 早期 levels 较宽，但后期大量 levels 只包含少量 gates。为每个 narrow level 启动一个 kernel 时，每次 launch 提供的 GPU work 很少，因此 host-side launch overhead 可能主导 runtime。所以，levelization 的效果取决于 circuit 的 level width distribution。

[Figure 4: Gate-level scheduling execution versus levelization. 比较最佳 gate-level batch configuration 和 levelization 的 makespan 与 throughput。]

## 5.4. Fused Levelization
Fused levelization 直接针对 narrow-tail problem。通过在一个 kernel 内执行 consecutive small levels，它减少了重复的 host-side launches 和 synchronization。我们比较 `fused_level(256)`、`fused_level(1024)` 和 `fused_level(2048)`。较小 threshold 更保守，能保留更多原始 levelization structure；较大 threshold 更激进地减少 launch count，但也可能把更多 sequential level work 放入同一个 kernel。

[Figure 5: Levelization versus fused levelization. 比较 levelization、fused_level(256)、fused_level(1024) 和 fused_level(2048) 的 makespan 与 throughput。]

# 6. Weakness and Future Work
目前，本项目仍有若干限制。第一，GPU utilization 使用 host-side active intervals 测量，而不是 profiler-level SM occupancy。第二，executor 是一个简化的 course-project backend，而不是完整的 industrial simulator。第三，fused-level threshold 是经验性的，取决于 GPU architecture、memory behavior 和 circuit structure。

基于实验结果，最重要的观察是 levelization 能显著改善 circuit graph execution。在回顾 related work 后，我们认为，与不断设计更 fine-grained GPU scheduling policies 相比，levelization 和 graph partitioning 更适合 circuit graph execution。未来工作应重点改进 levelized execution，并探索 partition-based execution。对于 levelization，CUDA Graphs 或 conditional CUDA Graphs 可能进一步减少重复 launch overhead。对于 partitioning，可以将 circuit 划分为若干 subgraphs，在 parallelism、dependency depth 和 GPU occupancy 之间取得平衡，也可以考虑 replication-aided partitioning 技术。

# 7. Conclusion
本项目比较了 GPU logic simulation 中的多种 scheduling policies 和 execution granularity。Gate-level scheduling policies 会影响 wait time 和 dependency progress，但其影响受到单个 gate operation 成本极低这一事实的限制。Batch size 影响较大，因为它同时改变 launch overhead 和 dependency update frequency。Levelization 通过逐层执行 gates 来降低 scheduling granularity，实验结果表明它在 circuit graph execution 中可以优于 fine-grained scheduling。然而，narrow tail levels 仍可能导致低效的小 kernel launches。Fused levelization 通过在一个 kernel 内执行 consecutive small levels 来减少这一开销。

`batch_size = 512` 与 levelization 的比较表明，仅让每个 GPU kernel 中的 gate count 相近，并不足以获得相同性能。Levelization 还通过将 schedulable unit 从 gate 改为 level，移除了大量 per-gate host-side scheduling 和 dependency-update overhead。

总体而言，对于 logic simulation 这类 fine-grained、dependency-heavy GPU applications，选择合适的 execution granularity 通常比设计更复杂的 ready-queue scheduler 更重要。
