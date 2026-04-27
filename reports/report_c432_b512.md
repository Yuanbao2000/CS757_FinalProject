# GPU Scheduler Report
Circuit: c432 | batch_size=512 | runs=10 (averaged)

Generated: 20260427_094316

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.048 | 0.127 | 0.006 | 0.054 | 0.132 | 1361199.25 | 100.00 |
| fanin_priority | 0.045 | 0.123 | 0.006 | 0.051 | 0.128 | 1382524.00 | 100.00 |
| DependencyAware | 0.044 | 0.117 | 0.006 | 0.050 | 0.121 | 1461829.12 | 100.00 |
| SJF | 0.044 | 0.119 | 0.006 | 0.050 | 0.124 | 1432429.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.05 ± 0.01 | 0.13 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.13 ± 0.02 | 1361199.25 ± 142771.73 | 100.00 ± 0.00 |
| fanin_priority | 0.05 ± 0.00 | 0.12 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.13 ± 0.01 | 1382524.00 ± 70094.59 | 100.00 ± 0.00 |
| DependencyAware | 0.04 ± 0.00 | 0.12 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.12 ± 0.01 | 1461829.12 ± 59998.23 | 100.00 ± 0.00 |
| SJF | 0.04 ± 0.00 | 0.12 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.12 ± 0.01 | 1432429.25 ± 82753.55 | 100.00 ± 0.00 |
