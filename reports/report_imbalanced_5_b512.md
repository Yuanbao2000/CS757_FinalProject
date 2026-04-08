# GPU Scheduler Report
Group: imbalanced_5 | batch_size=512 | runs=10 (averaged)

Generated: 20260408_184455

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 15.843 | 63.571 | 0.348 | 16.191 | 63.700 | 37727.52 | 13.31 | 0.9995 | 552.00x | 9619.91x | 301.06x |
| Priority | 19.836 | 76.690 | 0.251 | 20.087 | 76.830 | 31242.62 | 7.82 | 0.9995 | 925.12x | 4464.56x | 489.75x |
| DependencyAware | 17.107 | 64.938 | 0.349 | 17.456 | 65.075 | 36883.86 | 12.58 | 0.9996 | 593.08x | 10514.28x | 335.14x |
| SJF | 19.733 | 76.326 | 0.251 | 19.984 | 76.461 | 31392.97 | 7.86 | 0.9996 | 944.38x | 4628.43x | 499.30x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 15.84 ± 0.81 | 63.57 ± 2.41 | 0.35 ± 0.00 | 16.19 ± 0.81 | 63.70 ± 2.40 | 37727.52 ± 1354.71 | 13.31 ± 0.60 | 1.00 | 552.00x ± 70.06 | 9619.91x | 301.06x ± 36.25 |
| Priority | 19.84 ± 0.26 | 76.69 ± 0.94 | 0.25 ± 0.00 | 20.09 ± 0.26 | 76.83 ± 0.94 | 31242.62 ± 379.81 | 7.82 ± 0.15 | 1.00 | 925.12x ± 111.52 | 4464.56x | 489.75x ± 58.00 |
| DependencyAware | 17.11 ± 0.20 | 64.94 ± 0.63 | 0.35 ± 0.00 | 17.46 ± 0.21 | 65.08 ± 0.64 | 36883.86 ± 360.57 | 12.58 ± 0.15 | 1.00 | 593.08x ± 21.74 | 10514.28x | 335.14x ± 11.85 |
| SJF | 19.73 ± 0.29 | 76.33 ± 0.91 | 0.25 ± 0.00 | 19.98 ± 0.29 | 76.46 ± 0.91 | 31392.97 ± 373.88 | 7.86 ± 0.12 | 1.00 | 944.38x ± 41.07 | 4628.43x | 499.30x ± 21.41 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 795.47x | 1037.72x | 674.60x | 1067.55x |
| wl 1 | 592.50x | 1054.66x | 647.40x | 1078.46x |
| wl 2 | 501.32x | 843.77x | 554.81x | 859.38x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 549.766 ms² | 824.739 ms² | 567.686 ms² | 816.160 ms² |
| wl 1 | 394.273 ms² | 576.628 ms² | 390.830 ms² | 569.436 ms² |
| wl 2 | 296.098 ms² | 447.095 ms² | 304.486 ms² | 440.890 ms² |
