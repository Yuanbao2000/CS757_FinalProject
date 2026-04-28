# GPU Scheduler Report
Circuit: c1355 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022335

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.007 | 0.007 | 0.095 | 2682818.50 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.006 | 0.006 | 0.093 | 2735239.25 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.007 | 0.007 | 0.095 | 2686657.25 | 100.00 |
| SJF | 0.000 | 0.000 | 0.007 | 0.007 | 0.097 | 2664622.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.09 ± 0.01 | 2682818.50 ± 206072.64 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.09 ± 0.01 | 2735239.25 ± 256280.02 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.09 ± 0.01 | 2686657.25 ± 177114.11 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.10 ± 0.02 | 2664622.00 ± 375432.56 | 100.00 ± 0.00 |
