# GPU Scheduler Report
Group: imbalanced_5 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_024155

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 2.838 | 9.105 | 0.034 | 2.872 | 9.218 | 271787.34 | 11.70 | 0.9946 | 157.97x | 657.59x | 84.47x |
| Priority | 1.860 | 8.005 | 0.033 | 1.892 | 8.116 | 300408.69 | 15.07 | 0.9915 | 101.77x | 552.91x | 53.83x |
| DependencyAware | 2.688 | 8.679 | 0.034 | 2.722 | 8.797 | 278857.38 | 12.35 | 0.9920 | 139.29x | 563.28x | 77.13x |
| SJF | 1.904 | 7.983 | 0.033 | 1.938 | 8.114 | 300222.12 | 15.21 | 0.9834 | 100.33x | 530.12x | 53.11x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 2.84 ± 0.82 | 9.11 ± 2.19 | 0.03 ± 0.01 | 2.87 ± 0.83 | 9.22 ± 2.20 | 271787.34 ± 48176.69 | 11.70 ± 1.08 | 0.99 | 157.97x ± 32.74 | 657.59x | 84.47x ± 17.05 |
| Priority | 1.86 ± 0.22 | 8.01 ± 1.12 | 0.03 ± 0.00 | 1.89 ± 0.23 | 8.12 ± 1.13 | 300408.69 ± 33905.38 | 15.07 ± 0.59 | 0.99 | 101.77x ± 6.65 | 552.91x | 53.83x ± 3.45 |
| DependencyAware | 2.69 ± 1.01 | 8.68 ± 1.48 | 0.03 ± 0.00 | 2.72 ± 1.01 | 8.80 ± 1.49 | 278857.38 ± 36115.92 | 12.35 ± 1.17 | 0.99 | 139.29x ± 32.64 | 563.28x | 77.13x ± 18.67 |
| SJF | 1.90 ± 0.33 | 7.98 ± 1.09 | 0.03 ± 0.00 | 1.94 ± 0.33 | 8.11 ± 1.09 | 300222.12 ± 33052.13 | 15.21 ± 0.80 | 0.98 | 100.33x ± 6.21 | 530.12x | 53.11x ± 3.24 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 154.70x | 149.51x | 148.94x | 142.09x |
| wl 1 | 172.32x | 120.99x | 145.63x | 112.28x |
| wl 2 | 150.87x | 85.94x | 134.80x | 89.02x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 8.541 ms² | 7.311 ms² | 7.221 ms² | 6.831 ms² |
| wl 1 | 5.504 ms² | 3.573 ms² | 4.495 ms² | 3.207 ms² |
| wl 2 | 4.709 ms² | 2.076 ms² | 3.115 ms² | 2.244 ms² |
