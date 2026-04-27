# GPU Scheduler Report
Circuit: c499 | batch_size=512 | runs=10 (averaged)

Generated: 20260427_094316

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.046 | 0.096 | 0.007 | 0.053 | 0.104 | 2510834.50 | 100.00 |
| fanin_priority | 0.040 | 0.082 | 0.006 | 0.046 | 0.088 | 2844989.50 | 100.00 |
| DependencyAware | 0.041 | 0.083 | 0.007 | 0.047 | 0.090 | 2762516.50 | 100.00 |
| SJF | 0.040 | 0.082 | 0.006 | 0.046 | 0.088 | 2822159.25 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.05 ± 0.01 | 0.10 ± 0.02 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.10 ± 0.03 | 2510834.50 ± 475517.06 | 100.00 ± 0.00 |
| fanin_priority | 0.04 ± 0.00 | 0.08 ± 0.01 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.09 ± 0.01 | 2844989.50 ± 241183.02 | 100.00 ± 0.00 |
| DependencyAware | 0.04 ± 0.00 | 0.08 ± 0.00 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.09 ± 0.00 | 2762516.50 ± 128804.03 | 100.00 ± 0.00 |
| SJF | 0.04 ± 0.00 | 0.08 ± 0.00 | 0.01 ± 0.00 | 0.05 ± 0.00 | 0.09 ± 0.00 | 2822159.25 ± 109258.59 | 100.00 ± 0.00 |
