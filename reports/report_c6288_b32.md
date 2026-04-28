# GPU Scheduler Report
Circuit: c6288 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025414

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.007 | 0.083 | 0.012 | 0.018 | 0.950 | 2077786.38 | 100.00 |
| fanin_priority | 0.007 | 0.097 | 0.012 | 0.019 | 0.966 | 2000402.00 | 100.00 |
| DependencyAware | 0.008 | 0.109 | 0.012 | 0.020 | 0.980 | 1946042.25 | 100.00 |
| SJF | 0.006 | 0.109 | 0.012 | 0.018 | 0.932 | 2084893.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.01 ± 0.00 | 0.08 ± 0.03 | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.95 ± 0.39 | 2077786.38 ± 645770.88 | 100.00 ± 0.00 |
| fanin_priority | 0.01 ± 0.00 | 0.10 ± 0.04 | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.97 ± 0.35 | 2000402.00 ± 595402.44 | 100.00 ± 0.00 |
| DependencyAware | 0.01 ± 0.00 | 0.11 ± 0.03 | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.98 ± 0.33 | 1946042.25 ± 545419.00 | 100.00 ± 0.00 |
| SJF | 0.01 ± 0.00 | 0.11 ± 0.04 | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.93 ± 0.36 | 2084893.00 ± 613097.88 | 100.00 ± 0.00 |
