# GPU Scheduler Report
Group: imbalanced_2 | batch_size=512 | runs=10 (averaged)

Generated: 20260408_184414

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 7.464 | 36.633 | 0.310 | 7.774 | 36.773 | 19934.19 | 23.27 | 0.9405 | 250.05x | 2380.39x | 141.94x |
| Priority | 8.297 | 38.905 | 0.186 | 8.483 | 39.065 | 18764.03 | 12.98 | 0.9379 | 355.62x | 2253.90x | 202.66x |
| DependencyAware | 7.778 | 36.461 | 0.300 | 8.078 | 36.600 | 20027.83 | 22.14 | 0.9529 | 234.93x | 2770.56x | 137.02x |
| SJF | 8.319 | 39.066 | 0.187 | 8.506 | 39.203 | 18698.17 | 12.99 | 0.9377 | 357.30x | 2292.36x | 203.71x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 7.46 ± 0.06 | 36.63 ± 0.23 | 0.31 ± 0.01 | 7.77 ± 0.06 | 36.77 ± 0.24 | 19934.19 ± 128.67 | 23.27 ± 0.56 | 0.94 | 250.05x ± 37.60 | 2380.39x | 141.94x ± 20.04 |
| Priority | 8.30 ± 0.04 | 38.91 ± 0.22 | 0.19 ± 0.00 | 8.48 ± 0.04 | 39.07 ± 0.21 | 18764.03 ± 103.46 | 12.98 ± 0.05 | 0.94 | 355.62x ± 9.37 | 2253.90x | 202.66x ± 5.65 |
| DependencyAware | 7.78 ± 0.06 | 36.46 ± 0.16 | 0.30 ± 0.00 | 8.08 ± 0.06 | 36.60 ± 0.17 | 20027.83 ± 94.85 | 22.14 ± 0.30 | 0.95 | 234.93x ± 5.94 | 2770.56x | 137.02x ± 3.49 |
| SJF | 8.32 ± 0.04 | 39.07 ± 0.25 | 0.19 ± 0.00 | 8.51 ± 0.04 | 39.20 ± 0.25 | 18698.17 ± 119.22 | 12.99 ± 0.04 | 0.94 | 357.30x ± 6.80 | 2292.36x | 203.71x ± 4.89 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 342.60x | 407.65x | 205.16x | 412.47x |
| wl 1 | 277.97x | 398.57x | 318.92x | 400.23x |
| wl 2 | 174.06x | 290.79x | 183.98x | 290.68x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 147.771 ms² | 168.801 ms² | 149.710 ms² | 169.760 ms² |
| wl 1 | 57.675 ms² | 66.883 ms² | 61.190 ms² | 67.259 ms² |
| wl 2 | 84.585 ms² | 93.636 ms² | 86.712 ms² | 94.168 ms² |
