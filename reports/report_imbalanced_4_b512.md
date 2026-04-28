# GPU Scheduler Group Report
Group: imbalanced_4 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025632

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.018 | 0.018 | 0.345 | 5504026.00 | 100.00 | 0.8516 | 1.00x | 1.00x | 1.83x |
| fanin_priority | 0.000 | 0.000 | 0.017 | 0.017 | 0.323 | 5873414.00 | 100.00 | 0.8578 | 1.00x | 1.00x | 1.83x |
| DependencyAware | 0.000 | 0.000 | 0.020 | 0.020 | 0.367 | 5148709.00 | 100.00 | 0.8477 | 1.00x | 1.00x | 1.83x |
| SJF | 0.000 | 0.000 | 0.019 | 0.019 | 0.350 | 5437547.00 | 100.00 | 0.8543 | 1.00x | 1.00x | 1.83x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.35 ± 0.11 | 5504026.00 ± 1425366.00 | 100.00 ± 0.00 | 0.85 ± 0.02 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.83x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.32 ± 0.10 | 5873414.00 ± 1436674.12 | 100.00 ± 0.00 | 0.86 ± 0.02 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.83x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.37 ± 0.11 | 5148709.00 ± 1313819.88 | 100.00 ± 0.00 | 0.85 ± 0.02 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.83x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.35 ± 0.11 | 5437547.00 ± 1377591.25 | 100.00 ± 0.00 | 0.85 ± 0.02 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.83x ± 0.00 |

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
| wl 1 | 0.011 ms² | 0.010 ms² | 0.012 ms² | 0.012 ms² |
| wl 2 | 0.008 ms² | 0.007 ms² | 0.009 ms² | 0.008 ms² |
