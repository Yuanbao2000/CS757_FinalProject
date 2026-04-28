# GPU Scheduler Group Report
Group: imbalanced_3 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025530

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.002 | 0.021 | 0.016 | 0.018 | 0.461 | 3903830.00 | 100.00 | 0.9695 | 1.11x | 2.34x | 2.15x |
| fanin_priority | 0.003 | 0.057 | 0.017 | 0.020 | 0.455 | 3967784.50 | 100.00 | 0.9844 | 1.16x | 4.16x | 2.16x |
| DependencyAware | 0.004 | 0.039 | 0.017 | 0.021 | 0.470 | 3836752.75 | 100.00 | 0.9721 | 1.25x | 3.47x | 2.37x |
| SJF | 0.003 | 0.058 | 0.016 | 0.019 | 0.390 | 4561067.00 | 100.00 | 0.9877 | 1.15x | 4.35x | 2.27x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.46 ± 0.16 | 3903830.00 ± 1241338.75 | 100.00 ± 0.00 | 0.97 ± 0.02 | 1.11x ± 0.01 | 2.34x ± 0.16 | 2.15x ± 0.01 |
| fanin_priority | 0.00 ± 0.00 | 0.06 ± 0.01 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.46 ± 0.16 | 3967784.50 ± 1225913.25 | 100.00 ± 0.00 | 0.98 ± 0.00 | 1.16x ± 0.02 | 4.16x ± 0.61 | 2.16x ± 0.02 |
| DependencyAware | 0.00 ± 0.00 | 0.04 ± 0.01 | 0.02 ± 0.00 | 0.02 ± 0.01 | 0.47 ± 0.17 | 3836752.75 ± 1199144.75 | 100.00 ± 0.00 | 0.97 ± 0.02 | 1.25x ± 0.03 | 3.47x ± 0.59 | 2.37x ± 0.07 |
| SJF | 0.00 ± 0.00 | 0.06 ± 0.01 | 0.02 ± 0.00 | 0.02 ± 0.01 | 0.39 ± 0.14 | 4561067.00 ± 1241886.38 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.15x ± 0.01 | 4.35x ± 0.77 | 2.27x ± 0.02 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.08x | 1.20x | 1.09x | 1.12x |
| wl 1 | 1.14x | 1.27x | 1.50x | 1.26x |
| wl 2 | 1.09x | 1.05x | 1.12x | 1.09x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.012 ms² | 0.015 ms² | 0.014 ms² | 0.010 ms² |
| wl 1 | 0.005 ms² | 0.008 ms² | 0.004 ms² | 0.005 ms² |
| wl 2 | 0.011 ms² | 0.013 ms² | 0.012 ms² | 0.008 ms² |
