### Update from my side:

**Merged both approaches:**
I plugged the ISCAS-85 circuit parser (from the LSIM infrastructure) into the gpu_scheduler. We're now running all three scheduling policies (FIFO, Priority, DependencyAware) on real circuits. The `batch_size` knob from the FIFO branch is also wired in. We run each config 10 times with batch size (32, 128, 512) and report mean ± stddev, so results are statistically solid.

**How workloads are structured:**
We defined 6 workload groups: 2 balanced (circuits of similar size competing) and 4 imbalanced (mix of tiny to huge circuits). Each group runs all 3 circuits simultaneously so the scheduler has to balance between them. This makes Jain's fairness meaningful.

**Key findings from the reports:**
- **Balanced groups**: all schedulers behave similarly on fairness (~0.98)
- **Imbalanced groups**: fairness degrades, especially imbalanced_4 (c17 + c1908 + c7552) which drops to 0.67 ~ 0.81
- In that extreme case, Priority gives c17 only 17x slowdown at batch=128 (nearly instant) but starves the larger circuits. DependencyAware buries c17 at 605x slowdown because it prioritizes high fan-in gates.
- GPU utilization is consistently low (~10–25%). This is expected because serial batch dispatch leaves the GPU idle while the CPU updates dependents between batches.

**What we can do next (worth a discussion together):**
The low GPU utilization points directly to the concurrent dispatch improvement. Instead of launching one batch, syncing, then scheduling the next, we launch all ready tasks across streams and update dependents while the GPU is still running. This would give us a direct before/after comparison on `utilization` and `makespan`, which is a clean contribution for the paper. I think this is worth a quick sync before anyone starts implementing.
