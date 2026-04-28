# GPU Scheduler Report
Group: imbalanced_2 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_024216

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.471 | 5.267 | 0.035 | 1.505 | 5.373 | 136642.19 | 16.55 | 0.9603 | 86.34x | 395.63x | 48.94x |
| Priority | 1.472 | 5.320 | 0.035 | 1.506 | 5.424 | 135438.00 | 16.61 | 0.9622 | 79.75x | 385.70x | 44.52x |
| DependencyAware | 1.410 | 5.131 | 0.035 | 1.444 | 5.238 | 140215.59 | 17.15 | 0.9560 | 74.94x | 333.35x | 43.18x |
| SJF | 1.422 | 5.201 | 0.034 | 1.456 | 5.310 | 138104.06 | 16.81 | 0.9601 | 77.87x | 365.39x | 43.53x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.47 ± 0.14 | 5.27 ± 0.22 | 0.03 ± 0.00 | 1.51 ± 0.14 | 5.37 ± 0.22 | 136642.19 ± 5486.88 | 16.55 ± 1.27 | 0.96 | 86.34x ± 27.72 | 395.63x | 48.94x ± 15.04 |
| Priority | 1.47 ± 0.11 | 5.32 ± 0.26 | 0.03 ± 0.00 | 1.51 ± 0.11 | 5.42 ± 0.26 | 135438.00 ± 6125.52 | 16.61 ± 0.45 | 0.96 | 79.75x ± 4.91 | 385.70x | 44.52x ± 2.70 |
| DependencyAware | 1.41 ± 0.07 | 5.13 ± 0.24 | 0.03 ± 0.00 | 1.44 ± 0.08 | 5.24 ± 0.24 | 140215.59 ± 6050.62 | 17.15 ± 0.29 | 0.96 | 74.94x ± 2.79 | 333.35x | 43.18x ± 1.57 |
| SJF | 1.42 ± 0.04 | 5.20 ± 0.13 | 0.03 ± 0.00 | 1.46 ± 0.04 | 5.31 ± 0.12 | 138104.06 ± 3123.22 | 16.81 ± 0.35 | 0.96 | 77.87x ± 1.57 | 365.39x | 43.53x ± 0.89 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 80.85x | 85.68x | 73.03x | 83.03x |
| wl 1 | 99.65x | 88.99x | 87.67x | 88.07x |
| wl 2 | 78.70x | 68.83x | 65.71x | 66.63x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 2.936 ms² | 3.016 ms² | 2.754 ms² | 2.840 ms² |
| wl 1 | 1.676 ms² | 1.733 ms² | 1.545 ms² | 1.616 ms² |
| wl 2 | 1.846 ms² | 1.918 ms² | 1.715 ms² | 1.788 ms² |
