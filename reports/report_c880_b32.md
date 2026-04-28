# GPU Scheduler Report
Circuit: c880 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022142

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.001 | 0.011 | 0.006 | 0.007 | 0.140 | 2203557.75 | 100.00 |
| fanin_priority | 0.001 | 0.022 | 0.006 | 0.007 | 0.137 | 2243486.75 | 100.00 |
| DependencyAware | 0.001 | 0.010 | 0.007 | 0.008 | 0.146 | 2117859.75 | 100.00 |
| SJF | 0.001 | 0.016 | 0.006 | 0.007 | 0.148 | 2082272.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.01 | 2203557.75 ± 121583.66 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.00 | 2243486.75 ± 71095.81 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.15 ± 0.01 | 2117859.75 ± 134765.16 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.15 ± 0.01 | 2082272.75 ± 123190.03 | 100.00 ± 0.00 |
