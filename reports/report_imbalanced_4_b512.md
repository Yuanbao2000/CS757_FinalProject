# GPU Scheduler Group Report
Group: imbalanced_4 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022414

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.015 | 0.015 | 0.291 | 6191773.50 | 100.00 | 0.8445 | 1.00x | 1.00x | 1.83x |
| fanin_priority | 0.000 | 0.000 | 0.015 | 0.015 | 0.278 | 6366299.00 | 100.00 | 0.8518 | 1.00x | 1.00x | 1.83x |
| DependencyAware | 0.000 | 0.000 | 0.017 | 0.017 | 0.325 | 5590665.50 | 100.00 | 0.8413 | 1.00x | 1.00x | 1.83x |
| SJF | 0.000 | 0.000 | 0.015 | 0.015 | 0.274 | 6449389.00 | 100.00 | 0.8628 | 1.00x | 1.00x | 1.83x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.29 ± 0.05 | 6191773.50 ± 989541.62 | 100.00 ± 0.00 | 0.84 ± 0.02 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.83x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.28 ± 0.03 | 6366299.00 ± 638021.56 | 100.00 ± 0.00 | 0.85 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.83x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.32 ± 0.06 | 5590665.50 ± 1024194.75 | 100.00 ± 0.00 | 0.84 ± 0.03 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.83x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.27 ± 0.02 | 6449389.00 ± 573701.75 | 100.00 ± 0.00 | 0.86 ± 0.02 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.83x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.00x | 1.00x | 1.00x | 1.00x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.001 ms² | 0.001 ms² | 0.001 ms² | 0.001 ms² |
| wl 1 | 0.008 ms² | 0.007 ms² | 0.010 ms² | 0.007 ms² |
| wl 2 | 0.006 ms² | 0.005 ms² | 0.007 ms² | 0.005 ms² |
