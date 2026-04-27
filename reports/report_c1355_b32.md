# GPU Scheduler Report
Circuit: c1355 | batch_size=32 | runs=10 (averaged)

Generated: 20260427_094237

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.046 | 0.092 | 0.007 | 0.052 | 0.102 | 2513415.75 | 100.00 |
| fanin_priority | 0.044 | 0.087 | 0.006 | 0.050 | 0.094 | 2728492.50 | 100.00 |
| DependencyAware | 0.047 | 0.093 | 0.007 | 0.053 | 0.099 | 2562724.25 | 100.00 |
| SJF | 0.044 | 0.090 | 0.006 | 0.050 | 0.097 | 2611943.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.05 ± 0.01 | 0.09 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.10 ± 0.01 | 2513415.75 ± 287119.66 | 100.00 ± 0.00 |
| fanin_priority | 0.04 ± 0.00 | 0.09 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.09 ± 0.01 | 2728492.50 ± 233720.58 | 100.00 ± 0.00 |
| DependencyAware | 0.05 ± 0.01 | 0.09 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.10 ± 0.01 | 2562724.25 ± 172045.67 | 100.00 ± 0.00 |
| SJF | 0.04 ± 0.00 | 0.09 ± 0.00 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.10 ± 0.00 | 2611943.25 ± 128746.98 | 100.00 ± 0.00 |
