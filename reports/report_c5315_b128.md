# GPU Scheduler Report
Circuit: c5315 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_025504

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.003 | 0.028 | 0.018 | 0.021 | 0.376 | 3617664.00 | 100.00 |
| fanin_priority | 0.002 | 0.075 | 0.017 | 0.018 | 0.372 | 3865903.50 | 100.00 |
| DependencyAware | 0.006 | 0.064 | 0.019 | 0.025 | 0.392 | 3609935.50 | 100.00 |
| SJF | 0.003 | 0.059 | 0.017 | 0.020 | 0.407 | 3455650.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.03 ± 0.01 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.38 ± 0.12 | 3617664.00 ± 1250829.12 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.08 ± 0.02 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.37 ± 0.15 | 3865903.50 ± 1485839.00 | 100.00 ± 0.00 |
| DependencyAware | 0.01 ± 0.00 | 0.06 ± 0.02 | 0.02 ± 0.01 | 0.03 ± 0.01 | 0.39 ± 0.14 | 3609935.50 ± 1461649.25 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.06 ± 0.02 | 0.02 ± 0.01 | 0.02 ± 0.01 | 0.41 ± 0.15 | 3455650.75 ± 1289819.12 | 100.00 ± 0.00 |
