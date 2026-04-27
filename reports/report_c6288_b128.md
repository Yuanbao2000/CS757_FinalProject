# GPU Scheduler Report
Circuit: c6288 | batch_size=128 | runs=10 (averaged)

Generated: 20260427_094311

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.345 | 0.879 | 0.013 | 0.357 | 0.885 | 2171588.50 | 100.00 |
| fanin_priority | 0.318 | 0.892 | 0.013 | 0.331 | 0.899 | 2206041.25 | 100.00 |
| DependencyAware | 0.350 | 0.922 | 0.013 | 0.363 | 0.929 | 2109008.25 | 100.00 |
| SJF | 0.311 | 0.842 | 0.012 | 0.323 | 0.849 | 2319137.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.34 ± 0.12 | 0.88 ± 0.31 | 0.01 ± 0.00 | 0.36 ± 0.13 | 0.88 ± 0.32 | 2171588.50 ± 627508.81 | 100.00 ± 0.00 |
| fanin_priority | 0.32 ± 0.12 | 0.89 ± 0.37 | 0.01 ± 0.01 | 0.33 ± 0.13 | 0.90 ± 0.37 | 2206041.25 ± 709277.56 | 100.00 ± 0.00 |
| DependencyAware | 0.35 ± 0.13 | 0.92 ± 0.36 | 0.01 ± 0.00 | 0.36 ± 0.14 | 0.93 ± 0.36 | 2109008.25 ± 642721.00 | 100.00 ± 0.00 |
| SJF | 0.31 ± 0.13 | 0.84 ± 0.35 | 0.01 ± 0.00 | 0.32 ± 0.13 | 0.85 ± 0.35 | 2319137.25 ± 703532.38 | 100.00 ± 0.00 |
