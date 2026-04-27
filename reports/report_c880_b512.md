# GPU Scheduler Report
Circuit: c880 | batch_size=512 | runs=10 (averaged)

Generated: 20260427_094316

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.050 | 0.158 | 0.008 | 0.058 | 0.163 | 2041927.25 | 100.00 |
| fanin_priority | 0.049 | 0.153 | 0.008 | 0.057 | 0.159 | 2032335.75 | 100.00 |
| DependencyAware | 0.050 | 0.149 | 0.008 | 0.058 | 0.154 | 2103111.50 | 100.00 |
| SJF | 0.054 | 0.172 | 0.008 | 0.063 | 0.177 | 1972778.62 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.05 ± 0.02 | 0.16 ± 0.05 | 0.01 ± 0.00 | 0.06 ± 0.02 | 0.16 ± 0.06 | 2041927.25 ± 473602.19 | 100.00 ± 0.00 |
| fanin_priority | 0.05 ± 0.02 | 0.15 ± 0.04 | 0.01 ± 0.00 | 0.06 ± 0.02 | 0.16 ± 0.04 | 2032335.75 ± 377053.31 | 100.00 ± 0.00 |
| DependencyAware | 0.05 ± 0.02 | 0.15 ± 0.05 | 0.01 ± 0.00 | 0.06 ± 0.02 | 0.15 ± 0.05 | 2103111.50 ± 384929.84 | 100.00 ± 0.00 |
| SJF | 0.05 ± 0.02 | 0.17 ± 0.08 | 0.01 ± 0.00 | 0.06 ± 0.03 | 0.18 ± 0.08 | 1972778.62 ± 557552.25 | 100.00 ± 0.00 |
