# GPU Scheduler Report
Circuit: c1908 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022142

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.009 | 0.007 | 0.007 | 0.135 | 2159739.25 | 100.00 |
| fanin_priority | 0.000 | 0.008 | 0.007 | 0.007 | 0.136 | 2137833.50 | 100.00 |
| DependencyAware | 0.000 | 0.008 | 0.006 | 0.006 | 0.127 | 2208588.25 | 100.00 |
| SJF | 0.000 | 0.008 | 0.006 | 0.006 | 0.125 | 2242736.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.04 | 2159739.25 ± 353796.59 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.03 | 2137833.50 ± 330490.94 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.01 | 2208588.25 ± 117223.78 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.00 | 2242736.50 ± 76254.25 | 100.00 ± 0.00 |
