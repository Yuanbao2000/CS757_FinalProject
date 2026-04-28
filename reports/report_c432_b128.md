# GPU Scheduler Report
Circuit: c432 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025457

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.006 | 0.006 | 0.121 | 1471396.25 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.005 | 0.005 | 0.116 | 1530519.12 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.006 | 0.006 | 0.120 | 1472145.88 | 100.00 |
| SJF | 0.000 | 0.000 | 0.006 | 0.006 | 0.123 | 1441572.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.01 | 1471396.25 ± 77420.05 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.01 | 1530519.12 ± 81185.66 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.00 | 1472145.88 ± 51025.36 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.01 | 1441572.25 ± 94842.28 | 100.00 ± 0.00 |
