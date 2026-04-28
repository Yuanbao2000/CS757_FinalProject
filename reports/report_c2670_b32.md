# GPU Scheduler Report
Circuit: c2670 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025401

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.017 | 0.115 | 0.019 | 0.036 | 0.410 | 1684168.75 | 100.00 |
| fanin_priority | 0.016 | 0.197 | 0.016 | 0.032 | 0.347 | 1828985.38 | 100.00 |
| DependencyAware | 0.031 | 0.127 | 0.018 | 0.049 | 0.374 | 1704635.00 | 100.00 |
| SJF | 0.016 | 0.105 | 0.016 | 0.032 | 0.377 | 1742382.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.02 ± 0.01 | 0.11 ± 0.11 | 0.02 ± 0.01 | 0.04 ± 0.01 | 0.41 ± 0.20 | 1684168.75 ± 690518.25 | 100.00 ± 0.00 |
| fanin_priority | 0.02 ± 0.00 | 0.20 ± 0.06 | 0.02 ± 0.01 | 0.03 ± 0.01 | 0.35 ± 0.11 | 1828985.38 ± 666094.75 | 100.00 ± 0.00 |
| DependencyAware | 0.03 ± 0.01 | 0.13 ± 0.05 | 0.02 ± 0.01 | 0.05 ± 0.01 | 0.37 ± 0.11 | 1704635.00 ± 667484.50 | 100.00 ± 0.00 |
| SJF | 0.02 ± 0.01 | 0.10 ± 0.05 | 0.02 ± 0.01 | 0.03 ± 0.01 | 0.38 ± 0.14 | 1742382.00 ± 702011.12 | 100.00 ± 0.00 |
