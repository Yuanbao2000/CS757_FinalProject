# GPU Scheduler Report
Circuit: c2670 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022336

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.010 | 0.010 | 0.123 | 4622656.00 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.010 | 0.010 | 0.127 | 4491951.00 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.010 | 0.010 | 0.138 | 4295942.00 | 100.00 |
| SJF | 0.000 | 0.000 | 0.011 | 0.011 | 0.140 | 4205660.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.01 | 4622656.00 ± 376286.66 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.01 | 4491951.00 ± 452478.44 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.04 | 4295942.00 ± 793253.44 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.03 | 4205660.50 ± 777144.69 | 100.00 ± 0.00 |
