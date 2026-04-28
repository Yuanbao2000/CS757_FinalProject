# GPU Scheduler Report
Circuit: c5315 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_025407

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.020 | 0.059 | 0.009 | 0.029 | 0.412 | 3051429.75 | 100.00 |
| fanin_priority | 0.013 | 0.245 | 0.010 | 0.023 | 0.441 | 2892976.75 | 100.00 |
| DependencyAware | 0.045 | 0.271 | 0.010 | 0.055 | 0.427 | 2935033.25 | 100.00 |
| SJF | 0.017 | 0.167 | 0.009 | 0.026 | 0.409 | 3130914.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.02 ± 0.00 | 0.06 ± 0.01 | 0.01 ± 0.00 | 0.03 ± 0.00 | 0.41 ± 0.09 | 3051429.75 ± 471470.69 | 100.00 ± 0.00 |
| fanin_priority | 0.01 ± 0.00 | 0.24 ± 0.07 | 0.01 ± 0.00 | 0.02 ± 0.01 | 0.44 ± 0.09 | 2892976.75 ± 592578.06 | 100.00 ± 0.00 |
| DependencyAware | 0.04 ± 0.01 | 0.27 ± 0.07 | 0.01 ± 0.00 | 0.05 ± 0.02 | 0.43 ± 0.08 | 2935033.25 ± 436498.44 | 100.00 ± 0.00 |
| SJF | 0.02 ± 0.00 | 0.17 ± 0.03 | 0.01 ± 0.00 | 0.03 ± 0.01 | 0.41 ± 0.11 | 3130914.25 ± 593646.56 | 100.00 ± 0.00 |
