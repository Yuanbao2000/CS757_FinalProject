# GPU Scheduler Report
Group: imbalanced_5 | batch_size=32 | runs=10 (averaged)

Generated: 20260403_231733

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 32.255 | 108.810 | 0.307 | 32.561 | 108.926 | 23350.41 | 22.76 | 0.9999 | 1324.56x | 18216.35x | 731.12x |
| Priority | 19.993 | 105.552 | 0.224 | 20.218 | 105.678 | 23362.70 | 18.08 | 0.9999 | 899.53x | 7018.78x | 475.74x |
| DependencyAware | 30.776 | 93.274 | 0.283 | 31.059 | 93.394 | 25702.31 | 22.88 | 1.0000 | 1180.56x | 15257.18x | 707.56x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 32.25 ± 5.07 | 108.81 ± 35.27 | 0.31 ± 0.02 | 32.56 ± 5.08 | 108.93 ± 35.27 | 23350.41 ± 4073.44 | 22.76 ± 3.38 | 1.00 | 1324.56x ± 374.55 | 18216.35x | 731.12x ± 210.70 |
| Priority | 19.99 ± 6.16 | 105.55 ± 21.97 | 0.22 ± 0.01 | 20.22 ± 6.17 | 105.68 ± 21.97 | 23362.70 ± 3141.52 | 18.08 ± 2.06 | 1.00 | 899.53x ± 274.38 | 7018.78x | 475.74x ± 143.47 |
| DependencyAware | 30.78 ± 0.41 | 93.27 ± 1.27 | 0.28 ± 0.00 | 31.06 ± 0.41 | 93.39 ± 1.27 | 25702.31 ± 348.12 | 22.88 ± 0.27 | 1.00 | 1180.56x ± 61.18 | 15257.18x | 707.56x ± 36.84 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 1708.53x | 1846.64x | 1664.57x |
| wl 1 | 1342.53x | 1147.32x | 1125.73x |
| wl 2 | 1268.62x | 655.21x | 1150.53x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 1946.889 ms² | 1756.224 ms² | 1306.167 ms² |
| wl 1 | 1371.776 ms² | 1311.589 ms² | 890.054 ms² |
| wl 2 | 1158.604 ms² | 642.355 ms² | 889.065 ms² |
