# GPU Scheduler Report
Group: imbalanced_5 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_024306

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 2.018 | 8.245 | 0.034 | 2.051 | 8.361 | 292440.56 | 10.76 | 0.9909 | 113.95x | 553.81x | 60.49x |
| Priority | 1.914 | 7.967 | 0.032 | 1.947 | 8.084 | 302340.12 | 10.98 | 0.9900 | 104.77x | 506.60x | 55.16x |
| DependencyAware | 2.421 | 8.588 | 0.035 | 2.456 | 8.707 | 285790.69 | 10.50 | 0.9901 | 120.99x | 537.59x | 65.26x |
| SJF | 2.080 | 8.228 | 0.033 | 2.114 | 8.354 | 294011.91 | 10.57 | 0.9905 | 112.05x | 564.81x | 59.01x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 2.02 ± 0.29 | 8.24 ± 1.23 | 0.03 ± 0.00 | 2.05 ± 0.30 | 8.36 ± 1.26 | 292440.56 ± 36045.34 | 10.76 ± 0.90 | 0.99 | 113.95x ± 23.21 | 553.81x | 60.49x ± 11.88 |
| Priority | 1.91 ± 0.21 | 7.97 ± 1.21 | 0.03 ± 0.00 | 1.95 ± 0.21 | 8.08 ± 1.22 | 302340.12 ± 36349.96 | 10.98 ± 0.41 | 0.99 | 104.77x ± 3.51 | 506.60x | 55.16x ± 1.93 |
| DependencyAware | 2.42 ± 1.43 | 8.59 ± 1.97 | 0.03 ± 0.01 | 2.46 ± 1.43 | 8.71 ± 1.98 | 285790.69 ± 45364.40 | 10.50 ± 1.96 | 0.99 | 120.99x ± 50.90 | 537.59x | 65.26x ± 27.95 |
| SJF | 2.08 ± 0.61 | 8.23 ± 1.42 | 0.03 ± 0.00 | 2.11 ± 0.61 | 8.35 ± 1.43 | 294011.91 ± 39342.61 | 10.57 ± 1.18 | 0.99 | 112.05x ± 22.21 | 564.81x | 59.01x ± 11.63 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 107.48x | 112.18x | 126.16x | 121.59x |
| wl 1 | 131.44x | 121.62x | 134.46x | 129.72x |
| wl 2 | 105.60x | 95.07x | 113.33x | 101.67x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 6.455 ms² | 5.830 ms² | 6.929 ms² | 6.542 ms² |
| wl 1 | 4.470 ms² | 4.001 ms² | 4.436 ms² | 4.454 ms² |
| wl 2 | 3.307 ms² | 2.892 ms² | 3.613 ms² | 3.420 ms² |
