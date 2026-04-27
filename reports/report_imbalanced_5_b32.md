# GPU Scheduler Report
Group: imbalanced_5 | batch_size=32 | runs=10 (averaged)

Generated: 20260408_184258

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 32.484 | 109.320 | 0.305 | 32.790 | 109.455 | 23220.03 | 22.55 | 0.9999 | 1235.79x | 16677.23x | 683.78x |
| Priority | 20.591 | 105.760 | 0.225 | 20.815 | 105.891 | 23257.68 | 18.04 | 0.9999 | 895.02x | 6448.41x | 474.10x |
| DependencyAware | 31.618 | 94.934 | 0.286 | 31.904 | 95.068 | 25249.08 | 22.71 | 1.0000 | 1120.61x | 13921.71x | 669.43x |
| SJF | 17.081 | 98.453 | 0.214 | 17.294 | 98.586 | 24344.63 | 17.78 | 1.0000 | 738.18x | 5896.39x | 395.21x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 32.48 ± 5.08 | 109.32 ± 35.19 | 0.31 ± 0.02 | 32.79 ± 5.10 | 109.46 ± 35.19 | 23220.03 ± 4024.65 | 22.55 ± 3.26 | 1.00 | 1235.79x ± 375.03 | 16677.23x | 683.78x ± 214.32 |
| Priority | 20.59 ± 5.81 | 105.76 ± 20.85 | 0.22 ± 0.01 | 20.82 ± 5.82 | 105.89 ± 20.85 | 23257.68 ± 3012.33 | 18.04 ± 2.02 | 1.00 | 895.02x ± 244.00 | 6448.41x | 474.10x ± 127.96 |
| DependencyAware | 31.62 ± 0.39 | 94.93 ± 1.22 | 0.29 ± 0.00 | 31.90 ± 0.39 | 95.07 ± 1.22 | 25249.08 ± 320.89 | 22.71 ± 0.24 | 1.00 | 1120.61x ± 19.12 | 13921.71x | 669.43x ± 10.55 |
| SJF | 17.08 ± 0.12 | 98.45 ± 0.35 | 0.21 ± 0.00 | 17.29 ± 0.12 | 98.59 ± 0.36 | 24344.63 ± 88.49 | 17.78 ± 0.04 | 1.00 | 738.18x ± 7.71 | 5896.39x | 395.21x ± 4.06 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1634.98x | 1848.83x | 1618.91x | 1495.35x |
| wl 1 | 1267.62x | 1121.80x | 1084.33x | 891.89x |
| wl 2 | 1170.77x | 660.87x | 1079.17x | 566.05x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1956.185 ms² | 1739.565 ms² | 1354.990 ms² | 1416.477 ms² |
| wl 1 | 1376.425 ms² | 1286.571 ms² | 921.145 ms² | 805.726 ms² |
| wl 2 | 1163.555 ms² | 629.956 ms² | 920.245 ms² | 458.129 ms² |
