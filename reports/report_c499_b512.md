# GPU Scheduler Report
Circuit: c499 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022334

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.007 | 0.007 | 0.101 | 2578479.00 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.007 | 0.007 | 0.100 | 2583160.50 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.008 | 0.008 | 0.102 | 2521111.25 | 100.00 |
| SJF | 0.000 | 0.000 | 0.008 | 0.008 | 0.107 | 2453249.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.10 ± 0.03 | 2578479.00 ± 456683.69 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.10 ± 0.02 | 2583160.50 ± 394335.97 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.10 ± 0.02 | 2521111.25 ± 405347.00 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.11 ± 0.03 | 2453249.50 ± 480754.09 | 100.00 ± 0.00 |
