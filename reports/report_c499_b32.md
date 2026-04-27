# GPU Scheduler Report
Circuit: c499 | batch_size=32 | runs=10 (averaged)

Generated: 20260427_094236

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.048 | 0.093 | 0.006 | 0.054 | 0.099 | 2528584.50 | 100.00 |
| fanin_priority | 0.048 | 0.097 | 0.006 | 0.054 | 0.103 | 2437446.25 | 100.00 |
| DependencyAware | 0.046 | 0.090 | 0.006 | 0.052 | 0.096 | 2622453.00 | 100.00 |
| SJF | 0.051 | 0.099 | 0.007 | 0.058 | 0.107 | 2413734.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.05 ± 0.01 | 0.09 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.10 ± 0.01 | 2528584.50 ± 249196.97 | 100.00 ± 0.00 |
| fanin_priority | 0.05 ± 0.00 | 0.10 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.10 ± 0.01 | 2437446.25 ± 156595.30 | 100.00 ± 0.00 |
| DependencyAware | 0.05 ± 0.00 | 0.09 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.10 ± 0.01 | 2622453.00 ± 196127.38 | 100.00 ± 0.00 |
| SJF | 0.05 ± 0.01 | 0.10 ± 0.02 | 0.01 ± 0.00 | 0.06 ± 0.01 | 0.11 ± 0.02 | 2413734.75 ± 387017.53 | 100.00 ± 0.00 |
