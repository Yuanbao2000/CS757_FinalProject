# GPU Scheduler Report
Group: balanced_0 | batch_size=32 | runs=10 (averaged)

Generated: 20260405_141519

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.000 | 0.000 | 0.000 | inf | 0.00 | -nan(ind) | 0.00x | 0.00x | 0.00x |
| Priority | 0.000 | 0.000 | 0.000 | 0.000 | 0.000 | inf | 0.00 | -nan(ind) | 0.00x | 0.00x | 0.00x |
| DependencyAware | 0.000 | 0.000 | 0.000 | 0.000 | 0.000 | inf | 0.00 | -nan(ind) | 0.00x | 0.00x | 0.00x |
| SJF | 0.000 | 0.000 | 0.000 | 0.000 | 0.000 | inf | 0.00 | -nan(ind) | 0.00x | 0.00x | 0.00x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | inf ± -nan(ind) | 0.00 ± 0.00 | -nan(ind) | 0.00x ± 0.00 | 0.00x | 0.00x ± 0.00 |
| Priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | inf ± -nan(ind) | 0.00 ± 0.00 | -nan(ind) | 0.00x ± 0.00 | 0.00x | 0.00x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | inf ± -nan(ind) | 0.00 ± 0.00 | -nan(ind) | 0.00x ± 0.00 | 0.00x | 0.00x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | inf ± -nan(ind) | 0.00 ± 0.00 | -nan(ind) | 0.00x ± 0.00 | 0.00x | 0.00x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.00x | 0.00x | 0.00x | 0.00x |
| wl 1 | 0.00x | 0.00x | 0.00x | 0.00x |
| wl 2 | 0.00x | 0.00x | 0.00x | 0.00x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.000 ms² | 0.000 ms² | 0.000 ms² | 0.000 ms² |
| wl 1 | 0.000 ms² | 0.000 ms² | 0.000 ms² | 0.000 ms² |
| wl 2 | 0.000 ms² | 0.000 ms² | 0.000 ms² | 0.000 ms² |
