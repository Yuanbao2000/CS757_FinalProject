# GPU Scheduler Report
Group: balanced_0 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_023942

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 4.887 | 13.128 | 0.037 | 4.924 | 13.254 | 111487.11 | 14.25 | 0.9941 | 379.38x | 1603.88x | 218.77x |
| Priority | 3.163 | 10.057 | 0.036 | 3.199 | 10.164 | 128223.35 | 17.39 | 0.9970 | 199.98x | 815.86x | 109.97x |
| DependencyAware | 3.929 | 10.733 | 0.036 | 3.965 | 10.856 | 111257.70 | 13.94 | 0.9892 | 236.79x | 930.21x | 141.75x |
| SJF | 2.864 | 9.476 | 0.034 | 2.898 | 9.577 | 121593.46 | 18.10 | 0.9836 | 188.66x | 815.54x | 103.21x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 4.89 ± 4.75 | 13.13 ± 10.94 | 0.04 ± 0.01 | 4.92 ± 4.76 | 13.25 ± 10.96 | 111487.11 ± 31194.31 | 14.25 ± 3.10 | 0.99 | 379.38x ± 493.54 | 1603.88x | 218.77x ± 292.48 |
| Priority | 3.16 ± 1.07 | 10.06 ± 4.83 | 0.04 ± 0.01 | 3.20 ± 1.07 | 10.16 ± 4.84 | 128223.35 ± 33493.36 | 17.39 ± 3.31 | 1.00 | 199.98x ± 62.13 | 815.86x | 109.97x ± 34.18 |
| DependencyAware | 3.93 ± 0.85 | 10.73 ± 2.72 | 0.04 ± 0.01 | 3.96 ± 0.85 | 10.86 ± 2.73 | 111257.70 ± 21148.49 | 13.94 ± 0.89 | 0.99 | 236.79x ± 16.85 | 930.21x | 141.75x ± 10.04 |
| SJF | 2.86 ± 0.43 | 9.48 ± 1.07 | 0.03 ± 0.00 | 2.90 ± 0.43 | 9.58 ± 1.09 | 121593.46 ± 12430.90 | 18.10 ± 0.63 | 0.98 | 188.66x ± 22.76 | 815.54x | 103.21x ± 12.20 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 380.51x | 216.91x | 240.64x | 244.59x |
| wl 1 | 516.87x | 274.49x | 312.45x | 221.61x |
| wl 2 | 310.52x | 153.78x | 197.13x | 141.85x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 20.841 ms² | 10.620 ms² | 7.819 ms² | 7.710 ms² |
| wl 1 | 19.337 ms² | 11.888 ms² | 11.733 ms² | 2.739 ms² |
| wl 2 | 6.131 ms² | 6.948 ms² | 4.778 ms² | 3.162 ms² |
