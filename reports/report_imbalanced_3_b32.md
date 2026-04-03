# GPU Scheduler Report
Group: imbalanced_3 | batch_size=32 | runs=10 (averaged)

Generated: 20260403_231710

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 25.389 | 77.184 | 0.332 | 25.721 | 77.300 | 20792.13 | 22.87 | 0.9986 | 1108.91x | 13003.59x | 587.22x |
| Priority | 17.316 | 79.620 | 0.218 | 17.533 | 79.734 | 20155.52 | 14.83 | 1.0000 | 948.83x | 6247.58x | 507.63x |
| DependencyAware | 28.261 | 79.226 | 0.330 | 28.591 | 79.362 | 20249.60 | 21.90 | 0.9987 | 1251.02x | 12364.69x | 706.32x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 25.39 ± 0.27 | 77.18 ± 0.93 | 0.33 ± 0.00 | 25.72 ± 0.27 | 77.30 ± 0.92 | 20792.13 ± 244.60 | 22.87 ± 0.22 | 1.00 | 1108.91x ± 42.89 | 13003.59x | 587.22x ± 22.08 |
| Priority | 17.32 ± 0.12 | 79.62 ± 0.60 | 0.22 ± 0.00 | 17.53 ± 0.12 | 79.73 ± 0.59 | 20155.52 ± 148.90 | 14.83 ± 0.23 | 1.00 | 948.83x ± 120.47 | 6247.58x | 507.63x ± 62.83 |
| DependencyAware | 28.26 ± 0.22 | 79.23 ± 0.39 | 0.33 ± 0.00 | 28.59 ± 0.22 | 79.36 ± 0.41 | 20249.60 ± 103.71 | 21.90 ± 0.22 | 1.00 | 1251.02x ± 23.55 | 12364.69x | 706.32x ± 13.73 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 1436.45x | 1057.23x | 2047.76x |
| wl 1 | 580.07x | 994.86x | 768.32x |
| wl 2 | 1379.63x | 875.03x | 1315.44x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 771.751 ms² | 586.260 ms² | 857.614 ms² |
| wl 1 | 289.157 ms² | 595.707 ms² | 489.110 ms² |
| wl 2 | 581.057 ms² | 534.582 ms² | 638.494 ms² |
