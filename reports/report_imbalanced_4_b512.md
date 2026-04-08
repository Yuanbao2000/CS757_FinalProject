# GPU Scheduler Report
Group: imbalanced_4 | batch_size=512 | runs=10 (averaged)

Generated: 20260408_184436

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 9.915 | 38.191 | 0.227 | 10.142 | 38.330 | 45847.13 | 14.67 | 0.7138 | 345.77x | 5819.85x | 196.83x |
| Priority | 14.339 | 51.758 | 0.137 | 14.476 | 51.902 | 33785.86 | 6.28 | 0.7156 | 653.61x | 3055.37x | 364.37x |
| DependencyAware | 11.138 | 41.175 | 0.236 | 11.374 | 41.316 | 42456.82 | 13.83 | 0.7301 | 403.49x | 6005.12x | 238.31x |
| SJF | 14.368 | 51.878 | 0.136 | 14.504 | 52.020 | 33710.88 | 6.19 | 0.7155 | 710.13x | 3173.48x | 394.51x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 9.91 ± 0.56 | 38.19 ± 1.88 | 0.23 ± 0.01 | 10.14 ± 0.56 | 38.33 ± 1.88 | 45847.13 ± 2314.88 | 14.67 ± 0.68 | 0.71 | 345.77x ± 33.04 | 5819.85x | 196.83x ± 18.47 |
| Priority | 14.34 ± 0.25 | 51.76 ± 0.92 | 0.14 ± 0.00 | 14.48 ± 0.25 | 51.90 ± 0.91 | 33785.86 ± 620.47 | 6.28 ± 0.18 | 0.72 | 653.61x ± 97.93 | 3055.37x | 364.37x ± 52.90 |
| DependencyAware | 11.14 ± 0.32 | 41.17 ± 1.03 | 0.24 ± 0.00 | 11.37 ± 0.32 | 41.32 ± 1.04 | 42456.82 ± 1117.10 | 13.83 ± 0.26 | 0.73 | 403.49x ± 16.65 | 6005.12x | 238.31x ± 10.37 |
| SJF | 14.37 ± 0.26 | 51.88 ± 0.96 | 0.14 ± 0.00 | 14.50 ± 0.26 | 52.02 ± 0.96 | 33710.88 ± 654.77 | 6.19 ± 0.02 | 0.72 | 710.13x ± 18.87 | 3173.48x | 394.51x ± 10.32 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 34.27x | 85.98x | 93.71x | 90.19x |
| wl 1 | 553.47x | 1000.54x | 609.95x | 1076.14x |
| wl 2 | 308.71x | 592.13x | 366.65x | 645.46x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.465 ms² | 3.303 ms² | 3.564 ms² | 3.313 ms² |
| wl 1 | 189.385 ms² | 368.883 ms² | 209.500 ms² | 371.051 ms² |
| wl 2 | 128.078 ms² | 254.114 ms² | 141.275 ms² | 255.664 ms² |
