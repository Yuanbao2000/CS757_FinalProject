# GPU Scheduler Report
Circuit: c3540 | batch_size=32 | runs=10 (averaged)

Generated: 20260427_094239

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.116 | 0.293 | 0.009 | 0.125 | 0.297 | 2734252.25 | 100.00 |
| fanin_priority | 0.108 | 0.283 | 0.008 | 0.115 | 0.287 | 2671971.00 | 100.00 |
| DependencyAware | 0.112 | 0.291 | 0.009 | 0.121 | 0.296 | 2677085.75 | 100.00 |
| SJF | 0.113 | 0.311 | 0.009 | 0.122 | 0.316 | 2621176.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.12 ± 0.04 | 0.29 ± 0.09 | 0.01 ± 0.00 | 0.13 ± 0.04 | 0.30 ± 0.09 | 2734252.25 ± 538637.00 | 100.00 ± 0.00 |
| fanin_priority | 0.11 ± 0.01 | 0.28 ± 0.02 | 0.01 ± 0.00 | 0.12 ± 0.01 | 0.29 ± 0.02 | 2671971.00 ± 203048.38 | 100.00 ± 0.00 |
| DependencyAware | 0.11 ± 0.03 | 0.29 ± 0.07 | 0.01 ± 0.00 | 0.12 ± 0.04 | 0.30 ± 0.07 | 2677085.75 ± 437417.81 | 100.00 ± 0.00 |
| SJF | 0.11 ± 0.04 | 0.31 ± 0.12 | 0.01 ± 0.00 | 0.12 ± 0.04 | 0.32 ± 0.12 | 2621176.25 ± 576499.88 | 100.00 ± 0.00 |
