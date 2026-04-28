# GPU Scheduler Report
Circuit: c2670 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022240

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.001 | 0.014 | 0.011 | 0.011 | 0.140 | 4133210.75 | 100.00 |
| fanin_priority | 0.001 | 0.016 | 0.010 | 0.011 | 0.128 | 4439285.00 | 100.00 |
| DependencyAware | 0.001 | 0.014 | 0.012 | 0.012 | 0.156 | 3895766.75 | 100.00 |
| SJF | 0.001 | 0.013 | 0.011 | 0.011 | 0.145 | 4020443.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.01 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.02 | 4133210.75 ± 621975.12 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.01 | 4439285.00 ± 320355.38 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.16 ± 0.05 | 3895766.75 ± 835599.38 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.03 | 4020443.50 ± 643351.94 | 100.00 ± 0.00 |
