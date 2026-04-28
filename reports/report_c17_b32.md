# GPU Scheduler Report
Circuit: c17 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022141

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.006 | 0.006 | 0.029 | 481641.69 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.005 | 0.005 | 0.024 | 535948.12 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.005 | 0.005 | 0.025 | 527806.56 | 100.00 |
| SJF | 0.000 | 0.000 | 0.005 | 0.005 | 0.024 | 555937.31 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.03 ± 0.01 | 481641.69 ± 103761.24 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.00 | 535948.12 ± 37691.88 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.00 | 527806.56 ± 61505.65 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 555937.31 ± 39782.83 | 100.00 ± 0.00 |
