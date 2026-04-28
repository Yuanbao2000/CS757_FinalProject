# GPU Scheduler Report
Circuit: c1908 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025457

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.006 | 0.006 | 0.132 | 2187182.75 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.007 | 0.007 | 0.137 | 2154760.50 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.007 | 0.007 | 0.147 | 2020825.38 | 100.00 |
| SJF | 0.000 | 0.000 | 0.006 | 0.006 | 0.125 | 2255377.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.03 | 2187182.75 ± 326333.56 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.04 | 2154760.50 ± 372627.56 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.15 ± 0.04 | 2020825.38 ± 397257.00 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.01 | 2255377.50 ± 124561.64 | 100.00 ± 0.00 |
