# GPU Scheduler Report
Circuit: c1355 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025457

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.007 | 0.007 | 0.101 | 2614093.50 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.008 | 0.008 | 0.111 | 2506683.50 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.008 | 0.008 | 0.114 | 2481988.00 | 100.00 |
| SJF | 0.000 | 0.000 | 0.008 | 0.008 | 0.104 | 2620343.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.10 ± 0.03 | 2614093.50 ± 435861.91 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.11 ± 0.04 | 2506683.50 ± 624932.62 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.11 ± 0.05 | 2481988.00 ± 641367.44 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.10 ± 0.04 | 2620343.25 ± 520840.25 | 100.00 ± 0.00 |
