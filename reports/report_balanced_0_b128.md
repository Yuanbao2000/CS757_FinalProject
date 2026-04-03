# GPU Scheduler Report
Group: balanced_0 | batch_size=128 | runs=10 (averaged)

Generated: 20260403_231737

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 9.641 | 42.406 | 0.294 | 9.936 | 42.522 | 27073.60 | 20.08 | 0.9889 | 302.58x | 7134.82x | 163.54x |
| Priority | 14.029 | 56.143 | 0.165 | 14.194 | 56.257 | 20460.35 | 7.67 | 0.9914 | 675.16x | 3543.53x | 373.36x |
| DependencyAware | 13.021 | 49.545 | 0.313 | 13.333 | 49.662 | 23180.40 | 16.37 | 0.9955 | 453.13x | 7426.89x | 255.99x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 9.64 ± 0.22 | 42.41 ± 0.58 | 0.29 ± 0.00 | 9.94 ± 0.22 | 42.52 ± 0.58 | 27073.60 ± 369.89 | 20.08 ± 0.54 | 0.99 | 302.58x ± 36.32 | 7134.82x | 163.54x ± 18.81 |
| Priority | 14.03 ± 0.11 | 56.14 ± 0.29 | 0.16 ± 0.00 | 14.19 ± 0.11 | 56.26 ± 0.29 | 20460.35 ± 106.16 | 7.67 ± 0.10 | 0.99 | 675.16x ± 83.62 | 3543.53x | 373.36x ± 44.85 |
| DependencyAware | 13.02 ± 0.21 | 49.54 ± 0.64 | 0.31 ± 0.00 | 13.33 ± 0.21 | 49.66 ± 0.64 | 23180.40 ± 297.65 | 16.37 ± 0.20 | 1.00 | 453.13x ± 12.44 | 7426.89x | 255.99x ± 7.51 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 375.80x | 782.38x | 529.32x |
| wl 1 | 425.22x | 1126.49x | 672.68x |
| wl 2 | 201.83x | 392.73x | 302.67x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware |
|---|---|---|---|
| wl 0 | 159.572 ms² | 288.622 ms² | 214.593 ms² |
| wl 1 | 194.332 ms² | 336.716 ms² | 247.533 ms² |
| wl 2 | 52.053 ms² | 103.358 ms² | 81.554 ms² |
