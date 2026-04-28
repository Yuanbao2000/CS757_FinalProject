# GPU Scheduler Report
Circuit: c432 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022141

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.007 | 0.006 | 0.006 | 0.137 | 1301102.25 | 100.00 |
| fanin_priority | 0.000 | 0.011 | 0.007 | 0.007 | 0.129 | 1381789.88 | 100.00 |
| DependencyAware | 0.000 | 0.007 | 0.006 | 0.006 | 0.132 | 1361777.25 | 100.00 |
| SJF | 0.000 | 0.009 | 0.007 | 0.007 | 0.136 | 1325481.12 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.01 | 1301102.25 ± 129052.58 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.01 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.01 | 1381789.88 ± 129315.98 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.02 | 1361777.25 ± 158495.33 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.02 | 1325481.12 ± 159694.55 | 100.00 ± 0.00 |
