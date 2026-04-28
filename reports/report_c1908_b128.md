# GPU Scheduler Report
Circuit: c1908 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022239

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.006 | 0.006 | 0.132 | 2143989.75 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.006 | 0.006 | 0.134 | 2114094.00 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.006 | 0.006 | 0.133 | 2117392.25 | 100.00 |
| SJF | 0.000 | 0.000 | 0.006 | 0.006 | 0.126 | 2230505.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.01 | 2143989.75 ± 200474.14 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.02 | 2114094.00 ± 234935.12 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.01 | 2117392.25 ± 192654.95 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.01 | 2230505.50 ± 127442.30 | 100.00 ± 0.00 |
