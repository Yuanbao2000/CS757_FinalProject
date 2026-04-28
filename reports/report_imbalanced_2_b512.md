# GPU Scheduler Group Report
Group: imbalanced_2 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022401

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.009 | 0.009 | 0.181 | 4090530.00 | 100.00 | 0.9821 | 1.00x | 1.00x | 1.84x |
| fanin_priority | 0.000 | 0.000 | 0.010 | 0.010 | 0.215 | 3717103.50 | 100.00 | 0.9770 | 1.00x | 1.00x | 1.84x |
| DependencyAware | 0.000 | 0.000 | 0.011 | 0.011 | 0.214 | 3815940.00 | 100.00 | 0.9821 | 1.00x | 1.00x | 1.84x |
| SJF | 0.000 | 0.000 | 0.009 | 0.009 | 0.176 | 4171024.00 | 100.00 | 0.9826 | 1.00x | 1.00x | 1.84x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.18 ± 0.02 | 4090530.00 ± 346042.28 | 100.00 ± 0.00 | 0.98 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.84x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.22 ± 0.08 | 3717103.50 ± 876320.06 | 100.00 ± 0.00 | 0.98 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.84x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.21 ± 0.10 | 3815940.00 ± 833402.06 | 100.00 ± 0.00 | 0.98 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.84x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.18 ± 0.01 | 4171024.00 ± 260023.72 | 100.00 ± 0.00 | 0.98 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.84x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.00x | 1.00x | 1.00x | 1.00x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.003 ms² | 0.005 ms² | 0.006 ms² | 0.003 ms² |
| wl 1 | 0.002 ms² | 0.004 ms² | 0.004 ms² | 0.002 ms² |
| wl 2 | 0.002 ms² | 0.003 ms² | 0.004 ms² | 0.002 ms² |
