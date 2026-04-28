# GPU Scheduler Group Report
Group: imbalanced_2 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025619

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.018 | 0.018 | 0.392 | 1981164.25 | 100.00 | 0.9772 | 1.00x | 1.00x | 1.84x |
| fanin_priority | 0.000 | 0.000 | 0.018 | 0.018 | 0.369 | 2107918.00 | 100.00 | 0.9817 | 1.00x | 1.00x | 1.84x |
| DependencyAware | 0.000 | 0.000 | 0.018 | 0.018 | 0.370 | 2217767.50 | 100.00 | 0.9769 | 1.00x | 1.00x | 1.84x |
| SJF | 0.000 | 0.000 | 0.016 | 0.016 | 0.346 | 2264923.50 | 100.00 | 0.9794 | 1.00x | 1.00x | 1.84x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.39 ± 0.09 | 1981164.25 ± 470033.34 | 100.00 ± 0.00 | 0.98 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.84x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.37 ± 0.09 | 2107918.00 ± 502492.22 | 100.00 ± 0.00 | 0.98 ± 0.00 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.84x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.37 ± 0.11 | 2217767.50 ± 882814.81 | 100.00 ± 0.00 | 0.98 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.84x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.35 ± 0.08 | 2264923.50 ± 642636.62 | 100.00 ± 0.00 | 0.98 ± 0.01 | 1.00x ± 0.00 | 1.00x ± 0.00 | 1.84x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.00x | 1.00x | 1.00x | 1.00x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.016 ms² | 0.014 ms² | 0.014 ms² | 0.013 ms² |
| wl 1 | 0.011 ms² | 0.010 ms² | 0.010 ms² | 0.009 ms² |
| wl 2 | 0.011 ms² | 0.010 ms² | 0.010 ms² | 0.008 ms² |
