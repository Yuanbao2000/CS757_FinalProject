# GPU Scheduler Group Report
Group: balanced_1 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025426

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.017 | 0.064 | 0.013 | 0.030 | 0.623 | 2130158.00 | 100.00 | 0.9827 | 2.26x | 5.82x | 4.43x |
| fanin_priority | 0.015 | 0.329 | 0.014 | 0.029 | 0.648 | 2122811.25 | 100.00 | 0.9947 | 2.10x | 27.41x | 3.25x |
| DependencyAware | 0.031 | 0.302 | 0.015 | 0.046 | 0.686 | 1999572.00 | 100.00 | 0.9894 | 3.08x | 24.28x | 6.06x |
| SJF | 0.018 | 0.245 | 0.014 | 0.032 | 0.662 | 1995722.75 | 100.00 | 0.9802 | 2.25x | 23.52x | 4.84x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.02 ± 0.01 | 0.06 ± 0.03 | 0.01 ± 0.00 | 0.03 ± 0.01 | 0.62 ± 0.20 | 2130158.00 ± 698389.19 | 100.00 ± 0.00 | 0.98 ± 0.01 | 2.26x ± 0.04 | 5.82x ± 0.37 | 4.43x ± 0.09 |
| fanin_priority | 0.02 ± 0.00 | 0.33 ± 0.11 | 0.01 ± 0.00 | 0.03 ± 0.01 | 0.65 ± 0.23 | 2122811.25 ± 814277.44 | 100.00 ± 0.00 | 0.99 ± 0.00 | 2.10x ± 0.09 | 27.41x ± 3.55 | 3.25x ± 0.10 |
| DependencyAware | 0.03 ± 0.01 | 0.30 ± 0.11 | 0.02 ± 0.01 | 0.05 ± 0.02 | 0.69 ± 0.25 | 1999572.00 ± 780614.25 | 100.00 ± 0.00 | 0.99 ± 0.01 | 3.08x ± 0.07 | 24.28x ± 4.77 | 6.06x ± 0.14 |
| SJF | 0.02 ± 0.00 | 0.24 ± 0.07 | 0.01 ± 0.00 | 0.03 ± 0.01 | 0.66 ± 0.21 | 1995722.75 ± 644101.12 | 100.00 ± 0.00 | 0.98 ± 0.01 | 2.25x ± 0.10 | 23.52x ± 8.15 | 4.84x ± 0.25 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.92x | 3.70x | 2.55x | 1.90x |
| wl 1 | 2.23x | 3.12x | 3.01x | 2.03x |
| wl 2 | 2.36x | 1.39x | 3.22x | 2.40x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.040 ms² | 0.037 ms² | 0.045 ms² | 0.056 ms² |
| wl 1 | 0.033 ms² | 0.025 ms² | 0.036 ms² | 0.024 ms² |
| wl 2 | 0.024 ms² | 0.021 ms² | 0.031 ms² | 0.025 ms² |
