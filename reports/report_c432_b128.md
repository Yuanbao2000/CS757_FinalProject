# GPU Scheduler Report
Circuit: c432 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022239

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.009 | 0.009 | 0.175 | 1138879.25 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.007 | 0.007 | 0.168 | 1189062.00 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.009 | 0.009 | 0.170 | 1200244.50 | 100.00 |
| SJF | 0.000 | 0.000 | 0.008 | 0.008 | 0.167 | 1188828.62 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.18 ± 0.07 | 1138879.25 ± 346340.50 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.17 ± 0.07 | 1189062.00 ± 335681.22 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.17 ± 0.08 | 1200244.50 ± 344649.28 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.17 ± 0.07 | 1188828.62 ± 331840.22 | 100.00 ± 0.00 |
