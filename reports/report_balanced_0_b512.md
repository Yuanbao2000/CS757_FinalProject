# GPU Scheduler Group Report
Group: balanced_0 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022356

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.014 | 0.014 | 0.255 | 5008848.50 | 100.00 | 0.9919 | 1.00x | 1.00x | 1.85x |
| fanin_priority | 0.000 | 0.000 | 0.015 | 0.015 | 0.288 | 4659881.00 | 100.00 | 0.9887 | 1.00x | 1.00x | 1.85x |
| DependencyAware | 0.000 | 0.000 | 0.016 | 0.016 | 0.293 | 4444889.00 | 100.00 | 0.9878 | 1.00x | 1.00x | 1.85x |
| SJF | 0.000 | 0.000 | 0.015 | 0.015 | 0.268 | 4564691.50 | 100.00 | 0.9921 | 1.00x | 1.00x | 1.85x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.25 ± 0.10 | 5008848.50 ± 1261158.50 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.85x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.29 ± 0.13 | 4659881.00 ± 1519237.62 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.85x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.29 ± 0.12 | 4444889.00 ± 1293495.62 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.85x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.27 ± 0.09 | 4564691.50 ± 867349.56 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.85x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.00x | 1.00x | 1.00x | 1.00x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.006 ms² | 0.007 ms² | 0.007 ms² | 0.005 ms² |
| wl 1 | 0.006 ms² | 0.008 ms² | 0.007 ms² | 0.006 ms² |
| wl 2 | 0.003 ms² | 0.003 ms² | 0.003 ms² | 0.002 ms² |
