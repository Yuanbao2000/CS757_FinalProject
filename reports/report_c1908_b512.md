# GPU Scheduler Report
Circuit: c1908 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022335

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.007 | 0.007 | 0.139 | 2146217.00 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.007 | 0.007 | 0.153 | 1978846.62 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.007 | 0.007 | 0.149 | 1984255.75 | 100.00 |
| SJF | 0.000 | 0.000 | 0.007 | 0.007 | 0.142 | 2088044.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.05 | 2146217.00 ± 402093.41 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.15 ± 0.05 | 1978846.62 ± 464063.25 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.15 ± 0.04 | 1984255.75 ± 366021.66 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.04 | 2088044.00 ± 369030.06 | 100.00 ± 0.00 |
