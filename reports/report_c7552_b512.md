# GPU Scheduler Report
Circuit: c7552 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025610

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.016 | 0.016 | 0.292 | 5423760.50 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.017 | 0.017 | 0.342 | 5003782.00 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.017 | 0.017 | 0.287 | 5376153.50 | 100.00 |
| SJF | 0.000 | 0.000 | 0.016 | 0.016 | 0.291 | 5292129.00 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.29 ± 0.10 | 5423760.50 ± 1304616.50 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.34 ± 0.18 | 5003782.00 ± 1452749.88 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.29 ± 0.09 | 5376153.50 ± 990649.56 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.02 ± 0.00 | 0.02 ± 0.00 | 0.29 ± 0.08 | 5292129.00 ± 988756.94 | 100.00 ± 0.00 |
