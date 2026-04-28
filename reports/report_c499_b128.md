# GPU Scheduler Report
Circuit: c499 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025457

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.006 | 0.006 | 0.091 | 2744959.25 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.007 | 0.007 | 0.091 | 2750986.50 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.007 | 0.007 | 0.090 | 2787536.75 | 100.00 |
| SJF | 0.000 | 0.000 | 0.006 | 0.006 | 0.090 | 2783526.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.09 ± 0.01 | 2744959.25 ± 201962.47 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.09 ± 0.01 | 2750986.50 ± 232710.48 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.09 ± 0.01 | 2787536.75 ± 163286.70 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.09 ± 0.01 | 2783526.50 ± 223765.03 | 100.00 ± 0.00 |
