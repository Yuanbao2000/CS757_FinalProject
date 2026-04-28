# GPU Scheduler Group Report
Group: balanced_1 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022400

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.013 | 0.013 | 0.285 | 4219793.00 | 100.00 | 0.9740 | 1.00x | 1.00x | 2.02x |
| fanin_priority | 0.000 | 0.000 | 0.010 | 0.010 | 0.254 | 4697267.00 | 100.00 | 0.9652 | 1.00x | 1.00x | 2.02x |
| DependencyAware | 0.000 | 0.000 | 0.011 | 0.011 | 0.289 | 4258142.00 | 100.00 | 0.9635 | 1.00x | 1.00x | 2.02x |
| SJF | 0.000 | 0.000 | 0.011 | 0.011 | 0.288 | 4329467.50 | 100.00 | 0.9605 | 1.00x | 1.00x | 2.02x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.28 ± 0.03 | 4219793.00 ± 438929.16 | 100.00 ± 0.00 | 0.97 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 2.02x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.25 ± 0.02 | 4697267.00 ± 302117.31 | 100.00 ± 0.00 | 0.97 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 2.02x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.29 ± 0.06 | 4258142.00 ± 722568.50 | 100.00 ± 0.00 | 0.96 ± 0.02 | 1.00x ± 0.00 | 1.00x ± 0.00 | 2.02x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.29 ± 0.08 | 4329467.50 ± 787434.12 | 100.00 ± 0.00 | 0.96 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 2.02x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.00x | 1.00x | 1.00x | 1.00x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.006 ms² | 0.004 ms² | 0.006 ms² | 0.006 ms² |
| wl 1 | 0.005 ms² | 0.003 ms² | 0.004 ms² | 0.004 ms² |
| wl 2 | 0.004 ms² | 0.003 ms² | 0.004 ms² | 0.004 ms² |
