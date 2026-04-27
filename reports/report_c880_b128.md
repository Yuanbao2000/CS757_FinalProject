# GPU Scheduler Report
Circuit: c880 | batch_size=128 | runs=10 (averaged)

Generated: 20260427_094257

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.042 | 0.130 | 0.007 | 0.048 | 0.135 | 2282340.00 | 100.00 |
| fanin_priority | 0.044 | 0.137 | 0.007 | 0.051 | 0.142 | 2211977.75 | 100.00 |
| DependencyAware | 0.041 | 0.132 | 0.007 | 0.048 | 0.136 | 2263420.50 | 100.00 |
| SJF | 0.043 | 0.137 | 0.007 | 0.050 | 0.141 | 2186580.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.04 ± 0.00 | 0.13 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.13 ± 0.01 | 2282340.00 ± 120889.80 | 100.00 ± 0.00 |
| fanin_priority | 0.04 ± 0.01 | 0.14 ± 0.02 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.14 ± 0.02 | 2211977.75 ± 273382.62 | 100.00 ± 0.00 |
| DependencyAware | 0.04 ± 0.00 | 0.13 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.14 ± 0.01 | 2263420.50 ± 139577.33 | 100.00 ± 0.00 |
| SJF | 0.04 ± 0.00 | 0.14 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.14 ± 0.01 | 2186580.25 ± 141924.02 | 100.00 ± 0.00 |
