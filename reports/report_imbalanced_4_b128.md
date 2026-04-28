# GPU Scheduler Report
Group: imbalanced_4 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_024131

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.906 | 6.212 | 0.029 | 1.934 | 6.335 | 288106.47 | 11.16 | 0.7741 | 112.06x | 464.78x | 62.97x |
| Priority | 1.639 | 6.348 | 0.030 | 1.669 | 6.485 | 279501.97 | 12.41 | 0.7461 | 87.51x | 418.89x | 48.87x |
| DependencyAware | 2.047 | 7.041 | 0.031 | 2.078 | 7.173 | 252592.38 | 11.01 | 0.8376 | 105.81x | 460.34x | 60.61x |
| SJF | 1.689 | 6.326 | 0.029 | 1.718 | 6.448 | 275831.81 | 12.47 | 0.7609 | 94.75x | 461.99x | 52.72x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.91 ± 0.60 | 6.21 ± 1.61 | 0.03 ± 0.01 | 1.93 ± 0.61 | 6.33 ± 1.63 | 288106.47 ± 44451.89 | 11.16 ± 1.47 | 0.77 | 112.06x ± 25.90 | 464.78x | 62.97x ± 13.72 |
| Priority | 1.64 ± 0.31 | 6.35 ± 1.34 | 0.03 ± 0.00 | 1.67 ± 0.31 | 6.48 ± 1.36 | 279501.97 ± 44198.59 | 12.41 ± 0.47 | 0.75 | 87.51x ± 5.65 | 418.89x | 48.87x ± 2.84 |
| DependencyAware | 2.05 ± 0.53 | 7.04 ± 1.51 | 0.03 ± 0.00 | 2.08 ± 0.54 | 7.17 ± 1.53 | 252592.38 ± 38713.37 | 11.01 ± 0.78 | 0.84 | 105.81x ± 11.58 | 460.34x | 60.61x ± 6.46 |
| SJF | 1.69 ± 0.30 | 6.33 ± 0.86 | 0.03 ± 0.00 | 1.72 ± 0.31 | 6.45 ± 0.86 | 275831.81 ± 29728.30 | 12.47 ± 1.49 | 0.76 | 94.75x ± 17.53 | 461.99x | 52.72x ± 9.43 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 25.24x | 20.09x | 32.95x | 28.42x |
| wl 1 | 145.12x | 125.56x | 139.43x | 148.86x |
| wl 2 | 106.49x | 80.81x | 100.01x | 84.97x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.166 ms² | 0.079 ms² | 0.550 ms² | 0.075 ms² |
| wl 1 | 4.290 ms² | 3.895 ms² | 4.965 ms² | 4.058 ms² |
| wl 2 | 3.159 ms² | 2.277 ms² | 2.792 ms² | 2.323 ms² |
