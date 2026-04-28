# GPU Scheduler Report
Circuit: c2670 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025553

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.018 | 0.018 | 0.250 | 2349263.25 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.018 | 0.018 | 0.269 | 2190263.75 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.021 | 0.021 | 0.297 | 1976398.25 | 100.00 |
| SJF | 0.000 | 0.000 | 0.019 | 0.019 | 0.270 | 2157806.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.25 ± 0.05 | 2349263.25 ± 456125.47 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.27 ± 0.05 | 2190263.75 ± 480661.22 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.30 ± 0.05 | 1976398.25 ± 427309.38 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.27 ± 0.04 | 2157806.75 ± 413481.97 | 100.00 ± 0.00 |
