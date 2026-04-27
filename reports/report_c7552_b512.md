# GPU Scheduler Report
Circuit: c7552 | batch_size=512 | runs=10 (averaged)

Generated: 20260427_094335

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.107 | 0.327 | 0.018 | 0.125 | 0.337 | 4939027.50 | 100.00 |
| fanin_priority | 0.116 | 0.345 | 0.020 | 0.136 | 0.354 | 4650117.50 | 100.00 |
| DependencyAware | 0.178 | 0.430 | 0.027 | 0.205 | 0.438 | 4772760.50 | 100.00 |
| SJF | 0.105 | 0.323 | 0.018 | 0.123 | 0.331 | 5085235.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.11 ± 0.03 | 0.33 ± 0.12 | 0.02 ± 0.01 | 0.13 ± 0.04 | 0.34 ± 0.13 | 4939027.50 ± 1621772.50 | 100.00 ± 0.00 |
| fanin_priority | 0.12 ± 0.04 | 0.34 ± 0.12 | 0.02 ± 0.01 | 0.14 ± 0.04 | 0.35 ± 0.12 | 4650117.50 ± 1572859.12 | 100.00 ± 0.00 |
| DependencyAware | 0.18 ± 0.22 | 0.43 ± 0.40 | 0.03 ± 0.03 | 0.21 ± 0.25 | 0.44 ± 0.40 | 4772760.50 ± 1838023.62 | 100.00 ± 0.00 |
| SJF | 0.11 ± 0.04 | 0.32 ± 0.13 | 0.02 ± 0.01 | 0.12 ± 0.04 | 0.33 ± 0.13 | 5085235.00 ± 1718458.25 | 100.00 ± 0.00 |
