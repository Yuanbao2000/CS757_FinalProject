# GPU Scheduler Report
Circuit: c2670 | batch_size=512 | runs=10 (averaged)

Generated: 20260427_094317

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.036 | 0.118 | 0.010 | 0.045 | 0.122 | 4704608.00 | 100.00 |
| fanin_priority | 0.034 | 0.113 | 0.009 | 0.043 | 0.117 | 4837778.50 | 100.00 |
| DependencyAware | 0.038 | 0.132 | 0.010 | 0.048 | 0.138 | 4453090.50 | 100.00 |
| SJF | 0.037 | 0.121 | 0.010 | 0.047 | 0.125 | 4567562.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.04 ± 0.01 | 0.12 ± 0.02 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.12 ± 0.02 | 4704608.00 ± 559949.19 | 100.00 ± 0.00 |
| fanin_priority | 0.03 ± 0.00 | 0.11 ± 0.01 | 0.01 ± 0.00 | 0.04 ± 0.01 | 0.12 ± 0.01 | 4837778.50 ± 199624.69 | 100.00 ± 0.00 |
| DependencyAware | 0.04 ± 0.01 | 0.13 ± 0.06 | 0.01 ± 0.00 | 0.05 ± 0.02 | 0.14 ± 0.06 | 4453090.50 ± 891738.12 | 100.00 ± 0.00 |
| SJF | 0.04 ± 0.01 | 0.12 ± 0.02 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.13 ± 0.02 | 4567562.50 ± 489696.78 | 100.00 ± 0.00 |
