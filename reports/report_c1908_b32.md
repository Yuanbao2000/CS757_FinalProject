# GPU Scheduler Report
Circuit: c1908 | batch_size=32 | runs=10 (averaged)

Generated: 20260427_094237

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.051 | 0.117 | 0.006 | 0.057 | 0.122 | 2294264.25 | 100.00 |
| fanin_priority | 0.050 | 0.121 | 0.006 | 0.056 | 0.126 | 2232148.50 | 100.00 |
| DependencyAware | 0.051 | 0.118 | 0.006 | 0.057 | 0.123 | 2285014.25 | 100.00 |
| SJF | 0.049 | 0.120 | 0.006 | 0.055 | 0.125 | 2256922.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.05 ± 0.00 | 0.12 ± 0.01 | 0.01 ± 0.00 | 0.06 ± 0.00 | 0.12 ± 0.01 | 2294264.25 ± 101269.34 | 100.00 ± 0.00 |
| fanin_priority | 0.05 ± 0.00 | 0.12 ± 0.01 | 0.01 ± 0.00 | 0.06 ± 0.00 | 0.13 ± 0.01 | 2232148.50 ± 142851.42 | 100.00 ± 0.00 |
| DependencyAware | 0.05 ± 0.00 | 0.12 ± 0.00 | 0.01 ± 0.00 | 0.06 ± 0.00 | 0.12 ± 0.00 | 2285014.25 ± 57297.24 | 100.00 ± 0.00 |
| SJF | 0.05 ± 0.00 | 0.12 ± 0.01 | 0.01 ± 0.00 | 0.06 ± 0.00 | 0.12 ± 0.01 | 2256922.50 ± 138996.09 | 100.00 ± 0.00 |
