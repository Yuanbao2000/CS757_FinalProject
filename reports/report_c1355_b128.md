# GPU Scheduler Report
Circuit: c1355 | batch_size=128 | runs=10 (averaged)

Generated: 20260427_094257

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.043 | 0.090 | 0.007 | 0.049 | 0.098 | 2633768.25 | 100.00 |
| fanin_priority | 0.040 | 0.083 | 0.006 | 0.046 | 0.089 | 2837167.25 | 100.00 |
| DependencyAware | 0.041 | 0.086 | 0.007 | 0.047 | 0.092 | 2759577.25 | 100.00 |
| SJF | 0.041 | 0.087 | 0.006 | 0.047 | 0.093 | 2763867.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.04 ± 0.01 | 0.09 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.10 ± 0.01 | 2633768.25 ± 344038.59 | 100.00 ± 0.00 |
| fanin_priority | 0.04 ± 0.00 | 0.08 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.09 ± 0.01 | 2837167.25 ± 161257.02 | 100.00 ± 0.00 |
| DependencyAware | 0.04 ± 0.00 | 0.09 ± 0.00 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.09 ± 0.00 | 2759577.25 ± 138659.09 | 100.00 ± 0.00 |
| SJF | 0.04 ± 0.00 | 0.09 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.09 ± 0.01 | 2763867.75 ± 287554.12 | 100.00 ± 0.00 |
