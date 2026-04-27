# GPU Scheduler Report
Circuit: c1908 | batch_size=128 | runs=10 (averaged)

Generated: 20260427_094257

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.050 | 0.121 | 0.006 | 0.056 | 0.126 | 2246374.00 | 100.00 |
| fanin_priority | 0.050 | 0.119 | 0.006 | 0.056 | 0.123 | 2277260.00 | 100.00 |
| DependencyAware | 0.052 | 0.123 | 0.006 | 0.058 | 0.128 | 2200164.50 | 100.00 |
| SJF | 0.051 | 0.120 | 0.006 | 0.057 | 0.124 | 2259733.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.05 ± 0.00 | 0.12 ± 0.01 | 0.01 ± 0.00 | 0.06 ± 0.00 | 0.13 ± 0.01 | 2246374.00 ± 200853.39 | 100.00 ± 0.00 |
| fanin_priority | 0.05 ± 0.00 | 0.12 ± 0.01 | 0.01 ± 0.00 | 0.06 ± 0.00 | 0.12 ± 0.01 | 2277260.00 ± 110610.32 | 100.00 ± 0.00 |
| DependencyAware | 0.05 ± 0.00 | 0.12 ± 0.01 | 0.01 ± 0.00 | 0.06 ± 0.00 | 0.13 ± 0.01 | 2200164.50 ± 130467.06 | 100.00 ± 0.00 |
| SJF | 0.05 ± 0.01 | 0.12 ± 0.01 | 0.01 ± 0.00 | 0.06 ± 0.01 | 0.12 ± 0.01 | 2259733.25 ± 148849.27 | 100.00 ± 0.00 |
