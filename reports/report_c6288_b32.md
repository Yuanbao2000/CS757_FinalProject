# GPU Scheduler Report
Circuit: c6288 | batch_size=32 | runs=10 (averaged)

Generated: 20260427_094250

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.281 | 0.687 | 0.009 | 0.290 | 0.692 | 2519690.75 | 100.00 |
| fanin_priority | 0.278 | 0.681 | 0.008 | 0.286 | 0.685 | 2544637.00 | 100.00 |
| DependencyAware | 0.284 | 0.694 | 0.009 | 0.293 | 0.699 | 2501612.25 | 100.00 |
| SJF | 0.289 | 0.694 | 0.009 | 0.298 | 0.698 | 2499646.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.28 ± 0.03 | 0.69 ± 0.06 | 0.01 ± 0.00 | 0.29 ± 0.03 | 0.69 ± 0.06 | 2519690.75 ± 206527.12 | 100.00 ± 0.00 |
| fanin_priority | 0.28 ± 0.03 | 0.68 ± 0.06 | 0.01 ± 0.00 | 0.29 ± 0.03 | 0.69 ± 0.06 | 2544637.00 ± 211331.73 | 100.00 ± 0.00 |
| DependencyAware | 0.28 ± 0.04 | 0.69 ± 0.07 | 0.01 ± 0.00 | 0.29 ± 0.04 | 0.70 ± 0.07 | 2501612.25 ± 244948.38 | 100.00 ± 0.00 |
| SJF | 0.29 ± 0.03 | 0.69 ± 0.07 | 0.01 ± 0.00 | 0.30 ± 0.03 | 0.70 ± 0.07 | 2499646.50 ± 221382.11 | 100.00 ± 0.00 |
