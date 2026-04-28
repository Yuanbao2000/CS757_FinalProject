# GPU Scheduler Group Report
Group: imbalanced_4 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022320

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.003 | 0.024 | 0.016 | 0.019 | 0.341 | 5448691.00 | 100.00 | 0.8498 | 1.18x | 2.44x | 2.09x |
| fanin_priority | 0.002 | 0.077 | 0.017 | 0.020 | 0.384 | 4957277.00 | 100.00 | 0.8981 | 1.12x | 5.01x | 1.96x |
| DependencyAware | 0.007 | 0.102 | 0.019 | 0.025 | 0.409 | 4633301.50 | 100.00 | 0.9090 | 1.35x | 6.33x | 2.27x |
| SJF | 0.003 | 0.111 | 0.016 | 0.019 | 0.369 | 5234709.50 | 100.00 | 0.8736 | 1.17x | 7.81x | 2.17x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.34 ± 0.10 | 5448691.00 ± 1146642.25 | 100.00 ± 0.00 | 0.85 ± 0.02 | 1.18x ± 0.03 | 2.44x ± 0.30 | 2.09x ± 0.03 |
| fanin_priority | 0.00 ± 0.00 | 0.08 ± 0.02 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.38 ± 0.12 | 4957277.00 ± 1341561.50 | 100.00 ± 0.00 | 0.90 ± 0.02 | 1.12x ± 0.01 | 5.01x ± 0.83 | 1.96x ± 0.01 |
| DependencyAware | 0.01 ± 0.00 | 0.10 ± 0.03 | 0.02 ± 0.01 | 0.03 ± 0.01 | 0.41 ± 0.12 | 4633301.50 ± 1207807.88 | 100.00 ± 0.00 | 0.91 ± 0.01 | 1.35x ± 0.02 | 6.33x ± 0.92 | 2.27x ± 0.03 |
| SJF | 0.00 ± 0.00 | 0.11 ± 0.03 | 0.02 ± 0.00 | 0.02 ± 0.01 | 0.37 ± 0.13 | 5234709.50 ± 1416687.50 | 100.00 ± 0.00 | 0.87 ± 0.02 | 1.17x ± 0.01 | 7.81x ± 1.40 | 2.17x ± 0.02 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.17x | 1.60x | 1.68x | 1.41x |
| wl 1 | 1.10x | 1.19x | 1.12x | 1.24x |
| wl 2 | 1.20x | 1.11x | 1.39x | 1.15x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.001 ms² | 0.002 ms² | 0.003 ms² | 0.001 ms² |
| wl 1 | 0.011 ms² | 0.013 ms² | 0.017 ms² | 0.011 ms² |
| wl 2 | 0.008 ms² | 0.009 ms² | 0.010 ms² | 0.008 ms² |
