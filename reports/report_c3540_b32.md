# GPU Scheduler Report
Circuit: c3540 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022144

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.006 | 0.029 | 0.008 | 0.014 | 0.273 | 2846721.25 | 100.00 |
| fanin_priority | 0.003 | 0.064 | 0.008 | 0.010 | 0.278 | 2760609.25 | 100.00 |
| DependencyAware | 0.009 | 0.098 | 0.008 | 0.017 | 0.293 | 2699997.25 | 100.00 |
| SJF | 0.005 | 0.109 | 0.008 | 0.013 | 0.304 | 2654605.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.01 ± 0.00 | 0.03 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.27 ± 0.04 | 2846721.25 ± 354108.31 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.06 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.28 ± 0.02 | 2760609.25 ± 196949.75 | 100.00 ± 0.00 |
| DependencyAware | 0.01 ± 0.00 | 0.10 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.29 ± 0.07 | 2699997.25 ± 411110.78 | 100.00 ± 0.00 |
| SJF | 0.01 ± 0.00 | 0.11 ± 0.03 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.30 ± 0.08 | 2654605.00 ± 529076.00 | 100.00 ± 0.00 |
