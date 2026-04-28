# GPU Scheduler Report
Group: balanced_1 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_023950

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 3.191 | 9.034 | 0.032 | 3.223 | 9.129 | 130287.41 | 16.14 | 0.9801 | 245.96x | 1145.46x | 128.93x |
| Priority | 2.810 | 8.487 | 0.031 | 2.841 | 8.579 | 138667.22 | 17.69 | 0.9734 | 209.78x | 849.39x | 107.42x |
| DependencyAware | 3.214 | 8.994 | 0.032 | 3.246 | 9.085 | 130960.27 | 15.96 | 0.9882 | 237.83x | 893.30x | 127.50x |
| SJF | 2.734 | 8.416 | 0.032 | 2.766 | 8.524 | 139625.39 | 19.39 | 0.9532 | 199.83x | 859.56x | 101.65x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 3.19 ± 0.08 | 9.03 ± 0.19 | 0.03 ± 0.00 | 3.22 ± 0.08 | 9.13 ± 0.18 | 130287.41 ± 2519.63 | 16.14 ± 0.48 | 0.98 | 245.96x ± 31.90 | 1145.46x | 128.93x ± 16.43 |
| Priority | 2.81 ± 0.12 | 8.49 ± 0.19 | 0.03 ± 0.00 | 2.84 ± 0.12 | 8.58 ± 0.20 | 138667.22 ± 3186.83 | 17.69 ± 0.24 | 0.97 | 209.78x ± 8.40 | 849.39x | 107.42x ± 4.15 |
| DependencyAware | 3.21 ± 0.10 | 8.99 ± 0.24 | 0.03 ± 0.00 | 3.25 ± 0.10 | 9.09 ± 0.24 | 130960.27 ± 3361.44 | 15.96 ± 0.26 | 0.99 | 237.83x ± 6.07 | 893.30x | 127.50x ± 3.06 |
| SJF | 2.73 ± 0.10 | 8.42 ± 0.27 | 0.03 ± 0.00 | 2.77 ± 0.10 | 8.52 ± 0.27 | 139625.39 ± 4331.76 | 19.39 ± 0.37 | 0.95 | 199.83x ± 8.16 | 859.56x | 101.65x ± 4.25 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 220.45x | 251.36x | 237.05x | 240.81x |
| wl 1 | 249.84x | 220.93x | 288.45x | 186.12x |
| wl 2 | 250.61x | 196.50x | 221.49x | 194.80x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 7.995 ms² | 8.804 ms² | 7.957 ms² | 8.265 ms² |
| wl 1 | 5.979 ms² | 3.684 ms² | 5.996 ms² | 2.766 ms² |
| wl 2 | 5.234 ms² | 3.815 ms² | 5.307 ms² | 3.847 ms² |
