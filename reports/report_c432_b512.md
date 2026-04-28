# GPU Scheduler Report
Circuit: c432 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022334

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.007 | 0.007 | 0.123 | 1444127.25 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.006 | 0.006 | 0.125 | 1428485.88 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.006 | 0.006 | 0.127 | 1407661.25 | 100.00 |
| SJF | 0.000 | 0.000 | 0.006 | 0.006 | 0.125 | 1434271.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.01 | 1444127.25 ± 111601.45 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.01 | 1428485.88 ± 112628.76 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.01 | 1407661.25 ± 138131.14 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.01 | 1434271.25 ± 151916.98 | 100.00 ± 0.00 |
