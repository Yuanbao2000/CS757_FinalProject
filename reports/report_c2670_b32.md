# GPU Scheduler Report
Circuit: c2670 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022143

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.008 | 0.033 | 0.007 | 0.015 | 0.166 | 3447187.50 | 100.00 |
| fanin_priority | 0.009 | 0.108 | 0.009 | 0.017 | 0.177 | 3438192.75 | 100.00 |
| DependencyAware | 0.016 | 0.070 | 0.009 | 0.025 | 0.195 | 3144302.75 | 100.00 |
| SJF | 0.008 | 0.051 | 0.008 | 0.016 | 0.181 | 3221824.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.01 ± 0.00 | 0.03 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.17 ± 0.02 | 3447187.50 ± 364476.62 | 100.00 ± 0.00 |
| fanin_priority | 0.01 ± 0.00 | 0.11 ± 0.03 | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.18 ± 0.06 | 3438192.75 ± 772187.06 | 100.00 ± 0.00 |
| DependencyAware | 0.02 ± 0.01 | 0.07 ± 0.04 | 0.01 ± 0.00 | 0.03 ± 0.01 | 0.20 ± 0.07 | 3144302.75 ± 739031.31 | 100.00 ± 0.00 |
| SJF | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.18 ± 0.04 | 3221824.00 ± 494909.34 | 100.00 ± 0.00 |
