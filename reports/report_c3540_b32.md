# GPU Scheduler Report
Circuit: c3540 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025403

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.007 | 0.040 | 0.008 | 0.015 | 0.284 | 2703730.00 | 100.00 |
| fanin_priority | 0.003 | 0.069 | 0.009 | 0.011 | 0.345 | 2498193.75 | 100.00 |
| DependencyAware | 0.010 | 0.105 | 0.008 | 0.018 | 0.298 | 2595891.50 | 100.00 |
| SJF | 0.005 | 0.109 | 0.008 | 0.014 | 0.291 | 2648706.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.01 ± 0.00 | 0.04 ± 0.02 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.28 ± 0.02 | 2703730.00 ± 218919.17 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.07 ± 0.02 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.34 ± 0.18 | 2498193.75 ± 558983.81 | 100.00 ± 0.00 |
| DependencyAware | 0.01 ± 0.00 | 0.11 ± 0.01 | 0.01 ± 0.00 | 0.02 ± 0.00 | 0.30 ± 0.04 | 2595891.50 ± 288617.81 | 100.00 ± 0.00 |
| SJF | 0.01 ± 0.00 | 0.11 ± 0.01 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.29 ± 0.03 | 2648706.75 ± 262136.58 | 100.00 ± 0.00 |
