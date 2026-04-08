# GPU Scheduler Report
Group: imbalanced_4 | batch_size=128 | runs=10 (averaged)

Generated: 20260408_184336

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 10.823 | 38.336 | 0.228 | 11.051 | 38.474 | 45672.04 | 14.42 | 0.7336 | 437.09x | 4368.92x | 252.03x |
| Priority | 12.699 | 51.856 | 0.147 | 12.845 | 51.992 | 33753.95 | 7.40 | 0.6778 | 621.00x | 3029.83x | 347.88x |
| DependencyAware | 11.252 | 42.059 | 0.258 | 11.510 | 42.194 | 41611.07 | 15.00 | 0.8039 | 363.96x | 5864.23x | 216.47x |
| SJF | 12.955 | 54.204 | 0.133 | 13.088 | 54.342 | 32278.27 | 6.72 | 0.6780 | 626.35x | 3229.86x | 350.05x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 10.82 ± 0.60 | 38.34 ± 1.91 | 0.23 ± 0.01 | 11.05 ± 0.60 | 38.47 ± 1.90 | 45672.04 ± 2200.52 | 14.42 ± 0.75 | 0.73 | 437.09x ± 49.89 | 4368.92x | 252.03x ± 27.36 |
| Priority | 12.70 ± 0.51 | 51.86 ± 1.70 | 0.15 ± 0.00 | 12.85 ± 0.51 | 51.99 ± 1.70 | 33753.95 ± 1137.15 | 7.40 ± 0.15 | 0.68 | 621.00x ± 26.22 | 3029.83x | 347.88x ± 14.43 |
| DependencyAware | 11.25 ± 0.51 | 42.06 ± 1.67 | 0.26 ± 0.01 | 11.51 ± 0.52 | 42.19 ± 1.67 | 41611.07 ± 1631.66 | 15.00 ± 0.63 | 0.80 | 363.96x ± 15.60 | 5864.23x | 216.47x ± 9.05 |
| SJF | 12.96 ± 0.33 | 54.20 ± 1.29 | 0.13 ± 0.00 | 13.09 ± 0.34 | 54.34 ± 1.29 | 32278.27 ± 815.54 | 6.72 ± 0.04 | 0.68 | 626.35x ± 12.96 | 3229.86x | 350.05x ± 7.35 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 69.96x | 21.30x | 112.45x | 26.09x |
| wl 1 | 589.57x | 1037.68x | 595.88x | 1133.51x |
| wl 2 | 411.11x | 546.43x | 321.72x | 534.43x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 2.963 ms² | 0.110 ms² | 10.318 ms² | 0.084 ms² |
| wl 1 | 186.239 ms² | 393.858 ms² | 219.250 ms² | 439.127 ms² |
| wl 2 | 134.661 ms² | 254.491 ms² | 134.040 ms² | 260.094 ms² |
