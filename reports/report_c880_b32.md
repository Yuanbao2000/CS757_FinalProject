# GPU Scheduler Report
Circuit: c880 | batch_size=32 | runs=10 (averaged)

Generated: 20260427_094237

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.051 | 0.160 | 0.007 | 0.059 | 0.164 | 1948024.00 | 100.00 |
| fanin_priority | 0.048 | 0.151 | 0.007 | 0.056 | 0.156 | 2059611.75 | 100.00 |
| DependencyAware | 0.053 | 0.156 | 0.007 | 0.061 | 0.161 | 2038611.62 | 100.00 |
| SJF | 0.054 | 0.160 | 0.007 | 0.061 | 0.164 | 1985996.62 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.05 ± 0.01 | 0.16 ± 0.04 | 0.01 ± 0.00 | 0.06 ± 0.01 | 0.16 ± 0.04 | 1948024.00 ± 370473.09 | 100.00 ± 0.00 |
| fanin_priority | 0.05 ± 0.01 | 0.15 ± 0.04 | 0.01 ± 0.00 | 0.06 ± 0.01 | 0.16 ± 0.04 | 2059611.75 ± 375038.38 | 100.00 ± 0.00 |
| DependencyAware | 0.05 ± 0.02 | 0.16 ± 0.06 | 0.01 ± 0.00 | 0.06 ± 0.02 | 0.16 ± 0.06 | 2038611.62 ± 387412.38 | 100.00 ± 0.00 |
| SJF | 0.05 ± 0.02 | 0.16 ± 0.05 | 0.01 ± 0.00 | 0.06 ± 0.02 | 0.16 ± 0.05 | 1985996.62 ± 358693.03 | 100.00 ± 0.00 |
