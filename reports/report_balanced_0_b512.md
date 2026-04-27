# GPU Scheduler Report
Group: balanced_0 | batch_size=512 | runs=10 (averaged)

Generated: 20260408_184403

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 9.962 | 42.929 | 0.302 | 10.263 | 43.057 | 26741.16 | 19.66 | 0.9884 | 268.26x | 6807.07x | 147.74x |
| Priority | 13.323 | 54.731 | 0.175 | 13.498 | 54.867 | 20978.48 | 8.59 | 0.9904 | 612.34x | 3190.98x | 341.39x |
| DependencyAware | 11.121 | 47.843 | 0.322 | 11.443 | 47.976 | 23993.57 | 18.66 | 0.9878 | 313.37x | 6501.59x | 176.20x |
| SJF | 13.384 | 55.165 | 0.175 | 13.560 | 55.306 | 20815.62 | 8.58 | 0.9901 | 609.24x | 3193.10x | 338.99x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 9.96 ± 0.33 | 42.93 ± 0.80 | 0.30 ± 0.01 | 10.26 ± 0.33 | 43.06 ± 0.80 | 26741.16 ± 498.64 | 19.66 ± 0.37 | 0.99 | 268.26x ± 26.66 | 6807.07x | 147.74x ± 12.55 |
| Priority | 13.32 ± 0.06 | 54.73 ± 0.24 | 0.17 ± 0.00 | 13.50 ± 0.06 | 54.87 ± 0.23 | 20978.48 ± 89.49 | 8.59 ± 0.04 | 0.99 | 612.34x ± 16.50 | 3190.98x | 341.39x ± 9.37 |
| DependencyAware | 11.12 ± 0.25 | 47.84 ± 0.46 | 0.32 ± 0.00 | 11.44 ± 0.25 | 47.98 ± 0.47 | 23993.57 ± 233.56 | 18.66 ± 0.46 | 0.99 | 313.37x ± 20.45 | 6501.59x | 176.20x ± 12.10 |
| SJF | 13.38 ± 0.21 | 55.16 ± 0.78 | 0.18 ± 0.00 | 13.56 ± 0.21 | 55.31 ± 0.78 | 20815.62 ± 291.61 | 8.58 ± 0.10 | 0.99 | 609.24x ± 28.04 | 3193.10x | 338.99x ± 15.25 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 329.06x | 700.79x | 386.63x | 695.16x |
| wl 1 | 372.60x | 1026.38x | 478.33x | 1023.04x |
| wl 2 | 183.36x | 358.64x | 191.60x | 357.03x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 164.449 ms² | 269.783 ms² | 200.428 ms² | 272.545 ms² |
| wl 1 | 199.849 ms² | 320.176 ms² | 237.615 ms² | 323.221 ms² |
| wl 2 | 57.445 ms² | 97.054 ms² | 69.135 ms² | 98.093 ms² |
