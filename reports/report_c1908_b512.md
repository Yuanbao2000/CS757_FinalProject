# GPU Scheduler Report
Circuit: c1908 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025552

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.009 | 0.009 | 0.199 | 1410273.62 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.009 | 0.009 | 0.197 | 1426124.12 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.009 | 0.009 | 0.194 | 1443802.62 | 100.00 |
| SJF | 0.000 | 0.000 | 0.009 | 0.009 | 0.194 | 1446971.38 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.20 ± 0.01 | 1410273.62 ± 57775.55 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.20 ± 0.01 | 1426124.12 ± 59136.25 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.19 ± 0.01 | 1443802.62 ± 42070.35 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.19 ± 0.01 | 1446971.38 ± 38271.15 | 100.00 ± 0.00 |
