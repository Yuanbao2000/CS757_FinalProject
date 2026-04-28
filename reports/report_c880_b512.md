# GPU Scheduler Report
Circuit: c880 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025552

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.010 | 0.010 | 0.213 | 1445089.75 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.010 | 0.010 | 0.210 | 1461829.75 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.010 | 0.010 | 0.214 | 1438427.25 | 100.00 |
| SJF | 0.000 | 0.000 | 0.010 | 0.010 | 0.212 | 1452345.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.21 ± 0.01 | 1445089.75 ± 62391.15 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.21 ± 0.01 | 1461829.75 ± 49432.50 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.21 ± 0.01 | 1438427.25 ± 55255.77 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.21 ± 0.01 | 1452345.75 ± 58443.73 | 100.00 ± 0.00 |
