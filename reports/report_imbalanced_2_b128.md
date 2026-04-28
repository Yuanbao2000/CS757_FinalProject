# GPU Scheduler Report
Group: imbalanced_2 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_024105

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.444 | 5.332 | 0.035 | 1.478 | 5.437 | 136012.53 | 16.37 | 0.9590 | 81.67x | 410.65x | 46.46x |
| Priority | 1.523 | 5.486 | 0.034 | 1.557 | 5.598 | 131128.03 | 17.16 | 0.9580 | 82.64x | 382.77x | 45.87x |
| DependencyAware | 1.486 | 5.326 | 0.035 | 1.522 | 5.434 | 135299.64 | 17.93 | 0.9525 | 78.41x | 348.82x | 45.07x |
| SJF | 1.523 | 5.413 | 0.034 | 1.557 | 5.520 | 132835.64 | 17.11 | 0.9606 | 83.70x | 384.83x | 46.53x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.44 ± 0.12 | 5.33 ± 0.55 | 0.03 ± 0.00 | 1.48 ± 0.13 | 5.44 ± 0.55 | 136012.53 ± 11790.89 | 16.37 ± 1.13 | 0.96 | 81.67x ± 16.45 | 410.65x | 46.46x ± 8.99 |
| Priority | 1.52 ± 0.05 | 5.49 ± 0.21 | 0.03 ± 0.00 | 1.56 ± 0.05 | 5.60 ± 0.22 | 131128.03 ± 4987.94 | 17.16 ± 0.31 | 0.96 | 82.64x ± 1.81 | 382.77x | 45.87x ± 1.03 |
| DependencyAware | 1.49 ± 0.05 | 5.33 ± 0.31 | 0.04 ± 0.00 | 1.52 ± 0.05 | 5.43 ± 0.31 | 135299.64 ± 7083.49 | 17.93 ± 0.42 | 0.95 | 78.41x ± 2.52 | 348.82x | 45.07x ± 1.63 |
| SJF | 1.52 ± 0.03 | 5.41 ± 0.09 | 0.03 ± 0.00 | 1.56 ± 0.03 | 5.52 ± 0.09 | 132835.64 ± 2241.52 | 17.11 ± 0.31 | 0.96 | 83.70x ± 1.84 | 384.83x | 46.53x ± 1.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 77.99x | 94.05x | 78.98x | 95.64x |
| wl 1 | 91.50x | 92.87x | 86.27x | 93.13x |
| wl 2 | 75.81x | 67.77x | 71.71x | 69.18x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 3.072 ms² | 3.223 ms² | 2.815 ms² | 3.176 ms² |
| wl 1 | 1.707 ms² | 1.774 ms² | 1.546 ms² | 1.777 ms² |
| wl 2 | 1.845 ms² | 1.897 ms² | 2.030 ms² | 1.883 ms² |
