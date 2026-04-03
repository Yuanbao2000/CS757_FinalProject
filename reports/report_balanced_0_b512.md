# GPU Scheduler Report
Group: balanced_0 | batch_size=512 | runs=10 (averaged)

Generated: 20260403_231819

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 9.647 | 42.611 | 0.296 | 9.944 | 42.732 | 26936.56 | 19.63 | 0.9884 | 278.82x | 7149.98x | 150.34x |
| Priority | 13.376 | 54.975 | 0.175 | 13.551 | 55.101 | 20889.14 | 8.56 | 0.9907 | 628.68x | 3332.17x | 349.52x |
| DependencyAware | 11.497 | 48.539 | 0.322 | 11.818 | 48.664 | 23655.07 | 18.20 | 0.9884 | 333.41x | 6828.79x | 187.36x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 9.65 ± 0.13 | 42.61 ± 0.26 | 0.30 ± 0.01 | 9.94 ± 0.13 | 42.73 ± 0.26 | 26936.56 ± 165.44 | 19.63 ± 0.46 | 0.99 | 278.82x ± 19.53 | 7149.98x | 150.34x ± 9.72 |
| Priority | 13.38 ± 0.06 | 54.97 ± 0.13 | 0.17 ± 0.00 | 13.55 ± 0.06 | 55.10 ± 0.13 | 20889.14 ± 49.02 | 8.56 ± 0.04 | 0.99 | 628.68x ± 9.26 | 3332.17x | 349.52x ± 5.09 |
| DependencyAware | 11.50 ± 0.28 | 48.54 ± 0.56 | 0.32 ± 0.00 | 11.82 ± 0.28 | 48.66 ± 0.56 | 23655.07 ± 268.99 | 18.20 ± 0.45 | 0.99 | 333.41x ± 9.39 | 6828.79x | 187.36x ± 5.66 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 334.45x | 713.04x | 408.01x |
| wl 1 | 396.40x | 1043.76x | 509.88x |
| wl 2 | 190.17x | 376.70x | 205.19x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 160.473 ms² | 273.136 ms² | 209.687 ms² |
| wl 1 | 196.345 ms² | 324.615 ms² | 247.458 ms² |
| wl 2 | 53.145 ms² | 97.792 ms² | 74.661 ms² |
