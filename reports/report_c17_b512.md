# GPU Scheduler Report
Circuit: c17 | batch_size=512 | runs=10 (averaged)

Generated: 20260427_094316

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.009 | 0.022 | 0.006 | 0.015 | 0.028 | 489813.66 | 100.00 |
| fanin_priority | 0.011 | 0.025 | 0.007 | 0.018 | 0.029 | 491315.81 | 100.00 |
| DependencyAware | 0.009 | 0.022 | 0.005 | 0.014 | 0.027 | 520653.34 | 100.00 |
| SJF | 0.008 | 0.020 | 0.005 | 0.013 | 0.024 | 549031.12 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.03 ± 0.01 | 489813.66 ± 102746.58 | 100.00 ± 0.00 |
| fanin_priority | 0.01 ± 0.01 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.03 ± 0.01 | 491315.81 ± 117607.61 | 100.00 ± 0.00 |
| DependencyAware | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.01 | 0.03 ± 0.01 | 520653.34 ± 102238.54 | 100.00 ± 0.00 |
| SJF | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.00 | 549031.12 ± 70775.89 | 100.00 ± 0.00 |
