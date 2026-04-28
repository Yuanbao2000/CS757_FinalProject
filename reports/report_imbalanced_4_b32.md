# GPU Scheduler Group Report
Group: imbalanced_4 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022223

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.025 | 0.076 | 0.009 | 0.034 | 0.532 | 3335759.00 | 100.00 | 0.8913 | 3.90x | 10.20x | 6.80x |
| fanin_priority | 0.016 | 0.494 | 0.010 | 0.026 | 0.594 | 3034244.50 | 100.00 | 0.9850 | 2.75x | 60.94x | 3.60x |
| DependencyAware | 0.046 | 0.391 | 0.010 | 0.056 | 0.593 | 3034142.75 | 100.00 | 0.9988 | 5.83x | 54.50x | 8.78x |
| SJF | 0.023 | 0.404 | 0.010 | 0.033 | 0.601 | 3005901.50 | 100.00 | 0.8893 | 3.59x | 54.55x | 7.46x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.02 ± 0.00 | 0.08 ± 0.02 | 0.01 ± 0.00 | 0.03 ± 0.00 | 0.53 ± 0.06 | 3335759.00 ± 368986.97 | 100.00 ± 0.00 | 0.89 ± 0.01 | 3.90x ± 0.08 | 10.20x ± 1.43 | 6.80x ± 0.11 |
| fanin_priority | 0.02 ± 0.00 | 0.49 ± 0.07 | 0.01 ± 0.00 | 0.03 ± 0.00 | 0.59 ± 0.11 | 3034244.50 ± 474871.84 | 100.00 ± 0.00 | 0.99 ± 0.01 | 2.75x ± 0.11 | 60.94x ± 11.65 | 3.60x ± 0.11 |
| DependencyAware | 0.05 ± 0.01 | 0.39 ± 0.08 | 0.01 ± 0.00 | 0.06 ± 0.01 | 0.59 ± 0.10 | 3034142.75 ± 472772.31 | 100.00 ± 0.00 | 1.00 ± 0.00 | 5.83x ± 0.35 | 54.50x ± 10.79 | 8.78x ± 0.34 |
| SJF | 0.02 ± 0.00 | 0.40 ± 0.06 | 0.01 ± 0.00 | 0.03 ± 0.00 | 0.60 ± 0.11 | 3005901.50 ± 495235.81 | 100.00 ± 0.00 | 0.89 ± 0.02 | 3.59x ± 0.20 | 54.55x ± 10.56 | 7.46x ± 0.46 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 3.99x | 8.34x | 9.72x | 4.44x |
| wl 1 | 2.81x | 3.22x | 3.42x | 3.20x |
| wl 2 | 4.11x | 2.61x | 6.26x | 3.65x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.006 ms² | 0.024 ms² | 0.032 ms² | 0.006 ms² |
| wl 1 | 0.029 ms² | 0.021 ms² | 0.038 ms² | 0.024 ms² |
| wl 2 | 0.021 ms² | 0.026 ms² | 0.024 ms² | 0.027 ms² |
