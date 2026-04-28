# GPU Scheduler Group Report
Group: imbalanced_3 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022216

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.041 | 0.295 | 0.016 | 0.057 | 0.932 | 2342618.00 | 100.00 | 0.9887 | 4.02x | 19.69x | 7.54x |
| fanin_priority | 0.031 | 0.540 | 0.012 | 0.043 | 0.717 | 2526591.50 | 100.00 | 0.9886 | 3.65x | 61.24x | 4.72x |
| DependencyAware | 0.053 | 0.399 | 0.013 | 0.066 | 0.707 | 2514769.75 | 100.00 | 0.9951 | 5.56x | 40.02x | 9.84x |
| SJF | 0.027 | 0.380 | 0.013 | 0.040 | 0.706 | 2512928.75 | 100.00 | 0.9988 | 3.41x | 38.30x | 7.59x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.04 ± 0.04 | 0.29 ± 0.62 | 0.02 ± 0.01 | 0.06 ± 0.06 | 0.93 ± 0.73 | 2342618.00 ± 912954.75 | 100.00 ± 0.00 | 0.99 ± 0.01 | 4.02x ± 1.65 | 19.69x ± 28.94 | 7.54x ± 3.07 |
| fanin_priority | 0.03 ± 0.01 | 0.54 ± 0.22 | 0.01 ± 0.00 | 0.04 ± 0.02 | 0.72 ± 0.28 | 2526591.50 ± 743575.75 | 100.00 ± 0.00 | 0.99 ± 0.00 | 3.65x ± 0.26 | 61.24x ± 10.45 | 4.72x ± 0.27 |
| DependencyAware | 0.05 ± 0.02 | 0.40 ± 0.15 | 0.01 ± 0.00 | 0.07 ± 0.02 | 0.71 ± 0.25 | 2514769.75 ± 707918.75 | 100.00 ± 0.00 | 1.00 ± 0.00 | 5.56x ± 0.27 | 40.02x ± 5.39 | 9.84x ± 0.35 |
| SJF | 0.03 ± 0.01 | 0.38 ± 0.13 | 0.01 ± 0.00 | 0.04 ± 0.01 | 0.71 ± 0.26 | 2512928.75 ± 676049.81 | 100.00 ± 0.00 | 1.00 ± 0.00 | 3.41x ± 0.30 | 38.30x ± 7.42 | 7.59x ± 0.76 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 3.18x | 3.58x | 2.92x | 2.70x |
| wl 1 | 5.01x | 6.69x | 7.91x | 4.27x |
| wl 2 | 3.59x | 1.44x | 4.80x | 3.04x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.118 ms² | 0.030 ms² | 0.048 ms² | 0.037 ms² |
| wl 1 | 0.142 ms² | 0.023 ms² | 0.030 ms² | 0.046 ms² |
| wl 2 | 0.033 ms² | 0.022 ms² | 0.036 ms² | 0.034 ms² |
