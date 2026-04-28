# GPU Scheduler Group Report
Group: imbalanced_2 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_041243

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0077 | 0.0444 | 0.0081 | 0.0158 | 0.2325 | 3273597.5000 | 100.0000 | 0.9912 | 1.8693x | 5.9980x | 3.0727x |
| fanin_priority (blocking batch) | 0.0052 | 0.0799 | 0.0078 | 0.0130 | 0.2456 | 3022931.0000 | 100.0000 | 0.9912 | 1.7014x | 13.5490x | 2.5581x |
| DependencyAware (blocking batch) | 0.0077 | 0.0412 | 0.0077 | 0.0154 | 0.2264 | 3290529.7500 | 100.0000 | 0.9893 | 1.9193x | 6.5065x | 3.1998x |
| SJF (blocking batch) | 0.0061 | 0.0580 | 0.0076 | 0.0137 | 0.2192 | 3355194.7500 | 100.0000 | 0.9935 | 1.7680x | 9.1222x | 2.9887x |
| FIFO (single-gate non-blocking) | 1.6509 | 6.1611 | 0.0040 | 1.6549 | 34.2762 | 21412.0254 | 96.5857 | 0.9970 | 484.6158x | 3006.7908x | 774.6373x |
| fanin_priority (single-gate non-blocking) | 1.5141 | 15.4072 | 0.0036 | 1.5177 | 34.2885 | 21438.7891 | 96.2606 | 0.9992 | 408.5839x | 6230.4893x | 590.1610x |
| DependencyAware (single-gate non-blocking) | 2.4746 | 9.1839 | 0.0026 | 2.4773 | 39.9531 | 18402.6035 | 96.4000 | 0.9982 | 1010.1301x | 4450.5835x | 1605.9958x |
| SJF (single-gate non-blocking) | 1.4910 | 10.6052 | 0.0036 | 1.4946 | 34.4405 | 21311.9629 | 96.6671 | 0.9980 | 474.3085x | 4812.9673x | 765.7874x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0077 ± 0.0025 | 0.0444 ± 0.0132 | 0.0081 ± 0.0023 | 0.0158 ± 0.0048 | 0.2325 ± 0.0568 | 3273597.5000 ± 499869.7500 | 100.0000 ± 0.0000 | 0.9912 ± 0.0026 | 1.8693x ± 0.0507 | 5.9980x ± 0.6928 | 3.0727x ± 0.0659 |
| fanin_priority (blocking batch) | 0.0052 ± 0.0002 | 0.0799 ± 0.0053 | 0.0078 ± 0.0010 | 0.0130 ± 0.0011 | 0.2456 ± 0.0290 | 3022931.0000 ± 321595.0625 | 100.0000 ± 0.0000 | 0.9912 ± 0.0043 | 1.7014x ± 0.0502 | 13.5490x ± 0.7720 | 2.5581x ± 0.0501 |
| DependencyAware (blocking batch) | 0.0077 ± 0.0025 | 0.0412 ± 0.0151 | 0.0077 ± 0.0014 | 0.0154 ± 0.0039 | 0.2264 ± 0.0328 | 3290529.7500 ± 367559.9688 | 100.0000 ± 0.0000 | 0.9893 ± 0.0031 | 1.9193x ± 0.0277 | 6.5065x ± 0.4687 | 3.1998x ± 0.0590 |
| SJF (blocking batch) | 0.0061 ± 0.0007 | 0.0580 ± 0.0088 | 0.0076 ± 0.0005 | 0.0137 ± 0.0012 | 0.2192 ± 0.0133 | 3355194.7500 ± 188562.5000 | 100.0000 ± 0.0000 | 0.9935 ± 0.0021 | 1.7680x ± 0.0549 | 9.1222x ± 0.8544 | 2.9887x ± 0.0697 |
| FIFO (single-gate non-blocking) | 1.6509 ± 0.0461 | 6.1611 ± 0.2667 | 0.0040 ± 0.0001 | 1.6549 ± 0.0461 | 34.2762 ± 1.2541 | 21412.0254 ± 735.6445 | 96.5857 ± 0.0938 | 0.9970 ± 0.0006 | 484.6158x ± 31.9111 | 3006.7908x ± 131.7003 | 774.6373x ± 47.7210 |
| fanin_priority (single-gate non-blocking) | 1.5141 ± 0.1289 | 15.4072 ± 1.7368 | 0.0036 ± 0.0001 | 1.5177 ± 0.1290 | 34.2885 ± 1.9645 | 21438.7891 ± 1071.2074 | 96.2606 ± 0.0840 | 0.9992 ± 0.0001 | 408.5839x ± 31.6973 | 6230.4893x ± 925.3011 | 590.1610x ± 31.6126 |
| DependencyAware (single-gate non-blocking) | 2.4746 ± 0.0844 | 9.1839 ± 0.2828 | 0.0026 ± 0.0004 | 2.4773 ± 0.0847 | 39.9531 ± 2.3677 | 18402.6035 ± 947.2519 | 96.4000 ± 0.0596 | 0.9982 ± 0.0002 | 1010.1301x ± 55.9006 | 4450.5835x ± 97.8891 | 1605.9958x ± 101.5852 |
| SJF (single-gate non-blocking) | 1.4910 ± 0.0367 | 10.6052 ± 0.3964 | 0.0036 ± 0.0001 | 1.4946 ± 0.0366 | 34.4405 ± 1.2996 | 21311.9629 ± 764.7409 | 96.6671 ± 0.0669 | 0.9980 ± 0.0003 | 474.3085x ± 33.6646 | 4812.9673x ± 434.7141 | 765.7874x ± 64.1316 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 1.5575x | 2.2344x | 1.7889x | 1.6928x | 269.4785x | 564.0872x | 947.5112x | 422.9566x |
| wl 1 | 1.9089x | 1.8601x | 1.9692x | 1.8572x | 561.3210x | 447.3747x | 1051.2687x | 554.7621x |
| wl 2 | 2.0170x | 1.2653x | 1.9539x | 1.7389x | 546.4387x | 287.4667x | 1012.8659x | 438.6615x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0054 ms² | 0.0051 ms² | 0.0040 ms² | 0.0040 ms² | 134.5525 ms² | 103.8879 ms² | 147.0108 ms² | 120.6583 ms² |
| wl 1 | 0.0038 ms² | 0.0036 ms² | 0.0032 ms² | 0.0027 ms² | 97.7572 ms² | 81.7524 ms² | 127.6767 ms² | 87.7553 ms² |
| wl 2 | 0.0030 ms² | 0.0029 ms² | 0.0030 ms² | 0.0030 ms² | 75.0909 ms² | 77.5683 ms² | 112.3294 ms² | 92.9787 ms² |
