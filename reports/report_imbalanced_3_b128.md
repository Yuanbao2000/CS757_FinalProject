# GPU Scheduler Group Report
Group: imbalanced_3 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022312

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.002 | 0.020 | 0.014 | 0.016 | 0.351 | 4634576.50 | 100.00 | 0.9808 | 1.11x | 2.47x | 2.15x |
| fanin_priority | 0.003 | 0.052 | 0.014 | 0.017 | 0.350 | 4628820.00 | 100.00 | 0.9884 | 1.17x | 4.35x | 2.17x |
| DependencyAware | 0.004 | 0.037 | 0.015 | 0.019 | 0.357 | 4541579.00 | 100.00 | 0.9860 | 1.25x | 3.63x | 2.36x |
| SJF | 0.002 | 0.050 | 0.013 | 0.016 | 0.356 | 4692613.00 | 100.00 | 0.9781 | 1.16x | 4.67x | 2.28x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.35 ± 0.04 | 4634576.50 ± 502684.78 | 100.00 ± 0.00 | 0.98 ± 0.01 | 1.11x ± 0.01 | 2.47x ± 0.24 | 2.15x ± 0.02 |
| fanin_priority | 0.00 ± 0.00 | 0.05 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.35 ± 0.03 | 4628820.00 ± 426760.25 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.17x ± 0.03 | 4.35x ± 0.88 | 2.17x ± 0.03 |
| DependencyAware | 0.00 ± 0.00 | 0.04 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.36 ± 0.03 | 4541579.00 ± 426853.22 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.25x ± 0.02 | 3.63x ± 0.46 | 2.36x ± 0.02 |
| SJF | 0.00 ± 0.00 | 0.05 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.36 ± 0.08 | 4692613.00 ± 822611.75 | 100.00 ± 0.00 | 0.98 ± 0.02 | 1.16x ± 0.01 | 4.67x ± 0.77 | 2.28x ± 0.03 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.08x | 1.22x | 1.10x | 1.12x |
| wl 1 | 1.15x | 1.30x | 1.50x | 1.27x |
| wl 2 | 1.09x | 1.04x | 1.12x | 1.09x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.008 ms² | 0.008 ms² | 0.010 ms² | 0.007 ms² |
| wl 1 | 0.003 ms² | 0.005 ms² | 0.004 ms² | 0.003 ms² |
| wl 2 | 0.006 ms² | 0.007 ms² | 0.007 ms² | 0.006 ms² |
