# GPU Scheduler Report
Circuit: c5315 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_022149

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.029 | 0.082 | 0.013 | 0.042 | 0.566 | 2452738.75 | 100.00 |
| fanin_priority | 0.015 | 0.348 | 0.014 | 0.030 | 0.641 | 2241432.50 | 100.00 |
| DependencyAware | 0.058 | 0.348 | 0.014 | 0.073 | 0.594 | 2373073.25 | 100.00 |
| SJF | 0.025 | 0.278 | 0.014 | 0.039 | 0.600 | 2374826.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.03 ± 0.01 | 0.08 ± 0.03 | 0.01 ± 0.00 | 0.04 ± 0.01 | 0.57 ± 0.19 | 2452738.75 ± 889630.31 | 100.00 ± 0.00 |
| fanin_priority | 0.02 ± 0.00 | 0.35 ± 0.11 | 0.01 ± 0.01 | 0.03 ± 0.01 | 0.64 ± 0.25 | 2241432.50 ± 924606.50 | 100.00 ± 0.00 |
| DependencyAware | 0.06 ± 0.02 | 0.35 ± 0.13 | 0.01 ± 0.01 | 0.07 ± 0.03 | 0.59 ± 0.22 | 2373073.25 ± 879905.62 | 100.00 ± 0.00 |
| SJF | 0.02 ± 0.01 | 0.28 ± 0.12 | 0.01 ± 0.01 | 0.04 ± 0.02 | 0.60 ± 0.24 | 2374826.50 ± 895346.25 | 100.00 ± 0.00 |
