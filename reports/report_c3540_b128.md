# GPU Scheduler Report
Circuit: c3540 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022242

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.009 | 0.009 | 0.219 | 3539400.75 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.010 | 0.010 | 0.235 | 3331283.50 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.010 | 0.010 | 0.266 | 3072411.50 | 100.00 |
| SJF | 0.000 | 0.000 | 0.009 | 0.009 | 0.213 | 3602097.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.22 ± 0.03 | 3539400.75 ± 367412.06 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.04 | 3331283.50 ± 453858.78 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.27 ± 0.09 | 3072411.50 ± 639758.38 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.21 ± 0.01 | 3602097.25 ± 199564.64 | 100.00 ± 0.00 |
