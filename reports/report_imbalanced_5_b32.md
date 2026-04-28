# GPU Scheduler Group Report
Group: imbalanced_5 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022239

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.052 | 0.133 | 0.013 | 0.065 | 1.071 | 2391608.50 | 100.00 | 0.9987 | 5.49x | 15.14x | 10.12x |
| fanin_priority | 0.025 | 0.795 | 0.014 | 0.039 | 1.140 | 2281502.50 | 100.00 | 0.9975 | 3.01x | 74.62x | 4.05x |
| DependencyAware | 0.096 | 0.895 | 0.015 | 0.110 | 1.128 | 2293085.25 | 100.00 | 0.9998 | 8.45x | 81.50x | 14.33x |
| SJF | 0.045 | 0.787 | 0.014 | 0.059 | 1.114 | 2336574.00 | 100.00 | 1.0000 | 4.62x | 80.87x | 10.66x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.05 ± 0.01 | 0.13 ± 0.03 | 0.01 ± 0.00 | 0.06 ± 0.02 | 1.07 ± 0.30 | 2391608.50 ± 553702.94 | 100.00 ± 0.00 | 1.00 ± 0.00 | 5.49x ± 0.32 | 15.14x ± 3.53 | 10.12x ± 0.44 |
| fanin_priority | 0.03 ± 0.01 | 0.79 ± 0.23 | 0.01 ± 0.00 | 0.04 ± 0.01 | 1.14 ± 0.37 | 2281502.50 ± 564861.88 | 100.00 ± 0.00 | 1.00 ± 0.00 | 3.01x ± 0.15 | 74.62x ± 15.12 | 4.05x ± 0.16 |
| DependencyAware | 0.10 ± 0.03 | 0.89 ± 0.25 | 0.01 ± 0.00 | 0.11 ± 0.03 | 1.13 ± 0.32 | 2293085.25 ± 595124.56 | 100.00 ± 0.00 | 1.00 ± 0.00 | 8.45x ± 0.84 | 81.50x ± 20.47 | 14.33x ± 1.31 |
| SJF | 0.05 ± 0.01 | 0.79 ± 0.25 | 0.01 ± 0.00 | 0.06 ± 0.02 | 1.11 ± 0.34 | 2336574.00 ± 605174.31 | 100.00 ± 0.00 | 1.00 ± 0.00 | 4.62x ± 0.30 | 80.87x ± 17.69 | 10.66x ± 0.92 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 3.90x | 5.68x | 4.32x | 3.61x |
| wl 1 | 5.25x | 3.07x | 8.49x | 4.67x |
| wl 2 | 5.80x | 2.65x | 8.93x | 4.72x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.147 ms² | 0.099 ms² | 0.167 ms² | 0.169 ms² |
| wl 1 | 0.086 ms² | 0.056 ms² | 0.109 ms² | 0.091 ms² |
| wl 2 | 0.083 ms² | 0.094 ms² | 0.100 ms² | 0.097 ms² |
