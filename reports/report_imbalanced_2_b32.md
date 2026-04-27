# GPU Scheduler Report
Group: imbalanced_2 | batch_size=32 | runs=10 (averaged)

Generated: 20260408_184216

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 8.993 | 38.258 | 0.301 | 9.293 | 38.384 | 19096.94 | 26.79 | 0.9508 | 354.14x | 5416.20x | 205.61x |
| Priority | 8.963 | 38.203 | 0.205 | 9.168 | 38.333 | 19122.58 | 20.16 | 0.9775 | 478.39x | 2618.77x | 269.10x |
| DependencyAware | 8.772 | 37.143 | 0.327 | 9.099 | 37.273 | 19672.03 | 30.48 | 0.9637 | 361.56x | 3189.52x | 201.78x |
| SJF | 9.163 | 39.086 | 0.186 | 9.348 | 39.217 | 18691.08 | 15.23 | 0.9672 | 505.98x | 2800.30x | 286.08x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 8.99 ± 0.07 | 38.26 ± 0.18 | 0.30 ± 0.00 | 9.29 ± 0.07 | 38.38 ± 0.18 | 19096.94 ± 90.42 | 26.79 ± 0.33 | 0.95 | 354.14x ± 16.62 | 5416.20x | 205.61x ± 9.61 |
| Priority | 8.96 ± 0.05 | 38.20 ± 0.19 | 0.21 ± 0.00 | 9.17 ± 0.05 | 38.33 ± 0.19 | 19122.58 ± 95.41 | 20.16 ± 0.09 | 0.98 | 478.39x ± 50.85 | 2618.77x | 269.10x ± 27.84 |
| DependencyAware | 8.77 ± 0.07 | 37.14 ± 0.67 | 0.33 ± 0.00 | 9.10 ± 0.07 | 37.27 ± 0.67 | 19672.03 ± 357.86 | 30.48 ± 0.55 | 0.96 | 361.56x ± 8.30 | 3189.52x | 201.78x ± 5.21 |
| SJF | 9.16 ± 0.05 | 39.09 ± 0.17 | 0.19 ± 0.00 | 9.35 ± 0.05 | 39.22 ± 0.16 | 18691.08 ± 77.46 | 15.23 ± 0.05 | 0.97 | 505.98x ± 20.20 | 2800.30x | 286.08x ± 11.08 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 349.33x | 511.27x | 394.97x | 518.81x |
| wl 1 | 442.47x | 577.99x | 405.31x | 592.71x |
| wl 2 | 285.26x | 378.66x | 306.81x | 428.22x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 159.076 ms² | 165.946 ms² | 143.291 ms² | 166.578 ms² |
| wl 1 | 73.444 ms² | 73.855 ms² | 70.161 ms² | 77.131 ms² |
| wl 2 | 98.381 ms² | 81.990 ms² | 96.367 ms² | 93.175 ms² |
