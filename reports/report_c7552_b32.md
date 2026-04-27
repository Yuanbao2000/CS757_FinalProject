# GPU Scheduler Report
Circuit: c7552 | batch_size=32 | runs=10 (averaged)

Generated: 20260427_094256

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.293 | 0.626 | 0.013 | 0.306 | 0.635 | 2616939.75 | 100.00 |
| fanin_priority | 0.279 | 0.602 | 0.012 | 0.291 | 0.609 | 2752675.50 | 100.00 |
| DependencyAware | 0.280 | 0.588 | 0.013 | 0.293 | 0.602 | 2680757.50 | 100.00 |
| SJF | 0.298 | 0.648 | 0.013 | 0.311 | 0.656 | 2508739.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.29 ± 0.10 | 0.63 ± 0.23 | 0.01 ± 0.00 | 0.31 ± 0.11 | 0.64 ± 0.23 | 2616939.75 ± 885356.12 | 100.00 ± 0.00 |
| fanin_priority | 0.28 ± 0.11 | 0.60 ± 0.23 | 0.01 ± 0.00 | 0.29 ± 0.12 | 0.61 ± 0.24 | 2752675.50 ± 925629.06 | 100.00 ± 0.00 |
| DependencyAware | 0.28 ± 0.08 | 0.59 ± 0.19 | 0.01 ± 0.00 | 0.29 ± 0.09 | 0.60 ± 0.20 | 2680757.50 ± 796522.44 | 100.00 ± 0.00 |
| SJF | 0.30 ± 0.11 | 0.65 ± 0.23 | 0.01 ± 0.00 | 0.31 ± 0.11 | 0.66 ± 0.23 | 2508739.25 ± 838784.31 | 100.00 ± 0.00 |
