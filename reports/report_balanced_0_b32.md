# GPU Scheduler Group Report
Group: balanced_0 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025422

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.016 | 0.063 | 0.008 | 0.025 | 0.344 | 3381677.25 | 100.00 | 0.9972 | 3.07x | 10.44x | 5.08x |
| fanin_priority | 0.014 | 0.235 | 0.009 | 0.023 | 0.366 | 3216485.75 | 100.00 | 0.9933 | 2.74x | 29.05x | 3.60x |
| DependencyAware | 0.029 | 0.194 | 0.009 | 0.039 | 0.372 | 3183825.50 | 100.00 | 0.9954 | 4.37x | 27.76x | 6.60x |
| SJF | 0.016 | 0.146 | 0.009 | 0.025 | 0.397 | 2961636.00 | 100.00 | 0.9959 | 2.79x | 19.66x | 5.12x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.02 ± 0.00 | 0.06 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.34 ± 0.03 | 3381677.25 ± 319437.00 | 100.00 ± 0.00 | 1.00 ± 0.00 | 3.07x ± 0.05 | 10.44x ± 0.84 | 5.08x ± 0.09 |
| fanin_priority | 0.01 ± 0.00 | 0.23 ± 0.05 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.37 ± 0.06 | 3216485.75 ± 433945.25 | 100.00 ± 0.00 | 0.99 ± 0.00 | 2.74x ± 0.17 | 29.05x ± 6.30 | 3.60x ± 0.17 |
| DependencyAware | 0.03 ± 0.01 | 0.19 ± 0.06 | 0.01 ± 0.00 | 0.04 ± 0.01 | 0.37 ± 0.06 | 3183825.50 ± 531009.00 | 100.00 ± 0.00 | 1.00 ± 0.00 | 4.37x ± 0.17 | 27.76x ± 8.56 | 6.60x ± 0.18 |
| SJF | 0.02 ± 0.00 | 0.15 ± 0.05 | 0.01 ± 0.00 | 0.03 ± 0.01 | 0.40 ± 0.06 | 2961636.00 ± 416450.28 | 100.00 ± 0.00 | 1.00 ± 0.00 | 2.79x ± 0.11 | 19.66x ± 5.04 | 5.12x ± 0.37 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 2.60x | 3.52x | 3.77x | 2.65x |
| wl 1 | 2.22x | 2.60x | 2.31x | 2.29x |
| wl 2 | 3.75x | 2.40x | 5.71x | 3.12x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.010 ms² | 0.006 ms² | 0.011 ms² | 0.013 ms² |
| wl 1 | 0.009 ms² | 0.007 ms² | 0.013 ms² | 0.006 ms² |
| wl 2 | 0.005 ms² | 0.006 ms² | 0.008 ms² | 0.009 ms² |
