# GPU Scheduler Report
Group: imbalanced_4 | batch_size=32 | runs=10 (averaged)

Generated: 20260408_184237

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 17.886 | 53.132 | 0.199 | 18.085 | 53.261 | 32932.85 | 20.61 | 0.7564 | 799.16x | 8236.64x | 452.75x |
| Priority | 10.628 | 51.738 | 0.151 | 10.779 | 51.866 | 33822.78 | 16.98 | 0.6925 | 597.37x | 3716.69x | 338.10x |
| DependencyAware | 19.056 | 56.092 | 0.210 | 19.266 | 56.225 | 31185.99 | 20.79 | 0.9988 | 732.56x | 7479.77x | 444.05x |
| SJF | 10.069 | 54.011 | 0.142 | 10.212 | 54.140 | 32390.69 | 16.03 | 0.7010 | 563.04x | 4047.81x | 317.88x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 17.89 ± 0.69 | 53.13 ± 1.32 | 0.20 ± 0.00 | 18.09 ± 0.69 | 53.26 ± 1.31 | 32932.85 ± 799.81 | 20.61 ± 0.52 | 0.76 | 799.16x ± 43.26 | 8236.64x | 452.75x ± 24.24 |
| Priority | 10.63 ± 0.23 | 51.74 ± 1.39 | 0.15 ± 0.00 | 10.78 ± 0.24 | 51.87 ± 1.39 | 33822.78 ± 898.99 | 16.98 ± 0.09 | 0.69 | 597.37x ± 34.51 | 3716.69x | 338.10x ± 20.10 |
| DependencyAware | 19.06 ± 0.29 | 56.09 ± 0.90 | 0.21 ± 0.00 | 19.27 ± 0.29 | 56.23 ± 0.89 | 31185.99 ± 489.69 | 20.79 ± 0.24 | 1.00 | 732.56x ± 13.52 | 7479.77x | 444.05x ± 7.94 |
| SJF | 10.07 ± 0.15 | 54.01 ± 1.04 | 0.14 ± 0.00 | 10.21 ± 0.15 | 54.14 ± 1.04 | 32390.69 ± 620.17 | 16.03 ± 0.19 | 0.70 | 563.04x ± 10.92 | 4047.81x | 317.88x ± 6.25 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 217.50x | 79.29x | 584.71x | 118.39x |
| wl 1 | 1080.85x | 1010.16x | 1163.31x | 853.22x |
| wl 2 | 750.32x | 522.82x | 651.27x | 511.35x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 10.080 ms² | 0.486 ms² | 321.661 ms² | 0.940 ms² |
| wl 1 | 377.494 ms² | 300.485 ms² | 423.190 ms² | 243.170 ms² |
| wl 2 | 270.636 ms² | 199.847 ms² | 273.375 ms² | 218.660 ms² |
