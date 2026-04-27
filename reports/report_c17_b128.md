# GPU Scheduler Report
Circuit: c17 | batch_size=128 | runs=10 (averaged)

Generated: 20260427_094256

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.008 | 0.019 | 0.017 | 0.025 | 0.104 | 507087.44 | 100.00 |
| fanin_priority | 0.008 | 0.021 | 0.006 | 0.014 | 0.028 | 508389.09 | 100.00 |
| DependencyAware | 0.010 | 0.023 | 0.006 | 0.016 | 0.028 | 495807.00 | 100.00 |
| SJF | 0.008 | 0.021 | 0.005 | 0.014 | 0.026 | 521981.34 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.04 | 0.02 ± 0.04 | 0.10 ± 0.24 | 507087.44 ± 166356.98 | 100.00 ± 0.00 |
| fanin_priority | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.03 ± 0.01 | 508389.09 ± 127996.97 | 100.00 ± 0.00 |
| DependencyAware | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.03 ± 0.01 | 495807.00 ± 116565.77 | 100.00 ± 0.00 |
| SJF | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.03 ± 0.01 | 521981.34 ± 85537.61 | 100.00 ± 0.00 |
