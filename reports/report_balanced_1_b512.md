# GPU Scheduler Group Report
Group: balanced_1 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025617

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.013 | 0.013 | 0.324 | 4115436.00 | 100.00 | 0.9613 | 1.00x | 1.00x | 2.02x |
| fanin_priority | 0.000 | 0.000 | 0.014 | 0.014 | 0.318 | 4023025.50 | 100.00 | 0.9708 | 1.00x | 1.00x | 2.02x |
| DependencyAware | 0.000 | 0.000 | 0.012 | 0.012 | 0.299 | 4262784.00 | 100.00 | 0.9683 | 1.00x | 1.00x | 2.02x |
| SJF | 0.000 | 0.000 | 0.015 | 0.015 | 0.370 | 3674427.25 | 100.00 | 0.9644 | 1.00x | 1.00x | 2.02x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.32 ± 0.12 | 4115436.00 ± 1173096.12 | 100.00 ± 0.00 | 0.96 ± 0.02 | 1.00x ± 0.00 | 1.00x ± 0.00 | 2.02x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.32 ± 0.10 | 4023025.50 ± 962089.75 | 100.00 ± 0.00 | 0.97 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 2.02x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.30 ± 0.09 | 4262784.00 ± 926950.12 | 100.00 ± 0.00 | 0.97 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 2.02x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.01 | 0.01 ± 0.01 | 0.37 ± 0.16 | 3674427.25 ± 1121699.50 | 100.00 ± 0.00 | 0.96 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 2.02x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.00x | 1.00x | 1.00x | 1.00x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.009 ms² | 0.009 ms² | 0.007 ms² | 0.012 ms² |
| wl 1 | 0.006 ms² | 0.007 ms² | 0.005 ms² | 0.009 ms² |
| wl 2 | 0.006 ms² | 0.006 ms² | 0.005 ms² | 0.008 ms² |
