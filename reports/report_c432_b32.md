# GPU Scheduler Report
Circuit: c432 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025359

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.012 | 0.011 | 0.011 | 0.316 | 742938.00 | 100.00 |
| fanin_priority | 0.000 | 0.011 | 0.010 | 0.010 | 0.216 | 827885.81 | 100.00 |
| DependencyAware | 0.000 | 0.012 | 0.010 | 0.010 | 0.218 | 820104.75 | 100.00 |
| SJF | 0.000 | 0.011 | 0.010 | 0.010 | 0.209 | 848217.62 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.32 ± 0.29 | 742938.00 ± 207554.12 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.22 ± 0.02 | 827885.81 ± 74368.41 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.22 ± 0.02 | 820104.75 ± 74191.53 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.21 ± 0.01 | 848217.62 ± 46533.12 | 100.00 ± 0.00 |
