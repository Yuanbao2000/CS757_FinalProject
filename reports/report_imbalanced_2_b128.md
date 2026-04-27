# GPU Scheduler Report
Group: imbalanced_2 | batch_size=128 | runs=10 (averaged)

Generated: 20260408_184315

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 7.529 | 36.967 | 0.304 | 7.833 | 37.102 | 19758.53 | 22.45 | 0.9400 | 250.97x | 2272.91x | 141.71x |
| Priority | 8.409 | 39.838 | 0.202 | 8.612 | 39.975 | 18336.57 | 14.45 | 0.9391 | 370.41x | 2362.57x | 211.63x |
| DependencyAware | 7.997 | 36.986 | 0.295 | 8.291 | 37.117 | 19758.39 | 23.67 | 0.9430 | 270.44x | 2540.02x | 151.54x |
| SJF | 8.430 | 39.932 | 0.203 | 8.633 | 40.058 | 18298.67 | 14.43 | 0.9396 | 374.06x | 2439.17x | 213.89x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 7.53 ± 0.09 | 36.97 ± 0.36 | 0.30 ± 0.00 | 7.83 ± 0.09 | 37.10 ± 0.37 | 19758.53 ± 194.59 | 22.45 ± 0.32 | 0.94 | 250.97x ± 25.42 | 2272.91x | 141.71x ± 12.92 |
| Priority | 8.41 ± 0.03 | 39.84 ± 0.14 | 0.20 ± 0.00 | 8.61 ± 0.03 | 39.98 ± 0.14 | 18336.57 ± 63.79 | 14.45 ± 0.04 | 0.94 | 370.41x ± 2.83 | 2362.57x | 211.63x ± 2.32 |
| DependencyAware | 8.00 ± 0.11 | 36.99 ± 0.83 | 0.29 ± 0.00 | 8.29 ± 0.11 | 37.12 ± 0.83 | 19758.39 ± 442.68 | 23.67 ± 0.49 | 0.94 | 270.44x ± 6.00 | 2540.02x | 151.54x ± 4.01 |
| SJF | 8.43 ± 0.04 | 39.93 ± 0.10 | 0.20 ± 0.00 | 8.63 ± 0.04 | 40.06 ± 0.11 | 18298.67 ± 51.57 | 14.43 ± 0.04 | 0.94 | 374.06x ± 5.63 | 2439.17x | 213.89x ± 3.33 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 345.03x | 476.27x | 303.61x | 483.06x |
| wl 1 | 269.99x | 390.25x | 278.00x | 390.03x |
| wl 2 | 181.30x | 293.29x | 245.17x | 298.26x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 151.322 ms² | 183.574 ms² | 145.508 ms² | 185.180 ms² |
| wl 1 | 58.599 ms² | 59.148 ms² | 56.415 ms² | 59.617 ms² |
| wl 2 | 85.194 ms² | 90.271 ms² | 97.614 ms² | 90.779 ms² |
