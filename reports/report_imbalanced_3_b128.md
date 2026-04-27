# GPU Scheduler Report
Group: imbalanced_3 | batch_size=128 | runs=10 (averaged)

Generated: 20260408_184326

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 16.801 | 58.888 | 0.374 | 17.176 | 59.014 | 27249.50 | 15.63 | 0.9976 | 593.70x | 7480.79x | 319.98x |
| Priority | 19.321 | 69.054 | 0.265 | 19.586 | 69.187 | 23230.50 | 9.27 | 0.9984 | 911.04x | 4175.12x | 481.02x |
| DependencyAware | 18.232 | 60.859 | 0.390 | 18.621 | 61.008 | 26348.77 | 14.73 | 0.9967 | 641.89x | 7334.99x | 346.10x |
| SJF | 18.970 | 67.988 | 0.263 | 19.233 | 68.114 | 23594.78 | 8.81 | 0.9984 | 905.94x | 4137.55x | 479.28x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 16.80 ± 0.64 | 58.89 ± 1.57 | 0.37 ± 0.00 | 17.18 ± 0.64 | 59.01 ± 1.57 | 27249.50 ± 709.75 | 15.63 ± 0.63 | 1.00 | 593.70x ± 66.75 | 7480.79x | 319.98x ± 35.28 |
| Priority | 19.32 ± 0.29 | 69.05 ± 0.86 | 0.27 ± 0.00 | 19.59 ± 0.29 | 69.19 ± 0.86 | 23230.50 ± 291.00 | 9.27 ± 0.12 | 1.00 | 911.04x ± 20.32 | 4175.12x | 481.02x ± 10.75 |
| DependencyAware | 18.23 ± 0.36 | 60.86 ± 1.04 | 0.39 ± 0.00 | 18.62 ± 0.37 | 61.01 ± 1.04 | 26348.77 ± 456.55 | 14.73 ± 0.22 | 1.00 | 641.89x ± 12.89 | 7334.99x | 346.10x ± 7.45 |
| SJF | 18.97 ± 0.25 | 67.99 ± 0.63 | 0.26 ± 0.00 | 19.23 ± 0.25 | 68.11 ± 0.62 | 23594.78 ± 216.02 | 8.81 ± 0.10 | 1.00 | 905.94x ± 15.32 | 4137.55x | 479.28x ± 8.13 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 858.66x | 1389.05x | 896.83x | 1449.39x |
| wl 1 | 283.54x | 485.52x | 393.69x | 519.28x |
| wl 2 | 725.73x | 1050.16x | 731.80x | 992.32x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 420.040 ms² | 609.405 ms² | 450.987 ms² | 636.581 ms² |
| wl 1 | 143.667 ms² | 235.243 ms² | 140.134 ms² | 235.220 ms² |
| wl 2 | 366.327 ms² | 484.655 ms² | 355.182 ms² | 453.923 ms² |
