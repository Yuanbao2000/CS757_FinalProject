# GPU Scheduler Report
Circuit: c880 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025400

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.001 | 0.014 | 0.010 | 0.011 | 0.226 | 1359513.25 | 100.00 |
| fanin_priority | 0.001 | 0.033 | 0.010 | 0.011 | 0.219 | 1406251.00 | 100.00 |
| DependencyAware | 0.002 | 0.017 | 0.011 | 0.013 | 0.234 | 1312673.50 | 100.00 |
| SJF | 0.002 | 0.022 | 0.010 | 0.011 | 0.232 | 1328574.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.01 | 1359513.25 ± 50963.52 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.03 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.22 ± 0.01 | 1406251.00 ± 45699.41 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.01 | 1312673.50 ± 64410.07 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.01 | 1328574.75 ± 60254.43 | 100.00 ± 0.00 |
