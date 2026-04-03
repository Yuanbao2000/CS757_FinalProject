# GPU Scheduler Report
Group: imbalanced_4 | batch_size=512 | runs=10 (averaged)

Generated: 20260403_231843

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 10.097 | 38.811 | 0.226 | 10.324 | 38.943 | 45144.46 | 14.42 | 0.7105 | 369.97x | 6346.34x | 211.68x |
| Priority | 14.408 | 51.892 | 0.135 | 14.543 | 52.029 | 33726.34 | 6.16 | 0.7154 | 708.19x | 3145.36x | 391.33x |
| DependencyAware | 11.038 | 40.706 | 0.231 | 11.270 | 40.838 | 42954.38 | 13.68 | 0.7292 | 421.64x | 6311.45x | 250.30x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 10.10 ± 0.62 | 38.81 ± 2.08 | 0.23 ± 0.01 | 10.32 ± 0.62 | 38.94 ± 2.08 | 45144.46 ± 2443.61 | 14.42 ± 0.59 | 0.71 | 369.97x ± 23.18 | 6346.34x | 211.68x ± 13.14 |
| Priority | 14.41 ± 0.48 | 51.89 ± 1.61 | 0.14 ± 0.00 | 14.54 ± 0.48 | 52.03 ± 1.61 | 33726.34 ± 1092.06 | 6.16 ± 0.12 | 0.72 | 708.19x ± 78.51 | 3145.36x | 391.33x ± 43.09 |
| DependencyAware | 11.04 ± 0.27 | 40.71 ± 1.04 | 0.23 ± 0.01 | 11.27 ± 0.28 | 40.84 ± 1.04 | 42954.38 ± 1117.22 | 13.68 ± 0.20 | 0.73 | 421.64x ± 19.12 | 6311.45x | 250.30x ± 10.44 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 32.47x | 93.31x | 89.71x |
| wl 1 | 584.89x | 1063.06x | 639.74x |
| wl 2 | 331.75x | 645.61x | 382.77x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 1.342 ms² | 3.322 ms² | 3.460 ms² |
| wl 1 | 200.100 ms² | 373.138 ms² | 205.720 ms² |
| wl 2 | 135.799 ms² | 257.360 ms² | 139.042 ms² |
