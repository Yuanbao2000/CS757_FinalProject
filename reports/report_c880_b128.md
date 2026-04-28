# GPU Scheduler Report
Circuit: c880 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022239

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.007 | 0.007 | 0.146 | 2147210.50 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.007 | 0.007 | 0.140 | 2210481.50 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.007 | 0.007 | 0.135 | 2282113.00 | 100.00 |
| SJF | 0.000 | 0.000 | 0.007 | 0.007 | 0.142 | 2178012.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.15 ± 0.02 | 2147210.50 ± 264446.69 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.02 | 2210481.50 ± 213427.41 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.00 | 2282113.00 ± 79852.26 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.01 | 2178012.25 ± 157616.19 | 100.00 ± 0.00 |
