# GPU Scheduler Report
Circuit: c1908 | batch_size=512 | runs=10 (averaged)

Generated: 20260427_094316

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.053 | 0.123 | 0.006 | 0.059 | 0.129 | 2201038.50 | 100.00 |
| fanin_priority | 0.055 | 0.124 | 0.006 | 0.061 | 0.129 | 2188900.50 | 100.00 |
| DependencyAware | 0.053 | 0.127 | 0.006 | 0.060 | 0.132 | 2123914.00 | 100.00 |
| SJF | 0.056 | 0.127 | 0.006 | 0.062 | 0.132 | 2193463.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.05 ± 0.01 | 0.12 ± 0.01 | 0.01 ± 0.00 | 0.06 ± 0.01 | 0.13 ± 0.01 | 2201038.50 ± 214306.78 | 100.00 ± 0.00 |
| fanin_priority | 0.05 ± 0.01 | 0.12 ± 0.01 | 0.01 ± 0.00 | 0.06 ± 0.01 | 0.13 ± 0.01 | 2188900.50 ± 206656.77 | 100.00 ± 0.00 |
| DependencyAware | 0.05 ± 0.00 | 0.13 ± 0.01 | 0.01 ± 0.00 | 0.06 ± 0.01 | 0.13 ± 0.01 | 2123914.00 ± 141476.06 | 100.00 ± 0.00 |
| SJF | 0.06 ± 0.02 | 0.13 ± 0.03 | 0.01 ± 0.00 | 0.06 ± 0.02 | 0.13 ± 0.03 | 2193463.75 ± 312382.34 | 100.00 ± 0.00 |
