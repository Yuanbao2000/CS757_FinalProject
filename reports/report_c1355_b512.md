# GPU Scheduler Report
Circuit: c1355 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025552

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.011 | 0.011 | 0.163 | 1584276.38 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.012 | 0.012 | 0.163 | 1585276.75 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.012 | 0.012 | 0.166 | 1562554.88 | 100.00 |
| SJF | 0.000 | 0.000 | 0.011 | 0.011 | 0.154 | 1656471.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.16 ± 0.02 | 1584276.38 ± 221767.03 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.16 ± 0.03 | 1585276.75 ± 236529.20 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.17 ± 0.03 | 1562554.88 ± 223584.08 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.15 ± 0.01 | 1656471.00 ± 122731.05 | 100.00 ± 0.00 |
