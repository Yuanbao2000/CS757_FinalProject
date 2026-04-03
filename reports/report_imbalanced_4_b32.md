# GPU Scheduler Report
Group: imbalanced_4 | batch_size=32 | runs=10 (averaged)

Generated: 20260403_231718

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 17.524 | 53.282 | 0.196 | 17.720 | 53.406 | 32858.86 | 20.25 | 0.7500 | 852.68x | 8743.35x | 484.49x |
| Priority | 10.648 | 52.763 | 0.154 | 10.802 | 52.884 | 33175.62 | 16.98 | 0.6905 | 619.83x | 4146.64x | 351.63x |
| DependencyAware | 18.796 | 55.708 | 0.213 | 19.009 | 55.826 | 31416.21 | 21.20 | 0.9988 | 791.17x | 8271.27x | 482.78x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 17.52 ± 0.49 | 53.28 ± 1.72 | 0.20 ± 0.01 | 17.72 ± 0.50 | 53.41 ± 1.73 | 32858.86 ± 1075.08 | 20.25 ± 0.55 | 0.75 | 852.68x ± 32.25 | 8743.35x | 484.49x ± 18.36 |
| Priority | 10.65 ± 0.25 | 52.76 ± 1.53 | 0.15 ± 0.00 | 10.80 ± 0.26 | 52.88 ± 1.53 | 33175.62 ± 963.24 | 16.98 ± 0.35 | 0.69 | 619.83x ± 62.91 | 4146.64x | 351.63x ± 34.80 |
| DependencyAware | 18.80 ± 0.37 | 55.71 ± 1.21 | 0.21 ± 0.01 | 19.01 ± 0.37 | 55.83 ± 1.21 | 31416.21 ± 689.19 | 21.20 ± 0.40 | 1.00 | 791.17x ± 15.91 | 8271.27x | 482.78x ± 9.60 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 218.31x | 75.89x | 604.69x |
| wl 1 | 1182.51x | 1061.18x | 1238.20x |
| wl 2 | 795.07x | 540.04x | 707.10x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 8.652 ms² | 0.429 ms² | 318.739 ms² |
| wl 1 | 383.491 ms² | 316.413 ms² | 419.844 ms² |
| wl 2 | 276.362 ms² | 210.082 ms² | 271.448 ms² |
