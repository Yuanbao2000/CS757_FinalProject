# GPU Scheduler Report
Group: imbalanced_5 | batch_size=128 | runs=10 (averaged)

Generated: 20260403_231814

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 17.604 | 66.165 | 0.343 | 17.947 | 66.282 | 36232.77 | 14.70 | 0.9997 | 697.59x | 9102.35x | 382.97x |
| Priority | 13.798 | 72.233 | 0.264 | 14.062 | 72.355 | 33171.82 | 12.32 | 0.9961 | 628.98x | 4298.47x | 332.67x |
| DependencyAware | 15.738 | 60.788 | 0.337 | 16.075 | 60.910 | 39416.80 | 15.94 | 0.9994 | 558.33x | 9396.27x | 328.23x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 17.60 ± 0.43 | 66.16 ± 1.69 | 0.34 ± 0.01 | 17.95 ± 0.44 | 66.28 ± 1.69 | 36232.77 ± 925.35 | 14.70 ± 0.39 | 1.00 | 697.59x ± 66.88 | 9102.35x | 382.97x ± 36.11 |
| Priority | 13.80 ± 0.21 | 72.23 ± 0.54 | 0.26 ± 0.00 | 14.06 ± 0.21 | 72.35 ± 0.54 | 33171.82 ± 246.97 | 12.32 ± 0.22 | 1.00 | 628.98x ± 80.91 | 4298.47x | 332.67x ± 42.37 |
| DependencyAware | 15.74 ± 0.35 | 60.79 ± 1.17 | 0.34 ± 0.00 | 16.07 ± 0.35 | 60.91 ± 1.18 | 39416.80 ± 751.68 | 15.94 ± 0.49 | 1.00 | 558.33x ± 25.97 | 9396.27x | 328.23x ± 14.62 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 795.40x | 1225.64x | 689.06x |
| wl 1 | 700.99x | 759.01x | 616.83x |
| wl 2 | 683.96x | 488.70x | 511.91x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 615.476 ms² | 786.809 ms² | 487.495 ms² |
| wl 1 | 427.063 ms² | 490.335 ms² | 333.565 ms² |
| wl 2 | 356.615 ms² | 293.996 ms² | 238.847 ms² |
