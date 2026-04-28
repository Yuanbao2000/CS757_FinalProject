# GPU Scheduler Group Report
Group: balanced_0 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022204

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.018 | 0.072 | 0.010 | 0.028 | 0.393 | 3314032.50 | 100.00 | 0.9975 | 3.04x | 10.01x | 5.09x |
| fanin_priority | 0.015 | 0.234 | 0.009 | 0.023 | 0.365 | 3239796.50 | 100.00 | 0.9936 | 2.79x | 30.07x | 3.64x |
| DependencyAware | 0.029 | 0.185 | 0.009 | 0.038 | 0.370 | 3214511.50 | 100.00 | 0.9958 | 4.51x | 27.48x | 6.77x |
| SJF | 0.015 | 0.145 | 0.009 | 0.024 | 0.391 | 3005293.25 | 100.00 | 0.9952 | 2.84x | 22.67x | 5.22x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.02 ± 0.01 | 0.07 ± 0.03 | 0.01 ± 0.00 | 0.03 ± 0.01 | 0.39 ± 0.20 | 3314032.50 ± 758447.69 | 100.00 ± 0.00 | 1.00 ± 0.00 | 3.04x ± 0.11 | 10.01x ± 0.87 | 5.09x ± 0.14 |
| fanin_priority | 0.01 ± 0.00 | 0.23 ± 0.05 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.36 ± 0.07 | 3239796.50 ± 462470.78 | 100.00 ± 0.00 | 0.99 ± 0.00 | 2.79x ± 0.26 | 30.07x ± 5.52 | 3.64x ± 0.26 |
| DependencyAware | 0.03 ± 0.01 | 0.19 ± 0.06 | 0.01 ± 0.00 | 0.04 ± 0.01 | 0.37 ± 0.07 | 3214511.50 ± 551526.69 | 100.00 ± 0.00 | 1.00 ± 0.00 | 4.51x ± 0.24 | 27.48x ± 8.24 | 6.77x ± 0.28 |
| SJF | 0.02 ± 0.00 | 0.15 ± 0.04 | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.39 ± 0.06 | 3005293.25 ± 420098.38 | 100.00 ± 0.00 | 1.00 ± 0.00 | 2.84x ± 0.14 | 22.67x ± 7.28 | 5.22x ± 0.48 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 2.62x | 3.61x | 3.81x | 2.69x |
| wl 1 | 2.23x | 2.68x | 2.34x | 2.32x |
| wl 2 | 3.68x | 2.39x | 5.97x | 3.17x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.017 ms² | 0.006 ms² | 0.011 ms² | 0.013 ms² |
| wl 1 | 0.015 ms² | 0.007 ms² | 0.014 ms² | 0.006 ms² |
| wl 2 | 0.008 ms² | 0.006 ms² | 0.008 ms² | 0.009 ms² |
