# GPU Scheduler Report
Group: balanced_1 | batch_size=512 | runs=10 (averaged)

Generated: 20260408_184410

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 14.624 | 51.376 | 0.359 | 14.983 | 51.506 | 23090.13 | 16.52 | 0.9848 | 536.95x | 7065.63x | 283.32x |
| Priority | 15.782 | 55.712 | 0.268 | 16.050 | 55.848 | 21290.59 | 11.23 | 0.9811 | 741.93x | 3342.91x | 389.60x |
| DependencyAware | 14.195 | 50.138 | 0.349 | 14.545 | 50.277 | 23651.79 | 16.20 | 0.9853 | 496.82x | 6580.51x | 272.18x |
| SJF | 15.892 | 55.824 | 0.268 | 16.161 | 55.956 | 21250.57 | 11.19 | 0.9813 | 730.88x | 3271.36x | 383.38x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 14.62 ± 0.30 | 51.38 ± 0.80 | 0.36 ± 0.00 | 14.98 ± 0.30 | 51.51 ± 0.80 | 23090.13 ± 360.01 | 16.52 ± 0.44 | 0.98 | 536.95x ± 58.65 | 7065.63x | 283.32x ± 29.18 |
| Priority | 15.78 ± 0.14 | 55.71 ± 0.33 | 0.27 ± 0.00 | 16.05 ± 0.14 | 55.85 ± 0.33 | 21290.59 ± 124.14 | 11.23 ± 0.09 | 0.98 | 741.93x ± 18.62 | 3342.91x | 389.60x ± 9.79 |
| DependencyAware | 14.20 ± 0.17 | 50.14 ± 0.55 | 0.35 ± 0.00 | 14.54 ± 0.18 | 50.28 ± 0.54 | 23651.79 ± 253.24 | 16.20 ± 0.13 | 0.99 | 496.82x ± 19.98 | 6580.51x | 272.18x ± 11.70 |
| SJF | 15.89 ± 0.19 | 55.82 ± 0.54 | 0.27 ± 0.00 | 16.16 ± 0.19 | 55.96 ± 0.53 | 21250.57 ± 201.76 | 11.19 ± 0.13 | 0.98 | 730.88x ± 29.54 | 3271.36x | 383.38x ± 15.46 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 605.81x | 701.86x | 535.09x | 693.83x |
| wl 1 | 607.06x | 863.75x | 483.26x | 852.52x |
| wl 2 | 498.10x | 711.46x | 492.36x | 699.77x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 346.668 ms² | 409.101 ms² | 334.710 ms² | 411.211 ms² |
| wl 1 | 248.665 ms² | 274.069 ms² | 228.070 ms² | 276.955 ms² |
| wl 2 | 254.554 ms² | 289.659 ms² | 241.137 ms² | 291.190 ms² |
