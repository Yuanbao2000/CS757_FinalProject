# GPU Scheduler Report
Group: imbalanced_2 | batch_size=128 | runs=10 (averaged)

Generated: 20260403_231746

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 7.355 | 36.328 | 0.297 | 7.652 | 36.456 | 20108.03 | 22.24 | 0.9401 | 269.72x | 2740.37x | 153.62x |
| Priority | 8.242 | 39.435 | 0.201 | 8.444 | 39.558 | 18530.13 | 14.55 | 0.9381 | 363.68x | 2353.07x | 206.51x |
| DependencyAware | 7.703 | 35.431 | 0.292 | 7.996 | 35.551 | 20625.17 | 24.35 | 0.9452 | 284.66x | 2755.03x | 162.53x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 7.36 ± 0.08 | 36.33 ± 0.35 | 0.30 ± 0.00 | 7.65 ± 0.08 | 36.46 ± 0.35 | 20108.03 ± 187.65 | 22.24 ± 0.50 | 0.94 | 269.72x ± 32.01 | 2740.37x | 153.62x ± 16.43 |
| Priority | 8.24 ± 0.03 | 39.43 ± 0.18 | 0.20 ± 0.00 | 8.44 ± 0.03 | 39.56 ± 0.18 | 18530.13 ± 83.02 | 14.55 ± 0.13 | 0.94 | 363.68x ± 11.92 | 2353.07x | 206.51x ± 6.73 |
| DependencyAware | 7.70 ± 0.07 | 35.43 ± 0.65 | 0.29 ± 0.00 | 8.00 ± 0.07 | 35.55 ± 0.65 | 20625.17 ± 366.76 | 24.35 ± 0.32 | 0.95 | 284.66x ± 9.49 | 2755.03x | 162.53x ± 6.80 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 364.65x | 453.47x | 308.98x |
| wl 1 | 303.99x | 386.20x | 318.45x |
| wl 2 | 187.19x | 293.65x | 243.22x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 146.367 ms² | 180.107 ms² | 134.904 ms² |
| wl 1 | 56.459 ms² | 56.799 ms² | 53.509 ms² |
| wl 2 | 82.012 ms² | 87.964 ms² | 90.611 ms² |
