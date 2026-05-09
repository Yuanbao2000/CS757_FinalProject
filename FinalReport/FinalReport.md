**题目：面向电路任务图执行的 GPU 调度与层次化方法**

# 摘要
基于 GPU 的逻辑仿真会产生大量细粒度操作，同时这些操作之间又存在严格的数据依赖。虽然同一依赖前沿中的门可以并行求值，但单个逻辑操作本身非常轻量，因此主机端调度开销和 CUDA kernel 启动开销可能主导总运行时间。本项目研究电路任务图中调度灵活性与执行粒度之间的权衡。我们将基准电路解析为有向无环图，实现多种门级调度策略，并比较 batch blocking、batch non-blocking、levelization 和 fused levelization。实验对每个电路独立运行，并报告 makespan、throughput、平均等待时间、平均执行时间、平均周转时间，以及运行时层面的 GPU 利用率。结果表明，对于极小的门操作，仅改变 ready queue 的排序通常影响有限；而通过 levelized 和 fused-level 执行减少重复的小 kernel 启动，往往能带来更直接的性能收益。

[图 1：整体系统流程。展示 ckt parser -> gate task graph / level task graph -> scheduler -> CUDA executor -> metrics and reports。]

# 1. 引言
逻辑仿真是数字电路验证中的核心步骤。一个电路可以自然地表示为有向无环图，其中每个节点是一个逻辑门，每条边表示一个信号依赖。一个门只有在所有前驱门都完成后才能执行。GPU 提供了大规模并行能力，同一依赖层级上的门理论上可以并行求值。然而，单个门执行的计算量非常小。AND、OR、XOR 和取反等基本逻辑操作通常只需要少量指令。因此，如果启动过多小型 GPU kernel，kernel 启动开销和同步开销可能会超过真正的计算开销。

本项目研究调度策略和执行粒度如何影响 GPU 逻辑仿真。我们比较两个主要方向。第一个方向是门级调度，即每个门都是一个可调度任务，调度器从 ready queue 中选择就绪门。第二个方向是层次化执行，即先按拓扑层级组织电路，然后将同一层中的所有门作为一个更粗粒度的任务执行。我们进一步实现 fused levelization，将连续的小层级合并到一个 GPU kernel 中，以减少窄尾层级中的重复启动开销。

本文的主要贡献如下。第一，我们实现并比较多种门级调度策略，包括 FIFO、fanin priority、SJF 和 dependency-aware scheduling。第二，我们评估不同执行模式，包括 batch blocking 和 batch non-blocking。第三，我们实现 levelization 和多个融合阈值下的 fused levelization。最后，我们使用主机端计时和 GPU busy interval 统计，分析基准电路上的性能表现。

# 2. 背景与动机
电路 DAG 的拓扑结构决定了哪些门可以并行执行。当一个门的所有前驱都完成后，该门变为 ready。门级调度策略决定哪个 ready gate 应该优先执行。例如，FIFO 保持 ready queue 顺序，fanin priority 优先选择输入更多的门，SJF 优先选择估计工作量更小的门，而 dependency-aware scheduling 优先选择具有更多直接下游依赖的门。这些策略可能影响依赖推进和等待时间，但它们仍然以单个门作为基本调度单元。

Levelization 改变了执行结构。每个门会被分配一个拓扑层级。主输入或源节点位于较早层级，后续每个门的层级由其前驱的最大层级决定。同一层中的门彼此没有依赖，因此可以并行执行。Levelization 将多个门打包为一个 level task，从而减少调度单元数量。

然而，许多电路包含较长的窄尾结构：后续层级可能只有少量门。如果每个窄层级都启动一个 GPU kernel，启动开销仍然可能主导运行时间。Fused levelization 通过合并连续的小层级来解决这个问题。如果一段连续层级中每一层的门数量都不超过选定阈值，例如 256、1024 或 2048 个门，则这段层级可以在一个 GPU kernel 内执行。该 kernel 按顺序处理层级，并在层级之间使用轻量级的 kernel 内同步。这样既避免了重复的主机端启动，又保留了层级之间的依赖顺序。

[图 2：Levelization 示例。展示一个小型电路 DAG，将门按层级组织，并突出显示若干连续窄层级被融合进一个 kernel。]

# 3. 方法
## 3.1. 电路解析与任务图构建
我们解析基准 `.ckt` 文件，得到门数量、连线关系、门类型和 fan-in 信息。电路以邻接表和逆邻接表形式存储。对于门级调度，每个门会被转换为一个 `Task` 对象。一个 task 存储其 gate id、priority、依赖列表、剩余依赖计数和计时字段。当剩余依赖计数降为 0 时，该 task 变为 ready。

对于 levelization，同一个电路 DAG 会被转换为 level-task graph。我们首先为每个门分配拓扑层级。源门被放在 level 0，其他每个门的层级为其所有前驱最大层级加 1。然后，所有相同层级的门被打包成一个 level task。一个 level task 存储属于该层级的 gate id 列表，并且 level task 之间按顺序连接，使得 level `k + 1` 只有在 level `k` 完成后才会变为 ready。该表示方式将调度单元从单个门改为整个拓扑层级。

## 3.2. GPU 执行后端
GPU executor 使用统一的 gate-batch kernel。调度器选出一批门后，主机将这些 gate id 拷贝到 GPU，并启动一个 CUDA kernel。在 kernel 内，每个 CUDA thread 对应选中 batch 中的一个 gate id。线程读取门类型和 fan-in 元数据，从扁平化输入列表中收集前驱输出，并计算该门输出。为了让门的计算成本在基准测试中可观测，我们按照 fan-in 分配合成工作量，并相应重复门计算。

每次调度器运行前，executor 会重置门输出。在每次 kernel 启动前后，主机记录启动与完成时间戳。这些时间戳用于计算主机端 makespan 和 GPU busy interval。GPU utilization 定义为主机端活跃 kernel 区间的并集除以 makespan。该指标是运行时层面的利用率，而不是 profiler 层面的 SM occupancy。

## 3.3. 门级调度策略
我们比较四种门级调度策略。FIFO 按提交顺序执行 ready gate，是最简单的 baseline。Fanin priority 优先选择 fan-in 更大的门。SJF 优先选择估计工作量更小的门，目标是减少平均等待时间。在我们的实现中，估计工作量与 fan-in 成正比，因此 SJF 实际上会优先选择 fan-in 最小的 ready gate。Dependency-aware scheduling 会预先计算每个门的直接下游依赖数量，并优先选择可能解锁更多后续工作的门。

这些策略在两种主要门级执行模式下进行评估。Batch blocking 每次最多选择 `batch_size` 个 ready gate，启动一个 gate-batch kernel，等待该 batch 完成，然后更新依赖。这会形成明确的 batch 级屏障：在整个已启动 batch 完成之前，不会提交任何后继门。Batch non-blocking 则在多个 CUDA stream 上保持若干 batch 同时执行。只要某个 stream 空闲，调度器就可以启动另一个 ready batch。当任意 in-flight batch 完成时，主机会更新该 batch 中门的依赖，并立即将新就绪的门提交回调度器。该模式减少空闲间隙并提高依赖响应速度，同时仍然使用 batch kernel，而不是为每个门单独启动 kernel。

## 3.4. Levelization 与 Fused Levelization
Levelization 将门级 DAG 转换为 level-task graph。每个 level task 包含同一拓扑层级中的所有门。基础 levelization 方法为每个 level task 启动一个 gate-batch kernel，并在 level wave 屏障处等待，然后解锁后续层级。由于同一层中的门互相独立，这种执行方式自然暴露并行性，并减少调度单元数量。

Fused levelization 进一步合并连续的小层级。给定阈值 `T`，如果一个 ready level 中的门数量不超过 `T`，调度器会继续检查同一电路中的后续层级。只要每一层也都低于阈值，这些层级就会被放入同一个 fused segment。该 fused segment 由一个 CUDA kernel 处理。Kernel 按顺序遍历各层级，使用一个 thread block 处理每层中的门，并在层级之间使用 `__syncthreads()`。我们评估 `fused_level(256)`、`fused_level(1024)` 和 `fused_level(2048)`。

[图 3：执行模式比较。展示三条时间线：batch blocking 启动 ready-gate batch，levelization 每层启动一个 kernel，fused levelization 为多个小层级启动一个 kernel。]

# 4. 实验设置与指标
## 4.1. 基准电路与参数
实验使用 ISCAS 风格的基准电路。小型电路包括 `c17`、`c432`、`c499` 和 `c880`。中型电路包括 `c1355`、`c1908`、`c2670` 和 `c3540`。大型电路包括 `c5315`、`c6288` 和 `c7552`。每个电路独立评估，因此报告结果关注单电路执行行为。

门级实验使用 batch size 32、128 和 512。Levelized 实验单独报告，并比较 levelization、`fused_level(256)`、`fused_level(1024)` 和 `fused_level(2048)`。每种配置重复运行多次，报告中包含平均值和标准差。

## 4.2. 指标
平均等待时间衡量一个门从变为 ready 到被启动之间等待了多久。最大等待时间用于指示潜在 starvation。

平均执行时间是归因到每个门的主机端服务区间。在 batch 执行中，同一 batch 中所有门共享该 batch 的服务时间。在 levelization 中，同一 level 中所有门共享该 level 的服务时间。在 fused levelization 中，fused segment 的服务时间会按各 level 的门数量比例分摊到 level 上，避免将整个 fused segment 时间重复分配给每个 level。

平均周转时间等于等待时间加执行时间。

Makespan 是一次调度器运行从开始到最后一个 GPU task 完成的主机端总运行时间。

Throughput 是完成的门数量除以 makespan。

GPU utilization 是主机端活跃 GPU 区间的并集除以 makespan。

# 5. 结果与分析
## 5.1. 门级 Batch 调度
我们首先在 batch blocking 模式下比较门级调度策略。
(1) 不同调度策略之间的差异通常较小。这与 GPU 逻辑仿真的特点一致：每个门操作都非常轻量，因此仅改变 ready queue 排序通常无法抵消过高的启动开销。Dependency-aware scheduling 在一些电路中可以通过更早解锁下游门带来帮助，但当 ready set 已经较大，或启动开销占主导时，其收益有限。
(2) 更大的 batch size 对性能的改善有限。较大的 batch size 会减少启动开销，并可能改善 makespan，但后继门必须等到当前整个 batch 完成后才能执行，这最终可能增加总 makespan。

## 5.2. Blocking 与 Non-Blocking 执行
Batch blocking 简单，并且每次选出一个 batch 后启动一个 kernel。然而，它引入了 batch 级屏障：即使某些门在概念上可以更早完成，其依赖也要等到整个 batch 完成后才会更新。Batch non-blocking 通过保持多个 batch 同时执行，移除了一部分屏障。一旦任意 batch 完成，调度器就会立即更新其后继，并在可用 stream 上启动新的 ready work。

当电路具有较深依赖链且 ready set 较小时，non-blocking 执行可能减少等待时间。然而，如果门计算极小，额外的 stream 管理和更频繁的依赖检查可能抵消更快依赖更新带来的收益。因此，non-blocking 执行并不总是降低 makespan，尤其是在小型电路或具有许多窄层级的电路中。

[图：比较 blocking 与 non-blocking 执行]

## 5.3. Levelization
Levelization 改变了执行粒度。它不再选择 ready gates 组成 batch，而是按拓扑层级执行电路。这减少了调度单元数量，并利用每层内部的自然并行性。
- 在我们的实验中，levelization 在电路图执行上显著优于之前的门级调度方法。主要原因是每个逻辑操作都极其轻量；即使少量主机端调度和启动开销，也会明显影响总运行时间。通过将门打包为 level task，levelization 减少了调度决策次数和 kernel 启动次数。
- 一个重要观察是，即使某个 level 的最大门数量不超过 batch size，较大的门级 batch size 仍然不等价于 levelization。例如，如果最大 level 少于 512 个门，那么使用 `batch_size = 512` 的门级调度器可能启动一个包含大致相同门数量的 GPU kernel。但主机端调度结构仍然不同。在门级调度中，每个门仍然是独立任务。一个 batch 完成后，运行时需要为每个完成的门更新依赖，并且当前实现会在门粒度上检查依赖关系。这些重复的主机端 bookkeeping 会被计入 makespan、等待时间和周转时间。
- 相比之下，levelization 将整个拓扑层级变成一个粗粒度任务。一个 level 完成后只需解锁下一个 level task，而不是反复把每个门作为独立可调度单元来处理依赖更新。因此，二者的差别不仅在于一个 CUDA kernel 中发送了多少门，还在于 CPU 端任务粒度和依赖维护成本。某些门级 batch 结果中较低的 GPU utilization 也支持这一解释：GPU 在大部分 wall-clock time 中处于空闲，而主机端花时间进行调度和依赖 bookkeeping。这解释了为什么即使没有任何单独 level 宽于 512 个门，`batch_size = 512` 仍可能明显慢于 levelization。
- Levelization 的主要弱点是窄尾层级。许多电路早期层级较宽，但后期大量层级只包含少量门。为每个窄层级启动一个 kernel 时，每次启动提供的 GPU 工作量很少，因此主机端启动开销可能主导运行时间。所以，levelization 的效果取决于电路的 level width distribution。

[图 4：门级调度执行与 levelization 对比。比较最佳门级 batch 配置和 levelization 的 makespan 与 throughput。]

## 5.4. Fused Levelization
Fused levelization 直接针对窄尾问题。通过在一个 kernel 内执行连续的小层级，它减少了重复的主机端启动和同步。我们比较 `fused_level(256)`、`fused_level(1024)` 和 `fused_level(2048)`。较小阈值更保守，能保留更多原始 levelization 结构；较大阈值更激进地减少启动次数，但也可能把更多顺序 level 工作放入同一个 kernel。

[图 5：Levelization 与 fused levelization 对比。比较 levelization、fused_level(256)、fused_level(1024) 和 fused_level(2048) 的 makespan 与 throughput。]

# 6. 不足与未来工作
目前，本项目仍有若干限制。第一，GPU utilization 使用主机端活跃区间测量，而不是 profiler 层面的 SM occupancy。第二，executor 是一个简化的课程项目后端，而不是完整的工业级仿真器。第三，fused-level 阈值是经验性的，取决于 GPU 架构、内存行为和电路结构。

基于实验结果，最重要的观察是 levelization 能显著改善电路图执行。在回顾相关工作后，我们认为，与不断设计更细粒度的 GPU 调度策略相比，levelization 和 graph partitioning 更适合电路图执行。未来工作应重点改进 levelized execution，并探索基于 partition 的执行方式。对于 levelization，CUDA Graphs 或 conditional CUDA Graphs 可能进一步减少重复启动开销。对于 partitioning，可以将电路划分为若干子图，在并行性、依赖深度和 GPU occupancy 之间取得平衡，也可以考虑 replication-aided partitioning 技术。

# 7. 结论
本项目比较了 GPU 逻辑仿真中的多种调度策略和执行粒度。门级调度策略会影响等待时间和依赖推进，但其影响受到单个门操作成本极低这一事实的限制。Batch size 影响较大，因为它同时改变启动开销和依赖更新频率。Levelization 通过逐层执行门来降低调度粒度，实验结果表明它在电路图执行中可以优于细粒度调度。然而，窄尾层级仍可能导致低效的小 kernel 启动。Fused levelization 通过在一个 kernel 内执行连续的小层级来减少这一开销。

`batch_size = 512` 与 levelization 的比较表明，仅让每个 GPU kernel 中的门数量相近，并不足以获得相同性能。Levelization 还通过将可调度单元从门改为 level，移除了大量逐门主机端调度和依赖更新开销。

总体而言，对于逻辑仿真这类细粒度、依赖密集的 GPU 应用，选择合适的执行粒度通常比设计更复杂的 ready-queue 调度器更重要。
