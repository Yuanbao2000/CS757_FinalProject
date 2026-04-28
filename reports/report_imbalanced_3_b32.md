# GPU Scheduler Group Report
Group: imbalanced_3 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025434

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.024 | 0.080 | 0.009 | 0.033 | 0.559 | 2961155.50 | 100.00 | 0.9910 | 3.58x | 10.33x | 6.72x |
| fanin_priority | 0.023 | 0.379 | 0.009 | 0.032 | 0.561 | 2933586.25 | 100.00 | 0.9754 | 3.97x | 56.43x | 5.04x |
| DependencyAware | 0.043 | 0.329 | 0.010 | 0.052 | 0.549 | 3010970.50 | 100.00 | 0.9961 | 5.88x | 47.38x | 10.23x |
| SJF | 0.021 | 0.292 | 0.010 | 0.030 | 0.534 | 3125468.50 | 100.00 | 0.9988 | 3.40x | 35.59x | 7.47x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.02 ± 0.01 | 0.08 ± 0.03 | 0.01 ± 0.00 | 0.03 ± 0.01 | 0.56 ± 0.10 | 2961155.50 ± 467320.69 | 100.00 ± 0.00 | 0.99 ± 0.01 | 3.58x ± 0.11 | 10.33x ± 1.82 | 6.72x ± 0.22 |
| fanin_priority | 0.02 ± 0.00 | 0.38 ± 0.04 | 0.01 ± 0.00 | 0.03 ± 0.01 | 0.56 ± 0.09 | 2933586.25 ± 428388.72 | 100.00 ± 0.00 | 0.98 ± 0.02 | 3.97x ± 0.54 | 56.43x ± 7.98 | 5.04x ± 0.55 |
| DependencyAware | 0.04 ± 0.01 | 0.33 ± 0.08 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.55 ± 0.10 | 3010970.50 ± 465128.03 | 100.00 ± 0.00 | 1.00 ± 0.00 | 5.88x ± 0.41 | 47.38x ± 11.39 | 10.23x ± 0.58 |
| SJF | 0.02 ± 0.00 | 0.29 ± 0.09 | 0.01 ± 0.00 | 0.03 ± 0.01 | 0.53 ± 0.12 | 3125468.50 ± 524880.25 | 100.00 ± 0.00 | 1.00 ± 0.00 | 3.40x ± 0.11 | 35.59x ± 6.35 | 7.47x ± 0.31 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 2.65x | 3.81x | 3.03x | 2.72x |
| wl 1 | 4.13x | 7.38x | 8.47x | 4.37x |
| wl 2 | 3.51x | 1.50x | 5.02x | 2.92x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.027 ms² | 0.016 ms² | 0.029 ms² | 0.021 ms² |
| wl 1 | 0.017 ms² | 0.009 ms² | 0.018 ms² | 0.026 ms² |
| wl 2 | 0.015 ms² | 0.008 ms² | 0.022 ms² | 0.019 ms² |
