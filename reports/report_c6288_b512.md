# GPU Scheduler Report
Circuit: c6288 | batch_size=512 | runs=10 (averaged)

Generated: 20260427_094330

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.238 | 0.660 | 0.010 | 0.248 | 0.666 | 2644704.25 | 100.00 |
| fanin_priority | 0.236 | 0.651 | 0.010 | 0.246 | 0.656 | 2734601.50 | 100.00 |
| DependencyAware | 0.243 | 0.641 | 0.010 | 0.253 | 0.646 | 2687191.50 | 100.00 |
| SJF | 0.244 | 0.666 | 0.010 | 0.254 | 0.671 | 2636010.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.24 ± 0.02 | 0.66 ± 0.10 | 0.01 ± 0.00 | 0.25 ± 0.02 | 0.67 ± 0.10 | 2644704.25 ± 307637.72 | 100.00 ± 0.00 |
| fanin_priority | 0.24 ± 0.05 | 0.65 ± 0.14 | 0.01 ± 0.00 | 0.25 ± 0.06 | 0.66 ± 0.14 | 2734601.50 ± 463412.31 | 100.00 ± 0.00 |
| DependencyAware | 0.24 ± 0.02 | 0.64 ± 0.03 | 0.01 ± 0.00 | 0.25 ± 0.02 | 0.65 ± 0.03 | 2687191.50 ± 135847.88 | 100.00 ± 0.00 |
| SJF | 0.24 ± 0.04 | 0.67 ± 0.10 | 0.01 ± 0.00 | 0.25 ± 0.04 | 0.67 ± 0.11 | 2636010.00 ± 369675.41 | 100.00 ± 0.00 |
