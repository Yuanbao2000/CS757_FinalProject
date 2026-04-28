# GPU Scheduler Group Report
Group: balanced_0 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025519

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.003 | 0.021 | 0.014 | 0.016 | 0.268 | 4736141.00 | 100.00 | 0.9919 | 1.14x | 2.27x | 2.04x |
| fanin_priority | 0.002 | 0.049 | 0.013 | 0.015 | 0.272 | 4595303.00 | 100.00 | 0.9876 | 1.14x | 4.47x | 1.99x |
| DependencyAware | 0.003 | 0.035 | 0.013 | 0.017 | 0.289 | 4432581.00 | 100.00 | 0.9919 | 1.24x | 3.62x | 2.18x |
| SJF | 0.002 | 0.033 | 0.012 | 0.014 | 0.242 | 4924310.50 | 100.00 | 0.9911 | 1.13x | 3.13x | 2.01x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.27 ± 0.11 | 4736141.00 ± 1080158.50 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.14x ± 0.02 | 2.27x ± 0.29 | 2.04x ± 0.03 |
| fanin_priority | 0.00 ± 0.00 | 0.05 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.27 ± 0.10 | 4595303.00 ± 961604.88 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.14x ± 0.02 | 4.47x ± 0.93 | 1.99x ± 0.02 |
| DependencyAware | 0.00 ± 0.00 | 0.04 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.29 ± 0.11 | 4432581.00 ± 1216629.38 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.24x ± 0.02 | 3.62x ± 0.48 | 2.18x ± 0.03 |
| SJF | 0.00 ± 0.00 | 0.03 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.24 ± 0.05 | 4924310.50 ± 863680.62 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.13x ± 0.01 | 3.13x ± 0.30 | 2.01x ± 0.01 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.12x | 1.27x | 1.13x | 1.21x |
| wl 1 | 1.08x | 1.16x | 1.06x | 1.10x |
| wl 2 | 1.19x | 1.06x | 1.39x | 1.10x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.006 ms² | 0.005 ms² | 0.006 ms² | 0.003 ms² |
| wl 1 | 0.006 ms² | 0.006 ms² | 0.007 ms² | 0.004 ms² |
| wl 2 | 0.003 ms² | 0.002 ms² | 0.002 ms² | 0.002 ms² |
