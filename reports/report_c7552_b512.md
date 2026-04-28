# GPU Scheduler Report
Circuit: c7552 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_022353

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.016 | 0.016 | 0.303 | 5258847.50 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.016 | 0.016 | 0.295 | 5326826.00 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.017 | 0.017 | 0.310 | 5189265.50 | 100.00 |
| SJF | 0.000 | 0.000 | 0.017 | 0.017 | 0.325 | 4824119.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.30 ± 0.09 | 5258847.50 ± 1452093.50 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.29 ± 0.09 | 5326826.00 ± 1315218.38 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.31 ± 0.10 | 5189265.50 ± 1420971.62 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.33 ± 0.09 | 4824119.50 ± 1275136.50 | 100.00 ± 0.00 |
