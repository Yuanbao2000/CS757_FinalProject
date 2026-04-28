# GPU Scheduler Report
Group: imbalanced_4 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_024242

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.494 | 5.620 | 0.028 | 1.522 | 5.749 | 307745.91 | 11.60 | 0.7673 | 88.80x | 422.49x | 49.54x |
| Priority | 1.723 | 6.279 | 0.029 | 1.752 | 6.414 | 285836.34 | 10.98 | 0.7476 | 91.69x | 406.95x | 50.88x |
| DependencyAware | 1.628 | 5.977 | 0.030 | 1.658 | 6.110 | 293551.38 | 11.47 | 0.7569 | 85.41x | 388.73x | 48.14x |
| SJF | 1.518 | 5.752 | 0.029 | 1.547 | 5.890 | 300280.44 | 11.64 | 0.7533 | 85.82x | 390.18x | 47.70x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 1.49 ± 0.24 | 5.62 ± 0.59 | 0.03 ± 0.00 | 1.52 ± 0.24 | 5.75 ± 0.60 | 307745.91 ± 26906.20 | 11.60 ± 0.80 | 0.77 | 88.80x ± 16.74 | 422.49x | 49.54x ± 8.89 |
| Priority | 1.72 ± 0.65 | 6.28 ± 1.68 | 0.03 ± 0.00 | 1.75 ± 0.65 | 6.41 ± 1.70 | 285836.34 ± 48002.87 | 10.98 ± 1.64 | 0.75 | 91.69x ± 19.60 | 406.95x | 50.88x ± 10.42 |
| DependencyAware | 1.63 ± 0.37 | 5.98 ± 1.02 | 0.03 ± 0.00 | 1.66 ± 0.38 | 6.11 ± 1.04 | 293551.38 ± 39291.35 | 11.47 ± 0.76 | 0.76 | 85.41x ± 5.94 | 388.73x | 48.14x ± 3.23 |
| SJF | 1.52 ± 0.18 | 5.75 ± 0.60 | 0.03 ± 0.00 | 1.55 ± 0.19 | 5.89 ± 0.61 | 300280.44 ± 25322.71 | 11.64 ± 0.22 | 0.75 | 85.82x ± 4.49 | 390.18x | 47.70x ± 2.52 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 10.29x | 18.24x | 20.43x | 18.77x |
| wl 1 | 117.70x | 128.75x | 115.13x | 121.57x |
| wl 2 | 83.96x | 85.24x | 80.28x | 79.56x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.116 ms² | 0.083 ms² | 0.128 ms² | 0.088 ms² |
| wl 1 | 3.114 ms² | 4.664 ms² | 3.683 ms² | 3.353 ms² |
| wl 2 | 1.978 ms² | 3.197 ms² | 2.384 ms² | 2.151 ms² |
