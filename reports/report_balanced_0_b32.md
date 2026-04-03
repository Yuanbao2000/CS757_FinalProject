# GPU Scheduler Report
Group: balanced_0 | batch_size=32 | runs=10 (averaged)

Generated: 20260403_231654

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 15.451 | 54.176 | 0.300 | 15.751 | 54.300 | 21750.60 | 23.29 | 0.9951 | 600.05x | 8853.71x | 335.46x |
| Priority | 11.592 | 53.246 | 0.224 | 11.817 | 53.365 | 21757.22 | 19.08 | 0.9989 | 619.05x | 3830.86x | 339.70x |
| DependencyAware | 17.653 | 54.251 | 0.321 | 17.975 | 54.376 | 21172.45 | 23.47 | 0.9938 | 672.88x | 7283.14x | 405.83x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 15.45 ± 4.62 | 54.18 ± 10.70 | 0.30 ± 0.02 | 15.75 ± 4.63 | 54.30 ± 10.69 | 21750.60 ± 2811.94 | 23.29 ± 2.44 | 1.00 | 600.05x ± 241.48 | 8853.71x | 335.46x ± 146.46 |
| Priority | 11.59 ± 1.18 | 53.25 ± 5.62 | 0.22 ± 0.01 | 11.82 ± 1.18 | 53.36 ± 5.62 | 21757.22 ± 1791.84 | 19.08 ± 1.49 | 1.00 | 619.05x ± 109.82 | 3830.86x | 339.70x ± 59.51 |
| DependencyAware | 17.65 ± 0.44 | 54.25 ± 0.85 | 0.32 ± 0.00 | 17.97 ± 0.44 | 54.38 ± 0.85 | 21172.45 ± 331.86 | 23.47 ± 0.39 | 0.99 | 672.88x ± 68.84 | 7283.14x | 405.83x ± 36.48 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 635.28x | 715.93x | 576.32x |
| wl 1 | 824.91x | 897.57x | 1032.14x |
| wl 2 | 469.25x | 428.03x | 547.09x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 273.032 ms² | 247.155 ms² | 229.234 ms² |
| wl 1 | 303.651 ms² | 234.672 ms² | 348.614 ms² |
| wl 2 | 110.691 ms² | 117.386 ms² | 156.131 ms² |
