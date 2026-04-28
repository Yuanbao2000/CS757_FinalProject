# GPU Scheduler Group Report
Group: balanced_0 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025613

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.013 | 0.013 | 0.230 | 5291831.00 | 100.00 | 0.9911 | 1.00x | 1.00x | 1.85x |
| fanin_priority | 0.000 | 0.000 | 0.012 | 0.012 | 0.218 | 5311803.00 | 100.00 | 0.9926 | 1.00x | 1.00x | 1.85x |
| DependencyAware | 0.000 | 0.000 | 0.013 | 0.013 | 0.232 | 5040541.50 | 100.00 | 0.9927 | 1.00x | 1.00x | 1.85x |
| SJF | 0.000 | 0.000 | 0.012 | 0.012 | 0.246 | 4969493.00 | 100.00 | 0.9877 | 1.00x | 1.00x | 1.85x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.07 | 5291831.00 ± 943642.62 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.85x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.22 ± 0.02 | 5311803.00 ± 430841.34 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.85x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.03 | 5040541.50 ± 605632.19 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.85x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.25 ± 0.07 | 4969493.00 ± 1035403.88 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.85x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.00x | 1.00x | 1.00x | 1.00x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.004 ms² | 0.004 ms² | 0.004 ms² | 0.004 ms² |
| wl 1 | 0.004 ms² | 0.004 ms² | 0.004 ms² | 0.005 ms² |
| wl 2 | 0.002 ms² | 0.002 ms² | 0.002 ms² | 0.001 ms² |
