# GPU Scheduler Report
Circuit: c5315 | batch_size=128 | runs=10 (averaged)

Generated: 20260427_094303

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.085 | 0.262 | 0.014 | 0.099 | 0.267 | 4713128.50 | 100.00 |
| fanin_priority | 0.083 | 0.255 | 0.012 | 0.095 | 0.260 | 4785273.00 | 100.00 |
| DependencyAware | 0.081 | 0.261 | 0.013 | 0.094 | 0.267 | 4651185.50 | 100.00 |
| SJF | 0.095 | 0.279 | 0.014 | 0.109 | 0.285 | 4501889.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.09 ± 0.01 | 0.26 ± 0.05 | 0.01 ± 0.00 | 0.10 ± 0.01 | 0.27 ± 0.05 | 4713128.50 ± 759753.75 | 100.00 ± 0.00 |
| fanin_priority | 0.08 ± 0.02 | 0.26 ± 0.05 | 0.01 ± 0.00 | 0.10 ± 0.02 | 0.26 ± 0.04 | 4785273.00 ± 607833.69 | 100.00 ± 0.00 |
| DependencyAware | 0.08 ± 0.01 | 0.26 ± 0.04 | 0.01 ± 0.00 | 0.09 ± 0.01 | 0.27 ± 0.04 | 4651185.50 ± 566053.88 | 100.00 ± 0.00 |
| SJF | 0.10 ± 0.03 | 0.28 ± 0.07 | 0.01 ± 0.00 | 0.11 ± 0.03 | 0.29 ± 0.07 | 4501889.50 ± 950099.38 | 100.00 ± 0.00 |
