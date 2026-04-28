# GPU Scheduler Report
Circuit: c17 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025457

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.006 | 0.006 | 0.028 | 480174.41 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.005 | 0.005 | 0.023 | 566071.12 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.005 | 0.005 | 0.026 | 515368.75 | 100.00 |
| SJF | 0.000 | 0.000 | 0.005 | 0.005 | 0.023 | 565135.31 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.03 ± 0.01 | 480174.41 ± 85203.12 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 566071.12 ± 21356.31 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.03 ± 0.00 | 515368.75 ± 72100.45 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 565135.31 ± 20665.60 | 100.00 ± 0.00 |
