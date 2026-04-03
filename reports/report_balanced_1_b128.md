# GPU Scheduler Report
Group: balanced_1 | batch_size=128 | runs=10 (averaged)

Generated: 20260403_231743

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 14.101 | 50.051 | 0.349 | 14.450 | 50.175 | 23704.36 | 16.27 | 0.9843 | 531.82x | 6898.08x | 284.01x |
| Priority | 15.578 | 55.095 | 0.268 | 15.845 | 55.214 | 21535.59 | 11.09 | 0.9810 | 746.04x | 3503.17x | 392.48x |
| DependencyAware | 13.653 | 48.156 | 0.339 | 13.991 | 48.276 | 24643.87 | 16.61 | 0.9843 | 530.80x | 6604.47x | 291.57x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 14.10 ± 0.33 | 50.05 ± 0.86 | 0.35 ± 0.00 | 14.45 ± 0.33 | 50.17 ± 0.87 | 23704.36 ± 411.21 | 16.27 ± 0.40 | 0.98 | 531.82x ± 47.15 | 6898.08x | 284.01x ± 23.62 |
| Priority | 15.58 ± 0.06 | 55.10 ± 0.42 | 0.27 ± 0.00 | 15.85 ± 0.06 | 55.21 ± 0.42 | 21535.59 ± 162.27 | 11.09 ± 0.06 | 0.98 | 746.04x ± 23.89 | 3503.17x | 392.48x ± 12.17 |
| DependencyAware | 13.65 ± 0.43 | 48.16 ± 1.19 | 0.34 ± 0.00 | 13.99 ± 0.43 | 48.28 ± 1.19 | 24643.87 ± 598.73 | 16.61 ± 0.65 | 0.98 | 530.80x ± 32.24 | 6604.47x | 291.57x ± 16.43 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 587.21x | 691.44x | 554.50x |
| wl 1 | 582.10x | 893.50x | 538.74x |
| wl 2 | 502.57x | 710.58x | 522.70x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 329.308 ms² | 400.870 ms² | 306.098 ms² |
| wl 1 | 233.113 ms² | 266.334 ms² | 202.551 ms² |
| wl 2 | 240.568 ms² | 282.378 ms² | 219.378 ms² |
