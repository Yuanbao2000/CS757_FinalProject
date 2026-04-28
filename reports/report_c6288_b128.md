# GPU Scheduler Report
Circuit: c6288 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022253

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.001 | 0.017 | 0.013 | 0.014 | 0.909 | 2153627.25 | 100.00 |
| fanin_priority | 0.001 | 0.039 | 0.014 | 0.015 | 0.974 | 1984716.00 | 100.00 |
| DependencyAware | 0.002 | 0.022 | 0.013 | 0.014 | 0.872 | 2248076.50 | 100.00 |
| SJF | 0.001 | 0.038 | 0.014 | 0.015 | 0.972 | 1948890.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.01 | 0.91 ± 0.36 | 2153627.25 ± 645177.62 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.04 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.97 ± 0.33 | 1984716.00 ± 639756.19 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.01 | 0.87 ± 0.35 | 2248076.50 ± 666208.06 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.04 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.97 ± 0.29 | 1948890.00 ± 593232.31 | 100.00 ± 0.00 |
