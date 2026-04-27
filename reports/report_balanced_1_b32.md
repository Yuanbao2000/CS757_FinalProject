# GPU Scheduler Report
Group: balanced_1 | batch_size=32 | runs=10 (averaged)

Generated: 20260408_184212

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 17.301 | 58.192 | 0.352 | 17.652 | 58.312 | 20398.44 | 25.80 | 0.9849 | 793.27x | 7096.90x | 434.24x |
| Priority | 15.836 | 62.510 | 0.220 | 16.056 | 62.637 | 18983.20 | 16.50 | 0.9726 | 862.17x | 4550.06x | 450.55x |
| DependencyAware | 16.956 | 55.461 | 0.326 | 17.282 | 55.591 | 21389.67 | 25.04 | 0.9924 | 747.84x | 7336.90x | 411.17x |
| SJF | 15.144 | 60.912 | 0.240 | 15.384 | 61.034 | 19481.15 | 19.60 | 0.9511 | 843.04x | 4595.51x | 436.15x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 17.30 ± 0.34 | 58.19 ± 1.17 | 0.35 ± 0.00 | 17.65 ± 0.34 | 58.31 ± 1.17 | 20398.44 ± 409.31 | 25.80 ± 0.50 | 0.98 | 793.27x ± 42.31 | 7096.90x | 434.24x ± 22.86 |
| Priority | 15.84 ± 0.11 | 62.51 ± 0.38 | 0.22 ± 0.00 | 16.06 ± 0.11 | 62.64 ± 0.38 | 18983.20 ± 114.04 | 16.50 ± 0.06 | 0.97 | 862.17x ± 33.78 | 4550.06x | 450.55x ± 17.44 |
| DependencyAware | 16.96 ± 0.23 | 55.46 ± 0.46 | 0.33 ± 0.01 | 17.28 ± 0.23 | 55.59 ± 0.46 | 21389.67 ± 177.82 | 25.04 ± 0.48 | 0.99 | 747.84x ± 66.64 | 7336.90x | 411.17x ± 32.99 |
| SJF | 15.14 ± 0.09 | 60.91 ± 0.22 | 0.24 ± 0.00 | 15.38 ± 0.09 | 61.03 ± 0.22 | 19481.15 ± 69.40 | 19.60 ± 0.03 | 0.95 | 843.04x ± 19.54 | 4595.51x | 436.15x ± 10.36 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 904.93x | 1313.74x | 846.02x | 1314.23x |
| wl 1 | 869.44x | 1007.61x | 924.47x | 855.86x |
| wl 2 | 742.51x | 709.95x | 667.43x | 729.55x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 451.004 ms² | 564.861 ms² | 397.704 ms² | 526.318 ms² |
| wl 1 | 331.243 ms² | 269.622 ms² | 311.187 ms² | 196.221 ms² |
| wl 2 | 338.988 ms² | 298.774 ms² | 278.512 ms² | 300.623 ms² |
