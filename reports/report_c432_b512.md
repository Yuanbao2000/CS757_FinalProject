# GPU Scheduler Report
Circuit: c432 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025551

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.010 | 0.010 | 0.194 | 933535.81 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.010 | 0.010 | 0.202 | 881127.31 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.010 | 0.010 | 0.200 | 891966.62 | 100.00 |
| SJF | 0.000 | 0.000 | 0.010 | 0.010 | 0.203 | 880254.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.19 ± 0.03 | 933535.81 ± 162658.23 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.20 ± 0.02 | 881127.31 ± 68237.12 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.20 ± 0.02 | 891966.62 ± 69459.63 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.20 ± 0.02 | 880254.50 ± 72595.16 | 100.00 ± 0.00 |
