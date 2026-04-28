# GPU Scheduler Group Report
Group: imbalanced_4 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025442

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.033 | 0.097 | 0.012 | 0.045 | 0.691 | 2841469.25 | 100.00 | 0.8941 | 3.87x | 11.11x | 6.74x |
| fanin_priority | 0.018 | 0.549 | 0.011 | 0.029 | 0.654 | 2974379.50 | 100.00 | 0.9862 | 2.79x | 57.50x | 3.63x |
| DependencyAware | 0.058 | 0.508 | 0.013 | 0.072 | 0.745 | 2681689.00 | 100.00 | 0.9992 | 5.87x | 54.79x | 8.85x |
| SJF | 0.026 | 0.482 | 0.012 | 0.037 | 0.715 | 2803882.25 | 100.00 | 0.8756 | 3.29x | 47.65x | 6.77x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.03 ± 0.01 | 0.10 ± 0.03 | 0.01 ± 0.00 | 0.05 ± 0.02 | 0.69 ± 0.25 | 2841469.25 ± 838457.50 | 100.00 ± 0.00 | 0.89 ± 0.02 | 3.87x ± 0.20 | 11.11x ± 3.78 | 6.74x ± 0.25 |
| fanin_priority | 0.02 ± 0.01 | 0.55 ± 0.22 | 0.01 ± 0.00 | 0.03 ± 0.01 | 0.65 ± 0.25 | 2974379.50 ± 769802.44 | 100.00 ± 0.00 | 0.99 ± 0.00 | 2.79x ± 0.08 | 57.50x ± 6.55 | 3.63x ± 0.08 |
| DependencyAware | 0.06 ± 0.02 | 0.51 ± 0.20 | 0.01 ± 0.01 | 0.07 ± 0.03 | 0.75 ± 0.30 | 2681689.00 ± 844016.50 | 100.00 ± 0.00 | 1.00 ± 0.00 | 5.87x ± 0.35 | 54.79x ± 8.87 | 8.85x ± 0.49 |
| SJF | 0.03 ± 0.01 | 0.48 ± 0.21 | 0.01 ± 0.01 | 0.04 ± 0.02 | 0.72 ± 0.30 | 2803882.25 ± 864741.31 | 100.00 ± 0.00 | 0.88 ± 0.01 | 3.29x ± 0.09 | 47.65x ± 6.65 | 6.77x ± 0.22 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 3.96x | 8.39x | 9.92x | 4.48x |
| wl 1 | 2.83x | 3.21x | 3.37x | 3.04x |
| wl 2 | 4.07x | 2.66x | 6.31x | 3.33x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.013 ms² | 0.034 ms² | 0.059 ms² | 0.009 ms² |
| wl 1 | 0.056 ms² | 0.027 ms² | 0.070 ms² | 0.037 ms² |
| wl 2 | 0.039 ms² | 0.034 ms² | 0.046 ms² | 0.042 ms² |
