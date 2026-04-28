# GPU Scheduler Report
Circuit: c499 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022141

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.008 | 0.007 | 0.007 | 0.102 | 2459526.75 | 100.00 |
| fanin_priority | 0.000 | 0.015 | 0.006 | 0.007 | 0.104 | 2411136.75 | 100.00 |
| DependencyAware | 0.000 | 0.008 | 0.007 | 0.007 | 0.102 | 2465662.00 | 100.00 |
| SJF | 0.000 | 0.008 | 0.007 | 0.007 | 0.103 | 2442358.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.10 ± 0.01 | 2459526.75 ± 244655.34 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.10 ± 0.01 | 2411136.75 ± 196031.30 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.10 ± 0.01 | 2465662.00 ± 205301.47 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.10 ± 0.01 | 2442358.75 ± 264235.50 | 100.00 ± 0.00 |
