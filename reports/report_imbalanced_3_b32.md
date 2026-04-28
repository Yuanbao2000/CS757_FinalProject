# GPU Scheduler Report
Group: imbalanced_3 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_024007

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 4.676 | 12.189 | 0.033 | 4.710 | 12.302 | 132918.64 | 15.81 | 0.9915 | 324.54x | 1354.75x | 171.34x |
| Priority | 3.571 | 9.808 | 0.032 | 3.603 | 9.908 | 163969.62 | 17.98 | 0.9991 | 246.81x | 881.37x | 128.56x |
| DependencyAware | 4.763 | 12.198 | 0.033 | 4.796 | 12.300 | 133136.05 | 15.24 | 0.9941 | 315.48x | 1189.31x | 175.41x |
| SJF | 3.867 | 11.098 | 0.034 | 3.901 | 11.227 | 148607.94 | 17.73 | 0.9975 | 251.80x | 935.47x | 131.14x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 4.68 ± 0.66 | 12.19 ± 1.80 | 0.03 ± 0.00 | 4.71 ± 0.67 | 12.30 ± 1.80 | 132918.64 ± 15745.73 | 15.81 ± 0.63 | 0.99 | 324.54x ± 29.78 | 1354.75x | 171.34x ± 15.06 |
| Priority | 3.57 ± 0.46 | 9.81 ± 1.17 | 0.03 ± 0.00 | 3.60 ± 0.47 | 9.91 ± 1.18 | 163969.62 ± 15008.32 | 17.98 ± 0.24 | 1.00 | 246.81x ± 6.60 | 881.37x | 128.56x ± 3.30 |
| DependencyAware | 4.76 ± 0.83 | 12.20 ± 1.85 | 0.03 ± 0.00 | 4.80 ± 0.83 | 12.30 ± 1.87 | 133136.05 ± 16416.86 | 15.24 ± 0.49 | 0.99 | 315.48x ± 17.60 | 1189.31x | 175.41x ± 9.61 |
| SJF | 3.87 ± 0.99 | 11.10 ± 2.47 | 0.03 ± 0.01 | 3.90 ± 0.99 | 11.23 ± 2.48 | 148607.94 ± 24824.79 | 17.73 ± 0.91 | 1.00 | 251.80x ± 19.99 | 935.47x | 131.14x ± 9.55 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 378.34x | 275.25x | 429.66x | 299.81x |
| wl 1 | 201.05x | 222.01x | 236.31x | 219.94x |
| wl 2 | 396.07x | 254.70x | 332.11x | 257.73x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 13.841 ms² | 6.465 ms² | 14.987 ms² | 8.474 ms² |
| wl 1 | 6.605 ms² | 7.826 ms² | 8.417 ms² | 9.810 ms² |
| wl 2 | 9.288 ms² | 5.682 ms² | 10.941 ms² | 7.893 ms² |
