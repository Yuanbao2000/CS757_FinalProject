# GPU Scheduler Report
Circuit: c1355 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025400

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.012 | 0.010 | 0.010 | 0.153 | 1661649.00 | 100.00 |
| fanin_priority | 0.000 | 0.022 | 0.010 | 0.010 | 0.149 | 1697835.75 | 100.00 |
| DependencyAware | 0.001 | 0.013 | 0.010 | 0.010 | 0.152 | 1671756.25 | 100.00 |
| SJF | 0.000 | 0.011 | 0.010 | 0.011 | 0.162 | 1574593.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.15 ± 0.01 | 1661649.00 ± 124394.00 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.15 ± 0.00 | 1697835.75 ± 36112.43 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.15 ± 0.01 | 1671756.25 ± 72244.14 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.16 ± 0.02 | 1574593.25 ± 138194.50 | 100.00 ± 0.00 |
