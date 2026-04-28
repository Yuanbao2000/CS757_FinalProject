# GPU Scheduler Group Report
Group: balanced_1 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025522

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.016 | 0.011 | 0.012 | 0.269 | 4465859.00 | 100.00 | 0.9694 | 1.01x | 2.08x | 2.03x |
| fanin_priority | 0.000 | 0.011 | 0.011 | 0.011 | 0.297 | 4162638.75 | 100.00 | 0.9573 | 1.01x | 2.06x | 2.03x |
| DependencyAware | 0.000 | 0.015 | 0.012 | 0.012 | 0.271 | 4432645.00 | 100.00 | 0.9701 | 1.01x | 2.07x | 2.03x |
| SJF | 0.000 | 0.011 | 0.010 | 0.011 | 0.267 | 4507872.50 | 100.00 | 0.9561 | 1.01x | 2.01x | 2.04x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.27 ± 0.03 | 4465859.00 ± 409128.00 | 100.00 ± 0.00 | 0.97 ± 0.01 | 1.01x ± 0.00 | 2.08x ± 0.24 | 2.03x ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.30 ± 0.07 | 4162638.75 ± 712069.19 | 100.00 ± 0.00 | 0.96 ± 0.02 | 1.01x ± 0.00 | 2.06x ± 0.33 | 2.03x ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.27 ± 0.03 | 4432645.00 ± 418804.53 | 100.00 ± 0.00 | 0.97 ± 0.01 | 1.01x ± 0.00 | 2.07x ± 0.18 | 2.03x ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.27 ± 0.03 | 4507872.50 ± 493221.25 | 100.00 ± 0.00 | 0.96 ± 0.02 | 1.01x ± 0.00 | 2.01x ± 0.23 | 2.04x ± 0.00 |

## Per-Workload Avg Slowdown

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 1 | 1.00x | 1.00x | 1.00x | 1.00x |
| wl 2 | 1.01x | 1.01x | 1.01x | 1.01x |

## Per-Workload Completion Variance

| Workload | FIFO | fanin_priority | DependencyAware | SJF |
|---|---|---|---|---|
| wl 0 | 0.006 ms² | 0.006 ms² | 0.005 ms² | 0.005 ms² |
| wl 1 | 0.004 ms² | 0.004 ms² | 0.004 ms² | 0.003 ms² |
| wl 2 | 0.004 ms² | 0.005 ms² | 0.004 ms² | 0.003 ms² |
