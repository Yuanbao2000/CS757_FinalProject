# GPU Scheduler Report
Circuit: c1355 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022239

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.008 | 0.008 | 0.108 | 2435751.50 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.007 | 0.007 | 0.099 | 2646796.50 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.008 | 0.008 | 0.110 | 2435312.75 | 100.00 |
| SJF | 0.000 | 0.000 | 0.008 | 0.008 | 0.116 | 2378054.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.11 ± 0.02 | 2435751.50 ± 409654.19 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.10 ± 0.02 | 2646796.50 ± 383602.09 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.11 ± 0.03 | 2435312.75 ± 477929.72 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.04 | 2378054.50 ± 570110.19 | 100.00 ± 0.00 |
