# GPU Scheduler Report
Circuit: c17 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022334

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.006 | 0.006 | 0.026 | 524913.44 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.006 | 0.006 | 0.026 | 513412.00 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.005 | 0.005 | 0.025 | 539130.31 | 100.00 |
| SJF | 0.000 | 0.000 | 0.005 | 0.005 | 0.025 | 535342.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.03 ± 0.01 | 524913.44 ± 90089.84 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.03 ± 0.00 | 513412.00 ± 70207.30 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.00 | 539130.31 ± 64915.36 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.00 | 535342.75 ± 50088.57 | 100.00 ± 0.00 |
