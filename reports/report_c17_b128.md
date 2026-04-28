# GPU Scheduler Report
Circuit: c17 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022239

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.009 | 0.009 | 0.044 | 300379.94 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.010 | 0.010 | 0.047 | 284651.03 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.009 | 0.009 | 0.044 | 294063.91 | 100.00 |
| SJF | 0.000 | 0.000 | 0.009 | 0.009 | 0.044 | 295807.44 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.04 ± 0.00 | 300379.94 ± 26570.17 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.05 ± 0.01 | 284651.03 ± 42256.32 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.04 ± 0.00 | 294063.91 ± 23197.13 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.04 ± 0.00 | 295807.44 ± 32677.76 | 100.00 ± 0.00 |
