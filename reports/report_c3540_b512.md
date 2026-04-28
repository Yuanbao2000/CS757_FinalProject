# GPU Scheduler Report
Circuit: c3540 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022337

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.010 | 0.010 | 0.246 | 3185758.25 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.011 | 0.011 | 0.282 | 3012353.50 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.009 | 0.009 | 0.228 | 3387232.75 | 100.00 |
| SJF | 0.000 | 0.000 | 0.009 | 0.009 | 0.226 | 3416368.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.25 ± 0.04 | 3185758.25 ± 488271.03 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.28 ± 0.11 | 3012353.50 ± 812464.56 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.02 | 3387232.75 ± 327099.88 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.02 | 3416368.00 ± 335795.34 | 100.00 ± 0.00 |
