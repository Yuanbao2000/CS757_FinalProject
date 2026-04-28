# GPU Scheduler Report
Circuit: c7552 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025516

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.002 | 0.022 | 0.015 | 0.017 | 0.295 | 5495967.00 | 100.00 |
| fanin_priority | 0.001 | 0.036 | 0.015 | 0.016 | 0.308 | 5116975.00 | 100.00 |
| DependencyAware | 0.004 | 0.038 | 0.018 | 0.021 | 0.347 | 4699842.00 | 100.00 |
| SJF | 0.001 | 0.040 | 0.017 | 0.018 | 0.331 | 4801600.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.30 ± 0.11 | 5495967.00 ± 1543341.12 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.04 ± 0.01 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.31 ± 0.10 | 5116975.00 ± 1224133.50 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.04 ± 0.02 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.35 ± 0.12 | 4699842.00 ± 1447493.00 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.04 ± 0.01 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.33 ± 0.10 | 4801600.00 ± 1274657.38 | 100.00 ± 0.00 |
