# GPU Scheduler Report
Circuit: c3540 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025500

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.009 | 0.009 | 0.236 | 3429175.25 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.009 | 0.009 | 0.221 | 3473359.25 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.011 | 0.011 | 0.278 | 3096632.75 | 100.00 |
| SJF | 0.000 | 0.000 | 0.009 | 0.009 | 0.215 | 3579445.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.24 ± 0.08 | 3429175.25 ± 603044.75 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.22 ± 0.02 | 3473359.25 ± 272059.06 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.28 ± 0.12 | 3096632.75 ± 838341.94 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.22 ± 0.02 | 3579445.25 ± 313020.41 | 100.00 ± 0.00 |
