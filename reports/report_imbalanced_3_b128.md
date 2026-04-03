# GPU Scheduler Report
Group: imbalanced_3 | batch_size=128 | runs=10 (averaged)

Generated: 20260403_231753

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 16.399 | 57.532 | 0.366 | 16.765 | 57.650 | 27883.52 | 15.63 | 0.9977 | 637.01x | 7494.65x | 345.26x |
| Priority | 19.288 | 68.778 | 0.264 | 19.552 | 68.901 | 23326.06 | 9.25 | 0.9985 | 915.66x | 4425.87x | 479.73x |
| DependencyAware | 17.898 | 59.935 | 0.378 | 18.276 | 60.056 | 26763.10 | 14.53 | 0.9969 | 694.24x | 8049.98x | 376.70x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 16.40 ± 0.28 | 57.53 ± 1.00 | 0.37 ± 0.00 | 16.77 ± 0.28 | 57.65 ± 1.00 | 27883.52 ± 483.68 | 15.63 ± 0.23 | 1.00 | 637.01x ± 51.82 | 7494.65x | 345.26x ± 26.92 |
| Priority | 19.29 ± 0.26 | 68.78 ± 0.73 | 0.26 ± 0.00 | 19.55 ± 0.26 | 68.90 ± 0.73 | 23326.06 ± 245.34 | 9.25 ± 0.11 | 1.00 | 915.66x ± 115.75 | 4425.87x | 479.73x ± 58.72 |
| DependencyAware | 17.90 ± 0.38 | 59.94 ± 0.79 | 0.38 ± 0.00 | 18.28 ± 0.38 | 60.06 ± 0.79 | 26763.10 ± 349.94 | 14.53 ± 0.25 | 1.00 | 694.24x ± 17.47 | 8049.98x | 376.70x ± 9.05 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 945.45x | 1365.32x | 975.56x |
| wl 1 | 305.11x | 492.21x | 421.82x |
| wl 2 | 769.17x | 1063.65x | 792.37x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 405.833 ms² | 609.927 ms² | 442.715 ms² |
| wl 1 | 140.444 ms² | 235.956 ms² | 138.264 ms² |
| wl 2 | 354.515 ms² | 485.010 ms² | 351.274 ms² |
