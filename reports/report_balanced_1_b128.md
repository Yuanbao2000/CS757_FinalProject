# GPU Scheduler Group Report
Group: balanced_1 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022305

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.020 | 0.017 | 0.017 | 0.432 | 3039584.25 | 100.00 | 0.9645 | 1.01x | 2.01x | 2.03x |
| fanin_priority | 0.000 | 0.021 | 0.016 | 0.016 | 0.405 | 3376647.25 | 100.00 | 0.9631 | 1.01x | 2.25x | 2.03x |
| DependencyAware | 0.000 | 0.020 | 0.018 | 0.018 | 0.464 | 2867665.75 | 100.00 | 0.9642 | 1.01x | 2.00x | 2.03x |
| SJF | 0.000 | 0.017 | 0.017 | 0.017 | 0.440 | 3011342.50 | 100.00 | 0.9669 | 1.01x | 1.94x | 2.04x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.43 ± 0.13 | 3039584.25 ± 994025.38 | 100.00 ± 0.00 | 0.96 ± 0.01 | 1.01x ± 0.00 | 2.01x ± 0.26 | 2.03x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.40 ± 0.15 | 3376647.25 ± 1194759.38 | 100.00 ± 0.00 | 0.96 ± 0.01 | 1.01x ± 0.00 | 2.25x ± 0.50 | 2.03x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.46 ± 0.15 | 2867665.75 ± 994489.56 | 100.00 ± 0.00 | 0.96 ± 0.01 | 1.01x ± 0.00 | 2.00x ± 0.28 | 2.03x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.44 ± 0.14 | 3011342.50 ± 1009510.31 | 100.00 ± 0.00 | 0.97 ± 0.01 | 1.01x ± 0.00 | 1.94x ± 0.23 | 2.04x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.01x | 1.01x | 1.01x | 1.01x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.015 ms² | 0.013 ms² | 0.018 ms² | 0.016 ms² |
| wl 1 | 0.011 ms² | 0.010 ms² | 0.013 ms² | 0.012 ms² |
| wl 2 | 0.010 ms² | 0.010 ms² | 0.012 ms² | 0.011 ms² |
