# GPU Scheduler Report
Circuit: c499 | batch_size=128 | runs=10 (averaged)

Generated: 20260427_094257

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.041 | 0.083 | 0.006 | 0.047 | 0.089 | 2795837.50 | 100.00 |
| fanin_priority | 0.040 | 0.082 | 0.006 | 0.047 | 0.088 | 2829144.25 | 100.00 |
| DependencyAware | 0.042 | 0.084 | 0.007 | 0.048 | 0.090 | 2769695.50 | 100.00 |
| SJF | 0.042 | 0.085 | 0.006 | 0.048 | 0.092 | 2731778.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.04 ± 0.00 | 0.08 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.09 ± 0.01 | 2795837.50 ± 185288.84 | 100.00 ± 0.00 |
| fanin_priority | 0.04 ± 0.00 | 0.08 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.09 ± 0.01 | 2829144.25 ± 175130.81 | 100.00 ± 0.00 |
| DependencyAware | 0.04 ± 0.00 | 0.08 ± 0.00 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.09 ± 0.00 | 2769695.50 ± 114980.68 | 100.00 ± 0.00 |
| SJF | 0.04 ± 0.00 | 0.09 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.09 ± 0.01 | 2731778.50 ± 214414.84 | 100.00 ± 0.00 |
