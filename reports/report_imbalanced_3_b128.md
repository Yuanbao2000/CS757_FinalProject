# GPU Scheduler Report
Group: imbalanced_3 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_024118

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 2.126 | 8.006 | 0.037 | 2.162 | 8.131 | 200788.47 | 12.97 | 0.9753 | 116.15x | 545.05x | 61.69x |
| Priority | 1.876 | 7.513 | 0.036 | 1.912 | 7.625 | 213137.34 | 14.15 | 0.9798 | 99.42x | 509.71x | 52.21x |
| DependencyAware | 2.064 | 8.050 | 0.036 | 2.100 | 8.154 | 198933.16 | 12.75 | 0.9746 | 108.57x | 554.22x | 58.73x |
| SJF | 1.730 | 7.357 | 0.036 | 1.766 | 7.476 | 217033.45 | 14.23 | 0.9798 | 90.87x | 471.88x | 47.93x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 2.13 ± 0.36 | 8.01 ± 1.12 | 0.04 ± 0.01 | 2.16 ± 0.36 | 8.13 ± 1.13 | 200788.47 ± 22817.97 | 12.97 ± 0.90 | 0.98 | 116.15x ± 23.14 | 545.05x | 61.69x ± 11.82 |
| Priority | 1.88 ± 0.55 | 7.51 ± 0.88 | 0.04 ± 0.00 | 1.91 ± 0.55 | 7.63 ± 0.88 | 213137.34 ± 20783.21 | 14.15 ± 1.56 | 0.98 | 99.42x ± 25.84 | 509.71x | 52.21x ± 13.27 |
| DependencyAware | 2.06 ± 0.27 | 8.05 ± 0.83 | 0.04 ± 0.00 | 2.10 ± 0.27 | 8.15 ± 0.84 | 198933.16 ± 18096.63 | 12.75 ± 0.32 | 0.97 | 108.57x ± 4.10 | 554.22x | 58.73x ± 2.23 |
| SJF | 1.73 ± 0.13 | 7.36 ± 0.78 | 0.04 ± 0.00 | 1.77 ± 0.14 | 7.48 ± 0.79 | 217033.45 ± 19792.95 | 14.23 ± 0.55 | 0.98 | 90.87x ± 5.56 | 471.88x | 47.93x ± 3.02 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 154.23x | 139.67x | 157.57x | 136.53x |
| wl 1 | 62.09x | 56.66x | 63.07x | 54.59x |
| wl 2 | 142.14x | 116.26x | 124.23x | 100.93x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 4.266 ms² | 4.046 ms² | 4.725 ms² | 4.035 ms² |
| wl 1 | 1.604 ms² | 1.623 ms² | 1.219 ms² | 1.355 ms² |
| wl 2 | 3.923 ms² | 3.466 ms² | 3.946 ms² | 3.168 ms² |
