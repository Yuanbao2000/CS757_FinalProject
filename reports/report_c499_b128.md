# GPU Scheduler Report
Circuit: c499 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_022239

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.009 | 0.009 | 0.122 | 2257843.50 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.008 | 0.008 | 0.113 | 2404504.00 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.008 | 0.008 | 0.113 | 2401694.00 | 100.00 |
| SJF | 0.000 | 0.000 | 0.008 | 0.008 | 0.112 | 2466600.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.12 ± 0.04 | 2257843.50 ± 628683.56 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.11 ± 0.04 | 2404504.00 ± 555891.81 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.11 ± 0.04 | 2401694.00 ± 542849.19 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.11 ± 0.04 | 2466600.50 ± 618914.12 | 100.00 ± 0.00 |
