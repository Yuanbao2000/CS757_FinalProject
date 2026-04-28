# GPU Scheduler Report
Group: balanced_1 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_024212

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.846 | 6.768 | 0.036 | 1.883 | 6.878 | 174790.84 | 15.22 | 0.9575 | 103.31x | 451.75x | 54.27x |
| Priority | 2.193 | 7.660 | 0.038 | 2.231 | 7.768 | 160248.72 | 13.78 | 0.9635 | 114.07x | 498.39x | 59.18x |
| DependencyAware | 1.919 | 6.870 | 0.037 | 1.957 | 6.980 | 173429.14 | 15.30 | 0.9573 | 97.75x | 429.32x | 52.41x |
| SJF | 2.229 | 7.722 | 0.039 | 2.268 | 7.829 | 159843.81 | 13.86 | 0.9654 | 109.18x | 475.05x | 56.33x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.85 ± 0.18 | 6.77 ± 0.74 | 0.04 ± 0.01 | 1.88 ± 0.18 | 6.88 ± 0.77 | 174790.84 ± 17268.80 | 15.22 ± 1.12 | 0.96 | 103.31x ± 23.38 | 451.75x | 54.27x ± 11.93 |
| Priority | 2.19 ± 0.62 | 7.66 ± 1.78 | 0.04 ± 0.01 | 2.23 ± 0.62 | 7.77 ± 1.80 | 160248.72 ± 31216.67 | 13.78 ± 2.17 | 0.96 | 114.07x ± 26.89 | 498.39x | 59.18x ± 13.86 |
| DependencyAware | 1.92 ± 0.33 | 6.87 ± 1.04 | 0.04 ± 0.01 | 1.96 ± 0.34 | 6.98 ± 1.05 | 173429.14 ± 20617.10 | 15.30 ± 0.65 | 0.96 | 97.75x ± 4.80 | 429.32x | 52.41x ± 2.58 |
| SJF | 2.23 ± 0.66 | 7.72 ± 1.91 | 0.04 ± 0.01 | 2.27 ± 0.66 | 7.83 ± 1.93 | 159843.81 ± 32369.32 | 13.86 ± 1.56 | 0.97 | 109.18x ± 12.36 | 475.05x | 56.33x ± 6.13 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 83.98x | 104.59x | 93.72x | 99.54x |
| wl 1 | 110.51x | 123.93x | 107.54x | 119.08x |
| wl 2 | 105.45x | 113.05x | 95.49x | 108.19x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 3.834 ms² | 5.980 ms² | 4.144 ms² | 6.026 ms² |
| wl 1 | 2.580 ms² | 4.230 ms² | 2.898 ms² | 4.495 ms² |
| wl 2 | 2.673 ms² | 4.258 ms² | 2.909 ms² | 4.344 ms² |
