# GPU Scheduler Report
Circuit: c6288 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_025605

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.000 | 0.000 | 0.011 | 0.011 | 0.742 | 2507711.75 | 100.00 |
| fanin_priority | 0.000 | 0.000 | 0.012 | 0.012 | 0.786 | 2436738.50 | 100.00 |
| DependencyAware | 0.000 | 0.000 | 0.012 | 0.012 | 0.891 | 2339070.25 | 100.00 |
| SJF | 0.000 | 0.000 | 0.013 | 0.013 | 0.865 | 2240001.75 | 100.00 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.74 ± 0.23 | 2507711.75 ± 579825.44 | 100.00 ± 0.00 |
| fanin_priority | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.79 ± 0.28 | 2436738.50 ± 673123.62 | 100.00 ± 0.00 |
| DependencyAware | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.89 ± 0.55 | 2339070.25 ± 692702.00 | 100.00 ± 0.00 |
| SJF | 0.00 ± 0.00 | 0.00 ± 0.00 | 0.01 ± 0.00 | 0.01 ± 0.00 | 0.86 ± 0.32 | 2240001.75 ± 656462.75 | 100.00 ± 0.00 |
