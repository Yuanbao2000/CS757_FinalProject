# GPU Scheduler Report
Group: imbalanced_2 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_023954

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 2.447 | 7.254 | 0.037 | 2.484 | 7.366 | 103264.80 | 16.07 | 0.9777 | 154.38x | 656.30x | 87.53x |
| Priority | 2.750 | 7.521 | 0.038 | 2.788 | 7.631 | 110959.71 | 17.77 | 0.9868 | 163.60x | 602.99x | 90.24x |
| DependencyAware | 2.407 | 6.931 | 0.037 | 2.444 | 7.042 | 108180.19 | 16.83 | 0.9717 | 144.28x | 630.53x | 83.04x |
| SJF | 2.269 | 6.969 | 0.038 | 2.307 | 7.093 | 106330.84 | 16.68 | 0.9831 | 135.65x | 571.62x | 75.18x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 2.45 ± 0.47 | 7.25 ± 1.50 | 0.04 ± 0.01 | 2.48 ± 0.47 | 7.37 ± 1.52 | 103264.80 ± 18471.56 | 16.07 ± 0.98 | 0.98 | 154.38x ± 18.36 | 656.30x | 87.53x ± 10.41 |
| Priority | 2.75 ± 1.99 | 7.52 ± 4.19 | 0.04 ± 0.01 | 2.79 ± 2.00 | 7.63 ± 4.20 | 110959.71 ± 28563.02 | 17.77 ± 2.70 | 0.99 | 163.60x ± 84.71 | 602.99x | 90.24x ± 45.76 |
| DependencyAware | 2.41 ± 0.62 | 6.93 ± 1.47 | 0.04 ± 0.01 | 2.44 ± 0.63 | 7.04 ± 1.49 | 108180.19 ± 19601.13 | 16.83 ± 0.81 | 0.97 | 144.28x ± 14.15 | 630.53x | 83.04x ± 7.88 |
| SJF | 2.27 ± 0.36 | 6.97 ± 1.21 | 0.04 ± 0.01 | 2.31 ± 0.36 | 7.09 ± 1.23 | 106330.84 ± 17474.21 | 16.68 ± 0.79 | 0.98 | 135.65x ± 8.56 | 571.62x | 75.18x ± 4.76 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 148.51x | 156.61x | 136.39x | 133.97x |
| wl 1 | 169.11x | 193.26x | 166.92x | 151.85x |
| wl 2 | 145.83x | 143.57x | 130.46x | 123.49x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 5.426 ms² | 8.244 ms² | 4.460 ms² | 4.808 ms² |
| wl 1 | 3.435 ms² | 5.513 ms² | 2.837 ms² | 2.686 ms² |
| wl 2 | 3.533 ms² | 5.006 ms² | 3.267 ms² | 3.095 ms² |
