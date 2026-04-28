# GPU Scheduler Report
Circuit: c880 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022334

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.007 | 0.007 | 0.135 | 2284904.50 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.007 | 0.007 | 0.136 | 2272658.50 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.007 | 0.007 | 0.137 | 2244633.75 | 100.00 |
| SJF | 0.000 | 0.000 | 0.006 | 0.006 | 0.138 | 2245104.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.01 | 2284904.50 ± 160263.73 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.01 | 2272658.50 ± 124378.43 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.01 | 2244633.75 ± 126361.95 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.01 | 2245104.00 ± 182705.03 | 100.00 ± 0.00 |
