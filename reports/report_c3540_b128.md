# GPU Scheduler Report
Circuit: c3540 | batch_size=128 | runs=10 (averaged)

Generated: 20260427_094259

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.078 | 0.259 | 0.010 | 0.088 | 0.264 | 3165898.75 | 100.00 |
| fanin_priority | 0.070 | 0.229 | 0.009 | 0.079 | 0.233 | 3433918.50 | 100.00 |
| DependencyAware | 0.067 | 0.214 | 0.009 | 0.076 | 0.218 | 3510792.50 | 100.00 |
| SJF | 0.067 | 0.227 | 0.009 | 0.075 | 0.232 | 3427720.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.08 ± 0.03 | 0.26 ± 0.10 | 0.01 ± 0.00 | 0.09 ± 0.03 | 0.26 ± 0.10 | 3165898.75 ± 754546.38 | 100.00 ± 0.00 |
| fanin_priority | 0.07 ± 0.01 | 0.23 ± 0.07 | 0.01 ± 0.00 | 0.08 ± 0.02 | 0.23 ± 0.07 | 3433918.50 ± 585395.56 | 100.00 ± 0.00 |
| DependencyAware | 0.07 ± 0.01 | 0.21 ± 0.01 | 0.01 ± 0.00 | 0.08 ± 0.01 | 0.22 ± 0.01 | 3510792.50 ± 223837.00 | 100.00 ± 0.00 |
| SJF | 0.07 ± 0.01 | 0.23 ± 0.06 | 0.01 ± 0.00 | 0.08 ± 0.01 | 0.23 ± 0.06 | 3427720.50 ± 568293.50 | 100.00 ± 0.00 |
