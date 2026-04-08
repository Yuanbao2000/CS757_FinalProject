# GPU Scheduler Report
Group: balanced_0 | batch_size=128 | runs=10 (averaged)

Generated: 20260408_184304

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 9.930 | 43.120 | 0.300 | 10.230 | 43.271 | 26608.02 | 20.05 | 0.9882 | 280.03x | 6573.53x | 151.94x |
| Priority | 13.977 | 56.010 | 0.166 | 14.143 | 56.140 | 20503.46 | 7.75 | 0.9911 | 652.51x | 3256.30x | 363.02x |
| DependencyAware | 13.236 | 50.190 | 0.318 | 13.554 | 50.321 | 22876.66 | 16.32 | 0.9952 | 412.34x | 6620.94x | 230.92x |
| SJF | 13.807 | 55.462 | 0.175 | 13.982 | 55.587 | 20706.51 | 8.33 | 0.9907 | 647.82x | 3206.16x | 362.37x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 9.93 ± 0.29 | 43.12 ± 0.73 | 0.30 ± 0.00 | 10.23 ± 0.29 | 43.27 ± 0.78 | 26608.02 ± 471.25 | 20.05 ± 0.42 | 0.99 | 280.03x ± 18.95 | 6573.53x | 151.94x ± 9.51 |
| Priority | 13.98 ± 0.15 | 56.01 ± 0.40 | 0.17 ± 0.00 | 14.14 ± 0.15 | 56.14 ± 0.40 | 20503.46 ± 144.28 | 7.75 ± 0.05 | 0.99 | 652.51x ± 13.43 | 3256.30x | 363.02x ± 7.37 |
| DependencyAware | 13.24 ± 0.22 | 50.19 ± 0.62 | 0.32 ± 0.00 | 13.55 ± 0.22 | 50.32 ± 0.62 | 22876.66 ± 283.78 | 16.32 ± 0.21 | 1.00 | 412.34x ± 8.70 | 6620.94x | 230.92x ± 5.04 |
| SJF | 13.81 ± 0.05 | 55.46 ± 0.18 | 0.18 ± 0.00 | 13.98 ± 0.05 | 55.59 ± 0.18 | 20706.51 ± 65.16 | 8.33 ± 0.03 | 0.99 | 647.82x ± 15.46 | 3206.16x | 362.37x ± 8.67 |

## Per-Workload Avg Slowdown

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 349.31x | 756.56x | 483.12x | 780.54x |
| wl 1 | 386.13x | 1089.16x | 612.39x | 1094.05x |
| wl 2 | 189.64x | 379.10x | 274.49x | 354.03x |

## Per-Workload Completion Variance

| Workload | FIFO | Priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 164.355 ms² | 284.448 ms² | 219.409 ms² | 267.190 ms² |
| wl 1 | 199.245 ms² | 331.494 ms² | 251.381 ms² | 323.920 ms² |
| wl 2 | 55.513 ms² | 101.717 ms² | 84.039 ms² | 91.916 ms² |
