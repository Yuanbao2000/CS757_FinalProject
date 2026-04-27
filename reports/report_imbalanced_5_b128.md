# GPU Scheduler Report
Group: imbalanced_5 | batch_size=128 | runs=10 (averaged)

Generated: 20260408_184356

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 17.462 | 65.604 | 0.342 | 17.804 | 65.741 | 36526.48 | 14.82 | 0.9997 | 643.88x | 8545.18x | 352.73x |
| Priority | 13.648 | 71.203 | 0.264 | 13.912 | 71.337 | 33645.79 | 12.48 | 0.9960 | 636.58x | 4301.25x | 338.47x |
| DependencyAware | 15.976 | 61.334 | 0.340 | 16.316 | 61.467 | 39058.09 | 15.97 | 0.9993 | 524.53x | 8886.88x | 307.42x |
| SJF | 13.726 | 71.415 | 0.270 | 13.996 | 71.548 | 33546.73 | 12.60 | 0.9941 | 647.53x | 4290.37x | 346.44x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 17.46 ± 0.51 | 65.60 ± 1.55 | 0.34 ± 0.01 | 17.80 ± 0.52 | 65.74 ± 1.55 | 36526.48 ± 832.90 | 14.82 ± 0.36 | 1.00 | 643.88x ± 84.70 | 8545.18x | 352.73x ± 44.91 |
| Priority | 13.65 ± 0.20 | 71.20 ± 0.66 | 0.26 ± 0.00 | 13.91 ± 0.20 | 71.34 ± 0.66 | 33645.79 ± 309.83 | 12.48 ± 0.19 | 1.00 | 636.58x ± 14.97 | 4301.25x | 338.47x ± 7.81 |
| DependencyAware | 15.98 ± 0.33 | 61.33 ± 1.10 | 0.34 ± 0.00 | 16.32 ± 0.33 | 61.47 ± 1.09 | 39058.09 ± 709.13 | 15.97 ± 0.38 | 1.00 | 524.53x ± 21.76 | 8886.88x | 307.42x ± 13.95 |
| SJF | 13.73 ± 0.27 | 71.41 ± 0.63 | 0.27 ± 0.00 | 14.00 ± 0.27 | 71.55 ± 0.63 | 33546.73 ± 293.75 | 12.60 ± 0.28 | 0.99 | 647.53x ± 16.42 | 4290.37x | 346.44x ± 8.57 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 734.47x | 1263.40x | 640.29x | 1246.06x |
| wl 1 | 641.91x | 766.45x | 589.62x | 713.92x |
| wl 2 | 633.94x | 492.72x | 476.49x | 540.27x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 601.240 ms² | 761.661 ms² | 493.887 ms² | 752.639 ms² |
| wl 1 | 415.372 ms² | 473.264 ms² | 337.706 ms² | 441.943 ms² |
| wl 2 | 348.388 ms² | 283.545 ms² | 241.886 ms² | 302.979 ms² |
