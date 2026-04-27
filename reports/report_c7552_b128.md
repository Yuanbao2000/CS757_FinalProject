# GPU Scheduler Report
Circuit: c7552 | batch_size=128 | runs=10 (averaged)

Generated: 20260427_094316

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.097 | 0.273 | 0.014 | 0.111 | 0.280 | 5489586.00 | 100.00 |
| fanin_priority | 0.102 | 0.294 | 0.014 | 0.116 | 0.301 | 5012549.00 | 100.00 |
| DependencyAware | 0.095 | 0.259 | 0.014 | 0.109 | 0.264 | 5567857.00 | 100.00 |
| SJF | 0.088 | 0.241 | 0.013 | 0.101 | 0.247 | 5943730.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.10 ± 0.02 | 0.27 ± 0.07 | 0.01 ± 0.00 | 0.11 ± 0.02 | 0.28 ± 0.08 | 5489586.00 ± 1061768.88 | 100.00 ± 0.00 |
| fanin_priority | 0.10 ± 0.01 | 0.29 ± 0.05 | 0.01 ± 0.00 | 0.12 ± 0.01 | 0.30 ± 0.06 | 5012549.00 ± 904017.31 | 100.00 ± 0.00 |
| DependencyAware | 0.09 ± 0.01 | 0.26 ± 0.02 | 0.01 ± 0.00 | 0.11 ± 0.01 | 0.26 ± 0.02 | 5567857.00 ± 487829.12 | 100.00 ± 0.00 |
| SJF | 0.09 ± 0.01 | 0.24 ± 0.02 | 0.01 ± 0.00 | 0.10 ± 0.01 | 0.25 ± 0.02 | 5943730.00 ± 441509.22 | 100.00 ± 0.00 |
