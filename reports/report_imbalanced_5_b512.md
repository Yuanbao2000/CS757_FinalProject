# GPU Scheduler Report
Group: imbalanced_5 | batch_size=512 | runs=10 (averaged)

Generated: 20260403_231857

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 15.770 | 63.398 | 0.343 | 16.113 | 63.535 | 37839.86 | 13.10 | 0.9996 | 555.88x | 9197.88x | 303.19x |
| Priority | 19.685 | 76.193 | 0.249 | 19.934 | 76.330 | 31446.30 | 7.82 | 0.9996 | 975.40x | 4872.75x | 514.77x |
| DependencyAware | 16.846 | 64.018 | 0.344 | 17.191 | 64.149 | 37420.68 | 12.64 | 0.9996 | 606.71x | 9837.51x | 342.04x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 15.77 ± 0.89 | 63.40 ± 2.72 | 0.34 ± 0.01 | 16.11 ± 0.89 | 63.53 ± 2.72 | 37839.86 ± 1525.13 | 13.10 ± 0.63 | 1.00 | 555.88x ± 78.60 | 9197.88x | 303.19x ± 41.76 |
| Priority | 19.69 ± 0.27 | 76.19 ± 0.85 | 0.25 ± 0.00 | 19.93 ± 0.27 | 76.33 ± 0.85 | 31446.30 ± 351.56 | 7.82 ± 0.12 | 1.00 | 975.40x ± 32.09 | 4872.75x | 514.77x ± 16.08 |
| DependencyAware | 16.85 ± 0.24 | 64.02 ± 0.93 | 0.34 ± 0.00 | 17.19 ± 0.24 | 64.15 ± 0.93 | 37420.68 ± 535.27 | 12.64 ± 0.28 | 1.00 | 606.71x ± 11.75 | 9837.51x | 342.04x ± 7.26 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 772.02x | 1095.77x | 671.88x |
| wl 1 | 597.30x | 1111.45x | 662.69x |
| wl 2 | 508.04x | 889.71x | 569.55x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 550.945 ms² | 816.548 ms² | 553.682 ms² |
| wl 1 | 396.838 ms² | 569.789 ms² | 380.496 ms² |
| wl 2 | 298.953 ms² | 441.064 ms² | 296.092 ms² |
