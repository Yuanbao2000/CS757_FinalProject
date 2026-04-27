# GPU Scheduler Report
Circuit: c5315 | batch_size=32 | runs=10 (averaged)

Generated: 20260427_094244

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.272 | 0.691 | 0.016 | 0.288 | 0.699 | 2313015.00 | 100.00 |
| fanin_priority | 0.259 | 0.614 | 0.014 | 0.273 | 0.624 | 2303908.75 | 100.00 |
| DependencyAware | 0.290 | 0.606 | 0.015 | 0.304 | 0.615 | 2168411.50 | 100.00 |
| SJF | 0.262 | 0.575 | 0.014 | 0.275 | 0.584 | 2372121.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.27 ± 0.10 | 0.69 ± 0.49 | 0.02 ± 0.01 | 0.29 ± 0.11 | 0.70 ± 0.49 | 2313015.00 ± 966644.56 | 100.00 ± 0.00 |
| fanin_priority | 0.26 ± 0.12 | 0.61 ± 0.27 | 0.01 ± 0.01 | 0.27 ± 0.13 | 0.62 ± 0.27 | 2303908.75 ± 881123.31 | 100.00 ± 0.00 |
| DependencyAware | 0.29 ± 0.08 | 0.61 ± 0.17 | 0.01 ± 0.00 | 0.30 ± 0.09 | 0.61 ± 0.17 | 2168411.50 ± 687373.06 | 100.00 ± 0.00 |
| SJF | 0.26 ± 0.09 | 0.58 ± 0.21 | 0.01 ± 0.00 | 0.28 ± 0.10 | 0.58 ± 0.21 | 2372121.25 ± 824816.50 | 100.00 ± 0.00 |
