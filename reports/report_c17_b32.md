# GPU Scheduler Report
Circuit: c17 | batch_size=32 | runs=10 (averaged)

Generated: 20260427_094236

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.008 | 0.020 | 0.005 | 0.014 | 0.025 | 545174.12 | 100.00 |
| fanin_priority | 0.007 | 0.018 | 0.004 | 0.011 | 0.022 | 592704.19 | 100.00 |
| DependencyAware | 0.008 | 0.020 | 0.005 | 0.013 | 0.024 | 553769.62 | 100.00 |
| SJF | 0.007 | 0.018 | 0.005 | 0.012 | 0.022 | 582743.44 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.01 | 545174.12 ± 76754.05 | 100.00 ± 0.00 |
| fanin_priority | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.00 | 592704.19 ± 19792.19 | 100.00 ± 0.00 |
| DependencyAware | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.00 | 553769.62 ± 57025.38 | 100.00 ± 0.00 |
| SJF | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.02 ± 0.00 | 582743.44 ± 22600.72 | 100.00 ± 0.00 |
