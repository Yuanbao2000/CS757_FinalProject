# GPU Scheduler Report
Circuit: c1355 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022142

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.012 | 0.008 | 0.008 | 0.113 | 2409972.75 | 100.00 |
| fanin_priority | 0.000 | 0.019 | 0.008 | 0.008 | 0.115 | 2352029.25 | 100.00 |
| DependencyAware | 0.001 | 0.011 | 0.008 | 0.009 | 0.121 | 2276872.75 | 100.00 |
| SJF | 0.000 | 0.010 | 0.008 | 0.008 | 0.123 | 2302892.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.01 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.11 ± 0.04 | 2409972.75 ± 530275.88 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.11 ± 0.03 | 2352029.25 ± 500932.06 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.01 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.05 | 2276872.75 ± 518835.91 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.05 | 2302892.00 ± 595909.75 | 100.00 ± 0.00 |
