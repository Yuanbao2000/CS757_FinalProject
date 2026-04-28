# GPU Scheduler Report
Group: balanced_0 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_024203

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.492 | 6.449 | 0.036 | 1.529 | 6.557 | 178373.25 | 14.05 | 0.9795 | 79.93x | 420.13x | 44.89x |
| Priority | 1.496 | 6.631 | 0.036 | 1.533 | 6.759 | 172844.41 | 14.15 | 0.9766 | 75.64x | 397.10x | 41.83x |
| DependencyAware | 1.630 | 6.972 | 0.038 | 1.668 | 7.091 | 169590.69 | 14.03 | 0.9805 | 75.82x | 394.74x | 43.21x |
| SJF | 1.824 | 7.398 | 0.038 | 1.862 | 7.527 | 162116.52 | 12.81 | 0.9812 | 86.24x | 435.18x | 47.66x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.49 ± 0.18 | 6.45 ± 0.91 | 0.04 ± 0.01 | 1.53 ± 0.19 | 6.56 ± 0.92 | 178373.25 ± 20341.69 | 14.05 ± 1.01 | 0.98 | 79.93x ± 18.17 | 420.13x | 44.89x ± 9.80 |
| Priority | 1.50 ± 0.16 | 6.63 ± 0.85 | 0.04 ± 0.01 | 1.53 ± 0.17 | 6.76 ± 0.88 | 172844.41 ± 19759.12 | 14.15 ± 0.51 | 0.98 | 75.64x ± 4.68 | 397.10x | 41.83x ± 2.69 |
| DependencyAware | 1.63 ± 0.43 | 6.97 ± 1.64 | 0.04 ± 0.01 | 1.67 ± 0.43 | 7.09 ± 1.66 | 169590.69 ± 31224.84 | 14.03 ± 0.96 | 0.98 | 75.82x ± 9.13 | 394.74x | 43.21x ± 5.07 |
| SJF | 1.82 ± 0.79 | 7.40 ± 2.05 | 0.04 ± 0.01 | 1.86 ± 0.80 | 7.53 ± 2.07 | 162116.52 ± 33913.45 | 12.81 ± 2.09 | 0.98 | 86.24x ± 22.07 | 435.18x | 47.66x ± 12.05 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 82.10x | 86.93x | 87.72x | 97.93x |
| wl 1 | 137.13x | 122.44x | 118.91x | 139.91x |
| wl 2 | 50.35x | 46.26x | 47.96x | 53.22x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 3.143 ms² | 3.233 ms² | 3.826 ms² | 4.591 ms² |
| wl 1 | 3.572 ms² | 3.706 ms² | 4.388 ms² | 5.289 ms² |
| wl 2 | 1.070 ms² | 1.088 ms² | 1.363 ms² | 1.774 ms² |
