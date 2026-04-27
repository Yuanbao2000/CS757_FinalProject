# GPU Scheduler Report
Group: balanced_0 | batch_size=32 | runs=10 (averaged)

Generated: 20260408_184205

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 15.772 | 54.956 | 0.303 | 16.075 | 55.086 | 21467.58 | 23.24 | 0.9951 | 578.14x | 8645.20x | 325.03x |
| Priority | 11.638 | 53.960 | 0.224 | 11.862 | 54.084 | 21466.24 | 18.82 | 0.9989 | 641.56x | 3888.45x | 353.64x |
| DependencyAware | 17.731 | 54.669 | 0.324 | 18.054 | 54.802 | 21006.05 | 23.48 | 0.9937 | 670.99x | 6863.47x | 400.29x |
| SJF | 12.093 | 56.725 | 0.192 | 12.285 | 56.850 | 20246.97 | 16.87 | 0.9892 | 609.33x | 3934.60x | 333.70x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 15.77 ± 4.85 | 54.96 ± 11.16 | 0.30 ± 0.02 | 16.08 ± 4.87 | 55.09 ± 11.16 | 21467.58 ± 2828.60 | 23.24 ± 2.46 | 1.00 | 578.14x ± 253.45 | 8645.20x | 325.03x ± 156.22 |
| Priority | 11.64 ± 1.26 | 53.96 ± 5.66 | 0.22 ± 0.01 | 11.86 ± 1.27 | 54.08 ± 5.66 | 21466.24 ± 1762.26 | 18.82 ± 1.43 | 1.00 | 641.56x ± 59.25 | 3888.45x | 353.64x ± 33.09 |
| DependencyAware | 17.73 ± 0.33 | 54.67 ± 0.69 | 0.32 ± 0.01 | 18.05 ± 0.33 | 54.80 ± 0.69 | 21006.05 ± 264.36 | 23.48 ± 0.45 | 0.99 | 670.99x ± 27.20 | 6863.47x | 400.29x ± 16.81 |
| SJF | 12.09 ± 0.11 | 56.73 ± 0.35 | 0.19 ± 0.00 | 12.28 ± 0.11 | 56.85 ± 0.35 | 20246.97 ± 125.46 | 16.87 ± 0.23 | 0.99 | 609.33x ± 90.19 | 3934.60x | 333.70x ± 47.15 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 612.01x | 748.74x | 588.55x | 936.87x |
| wl 1 | 792.55x | 931.48x | 1008.98x | 698.56x |
| wl 2 | 453.26x | 439.28x | 548.07x | 386.74x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 281.820 ms² | 251.940 ms² | 230.702 ms² | 397.606 ms² |
| wl 1 | 312.646 ms² | 239.356 ms² | 352.405 ms² | 138.545 ms² |
| wl 2 | 115.358 ms² | 118.394 ms² | 155.881 ms² | 110.528 ms² |
