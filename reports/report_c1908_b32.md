# GPU Scheduler Report
Circuit: c1908 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025400

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.013 | 0.013 | 0.013 | 0.266 | 1096698.88 | 100.00 |
| fanin_priority | 0.000 | 0.016 | 0.013 | 0.013 | 0.260 | 1130527.50 | 100.00 |
| DependencyAware | 0.000 | 0.016 | 0.013 | 0.013 | 0.251 | 1147327.75 | 100.00 |
| SJF | 0.000 | 0.013 | 0.013 | 0.013 | 0.263 | 1112425.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.27 ± 0.05 | 1096698.88 ± 221297.92 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.26 ± 0.06 | 1130527.50 ± 252689.72 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.25 ± 0.05 | 1147327.75 ± 180985.52 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.26 ± 0.05 | 1112425.75 ± 230757.36 | 100.00 ± 0.00 |
