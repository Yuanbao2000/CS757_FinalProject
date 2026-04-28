# GPU Scheduler Report
Circuit: c5315 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022245

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.002 | 0.020 | 0.013 | 0.015 | 0.261 | 4869179.00 | 100.00 |
| fanin_priority | 0.001 | 0.067 | 0.013 | 0.014 | 0.263 | 4722188.50 | 100.00 |
| DependencyAware | 0.004 | 0.044 | 0.013 | 0.017 | 0.252 | 4912534.50 | 100.00 |
| SJF | 0.002 | 0.048 | 0.013 | 0.016 | 0.287 | 4388652.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.26 ± 0.06 | 4869179.00 ± 888976.19 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.07 ± 0.02 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.26 ± 0.04 | 4722188.50 ± 590709.25 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.04 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.25 ± 0.03 | 4912534.50 ± 564970.69 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.05 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.29 ± 0.06 | 4388652.00 ± 693913.38 | 100.00 ± 0.00 |
