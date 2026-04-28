# GPU Scheduler Group Report
Group: imbalanced_4 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025537

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.003 | 0.019 | 0.014 | 0.016 | 0.301 | 5956237.50 | 100.00 | 0.8444 | 1.18x | 2.42x | 2.10x |
| fanin_priority | 0.002 | 0.069 | 0.014 | 0.016 | 0.305 | 5798335.50 | 100.00 | 0.9058 | 1.13x | 5.52x | 1.96x |
| DependencyAware | 0.006 | 0.078 | 0.015 | 0.020 | 0.310 | 5718698.00 | 100.00 | 0.9200 | 1.37x | 6.38x | 2.30x |
| SJF | 0.003 | 0.096 | 0.013 | 0.016 | 0.295 | 5993309.50 | 100.00 | 0.8820 | 1.18x | 7.70x | 2.19x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.30 ± 0.05 | 5956237.50 ± 819605.19 | 100.00 ± 0.00 | 0.84 ± 0.02 | 1.18x ± 0.01 | 2.42x ± 0.17 | 2.10x ± 0.01 |
| fanin_priority | 0.00 ± 0.00 | 0.07 ± 0.02 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.31 ± 0.03 | 5798335.50 ± 550401.62 | 100.00 ± 0.00 | 0.91 ± 0.02 | 1.13x ± 0.01 | 5.52x ± 1.20 | 1.96x ± 0.01 |
| DependencyAware | 0.01 ± 0.00 | 0.08 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.31 ± 0.03 | 5718698.00 ± 596543.81 | 100.00 ± 0.00 | 0.92 ± 0.02 | 1.37x ± 0.04 | 6.38x ± 1.19 | 2.30x ± 0.05 |
| SJF | 0.00 ± 0.00 | 0.10 ± 0.02 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.29 ± 0.03 | 5993309.50 ± 529576.06 | 100.00 ± 0.00 | 0.88 ± 0.02 | 1.18x ± 0.01 | 7.70x ± 1.54 | 2.19x ± 0.05 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.15x | 1.64x | 1.71x | 1.47x |
| wl 1 | 1.09x | 1.20x | 1.13x | 1.27x |
| wl 2 | 1.20x | 1.11x | 1.41x | 1.16x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.001 ms² | 0.001 ms² | 0.002 ms² | 0.001 ms² |
| wl 1 | 0.007 ms² | 0.007 ms² | 0.009 ms² | 0.006 ms² |
| wl 2 | 0.005 ms² | 0.006 ms² | 0.005 ms² | 0.005 ms² |
