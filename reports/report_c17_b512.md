# GPU Scheduler Report
Circuit: c17 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_041537

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 | 0.0000 | 0.0077 | 0.0077 | 0.0314 | 415933.8750 | 100.0000 |
| fanin_priority (blocking batch) | 0.0000 | 0.0000 | 0.0054 | 0.0054 | 0.0259 | 518159.6875 | 100.0000 |
| DependencyAware (blocking batch) | 0.0000 | 0.0000 | 0.0071 | 0.0071 | 0.0323 | 459555.3125 | 100.0000 |
| SJF (blocking batch) | 0.0000 | 0.0000 | 0.0056 | 0.0056 | 0.0251 | 525863.3750 | 100.0000 |
| FIFO (single-gate non-blocking) | 0.0141 | 0.0329 | 0.0032 | 0.0173 | 0.2001 | 65602.4375 | 85.9386 |
| fanin_priority (single-gate non-blocking) | 0.0142 | 0.0329 | 0.0030 | 0.0172 | 0.2665 | 49025.3672 | 89.2380 |
| DependencyAware (single-gate non-blocking) | 0.0168 | 0.0382 | 0.0034 | 0.0202 | 0.2538 | 52368.4648 | 87.6082 |
| SJF (single-gate non-blocking) | 0.0140 | 0.0327 | 0.0029 | 0.0169 | 0.2566 | 51292.2422 | 89.0555 |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |
|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0077 ± 0.0009 | 0.0077 ± 0.0009 | 0.0314 ± 0.0023 | 415933.8750 ± 30009.9512 | 100.0000 ± 0.0000 |
| fanin_priority (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0054 ± 0.0009 | 0.0054 ± 0.0009 | 0.0259 ± 0.0055 | 518159.6875 ± 77312.2656 | 100.0000 ± 0.0000 |
| DependencyAware (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0071 ± 0.0034 | 0.0071 ± 0.0034 | 0.0323 ± 0.0144 | 459555.3125 ± 130126.8672 | 100.0000 ± 0.0000 |
| SJF (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0056 ± 0.0012 | 0.0056 ± 0.0012 | 0.0251 ± 0.0033 | 525863.3750 ± 54905.2539 | 100.0000 ± 0.0000 |
| FIFO (single-gate non-blocking) | 0.0141 ± 0.0015 | 0.0329 ± 0.0043 | 0.0032 ± 0.0004 | 0.0173 ± 0.0018 | 0.2001 ± 0.0207 | 65602.4375 ± 6216.0986 | 85.9386 ± 2.8820 |
| fanin_priority (single-gate non-blocking) | 0.0142 ± 0.0008 | 0.0329 ± 0.0023 | 0.0030 ± 0.0002 | 0.0172 ± 0.0009 | 0.2665 ± 0.0191 | 49025.3672 ± 3448.5916 | 89.2380 ± 1.0760 |
| DependencyAware (single-gate non-blocking) | 0.0168 ± 0.0029 | 0.0382 ± 0.0068 | 0.0034 ± 0.0012 | 0.0202 ± 0.0041 | 0.2538 ± 0.0455 | 52368.4648 ± 6377.4507 | 87.6082 ± 0.2990 |
| SJF (single-gate non-blocking) | 0.0140 ± 0.0011 | 0.0327 ± 0.0019 | 0.0029 ± 0.0002 | 0.0169 ± 0.0012 | 0.2566 ± 0.0319 | 51292.2422 ± 5054.6328 | 89.0555 ± 0.5593 |
