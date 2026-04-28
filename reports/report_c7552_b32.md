# GPU Scheduler Report
Circuit: c7552 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025419

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.021 | 0.061 | 0.009 | 0.030 | 0.423 | 3486838.50 | 100.00 |
| fanin_priority | 0.013 | 0.263 | 0.009 | 0.021 | 0.443 | 3342014.50 | 100.00 |
| DependencyAware | 0.045 | 0.362 | 0.011 | 0.056 | 0.507 | 2892597.50 | 100.00 |
| SJF | 0.016 | 0.249 | 0.009 | 0.024 | 0.433 | 3389002.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.02 ± 0.00 | 0.06 ± 0.01 | 0.01 ± 0.00 | 0.03 ± 0.00 | 0.42 ± 0.04 | 3486838.50 ± 327708.88 | 100.00 ± 0.00 |
| fanin_priority | 0.01 ± 0.00 | 0.26 ± 0.05 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.44 ± 0.06 | 3342014.50 ± 386908.38 | 100.00 ± 0.00 |
| DependencyAware | 0.04 ± 0.00 | 0.36 ± 0.04 | 0.01 ± 0.00 | 0.06 ± 0.00 | 0.51 ± 0.03 | 2892597.50 ± 180006.38 | 100.00 ± 0.00 |
| SJF | 0.02 ± 0.00 | 0.25 ± 0.02 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.43 ± 0.03 | 3389002.00 ± 252687.31 | 100.00 ± 0.00 |
