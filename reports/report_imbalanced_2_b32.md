# GPU Scheduler Group Report
Group: imbalanced_2 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022209

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.007 | 0.037 | 0.009 | 0.015 | 0.257 | 2978750.50 | 100.00 | 0.9896 | 1.78x | 5.27x | 2.99x |
| fanin_priority | 0.006 | 0.098 | 0.008 | 0.015 | 0.255 | 2938526.25 | 100.00 | 0.9932 | 1.74x | 14.72x | 2.60x |
| DependencyAware | 0.007 | 0.036 | 0.008 | 0.015 | 0.228 | 3291563.75 | 100.00 | 0.9883 | 1.94x | 6.69x | 3.23x |
| SJF | 0.006 | 0.062 | 0.008 | 0.014 | 0.229 | 3250397.50 | 100.00 | 0.9947 | 1.79x | 9.26x | 3.02x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.01 ± 0.00 | 0.04 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.26 ± 0.06 | 2978750.50 ± 507644.22 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.78x ± 0.05 | 5.27x ± 0.70 | 2.99x ± 0.08 |
| fanin_priority | 0.01 ± 0.00 | 0.10 ± 0.03 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.26 ± 0.04 | 2938526.25 ± 427734.78 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.74x ± 0.04 | 14.72x ± 3.68 | 2.60x ± 0.04 |
| DependencyAware | 0.01 ± 0.00 | 0.04 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.04 | 3291563.75 ± 439571.59 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.94x ± 0.05 | 6.69x ± 0.51 | 3.23x ± 0.07 |
| SJF | 0.01 ± 0.00 | 0.06 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.03 | 3250397.50 ± 379141.50 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.79x ± 0.08 | 9.26x ± 1.42 | 3.02x ± 0.14 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.47x | 2.38x | 1.78x | 1.72x |
| wl 1 | 1.85x | 1.88x | 2.00x | 1.91x |
| wl 2 | 1.92x | 1.25x | 1.98x | 1.74x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.007 ms² | 0.005 ms² | 0.004 ms² | 0.005 ms² |
| wl 1 | 0.005 ms² | 0.004 ms² | 0.003 ms² | 0.003 ms² |
| wl 2 | 0.004 ms² | 0.003 ms² | 0.003 ms² | 0.003 ms² |
