# GPU Scheduler Report
Group: balanced_1 | batch_size=32 | runs=10 (averaged)

Generated: 20260403_231700

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 16.976 | 57.334 | 0.347 | 17.323 | 57.469 | 20691.35 | 25.92 | 0.9843 | 823.37x | 6664.59x | 449.23x |
| Priority | 16.070 | 62.996 | 0.220 | 16.290 | 63.132 | 18833.62 | 16.32 | 0.9731 | 902.48x | 4808.88x | 470.29x |
| DependencyAware | 17.190 | 55.742 | 0.327 | 17.517 | 55.880 | 21280.51 | 24.98 | 0.9926 | 810.62x | 7549.83x | 448.53x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 16.98 ± 0.20 | 57.33 ± 0.56 | 0.35 ± 0.00 | 17.32 ± 0.21 | 57.47 ± 0.56 | 20691.35 ± 200.86 | 25.92 ± 0.20 | 0.98 | 823.37x ± 59.92 | 6664.59x | 449.23x ± 32.83 |
| Priority | 16.07 ± 0.09 | 63.00 ± 0.20 | 0.22 ± 0.00 | 16.29 ± 0.10 | 63.13 ± 0.19 | 18833.62 ± 58.11 | 16.32 ± 0.07 | 0.97 | 902.48x ± 81.27 | 4808.88x | 470.29x ± 42.28 |
| DependencyAware | 17.19 ± 0.31 | 55.74 ± 0.63 | 0.33 ± 0.00 | 17.52 ± 0.31 | 55.88 ± 0.63 | 21280.51 ± 240.70 | 24.98 ± 0.49 | 0.99 | 810.62x ± 57.21 | 7549.83x | 448.53x ± 28.76 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 917.31x | 1387.85x | 894.91x |
| wl 1 | 928.13x | 1050.25x | 1049.23x |
| wl 2 | 767.39x | 741.66x | 713.20x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 432.938 ms² | 574.477 ms² | 403.203 ms² |
| wl 1 | 314.189 ms² | 275.854 ms² | 317.863 ms² |
| wl 2 | 324.036 ms² | 303.918 ms² | 283.382 ms² |
