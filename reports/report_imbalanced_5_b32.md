# GPU Scheduler Group Report
Group: imbalanced_5 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025457

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.045 | 0.121 | 0.011 | 0.056 | 0.902 | 2746191.25 | 100.00 | 0.9986 | 5.49x | 16.21x | 10.14x |
| fanin_priority | 0.020 | 0.630 | 0.011 | 0.031 | 0.928 | 2681066.00 | 100.00 | 0.9969 | 3.02x | 72.22x | 4.07x |
| DependencyAware | 0.085 | 0.799 | 0.013 | 0.098 | 1.020 | 2553799.50 | 100.00 | 0.9997 | 8.41x | 83.64x | 14.14x |
| SJF | 0.039 | 0.691 | 0.012 | 0.051 | 0.983 | 2683668.50 | 100.00 | 1.0000 | 4.53x | 73.26x | 10.35x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.04 ± 0.01 | 0.12 ± 0.02 | 0.01 ± 0.00 | 0.06 ± 0.01 | 0.90 ± 0.19 | 2746191.25 ± 411024.03 | 100.00 ± 0.00 | 1.00 ± 0.00 | 5.49x ± 0.26 | 16.21x ± 3.60 | 10.14x ± 0.38 |
| fanin_priority | 0.02 ± 0.00 | 0.63 ± 0.14 | 0.01 ± 0.00 | 0.03 ± 0.01 | 0.93 ± 0.21 | 2681066.00 ± 427715.72 | 100.00 ± 0.00 | 1.00 ± 0.00 | 3.02x ± 0.13 | 72.22x ± 16.98 | 4.07x ± 0.14 |
| DependencyAware | 0.08 ± 0.03 | 0.80 ± 0.30 | 0.01 ± 0.00 | 0.10 ± 0.03 | 1.02 ± 0.36 | 2553799.50 ± 586204.12 | 100.00 ± 0.00 | 1.00 ± 0.00 | 8.41x ± 0.52 | 83.64x ± 10.62 | 14.14x ± 1.05 |
| SJF | 0.04 ± 0.01 | 0.69 ± 0.25 | 0.01 ± 0.00 | 0.05 ± 0.02 | 0.98 ± 0.37 | 2683668.50 ± 664396.75 | 100.00 ± 0.00 | 1.00 ± 0.00 | 4.53x ± 0.20 | 73.26x ± 11.64 | 10.35x ± 0.50 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 4.06x | 5.66x | 4.28x | 3.79x |
| wl 1 | 5.29x | 3.03x | 8.38x | 4.66x |
| wl 2 | 5.78x | 2.70x | 8.92x | 4.56x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.101 ms² | 0.064 ms² | 0.143 ms² | 0.134 ms² |
| wl 1 | 0.058 ms² | 0.038 ms² | 0.095 ms² | 0.072 ms² |
| wl 2 | 0.057 ms² | 0.058 ms² | 0.088 ms² | 0.076 ms² |
