# GPU Scheduler Group Report
Group: imbalanced_3 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022408

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.018 | 0.018 | 0.418 | 4118031.50 | 100.00 | 0.9751 | 1.00x | 1.00x | 1.98x |
| fanin_priority | 0.000 | 0.000 | 0.017 | 0.017 | 0.403 | 4297060.00 | 100.00 | 0.9720 | 1.00x | 1.00x | 1.98x |
| DependencyAware | 0.000 | 0.000 | 0.018 | 0.018 | 0.411 | 4305613.50 | 100.00 | 0.9734 | 1.00x | 1.00x | 1.98x |
| SJF | 0.000 | 0.000 | 0.019 | 0.019 | 0.418 | 4283880.50 | 100.00 | 0.9799 | 1.00x | 1.00x | 1.98x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.42 ± 0.12 | 4118031.50 ± 973464.12 | 100.00 ± 0.00 | 0.98 ± 0.02 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.98x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.40 ± 0.12 | 4297060.00 ± 1069730.00 | 100.00 ± 0.00 | 0.97 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.98x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.41 ± 0.14 | 4305613.50 ± 1190666.25 | 100.00 ± 0.00 | 0.97 ± 0.02 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.98x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.42 ± 0.15 | 4283880.50 ± 1278606.50 | 100.00 ± 0.00 | 0.98 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.98x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.00x | 1.00x | 1.00x | 1.00x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.011 ms² | 0.010 ms² | 0.010 ms² | 0.012 ms² |
| wl 1 | 0.005 ms² | 0.004 ms² | 0.004 ms² | 0.005 ms² |
| wl 2 | 0.009 ms² | 0.009 ms² | 0.009 ms² | 0.010 ms² |
