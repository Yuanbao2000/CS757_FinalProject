# GPU Scheduler Report
Circuit: c6288 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022155

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.006 | 0.077 | 0.009 | 0.015 | 0.720 | 2461069.50 | 100.00 |
| fanin_priority | 0.006 | 0.079 | 0.009 | 0.014 | 0.693 | 2517723.50 | 100.00 |
| DependencyAware | 0.006 | 0.078 | 0.009 | 0.015 | 0.748 | 2356826.00 | 100.00 |
| SJF | 0.007 | 0.111 | 0.009 | 0.015 | 0.708 | 2473706.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.01 ± 0.00 | 0.08 ± 0.03 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.72 ± 0.12 | 2461069.50 ± 360189.75 | 100.00 ± 0.00 |
| fanin_priority | 0.01 ± 0.00 | 0.08 ± 0.02 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.69 ± 0.06 | 2517723.50 ± 207893.45 | 100.00 ± 0.00 |
| DependencyAware | 0.01 ± 0.00 | 0.08 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.75 ± 0.10 | 2356826.00 ± 300243.50 | 100.00 ± 0.00 |
| SJF | 0.01 ± 0.00 | 0.11 ± 0.04 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.71 ± 0.08 | 2473706.25 ± 248708.80 | 100.00 ± 0.00 |
