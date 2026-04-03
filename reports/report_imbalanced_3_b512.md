# GPU Scheduler Report
Group: imbalanced_3 | batch_size=512 | runs=10 (averaged)

Generated: 20260403_231835

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 16.140 | 57.409 | 0.364 | 16.503 | 57.526 | 27944.71 | 14.30 | 0.9973 | 531.98x | 9437.21x | 286.73x |
| Priority | 20.596 | 70.839 | 0.242 | 20.838 | 70.967 | 22644.88 | 7.47 | 0.9977 | 997.77x | 4441.57x | 521.02x |
| DependencyAware | 16.002 | 56.879 | 0.356 | 16.357 | 57.001 | 28203.91 | 14.21 | 0.9964 | 576.33x | 8502.33x | 310.70x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 16.14 ± 0.34 | 57.41 ± 1.08 | 0.36 ± 0.00 | 16.50 ± 0.34 | 57.53 ± 1.08 | 27944.71 ± 517.61 | 14.30 ± 0.28 | 1.00 | 531.98x ± 46.13 | 9437.21x | 286.73x ± 23.66 |
| Priority | 20.60 ± 0.13 | 70.84 ± 0.33 | 0.24 ± 0.00 | 20.84 ± 0.13 | 70.97 ± 0.33 | 22644.88 ± 105.36 | 7.47 ± 0.05 | 1.00 | 997.77x ± 11.92 | 4441.57x | 521.02x ± 6.94 |
| DependencyAware | 16.00 ± 0.40 | 56.88 ± 1.14 | 0.36 ± 0.00 | 16.36 ± 0.41 | 57.00 ± 1.14 | 28203.91 ± 570.22 | 14.21 ± 0.23 | 1.00 | 576.33x ± 16.01 | 8502.33x | 310.70x ± 9.02 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 867.06x | 1496.92x | 784.41x |
| wl 1 | 251.96x | 506.35x | 308.21x |
| wl 2 | 616.01x | 1177.85x | 698.17x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 422.681 ms² | 635.603 ms² | 387.755 ms² |
| wl 1 | 143.781 ms² | 213.725 ms² | 130.908 ms² |
| wl 2 | 353.236 ms² | 521.127 ms² | 321.233 ms² |
