# GPU Scheduler Report
Circuit: c880 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025457

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.007 | 0.007 | 0.138 | 2248022.25 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.006 | 0.006 | 0.133 | 2301550.25 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.007 | 0.007 | 0.132 | 2332283.00 | 100.00 |
| SJF | 0.000 | 0.000 | 0.006 | 0.006 | 0.133 | 2306456.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.01 | 2248022.25 ± 177137.12 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.00 | 2301550.25 ± 62858.55 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.01 | 2332283.00 ± 111641.30 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.00 | 2306456.25 ± 79140.86 | 100.00 ± 0.00 |
