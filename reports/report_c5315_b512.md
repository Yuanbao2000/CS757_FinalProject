# GPU Scheduler Report
Circuit: c5315 | batch_size=512 | runs=10 (averaged)

Generated: 20260427_094323

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.091 | 0.321 | 0.018 | 0.109 | 0.328 | 4258096.50 | 100.00 |
| fanin_priority | 0.088 | 0.324 | 0.017 | 0.105 | 0.332 | 4156039.50 | 100.00 |
| DependencyAware | 0.095 | 0.345 | 0.019 | 0.114 | 0.356 | 3850876.00 | 100.00 |
| SJF | 0.093 | 0.327 | 0.018 | 0.111 | 0.335 | 4315256.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.09 ± 0.03 | 0.32 ± 0.13 | 0.02 ± 0.01 | 0.11 ± 0.04 | 0.33 ± 0.13 | 4258096.50 ± 1394191.00 | 100.00 ± 0.00 |
| fanin_priority | 0.09 ± 0.03 | 0.32 ± 0.13 | 0.02 ± 0.01 | 0.11 ± 0.04 | 0.33 ± 0.13 | 4156039.50 ± 1288799.62 | 100.00 ± 0.00 |
| DependencyAware | 0.09 ± 0.03 | 0.34 ± 0.11 | 0.02 ± 0.01 | 0.11 ± 0.03 | 0.36 ± 0.12 | 3850876.00 ± 1312953.25 | 100.00 ± 0.00 |
| SJF | 0.09 ± 0.03 | 0.33 ± 0.15 | 0.02 ± 0.01 | 0.11 ± 0.04 | 0.34 ± 0.15 | 4315256.50 ± 1527487.25 | 100.00 ± 0.00 |
