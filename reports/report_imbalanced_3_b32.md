# GPU Scheduler Report
Group: imbalanced_3 | batch_size=32 | runs=10 (averaged)

Generated: 20260408_184227

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 25.165 | 75.865 | 0.326 | 25.491 | 75.988 | 21152.98 | 22.92 | 0.9985 | 1002.12x | 11356.19x | 531.01x |
| Priority | 17.031 | 77.676 | 0.214 | 17.245 | 77.804 | 20654.88 | 14.93 | 1.0000 | 854.09x | 5475.59x | 459.09x |
| DependencyAware | 27.897 | 77.894 | 0.322 | 28.219 | 78.021 | 20598.63 | 21.78 | 0.9986 | 1131.31x | 11985.04x | 631.61x |
| SJF | 16.797 | 79.181 | 0.215 | 17.012 | 79.314 | 20261.97 | 14.99 | 0.9995 | 888.40x | 5659.38x | 480.37x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 25.16 ± 0.25 | 75.86 ± 1.16 | 0.33 ± 0.01 | 25.49 ± 0.25 | 75.99 ± 1.16 | 21152.98 ± 323.77 | 22.92 ± 0.39 | 1.00 | 1002.12x ± 32.37 | 11356.19x | 531.01x ± 17.66 |
| Priority | 17.03 ± 0.10 | 77.68 ± 0.32 | 0.21 ± 0.00 | 17.24 ± 0.10 | 77.80 ± 0.32 | 20654.88 ± 83.97 | 14.93 ± 0.21 | 1.00 | 854.09x ± 114.33 | 5475.59x | 459.09x ± 60.05 |
| DependencyAware | 27.90 ± 0.36 | 77.89 ± 0.69 | 0.32 ± 0.00 | 28.22 ± 0.36 | 78.02 ± 0.69 | 20598.63 ± 181.89 | 21.78 ± 0.30 | 1.00 | 1131.31x ± 23.94 | 11985.04x | 631.61x ± 13.60 |
| SJF | 16.80 ± 0.20 | 79.18 ± 0.49 | 0.21 ± 0.00 | 17.01 ± 0.20 | 79.31 ± 0.49 | 20261.97 ± 124.38 | 14.99 ± 0.07 | 1.00 | 888.40x ± 20.54 | 5659.38x | 480.37x ± 10.90 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1344.54x | 953.73x | 1850.37x | 1128.90x |
| wl 1 | 533.21x | 887.31x | 684.63x | 847.93x |
| wl 2 | 1223.07x | 792.97x | 1197.62x | 830.06x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 745.300 ms² | 553.961 ms² | 819.443 ms² | 584.743 ms² |
| wl 1 | 283.466 ms² | 563.957 ms² | 466.602 ms² | 535.351 ms² |
| wl 2 | 559.665 ms² | 504.848 ms² | 608.884 ms² | 520.356 ms² |
