# GPU Scheduler Report
Circuit: c17 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025551

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.010 | 0.010 | 0.053 | 297644.44 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.008 | 0.008 | 0.039 | 334675.06 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.008 | 0.008 | 0.040 | 323814.97 | 100.00 |
| SJF | 0.000 | 0.000 | 0.008 | 0.008 | 0.038 | 342806.16 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.01 | 0.01 ± 0.01 | 0.05 ± 0.04 | 297644.44 ± 76334.52 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.04 ± 0.00 | 334675.06 ± 18223.10 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.04 ± 0.00 | 323814.97 ± 20952.59 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.04 ± 0.00 | 342806.16 ± 15238.24 | 100.00 ± 0.00 |
