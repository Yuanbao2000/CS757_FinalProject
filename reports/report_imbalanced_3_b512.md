# GPU Scheduler Group Report
Group: imbalanced_3 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025625

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.015 | 0.015 | 0.333 | 4904590.50 | 100.00 | 0.9822 | 1.00x | 1.00x | 1.98x |
| fanin_priority | 0.000 | 0.000 | 0.015 | 0.015 | 0.346 | 4725717.50 | 100.00 | 0.9756 | 1.00x | 1.00x | 1.98x |
| DependencyAware | 0.000 | 0.000 | 0.016 | 0.016 | 0.335 | 4835343.00 | 100.00 | 0.9762 | 1.00x | 1.00x | 1.98x |
| SJF | 0.000 | 0.000 | 0.015 | 0.015 | 0.332 | 4882515.00 | 100.00 | 0.9783 | 1.00x | 1.00x | 1.98x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.33 ± 0.04 | 4904590.50 ± 596714.56 | 100.00 ± 0.00 | 0.98 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.98x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.35 ± 0.05 | 4725717.50 ± 581265.62 | 100.00 ± 0.00 | 0.98 ± 0.02 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.98x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.33 ± 0.03 | 4835343.00 ± 397417.94 | 100.00 ± 0.00 | 0.98 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.98x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.33 ± 0.03 | 4882515.00 ± 440786.31 | 100.00 ± 0.00 | 0.98 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.98x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.00x | 1.00x | 1.00x | 1.00x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.008 ms² | 0.007 ms² | 0.007 ms² | 0.007 ms² |
| wl 1 | 0.003 ms² | 0.003 ms² | 0.003 ms² | 0.003 ms² |
| wl 2 | 0.006 ms² | 0.006 ms² | 0.006 ms² | 0.006 ms² |
