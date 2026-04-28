# GPU Scheduler Report
Circuit: c17 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_041342

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 | 0.0000 | 0.0076 | 0.0076 | 0.0333 | 411798.0625 | 100.0000 |
| fanin_priority (blocking batch) | 0.0000 | 0.0000 | 0.0054 | 0.0054 | 0.0249 | 524060.7500 | 100.0000 |
| DependencyAware (blocking batch) | 0.0000 | 0.0000 | 0.0054 | 0.0054 | 0.0257 | 514354.5938 | 100.0000 |
| SJF (blocking batch) | 0.0000 | 0.0000 | 0.0050 | 0.0050 | 0.0237 | 550027.5000 | 100.0000 |
| FIFO (single-gate non-blocking) | 0.0092 | 0.0258 | 0.0027 | 0.0120 | 0.1299 | 100418.0625 | 92.3215 |
| fanin_priority (single-gate non-blocking) | 0.0105 | 0.0295 | 0.0028 | 0.0132 | 0.1467 | 89286.8125 | 92.5452 |
| DependencyAware (single-gate non-blocking) | 0.0119 | 0.0303 | 0.0028 | 0.0147 | 0.1509 | 86861.3047 | 91.1324 |
| SJF (single-gate non-blocking) | 0.0098 | 0.0272 | 0.0028 | 0.0126 | 0.1507 | 86768.0859 | 92.6119 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0076 ± 0.0017 | 0.0076 ± 0.0017 | 0.0333 ± 0.0095 | 411798.0625 ± 77789.9062 | 100.0000 ± 0.0000 |
| fanin_priority (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0054 ± 0.0005 | 0.0054 ± 0.0005 | 0.0249 ± 0.0014 | 524060.7500 ± 28394.8848 | 100.0000 ± 0.0000 |
| DependencyAware (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0054 ± 0.0006 | 0.0054 ± 0.0006 | 0.0257 ± 0.0040 | 514354.5938 ± 57390.0391 | 100.0000 ± 0.0000 |
| SJF (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0050 ± 0.0003 | 0.0050 ± 0.0003 | 0.0237 ± 0.0011 | 550027.5000 ± 26263.6895 | 100.0000 ± 0.0000 |
| FIFO (single-gate non-blocking) | 0.0092 ± 0.0009 | 0.0258 ± 0.0040 | 0.0027 ± 0.0004 | 0.0120 ± 0.0012 | 0.1299 ± 0.0078 | 100418.0625 ± 5674.1528 | 92.3215 ± 1.0773 |
| fanin_priority (single-gate non-blocking) | 0.0105 ± 0.0036 | 0.0295 ± 0.0122 | 0.0028 ± 0.0002 | 0.0132 ± 0.0037 | 0.1467 ± 0.0139 | 89286.8125 ± 6853.1104 | 92.5452 ± 0.5628 |
| DependencyAware (single-gate non-blocking) | 0.0119 ± 0.0008 | 0.0303 ± 0.0027 | 0.0028 ± 0.0002 | 0.0147 ± 0.0009 | 0.1509 ± 0.0150 | 86861.3047 ± 7052.6313 | 91.1324 ± 0.4801 |
| SJF (single-gate non-blocking) | 0.0098 ± 0.0015 | 0.0272 ± 0.0050 | 0.0028 ± 0.0003 | 0.0126 ± 0.0019 | 0.1507 ± 0.0115 | 86768.0859 ± 6385.8745 | 92.6119 ± 0.4668 |
