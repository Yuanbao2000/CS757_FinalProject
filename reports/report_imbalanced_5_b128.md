# GPU Scheduler Group Report
Group: imbalanced_5 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022334

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.009 | 0.043 | 0.018 | 0.026 | 0.499 | 4947817.50 | 100.00 | 0.9970 | 1.45x | 3.41x | 2.73x |
| fanin_priority | 0.004 | 0.134 | 0.017 | 0.021 | 0.532 | 4669349.00 | 100.00 | 0.9927 | 1.21x | 9.33x | 2.15x |
| DependencyAware | 0.015 | 0.177 | 0.018 | 0.033 | 0.531 | 4682616.00 | 100.00 | 0.9945 | 1.81x | 11.53x | 3.20x |
| SJF | 0.007 | 0.188 | 0.018 | 0.024 | 0.531 | 4879587.50 | 100.00 | 0.9922 | 1.37x | 12.14x | 2.74x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.01 ± 0.00 | 0.04 ± 0.01 | 0.02 ± 0.00 | 0.03 ± 0.01 | 0.50 ± 0.09 | 4947817.50 ± 752962.44 | 100.00 ± 0.00 | 1.00 ± 0.00 | 1.45x ± 0.01 | 3.41x ± 0.23 | 2.73x ± 0.01 |
| fanin_priority | 0.00 ± 0.00 | 0.13 ± 0.03 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.53 ± 0.11 | 4669349.00 ± 750121.88 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.21x ± 0.03 | 9.33x ± 1.81 | 2.15x ± 0.03 |
| DependencyAware | 0.02 ± 0.00 | 0.18 ± 0.02 | 0.02 ± 0.00 | 0.03 ± 0.00 | 0.53 ± 0.11 | 4682616.00 ± 784418.94 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.81x ± 0.04 | 11.53x ± 1.29 | 3.20x ± 0.06 |
| SJF | 0.01 ± 0.00 | 0.19 ± 0.05 | 0.02 ± 0.00 | 0.02 ± 0.01 | 0.53 ± 0.17 | 4879587.50 ± 1136345.50 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.37x ± 0.02 | 12.14x ± 2.30 | 2.74x ± 0.06 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.30x | 1.71x | 1.33x | 1.44x |
| wl 1 | 1.46x | 1.26x | 1.61x | 1.39x |
| wl 2 | 1.47x | 1.13x | 1.97x | 1.34x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.024 ms² | 0.018 ms² | 0.026 ms² | 0.031 ms² |
| wl 1 | 0.015 ms² | 0.012 ms² | 0.017 ms² | 0.014 ms² |
| wl 2 | 0.014 ms² | 0.013 ms² | 0.013 ms² | 0.014 ms² |
