# GPU Scheduler Report
Circuit: c7552 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022258

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.002 | 0.023 | 0.014 | 0.016 | 0.282 | 5253926.00 | 100.00 |
| fanin_priority | 0.001 | 0.032 | 0.014 | 0.015 | 0.279 | 5453037.00 | 100.00 |
| DependencyAware | 0.003 | 0.035 | 0.015 | 0.018 | 0.285 | 5213549.00 | 100.00 |
| SJF | 0.001 | 0.031 | 0.014 | 0.015 | 0.258 | 5723717.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.28 ± 0.03 | 5253926.00 ± 611788.25 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.03 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.28 ± 0.07 | 5453037.00 ± 893466.94 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.04 ± 0.01 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.28 ± 0.04 | 5213549.00 ± 656674.50 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.03 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.26 ± 0.03 | 5723717.00 ± 593108.31 | 100.00 ± 0.00 |
