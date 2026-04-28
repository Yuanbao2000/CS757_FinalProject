# GPU Scheduler Group Report
Group: imbalanced_2 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025523

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.017 | 0.011 | 0.012 | 0.218 | 3650085.50 | 100.00 | 0.9846 | 1.01x | 2.19x | 1.85x |
| fanin_priority | 0.000 | 0.013 | 0.010 | 0.010 | 0.197 | 3912420.00 | 100.00 | 0.9838 | 1.01x | 1.90x | 1.85x |
| DependencyAware | 0.000 | 0.014 | 0.010 | 0.010 | 0.186 | 3960857.50 | 100.00 | 0.9807 | 1.01x | 2.03x | 1.85x |
| SJF | 0.000 | 0.013 | 0.010 | 0.010 | 0.192 | 3872088.75 | 100.00 | 0.9807 | 1.01x | 1.91x | 1.85x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.22 ± 0.08 | 3650085.50 ± 861882.94 | 100.00 ± 0.00 | 0.98 ± 0.01 | 1.01x ± 0.01 | 2.19x ± 0.97 | 1.85x ± 0.01 |
| fanin_priority | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.20 ± 0.05 | 3912420.00 ± 727686.88 | 100.00 ± 0.00 | 0.98 ± 0.00 | 1.01x ± 0.00 | 1.90x ± 0.16 | 1.85x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.19 ± 0.01 | 3960857.50 ± 211596.81 | 100.00 ± 0.00 | 0.98 ± 0.00 | 1.01x ± 0.00 | 2.03x ± 0.27 | 1.85x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.19 ± 0.02 | 3872088.75 ± 394588.97 | 100.00 ± 0.00 | 0.98 ± 0.00 | 1.01x ± 0.00 | 1.91x ± 0.12 | 1.85x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.05x | 1.00x | 1.05x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.03x | 1.00x | 1.03x | 1.00x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.005 ms² | 0.004 ms² | 0.003 ms² | 0.004 ms² |
| wl 1 | 0.004 ms² | 0.003 ms² | 0.002 ms² | 0.002 ms² |
| wl 2 | 0.004 ms² | 0.003 ms² | 0.002 ms² | 0.002 ms² |
