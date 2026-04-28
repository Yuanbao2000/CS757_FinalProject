# GPU Scheduler Report
Circuit: c499 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025552

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.011 | 0.011 | 0.156 | 1626869.25 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.010 | 0.010 | 0.149 | 1690840.25 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.011 | 0.011 | 0.155 | 1626962.12 | 100.00 |
| SJF | 0.000 | 0.000 | 0.011 | 0.011 | 0.157 | 1623961.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.16 ± 0.02 | 1626869.25 ± 201694.06 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.15 ± 0.02 | 1690840.25 ± 154552.59 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.15 ± 0.02 | 1626962.12 ± 162330.70 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.16 ± 0.03 | 1623961.50 ± 220254.42 | 100.00 ± 0.00 |
