# GPU Scheduler Report
Group: balanced_1 | batch_size=512 | runs=10 (averaged)

Generated: 20260403_231825

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 14.273 | 50.625 | 0.354 | 14.627 | 50.752 | 23429.66 | 16.54 | 0.9845 | 552.67x | 6745.45x | 291.93x |
| Priority | 15.601 | 55.287 | 0.269 | 15.869 | 55.412 | 21459.34 | 11.34 | 0.9809 | 735.55x | 3565.89x | 385.86x |
| DependencyAware | 13.905 | 49.170 | 0.341 | 14.246 | 49.295 | 24123.75 | 16.09 | 0.9856 | 536.61x | 6948.82x | 295.43x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 14.27 ± 0.12 | 50.62 ± 0.50 | 0.35 ± 0.00 | 14.63 ± 0.12 | 50.75 ± 0.49 | 23429.66 ± 226.10 | 16.54 ± 0.27 | 0.98 | 552.67x ± 58.27 | 6745.45x | 291.93x ± 28.44 |
| Priority | 15.60 ± 0.15 | 55.29 ± 0.55 | 0.27 ± 0.00 | 15.87 ± 0.15 | 55.41 ± 0.55 | 21459.34 ± 206.22 | 11.34 ± 0.09 | 0.98 | 735.55x ± 25.70 | 3565.89x | 385.86x ± 13.97 |
| DependencyAware | 13.91 ± 0.22 | 49.17 ± 0.62 | 0.34 ± 0.00 | 14.25 ± 0.22 | 49.30 ± 0.62 | 24123.75 ± 299.09 | 16.09 ± 0.37 | 0.99 | 536.61x ± 10.37 | 6948.82x | 295.43x ± 6.45 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 624.55x | 673.78x | 570.40x |
| wl 1 | 616.35x | 870.67x | 540.02x |
| wl 2 | 515.21x | 705.79x | 527.66x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 337.615 ms² | 403.935 ms² | 323.055 ms² |
| wl 1 | 239.073 ms² | 268.239 ms² | 218.136 ms² |
| wl 2 | 247.057 ms² | 285.417 ms² | 232.380 ms² |
