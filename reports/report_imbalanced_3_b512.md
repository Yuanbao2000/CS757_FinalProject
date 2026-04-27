# GPU Scheduler Report
Group: imbalanced_3 | batch_size=512 | runs=10 (averaged)

Generated: 20260408_184425

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 16.445 | 58.252 | 0.366 | 16.811 | 58.382 | 27538.23 | 14.13 | 0.9971 | 522.52x | 9366.48x | 281.84x |
| Priority | 20.777 | 71.508 | 0.243 | 21.020 | 71.643 | 22432.36 | 7.45 | 0.9975 | 981.51x | 4296.73x | 515.86x |
| DependencyAware | 16.225 | 57.496 | 0.359 | 16.584 | 57.633 | 27895.31 | 14.18 | 0.9962 | 557.41x | 8404.61x | 299.93x |
| SJF | 20.657 | 71.045 | 0.243 | 20.900 | 71.174 | 22579.23 | 7.47 | 0.9975 | 967.75x | 4255.06x | 508.73x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 16.45 ± 0.44 | 58.25 ± 1.27 | 0.37 ± 0.00 | 16.81 ± 0.44 | 58.38 ± 1.26 | 27538.23 ± 591.49 | 14.13 ± 0.32 | 1.00 | 522.52x ± 41.94 | 9366.48x | 281.84x ± 21.56 |
| Priority | 20.78 ± 0.18 | 71.51 ± 0.60 | 0.24 ± 0.00 | 21.02 ± 0.18 | 71.64 ± 0.60 | 22432.36 ± 185.57 | 7.45 ± 0.07 | 1.00 | 981.51x ± 34.13 | 4296.73x | 515.86x ± 17.85 |
| DependencyAware | 16.22 ± 0.36 | 57.50 ± 1.21 | 0.36 ± 0.00 | 16.58 ± 0.37 | 57.63 ± 1.22 | 27895.31 ± 569.99 | 14.18 ± 0.25 | 1.00 | 557.41x ± 26.30 | 8404.61x | 299.93x ± 14.41 |
| SJF | 20.66 ± 0.11 | 71.04 ± 0.44 | 0.24 ± 0.00 | 20.90 ± 0.11 | 71.17 ± 0.44 | 22579.23 ± 138.12 | 7.47 ± 0.05 | 1.00 | 967.75x ± 34.30 | 4255.06x | 508.73x ± 17.72 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 881.83x | 1483.04x | 757.16x | 1458.68x |
| wl 1 | 248.90x | 497.46x | 293.43x | 488.56x |
| wl 2 | 592.92x | 1155.27x | 679.23x | 1141.81x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 431.139 ms² | 645.436 ms² | 395.337 ms² | 635.954 ms² |
| wl 1 | 147.557 ms² | 217.926 ms² | 135.180 ms² | 214.737 ms² |
| wl 2 | 360.103 ms² | 529.439 ms² | 327.398 ms² | 521.531 ms² |
