# GPU Scheduler Report
Circuit: c499 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025359

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.001 | 0.015 | 0.012 | 0.012 | 0.171 | 1476254.62 | 100.00 |
| fanin_priority | 0.001 | 0.024 | 0.010 | 0.011 | 0.172 | 1472565.00 | 100.00 |
| DependencyAware | 0.001 | 0.016 | 0.012 | 0.013 | 0.174 | 1449705.88 | 100.00 |
| SJF | 0.001 | 0.014 | 0.011 | 0.012 | 0.172 | 1472781.12 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.17 ± 0.02 | 1476254.62 ± 158850.05 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.17 ± 0.03 | 1472565.00 ± 171103.89 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.17 ± 0.02 | 1449705.88 ± 152762.58 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.17 ± 0.02 | 1472781.12 ± 184212.39 | 100.00 ± 0.00 |
