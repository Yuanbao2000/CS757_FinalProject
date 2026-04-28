# GPU Scheduler Report
Group: balanced_1 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_024101

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.920 | 6.880 | 0.036 | 1.956 | 6.989 | 172938.34 | 14.66 | 0.9605 | 106.89x | 499.53x | 56.20x |
| Priority | 2.013 | 7.306 | 0.038 | 2.051 | 7.415 | 163528.91 | 14.75 | 0.9604 | 100.96x | 446.57x | 52.21x |
| DependencyAware | 2.064 | 7.116 | 0.038 | 2.102 | 7.240 | 168820.34 | 14.69 | 0.9561 | 104.43x | 445.32x | 55.85x |
| SJF | 2.006 | 7.147 | 0.038 | 2.044 | 7.254 | 166290.61 | 14.50 | 0.9621 | 103.55x | 467.92x | 53.62x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.92 ± 0.31 | 6.88 ± 0.98 | 0.04 ± 0.01 | 1.96 ± 0.31 | 6.99 ± 0.99 | 172938.34 ± 19827.69 | 14.66 ± 1.07 | 0.96 | 106.89x ± 21.13 | 499.53x | 56.20x ± 10.63 |
| Priority | 2.01 ± 0.31 | 7.31 ± 1.09 | 0.04 ± 0.01 | 2.05 ± 0.31 | 7.42 ± 1.11 | 163528.91 ± 21335.74 | 14.75 ± 0.68 | 0.96 | 100.96x ± 5.93 | 446.57x | 52.21x ± 3.05 |
| DependencyAware | 2.06 ± 0.53 | 7.12 ± 1.31 | 0.04 ± 0.01 | 2.10 ± 0.53 | 7.24 ± 1.32 | 168820.34 ± 25309.84 | 14.69 ± 0.98 | 0.96 | 104.43x ± 14.57 | 445.32x | 55.85x ± 7.55 |
| SJF | 2.01 ± 0.30 | 7.15 ± 0.90 | 0.04 ± 0.01 | 2.04 ± 0.30 | 7.25 ± 0.91 | 166290.61 ± 19023.23 | 14.50 ± 0.57 | 0.96 | 103.55x ± 3.05 | 467.92x | 53.62x ± 1.57 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 88.40x | 91.87x | 98.38x | 95.49x |
| wl 1 | 115.23x | 107.53x | 112.85x | 108.42x |
| wl 2 | 108.45x | 100.93x | 103.09x | 103.83x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 4.211 ms² | 4.682 ms² | 4.518 ms² | 4.454 ms² |
| wl 1 | 2.894 ms² | 3.211 ms² | 3.076 ms² | 2.959 ms² |
| wl 2 | 2.938 ms² | 3.304 ms² | 3.072 ms² | 3.063 ms² |
