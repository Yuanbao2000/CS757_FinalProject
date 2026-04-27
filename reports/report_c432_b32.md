# GPU Scheduler Report
Circuit: c432 | batch_size=32 | runs=10 (averaged)

Generated: 20260427_094236

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.045 | 0.117 | 0.005 | 0.050 | 0.122 | 1458337.88 | 100.00 |
| fanin_priority | 0.043 | 0.121 | 0.006 | 0.049 | 0.126 | 1447176.25 | 100.00 |
| DependencyAware | 0.048 | 0.127 | 0.006 | 0.054 | 0.132 | 1381651.25 | 100.00 |
| SJF | 0.045 | 0.120 | 0.006 | 0.051 | 0.124 | 1441872.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.04 ± 0.00 | 0.12 ± 0.00 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.12 ± 0.00 | 1458337.88 ± 58625.58 | 100.00 ± 0.00 |
| fanin_priority | 0.04 ± 0.01 | 0.12 ± 0.03 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.13 ± 0.03 | 1447176.25 ± 216217.30 | 100.00 ± 0.00 |
| DependencyAware | 0.05 ± 0.01 | 0.13 ± 0.03 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.13 ± 0.03 | 1381651.25 ± 190710.61 | 100.00 ± 0.00 |
| SJF | 0.04 ± 0.00 | 0.12 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.12 ± 0.01 | 1441872.75 ± 123361.79 | 100.00 ± 0.00 |
