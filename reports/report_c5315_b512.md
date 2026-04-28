# GPU Scheduler Report
Circuit: c5315 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022341

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.018 | 0.018 | 0.334 | 4017146.75 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.019 | 0.019 | 0.351 | 3894330.50 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.019 | 0.019 | 0.363 | 3766783.25 | 100.00 |
| SJF | 0.000 | 0.000 | 0.019 | 0.019 | 0.366 | 3760722.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.33 ± 0.10 | 4017146.75 ± 1266225.75 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.35 ± 0.12 | 3894330.50 ± 1257857.00 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.36 ± 0.12 | 3766783.25 ± 1321695.50 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.37 ± 0.12 | 3760722.50 ± 1363144.12 | 100.00 ± 0.00 |
