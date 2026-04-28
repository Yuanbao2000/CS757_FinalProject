# GPU Scheduler Report
Circuit: c7552 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022201

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.027 | 0.080 | 0.011 | 0.038 | 0.549 | 2944612.00 | 100.00 |
| fanin_priority | 0.017 | 0.376 | 0.013 | 0.030 | 0.650 | 2625670.75 | 100.00 |
| DependencyAware | 0.053 | 0.461 | 0.014 | 0.067 | 0.662 | 2457527.25 | 100.00 |
| SJF | 0.023 | 0.359 | 0.013 | 0.036 | 0.637 | 2631562.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.03 ± 0.01 | 0.08 ± 0.03 | 0.01 ± 0.00 | 0.04 ± 0.01 | 0.55 ± 0.19 | 2944612.00 ± 820353.81 | 100.00 ± 0.00 |
| fanin_priority | 0.02 ± 0.01 | 0.38 ± 0.17 | 0.01 ± 0.01 | 0.03 ± 0.01 | 0.65 ± 0.28 | 2625670.75 ± 910982.62 | 100.00 ± 0.00 |
| DependencyAware | 0.05 ± 0.02 | 0.46 ± 0.16 | 0.01 ± 0.00 | 0.07 ± 0.02 | 0.66 ± 0.22 | 2457527.25 ± 777993.56 | 100.00 ± 0.00 |
| SJF | 0.02 ± 0.01 | 0.36 ± 0.16 | 0.01 ± 0.01 | 0.04 ± 0.01 | 0.64 ± 0.25 | 2631562.00 ± 878431.94 | 100.00 ± 0.00 |
