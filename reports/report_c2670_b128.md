# GPU Scheduler Report
Circuit: c2670 | batch_size=128 | runs=10 (averaged)

Generated: 20260427_094258

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.040 | 0.125 | 0.010 | 0.050 | 0.130 | 4395037.00 | 100.00 |
| fanin_priority | 0.037 | 0.125 | 0.009 | 0.047 | 0.130 | 4398803.50 | 100.00 |
| DependencyAware | 0.037 | 0.139 | 0.010 | 0.046 | 0.145 | 4075110.00 | 100.00 |
| SJF | 0.044 | 0.148 | 0.011 | 0.055 | 0.153 | 4006559.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.04 ± 0.01 | 0.13 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.13 ± 0.01 | 4395037.00 ± 421060.94 | 100.00 ± 0.00 |
| fanin_priority | 0.04 ± 0.01 | 0.12 ± 0.02 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.13 ± 0.02 | 4398803.50 ± 522136.38 | 100.00 ± 0.00 |
| DependencyAware | 0.04 ± 0.00 | 0.14 ± 0.04 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.15 ± 0.04 | 4075110.00 ± 763481.25 | 100.00 ± 0.00 |
| SJF | 0.04 ± 0.01 | 0.15 ± 0.06 | 0.01 ± 0.00 | 0.06 ± 0.02 | 0.15 ± 0.06 | 4006559.25 ± 885608.81 | 100.00 ± 0.00 |
