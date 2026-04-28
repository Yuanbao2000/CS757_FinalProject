# GPU Scheduler Group Report
Group: imbalanced_5 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025551

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.009 | 0.045 | 0.018 | 0.026 | 0.512 | 4923712.00 | 100.00 | 0.9965 | 1.45x | 3.30x | 2.73x |
| fanin_priority | 0.004 | 0.134 | 0.018 | 0.022 | 0.565 | 4489081.00 | 100.00 | 0.9935 | 1.21x | 7.63x | 2.14x |
| DependencyAware | 0.015 | 0.180 | 0.018 | 0.033 | 0.500 | 4901688.00 | 100.00 | 0.9949 | 1.83x | 13.16x | 3.22x |
| SJF | 0.007 | 0.198 | 0.018 | 0.025 | 0.525 | 4777245.00 | 100.00 | 0.9939 | 1.39x | 13.17x | 2.80x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.01 ± 0.00 | 0.04 ± 0.01 | 0.02 ± 0.00 | 0.03 ± 0.01 | 0.51 ± 0.13 | 4923712.00 ± 958314.25 | 100.00 ± 0.00 | 1.00 ± 0.00 | 1.45x ± 0.02 | 3.30x ± 0.32 | 2.73x ± 0.03 |
| fanin_priority | 0.00 ± 0.00 | 0.13 ± 0.03 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.56 ± 0.16 | 4489081.00 ± 895844.44 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.21x ± 0.02 | 7.63x ± 1.38 | 2.14x ± 0.02 |
| DependencyAware | 0.02 ± 0.00 | 0.18 ± 0.03 | 0.02 ± 0.00 | 0.03 ± 0.00 | 0.50 ± 0.08 | 4901688.00 ± 648262.62 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.83x ± 0.06 | 13.16x ± 1.59 | 3.22x ± 0.07 |
| SJF | 0.01 ± 0.00 | 0.20 ± 0.02 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.52 ± 0.12 | 4777245.00 ± 874982.31 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.39x ± 0.05 | 13.17x ± 2.80 | 2.80x ± 0.11 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.30x | 1.66x | 1.32x | 1.45x |
| wl 1 | 1.47x | 1.25x | 1.61x | 1.41x |
| wl 2 | 1.46x | 1.13x | 2.01x | 1.37x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.025 ms² | 0.022 ms² | 0.024 ms² | 0.029 ms² |
| wl 1 | 0.015 ms² | 0.014 ms² | 0.015 ms² | 0.013 ms² |
| wl 2 | 0.014 ms² | 0.015 ms² | 0.012 ms² | 0.013 ms² |
