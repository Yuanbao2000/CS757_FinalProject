# GPU Scheduler Group Report
Group: balanced_1 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022208

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.011 | 0.038 | 0.008 | 0.019 | 0.381 | 3155167.25 | 100.00 | 0.9811 | 2.33x | 6.19x | 4.52x |
| fanin_priority | 0.009 | 0.192 | 0.008 | 0.017 | 0.364 | 3287940.50 | 100.00 | 0.9954 | 2.17x | 28.74x | 3.33x |
| DependencyAware | 0.019 | 0.167 | 0.009 | 0.028 | 0.416 | 2932117.50 | 100.00 | 0.9893 | 3.30x | 24.42x | 6.48x |
| SJF | 0.012 | 0.160 | 0.009 | 0.021 | 0.418 | 2924831.00 | 100.00 | 0.9811 | 2.29x | 22.63x | 4.90x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.01 ± 0.00 | 0.04 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.38 ± 0.04 | 3155167.25 ± 322738.12 | 100.00 ± 0.00 | 0.98 ± 0.01 | 2.33x ± 0.03 | 6.19x ± 0.55 | 4.52x ± 0.07 |
| fanin_priority | 0.01 ± 0.00 | 0.19 ± 0.02 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.36 ± 0.03 | 3287940.50 ± 252117.48 | 100.00 ± 0.00 | 1.00 ± 0.00 | 2.17x ± 0.11 | 28.74x ± 2.24 | 3.33x ± 0.12 |
| DependencyAware | 0.02 ± 0.00 | 0.17 ± 0.03 | 0.01 ± 0.00 | 0.03 ± 0.00 | 0.42 ± 0.07 | 2932117.50 ± 456416.75 | 100.00 ± 0.00 | 0.99 ± 0.01 | 3.30x ± 0.19 | 24.42x ± 5.64 | 6.48x ± 0.39 |
| SJF | 0.01 ± 0.00 | 0.16 ± 0.06 | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.42 ± 0.08 | 2924831.00 ± 460714.28 | 100.00 ± 0.00 | 0.98 ± 0.01 | 2.29x ± 0.06 | 22.63x ± 5.50 | 4.90x ± 0.18 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 2.08x | 3.88x | 2.61x | 1.93x |
| wl 1 | 2.25x | 3.21x | 3.17x | 2.08x |
| wl 2 | 2.41x | 1.43x | 3.50x | 2.44x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.013 ms² | 0.010 ms² | 0.015 ms² | 0.022 ms² |
| wl 1 | 0.010 ms² | 0.006 ms² | 0.012 ms² | 0.011 ms² |
| wl 2 | 0.007 ms² | 0.006 ms² | 0.010 ms² | 0.010 ms² |
