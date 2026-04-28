# GPU Scheduler Report
Circuit: c17 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025359

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.009 | 0.009 | 0.040 | 330122.03 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.008 | 0.008 | 0.041 | 327501.94 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.008 | 0.008 | 0.039 | 337639.25 | 100.00 |
| SJF | 0.000 | 0.000 | 0.008 | 0.008 | 0.038 | 345638.16 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.04 ± 0.01 | 330122.03 ± 43992.87 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.04 ± 0.01 | 327501.94 ± 41585.82 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.04 ± 0.00 | 337639.25 ± 21746.59 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.04 ± 0.00 | 345638.16 ± 23738.39 | 100.00 ± 0.00 |
