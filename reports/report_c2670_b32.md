# GPU Scheduler Report
Circuit: c2670 | batch_size=32 | runs=10 (averaged)

Generated: 20260427_094238

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.076 | 0.175 | 0.008 | 0.085 | 0.179 | 3290645.00 | 100.00 |
| fanin_priority | 0.067 | 0.150 | 0.007 | 0.075 | 0.154 | 3688340.00 | 100.00 |
| DependencyAware | 0.073 | 0.173 | 0.008 | 0.082 | 0.177 | 3293363.75 | 100.00 |
| SJF | 0.072 | 0.186 | 0.008 | 0.080 | 0.191 | 3211518.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.08 ± 0.03 | 0.18 ± 0.05 | 0.01 ± 0.00 | 0.08 ± 0.03 | 0.18 ± 0.05 | 3290645.00 ± 568170.94 | 100.00 ± 0.00 |
| fanin_priority | 0.07 ± 0.01 | 0.15 ± 0.02 | 0.01 ± 0.00 | 0.07 ± 0.01 | 0.15 ± 0.02 | 3688340.00 ± 326051.09 | 100.00 ± 0.00 |
| DependencyAware | 0.07 ± 0.02 | 0.17 ± 0.04 | 0.01 ± 0.00 | 0.08 ± 0.02 | 0.18 ± 0.04 | 3293363.75 ± 532890.12 | 100.00 ± 0.00 |
| SJF | 0.07 ± 0.02 | 0.19 ± 0.07 | 0.01 ± 0.00 | 0.08 ± 0.03 | 0.19 ± 0.07 | 3211518.50 ± 698903.00 | 100.00 ± 0.00 |
