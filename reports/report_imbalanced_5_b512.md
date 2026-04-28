# GPU Scheduler Group Report
Group: imbalanced_5 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022428

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.020 | 0.020 | 0.425 | 5737779.00 | 100.00 | 0.9950 | 1.00x | 1.00x | 1.93x |
| fanin_priority | 0.000 | 0.000 | 0.021 | 0.021 | 0.454 | 5459006.00 | 100.00 | 0.9950 | 1.00x | 1.00x | 1.93x |
| DependencyAware | 0.000 | 0.000 | 0.023 | 0.023 | 0.494 | 5232867.00 | 100.00 | 0.9937 | 1.00x | 1.00x | 1.93x |
| SJF | 0.000 | 0.000 | 0.020 | 0.020 | 0.436 | 5630517.00 | 100.00 | 0.9929 | 1.00x | 1.00x | 1.93x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.42 ± 0.06 | 5737779.00 ± 650485.88 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.93x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.45 ± 0.09 | 5459006.00 ± 892279.62 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.93x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.49 ± 0.17 | 5232867.00 ± 1116459.50 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.93x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.44 ± 0.07 | 5630517.00 ± 771783.12 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.93x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.00x | 1.00x | 1.00x | 1.00x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.016 ms² | 0.019 ms² | 0.022 ms² | 0.016 ms² |
| wl 1 | 0.011 ms² | 0.012 ms² | 0.015 ms² | 0.011 ms² |
| wl 2 | 0.009 ms² | 0.010 ms² | 0.013 ms² | 0.009 ms² |
