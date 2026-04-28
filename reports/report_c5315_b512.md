# GPU Scheduler Report
Circuit: c5315 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025558

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.014 | 0.014 | 0.251 | 5088319.50 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.013 | 0.013 | 0.232 | 5297601.50 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.014 | 0.014 | 0.255 | 4932506.50 | 100.00 |
| SJF | 0.000 | 0.000 | 0.014 | 0.014 | 0.251 | 4983187.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.25 ± 0.06 | 5088319.50 ± 978009.19 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.23 ± 0.02 | 5297601.50 ± 433360.91 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.25 ± 0.05 | 4932506.50 ± 736852.25 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.25 ± 0.04 | 4983187.00 ± 742655.12 | 100.00 ± 0.00 |
