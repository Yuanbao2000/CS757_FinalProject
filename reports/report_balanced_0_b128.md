# GPU Scheduler Group Report
Group: balanced_0 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022301

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.002 | 0.017 | 0.012 | 0.014 | 0.231 | 5067322.50 | 100.00 | 0.9929 | 1.15x | 2.32x | 2.04x |
| fanin_priority | 0.002 | 0.044 | 0.012 | 0.014 | 0.246 | 4869143.00 | 100.00 | 0.9891 | 1.14x | 4.37x | 1.99x |
| DependencyAware | 0.003 | 0.035 | 0.012 | 0.016 | 0.247 | 4756433.50 | 100.00 | 0.9921 | 1.22x | 3.48x | 2.16x |
| SJF | 0.002 | 0.032 | 0.012 | 0.014 | 0.227 | 5102564.00 | 100.00 | 0.9929 | 1.13x | 2.96x | 2.00x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.03 | 5067322.50 ± 632698.62 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.15x ± 0.02 | 2.32x ± 0.31 | 2.04x ± 0.03 |
| fanin_priority | 0.00 ± 0.00 | 0.04 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.25 ± 0.06 | 4869143.00 ± 850186.12 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.14x ± 0.01 | 4.37x ± 0.77 | 1.99x ± 0.01 |
| DependencyAware | 0.00 ± 0.00 | 0.03 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.25 ± 0.04 | 4756433.50 ± 649130.38 | 100.00 ± 0.00 | 0.99 ± 0.01 | 1.22x ± 0.03 | 3.48x ± 0.64 | 2.16x ± 0.04 |
| SJF | 0.00 ± 0.00 | 0.03 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.02 | 5102564.00 ± 415948.38 | 100.00 ± 0.00 | 0.99 ± 0.00 | 1.13x ± 0.01 | 2.96x ± 0.47 | 2.00x ± 0.02 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.13x | 1.28x | 1.12x | 1.20x |
| wl 1 | 1.09x | 1.15x | 1.06x | 1.10x |
| wl 2 | 1.19x | 1.06x | 1.36x | 1.10x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.004 ms² | 0.004 ms² | 0.004 ms² | 0.003 ms² |
| wl 1 | 0.004 ms² | 0.004 ms² | 0.004 ms² | 0.003 ms² |
| wl 2 | 0.002 ms² | 0.002 ms² | 0.002 ms² | 0.002 ms² |
