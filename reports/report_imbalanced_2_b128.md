# GPU Scheduler Group Report
Group: imbalanced_2 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022306

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.012 | 0.010 | 0.010 | 0.203 | 3931088.50 | 100.00 | 0.9821 | 1.01x | 1.85x | 1.85x |
| fanin_priority | 0.000 | 0.013 | 0.011 | 0.011 | 0.227 | 3561231.50 | 100.00 | 0.9812 | 1.01x | 1.83x | 1.85x |
| DependencyAware | 0.000 | 0.015 | 0.011 | 0.011 | 0.208 | 3576168.50 | 100.00 | 0.9768 | 1.01x | 1.96x | 1.85x |
| SJF | 0.000 | 0.017 | 0.010 | 0.010 | 0.192 | 3877391.25 | 100.00 | 0.9776 | 1.01x | 2.21x | 1.85x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.20 ± 0.08 | 3931088.50 ± 830877.50 | 100.00 ± 0.00 | 0.98 ± 0.00 | 1.01x ± 0.00 | 1.85x ± 0.14 | 1.85x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.09 | 3561231.50 ± 867489.06 | 100.00 ± 0.00 | 0.98 ± 0.00 | 1.01x ± 0.00 | 1.83x ± 0.15 | 1.85x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.21 ± 0.03 | 3576168.50 ± 418191.94 | 100.00 ± 0.00 | 0.98 ± 0.02 | 1.01x ± 0.00 | 1.96x ± 0.36 | 1.85x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.19 ± 0.03 | 3877391.25 ± 430383.94 | 100.00 ± 0.00 | 0.98 ± 0.01 | 1.01x ± 0.01 | 2.21x ± 0.77 | 1.85x ± 0.01 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.04x | 1.00x | 1.06x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.02x | 1.00x | 1.03x | 1.00x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.005 ms² | 0.006 ms² | 0.004 ms² | 0.003 ms² |
| wl 1 | 0.003 ms² | 0.004 ms² | 0.003 ms² | 0.002 ms² |
| wl 2 | 0.003 ms² | 0.004 ms² | 0.003 ms² | 0.002 ms² |
