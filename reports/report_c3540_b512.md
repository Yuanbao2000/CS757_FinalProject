# GPU Scheduler Report
Circuit: c3540 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025555

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.011 | 0.011 | 0.291 | 2940358.25 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.010 | 0.010 | 0.255 | 3302099.25 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.010 | 0.010 | 0.263 | 3201320.50 | 100.00 |
| SJF | 0.000 | 0.000 | 0.009 | 0.009 | 0.225 | 3437597.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.29 ± 0.12 | 2940358.25 ± 786299.12 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.26 ± 0.11 | 3302099.25 ± 730837.44 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.26 ± 0.11 | 3201320.50 ± 710093.81 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.22 ± 0.03 | 3437597.25 ± 359535.25 | 100.00 ± 0.00 |
