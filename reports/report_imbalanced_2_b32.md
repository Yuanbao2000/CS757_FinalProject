# GPU Scheduler Group Report
Group: imbalanced_2 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025428

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.007 | 0.040 | 0.008 | 0.015 | 0.248 | 3056004.50 | 100.00 | 0.9890 | 1.83x | 6.33x | 3.02x |
| fanin_priority | 0.006 | 0.091 | 0.008 | 0.014 | 0.265 | 2915080.25 | 100.00 | 0.9916 | 1.72x | 13.70x | 2.58x |
| DependencyAware | 0.009 | 0.048 | 0.009 | 0.018 | 0.263 | 2866271.50 | 100.00 | 0.9914 | 1.90x | 6.41x | 3.19x |
| SJF | 0.006 | 0.057 | 0.008 | 0.014 | 0.230 | 3245946.00 | 100.00 | 0.9926 | 1.76x | 8.58x | 2.96x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.01 ± 0.00 | 0.04 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.25 ± 0.05 | 3056004.50 ± 499324.09 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.83x ± 0.08 | 6.33x ± 1.59 | 3.02x ± 0.10 |
| fanin_priority | 0.01 ± 0.00 | 0.09 ± 0.02 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.27 ± 0.08 | 2915080.25 ± 543727.56 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.72x ± 0.13 | 13.70x ± 3.00 | 2.58x ± 0.13 |
| DependencyAware | 0.01 ± 0.00 | 0.05 ± 0.02 | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.26 ± 0.05 | 2866271.50 ± 456136.72 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.90x ± 0.06 | 6.41x ± 0.64 | 3.19x ± 0.08 |
| SJF | 0.01 ± 0.00 | 0.06 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.03 | 3245946.00 ± 429592.69 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.76x ± 0.03 | 8.58x ± 1.04 | 2.96x ± 0.06 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.58x | 2.31x | 1.78x | 1.71x |
| wl 1 | 1.84x | 1.87x | 1.96x | 1.86x |
| wl 2 | 1.97x | 1.27x | 1.93x | 1.71x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.006 ms² | 0.006 ms² | 0.006 ms² | 0.005 ms² |
| wl 1 | 0.004 ms² | 0.004 ms² | 0.005 ms² | 0.003 ms² |
| wl 2 | 0.003 ms² | 0.003 ms² | 0.005 ms² | 0.003 ms² |
