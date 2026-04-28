# GPU Scheduler Group Report
Group: balanced_1 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_041437

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0001 | 0.0145 | 0.0137 | 0.0138 | 0.3160 | 3967379.2500 | 100.0000 | 0.9739 | 1.0071x | 2.0506x | 2.0318x |
| fanin_priority (blocking batch) | 0.0001 | 0.0126 | 0.0123 | 0.0124 | 0.3157 | 3981034.5000 | 100.0000 | 0.9631 | 1.0066x | 1.9848x | 2.0251x |
| DependencyAware (blocking batch) | 0.0001 | 0.0159 | 0.0134 | 0.0135 | 0.3322 | 3752024.5000 | 100.0000 | 0.9618 | 1.0078x | 2.1539x | 2.0340x |
| SJF (blocking batch) | 0.0001 | 0.0131 | 0.0121 | 0.0122 | 0.3026 | 4165748.0000 | 100.0000 | 0.9675 | 1.0074x | 2.0970x | 2.0406x |
| FIFO (single-gate non-blocking) | 2.3159 | 10.8840 | 0.0041 | 2.3200 | 90.2080 | 13274.3486 | 97.6352 | 0.9966 | 655.7877x | 5178.8662x | 1328.8616x |
| fanin_priority (single-gate non-blocking) | 2.4992 | 16.0011 | 0.0043 | 2.5035 | 94.6576 | 12666.3223 | 97.5609 | 0.9962 | 685.5148x | 5863.2456x | 1400.2585x |
| DependencyAware (single-gate non-blocking) | 3.9663 | 15.2585 | 0.0030 | 3.9693 | 103.7431 | 11605.0996 | 97.6201 | 0.9978 | 1431.7233x | 5791.1904x | 2889.8857x |
| SJF (single-gate non-blocking) | 2.5220 | 15.5161 | 0.0040 | 2.5260 | 93.2233 | 12935.4844 | 97.6280 | 0.9965 | 685.2712x | 5286.0752x | 1389.5164x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0001 ± 0.0000 | 0.0145 ± 0.0062 | 0.0137 ± 0.0037 | 0.0138 ± 0.0037 | 0.3160 ± 0.0848 | 3967379.2500 ± 788097.8750 | 100.0000 ± 0.0000 | 0.9739 ± 0.0073 | 1.0071x ± 0.0022 | 2.0506x ± 0.3238 | 2.0318x ± 0.0041 |
| fanin_priority (blocking batch) | 0.0001 ± 0.0000 | 0.0126 ± 0.0059 | 0.0123 ± 0.0031 | 0.0124 ± 0.0032 | 0.3157 ± 0.0858 | 3981034.5000 ± 802929.2500 | 100.0000 ± 0.0000 | 0.9631 ± 0.0069 | 1.0066x ± 0.0018 | 1.9848x ± 0.2646 | 2.0251x ± 0.0018 |
| DependencyAware (blocking batch) | 0.0001 ± 0.0000 | 0.0159 ± 0.0052 | 0.0134 ± 0.0029 | 0.0135 ± 0.0030 | 0.3322 ± 0.0780 | 3752024.5000 ± 744011.5000 | 100.0000 ± 0.0000 | 0.9618 ± 0.0251 | 1.0078x ± 0.0020 | 2.1539x ± 0.2982 | 2.0340x ± 0.0040 |
| SJF (blocking batch) | 0.0001 ± 0.0000 | 0.0131 ± 0.0040 | 0.0121 ± 0.0033 | 0.0122 ± 0.0033 | 0.3026 ± 0.0944 | 4165748.0000 ± 774615.3125 | 100.0000 ± 0.0000 | 0.9675 ± 0.0063 | 1.0074x ± 0.0012 | 2.0970x ± 0.1771 | 2.0406x ± 0.0036 |
| FIFO (single-gate non-blocking) | 2.3159 ± 0.2138 | 10.8840 ± 1.0921 | 0.0041 ± 0.0001 | 2.3200 ± 0.2138 | 90.2080 ± 8.4650 | 13274.3486 ± 998.7750 | 97.6352 ± 0.0246 | 0.9966 ± 0.0001 | 655.7877x ± 31.5590 | 5178.8662x ± 673.2104 | 1328.8616x ± 63.6577 |
| fanin_priority (single-gate non-blocking) | 2.4992 ± 0.2639 | 16.0011 ± 3.2875 | 0.0043 ± 0.0006 | 2.5035 ± 0.2643 | 94.6576 ± 9.0171 | 12666.3223 ± 1107.9371 | 97.5609 ± 0.1409 | 0.9962 ± 0.0009 | 685.5148x ± 68.5186 | 5863.2456x ± 2285.9417 | 1400.2585x ± 124.4014 |
| DependencyAware (single-gate non-blocking) | 3.9663 ± 0.4737 | 15.2585 ± 2.0827 | 0.0030 ± 0.0007 | 3.9693 ± 0.4744 | 103.7431 ± 12.4496 | 11605.0996 ± 1202.7554 | 97.6201 ± 0.0438 | 0.9978 ± 0.0002 | 1431.7233x ± 127.2212 | 5791.1904x ± 876.4279 | 2889.8857x ± 257.4049 |
| SJF (single-gate non-blocking) | 2.5220 ± 0.3280 | 15.5161 ± 2.0471 | 0.0040 ± 0.0002 | 2.5260 ± 0.3282 | 93.2233 ± 12.0517 | 12935.4844 ± 1401.6061 | 97.6280 ± 0.0567 | 0.9965 ± 0.0002 | 685.2712x ± 58.8468 | 5286.0752x ± 1643.8857 | 1389.5164x ± 142.1652 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 1084.3333x | 719.7947x | 1207.9685x | 409.7994x |
| wl 1 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 797.9303x | 545.6986x | 1134.2812x | 662.3998x |
| wl 2 | 1.0110x | 1.0103x | 1.0121x | 1.0115x | 509.9871x | 723.1906x | 1580.6981x | 756.6388x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0082 ms² | 0.0080 ms² | 0.0081 ms² | 0.0077 ms² | 1018.0482 ms² | 964.3345 ms² | 1203.7950 ms² | 1008.0381 ms² |
| wl 1 | 0.0064 ms² | 0.0055 ms² | 0.0061 ms² | 0.0057 ms² | 844.7117 ms² | 887.7383 ms² | 1071.8289 ms² | 863.6951 ms² |
| wl 2 | 0.0054 ms² | 0.0059 ms² | 0.0055 ms² | 0.0052 ms² | 548.4697 ms² | 673.5768 ms² | 761.0538 ms² | 623.4135 ms² |
