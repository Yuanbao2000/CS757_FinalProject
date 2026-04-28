# GPU Scheduler Report
Group: imbalanced_5 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_024044

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 8.754 | 28.695 | 0.038 | 8.793 | 28.817 | 127408.08 | 15.08 | 0.9985 | 579.87x | 3413.07x | 313.35x |
| Priority | 7.433 | 21.933 | 0.038 | 7.471 | 22.048 | 140193.11 | 18.31 | 0.9987 | 375.56x | 1557.82x | 195.32x |
| DependencyAware | 7.487 | 18.064 | 0.037 | 7.524 | 18.185 | 134967.70 | 15.69 | 0.9997 | 382.55x | 1207.38x | 215.56x |
| SJF | 5.773 | 15.542 | 0.036 | 5.810 | 15.675 | 155973.16 | 19.19 | 0.9999 | 293.32x | 1116.66x | 153.26x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 8.75 ± 5.29 | 28.69 ± 34.72 | 0.04 ± 0.01 | 8.79 ± 5.30 | 28.82 ± 34.71 | 127408.08 ± 37142.64 | 15.08 ± 3.57 | 1.00 | 579.87x ± 566.88 | 3413.07x | 313.35x ± 307.70 |
| Priority | 7.43 ± 5.08 | 21.93 ± 18.18 | 0.04 ± 0.01 | 7.47 ± 5.09 | 22.05 ± 18.18 | 140193.11 ± 40143.72 | 18.31 ± 4.12 | 1.00 | 375.56x ± 244.67 | 1557.82x | 195.32x ± 126.74 |
| DependencyAware | 7.49 ± 0.87 | 18.06 ± 3.03 | 0.04 ± 0.00 | 7.52 ± 0.88 | 18.18 ± 3.05 | 134967.70 ± 17895.03 | 15.69 ± 0.54 | 1.00 | 382.55x ± 12.34 | 1207.38x | 215.56x ± 6.78 |
| SJF | 5.77 ± 0.85 | 15.54 ± 2.31 | 0.04 ± 0.01 | 5.81 ± 0.85 | 15.68 ± 2.32 | 155973.16 ± 19425.59 | 19.19 ± 0.73 | 1.00 | 293.32x ± 8.54 | 1116.66x | 153.26x ± 4.64 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 599.94x | 539.61x | 401.56x | 359.28x |
| wl 1 | 619.52x | 436.26x | 380.52x | 332.33x |
| wl 2 | 556.72x | 323.94x | 381.30x | 264.93x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 317.172 ms² | 146.776 ms² | 43.929 ms² | 29.480 ms² |
| wl 1 | 209.809 ms² | 123.909 ms² | 28.030 ms² | 15.552 ms² |
| wl 2 | 169.933 ms² | 84.959 ms² | 26.729 ms² | 13.627 ms² |
