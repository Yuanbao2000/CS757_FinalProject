# GPU Scheduler Report
Circuit: c3540 | batch_size=512 | runs=10 (averaged)

Generated: 20260427_094319

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.089 | 0.295 | 0.012 | 0.100 | 0.301 | 2878993.00 | 100.00 |
| fanin_priority | 0.083 | 0.271 | 0.011 | 0.094 | 0.276 | 3059475.50 | 100.00 |
| DependencyAware | 0.094 | 0.338 | 0.013 | 0.107 | 0.344 | 2537391.50 | 100.00 |
| SJF | 0.095 | 0.304 | 0.013 | 0.108 | 0.309 | 2840583.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.09 ± 0.03 | 0.29 ± 0.12 | 0.01 ± 0.00 | 0.10 ± 0.04 | 0.30 ± 0.12 | 2878993.00 ± 857787.62 | 100.00 ± 0.00 |
| fanin_priority | 0.08 ± 0.03 | 0.27 ± 0.10 | 0.01 ± 0.00 | 0.09 ± 0.04 | 0.28 ± 0.10 | 3059475.50 ± 826633.25 | 100.00 ± 0.00 |
| DependencyAware | 0.09 ± 0.03 | 0.34 ± 0.12 | 0.01 ± 0.00 | 0.11 ± 0.03 | 0.34 ± 0.12 | 2537391.50 ± 917417.94 | 100.00 ± 0.00 |
| SJF | 0.10 ± 0.04 | 0.30 ± 0.13 | 0.01 ± 0.01 | 0.11 ± 0.04 | 0.31 ± 0.13 | 2840583.50 ± 932773.19 | 100.00 ± 0.00 |
