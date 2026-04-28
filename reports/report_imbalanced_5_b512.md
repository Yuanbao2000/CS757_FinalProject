# GPU Scheduler Group Report
Group: imbalanced_5 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025646

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.021 | 0.021 | 0.460 | 5363990.50 | 100.00 | 0.9944 | 1.00x | 1.00x | 1.93x |
| fanin_priority | 0.000 | 0.000 | 0.020 | 0.020 | 0.447 | 5469612.00 | 100.00 | 0.9934 | 1.00x | 1.00x | 1.93x |
| DependencyAware | 0.000 | 0.000 | 0.021 | 0.021 | 0.473 | 5314576.50 | 100.00 | 0.9926 | 1.00x | 1.00x | 1.93x |
| SJF | 0.000 | 0.000 | 0.021 | 0.021 | 0.477 | 5396504.00 | 100.00 | 0.9945 | 1.00x | 1.00x | 1.93x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.46 ± 0.09 | 5363990.50 ± 824970.38 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.93x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.45 ± 0.06 | 5469612.00 ± 711885.62 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.93x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.47 ± 0.11 | 5314576.50 ± 1027844.31 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.93x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.48 ± 0.15 | 5396504.00 ± 1197955.75 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.93x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.00x | 1.00x | 1.00x | 1.00x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.018 ms² | 0.017 ms² | 0.019 ms² | 0.020 ms² |
| wl 1 | 0.012 ms² | 0.011 ms² | 0.013 ms² | 0.013 ms² |
| wl 2 | 0.010 ms² | 0.009 ms² | 0.010 ms² | 0.011 ms² |
