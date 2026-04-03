# GPU Scheduler Report
Group: imbalanced_4 | batch_size=128 | runs=10 (averaged)

Generated: 20260403_231801

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 11.119 | 39.043 | 0.224 | 11.343 | 39.174 | 44868.59 | 13.82 | 0.7312 | 479.45x | 5005.92x | 275.65x |
| Priority | 12.602 | 51.856 | 0.147 | 12.749 | 51.988 | 33750.47 | 7.48 | 0.6756 | 631.70x | 3256.09x | 351.10x |
| DependencyAware | 10.815 | 40.446 | 0.252 | 11.066 | 40.571 | 43264.33 | 15.23 | 0.8055 | 396.62x | 6404.62x | 237.30x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 11.12 ± 0.65 | 39.04 ± 2.00 | 0.22 ± 0.01 | 11.34 ± 0.66 | 39.17 ± 2.00 | 44868.59 ± 2342.86 | 13.82 ± 0.60 | 0.73 | 479.45x ± 66.61 | 5005.92x | 275.65x ± 37.61 |
| Priority | 12.60 ± 0.38 | 51.86 ± 1.54 | 0.15 ± 0.00 | 12.75 ± 0.38 | 51.99 ± 1.54 | 33750.47 ± 1044.26 | 7.48 ± 0.14 | 0.68 | 631.70x ± 61.20 | 3256.09x | 351.10x ± 33.75 |
| DependencyAware | 10.81 ± 0.43 | 40.45 ± 1.46 | 0.25 ± 0.01 | 11.07 ± 0.43 | 40.57 ± 1.46 | 43264.33 ± 1571.00 | 15.23 ± 0.42 | 0.81 | 396.62x ± 14.63 | 6404.62x | 237.30x ± 9.44 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 75.50x | 17.86x | 106.95x |
| wl 1 | 659.18x | 1054.87x | 618.13x |
| wl 2 | 448.58x | 556.01x | 356.71x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 2.837 ms² | 0.047 ms² | 9.936 ms² |
| wl 1 | 197.612 ms² | 396.868 ms² | 202.061 ms² |
| wl 2 | 143.632 ms² | 256.065 ms² | 123.200 ms² |
