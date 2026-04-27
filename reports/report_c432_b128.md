# GPU Scheduler Report
Circuit: c432 | batch_size=128 | runs=10 (averaged)

Generated: 20260427_094256

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.050 | 0.132 | 0.007 | 0.056 | 0.137 | 1345331.38 | 100.00 |
| fanin_priority | 0.049 | 0.128 | 0.007 | 0.056 | 0.133 | 1384076.00 | 100.00 |
| DependencyAware | 0.046 | 0.121 | 0.006 | 0.052 | 0.126 | 1424150.75 | 100.00 |
| SJF | 0.047 | 0.126 | 0.006 | 0.053 | 0.131 | 1409276.50 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.05 ± 0.02 | 0.13 ± 0.03 | 0.01 ± 0.00 | 0.06 ± 0.02 | 0.14 ± 0.03 | 1345331.38 ± 243137.62 | 100.00 ± 0.00 |
| fanin_priority | 0.05 ± 0.01 | 0.13 ± 0.03 | 0.01 ± 0.00 | 0.06 ± 0.02 | 0.13 ± 0.03 | 1384076.00 ± 229743.08 | 100.00 ± 0.00 |
| DependencyAware | 0.05 ± 0.01 | 0.12 ± 0.02 | 0.01 ± 0.00 | 0.05 ± 0.01 | 0.13 ± 0.02 | 1424150.75 ± 145278.19 | 100.00 ± 0.00 |
| SJF | 0.05 ± 0.02 | 0.13 ± 0.03 | 0.01 ± 0.00 | 0.05 ± 0.02 | 0.13 ± 0.03 | 1409276.50 ± 225257.08 | 100.00 ± 0.00 |
