# GPU Scheduler Report
Circuit: c6288 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022348

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.011 | 0.011 | 0.700 | 2581505.50 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.010 | 0.010 | 0.611 | 2864768.75 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.011 | 0.011 | 0.697 | 2535056.75 | 100.00 |
| SJF | 0.000 | 0.000 | 0.010 | 0.010 | 0.613 | 2848649.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.70 ± 0.16 | 2581505.50 ± 487862.22 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.61 ± 0.07 | 2864768.75 ± 275979.28 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.70 ± 0.10 | 2535056.75 ± 366860.25 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.61 ± 0.06 | 2848649.50 ± 239615.83 | 100.00 ± 0.00 |
