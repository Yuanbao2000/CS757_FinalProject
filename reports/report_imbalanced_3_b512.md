# GPU Scheduler Report
Group: imbalanced_3 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_024229

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 2.085 | 8.065 | 0.036 | 2.121 | 8.177 | 205177.50 | 11.69 | 0.9721 | 111.17x | 535.51x | 58.54x |
| Priority | 2.114 | 8.397 | 0.036 | 2.151 | 8.506 | 201985.30 | 11.65 | 0.9725 | 111.27x | 534.05x | 58.21x |
| DependencyAware | 1.859 | 7.624 | 0.036 | 1.895 | 7.747 | 209608.48 | 12.44 | 0.9703 | 96.94x | 505.64x | 52.12x |
| SJF | 1.989 | 8.053 | 0.037 | 2.026 | 8.170 | 200171.78 | 12.08 | 0.9700 | 101.41x | 526.11x | 53.10x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 2.08 ± 0.76 | 8.07 ± 2.06 | 0.04 ± 0.01 | 2.12 ± 0.76 | 8.18 ± 2.08 | 205177.50 ± 34492.28 | 11.69 ± 1.58 | 0.97 | 111.17x ± 24.04 | 535.51x | 58.54x ± 12.17 |
| Priority | 2.11 ± 0.77 | 8.40 ± 2.95 | 0.04 ± 0.01 | 2.15 ± 0.77 | 8.51 ± 2.96 | 201985.30 ± 37900.73 | 11.65 ± 1.36 | 0.97 | 111.27x ± 22.30 | 534.05x | 58.21x ± 11.64 |
| DependencyAware | 1.86 ± 0.20 | 7.62 ± 0.85 | 0.04 ± 0.00 | 1.90 ± 0.21 | 7.75 ± 0.87 | 209608.48 ± 19254.20 | 12.44 ± 0.77 | 0.97 | 96.94x ± 5.84 | 505.64x | 52.12x ± 3.11 |
| SJF | 1.99 ± 0.43 | 8.05 ± 1.15 | 0.04 ± 0.00 | 2.03 ± 0.44 | 8.17 ± 1.16 | 200171.78 ± 24555.19 | 12.08 ± 0.84 | 0.97 | 101.41x ± 9.56 | 526.11x | 53.10x ± 4.91 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 143.65x | 158.41x | 138.65x | 143.03x |
| wl 1 | 61.85x | 58.69x | 52.80x | 53.70x |
| wl 2 | 135.70x | 132.85x | 114.26x | 121.40x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 5.236 ms² | 6.900 ms² | 4.132 ms² | 4.590 ms² |
| wl 1 | 2.068 ms² | 2.201 ms² | 1.348 ms² | 1.550 ms² |
| wl 2 | 4.577 ms² | 5.984 ms² | 3.690 ms² | 4.072 ms² |
