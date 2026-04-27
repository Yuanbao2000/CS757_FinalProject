# GPU Scheduler Report
Group: balanced_1 | batch_size=128 | runs=10 (averaged)

Generated: 20260408_184311

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 14.443 | 51.013 | 0.362 | 14.805 | 51.135 | 23255.25 | 16.53 | 0.9844 | 479.98x | 6645.85x | 253.00x |
| Priority | 15.996 | 56.174 | 0.269 | 16.265 | 56.302 | 21122.15 | 10.91 | 0.9812 | 753.33x | 3269.68x | 395.27x |
| DependencyAware | 14.119 | 49.648 | 0.347 | 14.466 | 49.770 | 23896.65 | 16.43 | 0.9858 | 515.20x | 6284.50x | 280.44x |
| SJF | 16.294 | 56.953 | 0.269 | 16.563 | 57.083 | 20837.76 | 10.72 | 0.9818 | 769.30x | 3350.52x | 404.08x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 14.44 ± 0.19 | 51.01 ± 0.60 | 0.36 ± 0.00 | 14.80 ± 0.19 | 51.14 ± 0.60 | 23255.25 ± 270.96 | 16.53 ± 0.30 | 0.98 | 479.98x ± 49.04 | 6645.85x | 253.00x ± 24.85 |
| Priority | 16.00 ± 0.29 | 56.17 ± 0.76 | 0.27 ± 0.00 | 16.26 ± 0.29 | 56.30 ± 0.76 | 21122.15 ± 279.09 | 10.91 ± 0.21 | 0.98 | 753.33x ± 20.36 | 3269.68x | 395.27x ± 10.94 |
| DependencyAware | 14.12 ± 0.24 | 49.65 ± 0.83 | 0.35 ± 0.00 | 14.47 ± 0.24 | 49.77 ± 0.82 | 23896.65 ± 394.95 | 16.43 ± 0.36 | 0.99 | 515.20x ± 10.69 | 6284.50x | 280.44x ± 6.30 |
| SJF | 16.29 ± 0.49 | 56.95 ± 1.15 | 0.27 ± 0.00 | 16.56 ± 0.49 | 57.08 ± 1.15 | 20837.76 ± 416.57 | 10.72 ± 0.33 | 0.98 | 769.30x ± 26.98 | 3350.52x | 404.08x ± 13.87 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 554.37x | 711.84x | 550.90x | 723.02x |
| wl 1 | 515.07x | 878.59x | 477.76x | 903.97x |
| wl 2 | 451.27x | 722.08x | 519.13x | 736.09x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 340.893 ms² | 416.553 ms² | 327.734 ms² | 432.158 ms² |
| wl 1 | 242.664 ms² | 278.987 ms² | 219.426 ms² | 292.858 ms² |
| wl 2 | 250.008 ms² | 293.914 ms² | 234.781 ms² | 306.499 ms² |
