# GPU Scheduler Report
Group: imbalanced_4 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_024019

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 4.635 | 11.038 | 0.027 | 4.662 | 11.149 | 160670.09 | 13.62 | 0.8424 | 341.96x | 1297.88x | 190.85x |
| Priority | 3.589 | 9.106 | 0.026 | 3.615 | 9.226 | 192156.88 | 16.35 | 0.7944 | 264.26x | 857.94x | 143.57x |
| DependencyAware | 4.782 | 11.411 | 0.027 | 4.809 | 11.534 | 153620.75 | 13.16 | 0.9982 | 328.99x | 1170.55x | 192.65x |
| SJF | 3.909 | 10.020 | 0.027 | 3.936 | 10.156 | 175858.77 | 16.63 | 0.8423 | 268.98x | 906.13x | 145.37x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 4.64 ± 0.71 | 11.04 ± 1.87 | 0.03 ± 0.00 | 4.66 ± 0.71 | 11.15 ± 1.87 | 160670.09 ± 20534.90 | 13.62 ± 0.88 | 0.84 | 341.96x ± 59.22 | 1297.88x | 190.85x ± 32.61 |
| Priority | 3.59 ± 0.33 | 9.11 ± 1.11 | 0.03 ± 0.00 | 3.61 ± 0.34 | 9.23 ± 1.12 | 192156.88 ± 17772.07 | 16.35 ± 0.37 | 0.79 | 264.26x ± 10.33 | 857.94x | 143.57x ± 5.76 |
| DependencyAware | 4.78 ± 0.46 | 11.41 ± 1.28 | 0.03 ± 0.00 | 4.81 ± 0.47 | 11.53 ± 1.29 | 153620.75 ± 14730.27 | 13.16 ± 0.23 | 1.00 | 328.99x ± 20.49 | 1170.55x | 192.65x ± 12.18 |
| SJF | 3.91 ± 0.76 | 10.02 ± 1.53 | 0.03 ± 0.00 | 3.94 ± 0.77 | 10.16 ± 1.52 | 175858.77 ± 21719.52 | 16.63 ± 0.35 | 0.84 | 268.98x ± 16.05 | 906.13x | 145.37x ± 8.21 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 98.21x | 90.55x | 183.39x | 141.63x |
| wl 1 | 420.80x | 337.03x | 403.52x | 338.32x |
| wl 2 | 329.01x | 251.86x | 315.99x | 256.82x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.624 ms² | 0.426 ms² | 12.179 ms² | 1.169 ms² |
| wl 1 | 14.076 ms² | 6.544 ms² | 15.604 ms² | 6.022 ms² |
| wl 2 | 9.748 ms² | 5.270 ms² | 10.028 ms² | 6.632 ms² |
