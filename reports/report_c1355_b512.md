# GPU Scheduler Report
Circuit: c1355 | batch_size=512 | runs=10 (averaged)

Generated: 20260427_094316

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.042 | 0.088 | 0.007 | 0.048 | 0.094 | 2748339.75 | 100.00 |
| fanin_priority | 0.044 | 0.094 | 0.007 | 0.051 | 0.102 | 2609169.50 | 100.00 |
| DependencyAware | 0.045 | 0.095 | 0.007 | 0.052 | 0.102 | 2584408.00 | 100.00 |
| SJF | 0.043 | 0.095 | 0.007 | 0.050 | 0.103 | 2551865.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.04 ± 0.01 | 0.09 ± 0.02 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.09 ± 0.02 | 2748339.75 ± 364444.69 | 100.00 ± 0.00 |
| fanin_priority | 0.04 ± 0.01 | 0.09 ± 0.03 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.10 ± 0.03 | 2609169.50 ± 452340.66 | 100.00 ± 0.00 |
| DependencyAware | 0.05 ± 0.01 | 0.10 ± 0.02 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.10 ± 0.03 | 2584408.00 ± 451514.69 | 100.00 ± 0.00 |
| SJF | 0.04 ± 0.01 | 0.10 ± 0.02 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.10 ± 0.02 | 2551865.75 ± 422598.56 | 100.00 ± 0.00 |
