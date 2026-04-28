# GPU Scheduler Report
Circuit: c6288 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025510

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.001 | 0.016 | 0.010 | 0.011 | 0.674 | 2615703.50 | 100.00 |
| fanin_priority | 0.001 | 0.035 | 0.009 | 0.011 | 0.622 | 2796399.75 | 100.00 |
| DependencyAware | 0.001 | 0.016 | 0.010 | 0.011 | 0.668 | 2633823.50 | 100.00 |
| SJF | 0.001 | 0.028 | 0.009 | 0.010 | 0.651 | 2696045.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.67 ± 0.09 | 2615703.50 ± 338301.25 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.04 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.62 ± 0.05 | 2796399.75 ± 192802.53 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.67 ± 0.09 | 2633823.50 ± 324742.62 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.03 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.65 ± 0.08 | 2696045.25 ± 303047.47 | 100.00 ± 0.00 |
