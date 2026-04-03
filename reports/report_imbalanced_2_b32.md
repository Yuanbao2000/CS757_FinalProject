# GPU Scheduler Report
Group: imbalanced_2 | batch_size=32 | runs=10 (averaged)

Generated: 20260403_231702

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 8.964 | 38.131 | 0.303 | 9.267 | 38.275 | 19151.51 | 27.05 | 0.9515 | 388.36x | 5708.38x | 225.36x |
| Priority | 9.059 | 38.427 | 0.206 | 9.264 | 38.570 | 19005.15 | 20.06 | 0.9777 | 526.28x | 2986.85x | 295.06x |
| DependencyAware | 8.785 | 36.664 | 0.331 | 9.117 | 36.799 | 19925.88 | 31.07 | 0.9655 | 391.14x | 3486.63x | 219.14x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 8.96 ± 0.07 | 38.13 ± 0.23 | 0.30 ± 0.00 | 9.27 ± 0.07 | 38.28 ± 0.24 | 19151.51 ± 118.85 | 27.05 ± 0.33 | 0.95 | 388.36x ± 26.15 | 5708.38x | 225.36x ± 14.86 |
| Priority | 9.06 ± 0.06 | 38.43 ± 0.21 | 0.21 ± 0.00 | 9.26 ± 0.06 | 38.57 ± 0.20 | 19005.15 ± 100.45 | 20.06 ± 0.07 | 0.98 | 526.28x ± 16.03 | 2986.85x | 295.06x ± 8.39 |
| DependencyAware | 8.79 ± 0.08 | 36.66 ± 0.70 | 0.33 ± 0.00 | 9.12 ± 0.09 | 36.80 ± 0.70 | 19925.88 ± 371.68 | 31.07 ± 0.39 | 0.97 | 391.14x ± 11.56 | 3486.63x | 219.14x ± 6.21 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 376.82x | 554.17x | 417.14x |
| wl 1 | 498.77x | 637.05x | 452.42x |
| wl 2 | 305.46x | 420.35x | 326.44x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 159.009 ms² | 168.644 ms² | 141.251 ms² |
| wl 1 | 73.573 ms² | 74.871 ms² | 71.107 ms² |
| wl 2 | 97.901 ms² | 83.136 ms² | 94.745 ms² |
