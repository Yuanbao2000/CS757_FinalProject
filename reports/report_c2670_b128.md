# GPU Scheduler Report
Circuit: c2670 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025458

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.001 | 0.011 | 0.009 | 0.010 | 0.131 | 4363223.00 | 100.00 |
| fanin_priority | 0.001 | 0.012 | 0.009 | 0.010 | 0.126 | 4489723.50 | 100.00 |
| DependencyAware | 0.001 | 0.014 | 0.011 | 0.011 | 0.145 | 4217329.00 | 100.00 |
| SJF | 0.001 | 0.012 | 0.010 | 0.010 | 0.130 | 4411425.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.02 | 4363223.00 ± 508241.78 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.01 | 4489723.50 ± 245734.31 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.14 ± 0.06 | 4217329.00 ± 835156.00 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.13 ± 0.02 | 4411425.00 ± 464493.72 | 100.00 ± 0.00 |
