# GPU Scheduler Report
Group: balanced_0 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_024052

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.608 | 6.307 | 0.034 | 1.642 | 6.423 | 180765.97 | 13.98 | 0.9807 | 97.62x | 464.45x | 54.93x |
| Priority | 1.520 | 6.460 | 0.034 | 1.554 | 6.564 | 175924.41 | 13.82 | 0.9820 | 83.24x | 420.57x | 46.27x |
| DependencyAware | 1.648 | 6.362 | 0.034 | 1.681 | 6.471 | 178039.89 | 12.77 | 0.9879 | 88.41x | 413.09x | 50.74x |
| SJF | 1.561 | 6.562 | 0.034 | 1.595 | 6.665 | 173825.02 | 13.39 | 0.9839 | 85.82x | 461.56x | 47.86x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.61 ± 0.40 | 6.31 ± 0.67 | 0.03 ± 0.00 | 1.64 ± 0.40 | 6.42 ± 0.67 | 180765.97 ± 15142.51 | 13.98 ± 1.74 | 0.98 | 97.62x ± 53.43 | 464.45x | 54.93x ± 28.82 |
| Priority | 1.52 ± 0.04 | 6.46 ± 0.37 | 0.03 ± 0.00 | 1.55 ± 0.04 | 6.56 ± 0.38 | 175924.41 ± 9686.43 | 13.82 ± 0.22 | 0.98 | 83.24x ± 2.86 | 420.57x | 46.27x ± 1.53 |
| DependencyAware | 1.65 ± 0.07 | 6.36 ± 0.19 | 0.03 ± 0.00 | 1.68 ± 0.07 | 6.47 ± 0.20 | 178039.89 ± 5232.36 | 12.77 ± 0.17 | 0.99 | 88.41x ± 1.97 | 413.09x | 50.74x ± 1.07 |
| SJF | 1.56 ± 0.12 | 6.56 ± 0.59 | 0.03 ± 0.00 | 1.60 ± 0.12 | 6.67 ± 0.59 | 173825.02 ± 12759.99 | 13.39 ± 0.33 | 0.98 | 85.82x ± 3.41 | 461.56x | 47.86x ± 1.87 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 98.26x | 97.34x | 100.62x | 104.33x |
| wl 1 | 159.28x | 134.31x | 132.05x | 141.57x |
| wl 2 | 66.67x | 50.21x | 60.09x | 48.08x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 3.085 ms² | 2.939 ms² | 2.985 ms² | 3.023 ms² |
| wl 1 | 3.393 ms² | 3.374 ms² | 3.376 ms² | 3.601 ms² |
| wl 2 | 1.176 ms² | 0.958 ms² | 1.032 ms² | 0.965 ms² |
