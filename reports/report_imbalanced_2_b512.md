# GPU Scheduler Report
Group: imbalanced_2 | batch_size=512 | runs=10 (averaged)

Generated: 20260403_231828

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 7.407 | 36.730 | 0.301 | 7.708 | 36.851 | 19894.30 | 22.43 | 0.9405 | 269.77x | 2691.21x | 153.61x |
| Priority | 8.253 | 39.030 | 0.186 | 8.439 | 39.162 | 18717.41 | 12.89 | 0.9375 | 362.50x | 2343.90x | 206.87x |
| DependencyAware | 7.670 | 36.254 | 0.297 | 7.968 | 36.386 | 20145.66 | 21.97 | 0.9523 | 261.42x | 2964.27x | 155.26x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 7.41 ± 0.08 | 36.73 ± 0.47 | 0.30 ± 0.00 | 7.71 ± 0.09 | 36.85 ± 0.47 | 19894.30 ± 250.93 | 22.43 ± 0.39 | 0.94 | 269.77x ± 27.91 | 2691.21x | 153.61x ± 14.33 |
| Priority | 8.25 ± 0.02 | 39.03 ± 0.12 | 0.19 ± 0.00 | 8.44 ± 0.02 | 39.16 ± 0.12 | 18717.41 ± 57.90 | 12.89 ± 0.05 | 0.94 | 362.50x ± 6.45 | 2343.90x | 206.87x ± 3.77 |
| DependencyAware | 7.67 ± 0.05 | 36.25 ± 0.20 | 0.30 ± 0.00 | 7.97 ± 0.05 | 36.39 ± 0.20 | 20145.66 ± 107.45 | 21.97 ± 0.29 | 0.95 | 261.42x ± 3.66 | 2964.27x | 155.26x ± 2.69 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 368.00x | 396.72x | 230.91x |
| wl 1 | 304.00x | 426.59x | 359.56x |
| wl 2 | 185.38x | 290.78x | 199.41x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 149.861 ms² | 170.470 ms² | 148.948 ms² |
| wl 1 | 58.025 ms² | 66.945 ms² | 60.102 ms² |
| wl 2 | 84.818 ms² | 94.172 ms² | 85.903 ms² |
