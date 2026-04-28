# GPU Scheduler Group Report
Group: balanced_0 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_041233

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0195 | 0.0926 | 0.0094 | 0.0289 | 0.3744 | 3356766.0000 | 100.0000 | 0.9980 | 3.3603x | 12.1699x | 5.4402x |
| fanin_priority (blocking batch) | 0.0133 | 0.2111 | 0.0082 | 0.0215 | 0.3553 | 3380366.5000 | 100.0000 | 0.9914 | 2.8113x | 29.3395x | 3.6620x |
| DependencyAware (blocking batch) | 0.0295 | 0.1880 | 0.0096 | 0.0391 | 0.3800 | 3147003.5000 | 100.0000 | 0.9963 | 4.4895x | 26.2288x | 6.7314x |
| SJF (blocking batch) | 0.0168 | 0.1437 | 0.0093 | 0.0261 | 0.4137 | 2920340.5000 | 100.0000 | 0.9950 | 2.9012x | 20.4413x | 5.2411x |
| FIFO (single-gate non-blocking) | 5.0968 | 17.2652 | 0.0040 | 5.1008 | 81.5995 | 14243.4824 | 96.8295 | 0.9994 | 1407.5527x | 7611.8960x | 2349.8928x |
| fanin_priority (single-gate non-blocking) | 4.5924 | 59.7897 | 0.0038 | 4.5962 | 81.7459 | 14235.7158 | 96.7001 | 0.9974 | 1246.6804x | 23100.9629x | 1556.6975x |
| DependencyAware (single-gate non-blocking) | 11.3504 | 59.8233 | 0.0028 | 11.3532 | 107.0564 | 10839.5938 | 96.7659 | 0.9996 | 4471.6230x | 26100.4121x | 6706.4399x |
| SJF (single-gate non-blocking) | 4.4374 | 33.0348 | 0.0035 | 4.4409 | 81.0594 | 14304.1484 | 96.4639 | 0.9997 | 1321.1641x | 13443.5020x | 2332.4319x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0195 ± 0.0069 | 0.0926 ± 0.0639 | 0.0094 ± 0.0040 | 0.0289 ± 0.0109 | 0.3744 ± 0.1501 | 3356766.0000 ± 724410.4375 | 100.0000 ± 0.0000 | 0.9980 ± 0.0006 | 3.3603x ± 0.2105 | 12.1699x ± 1.1083 | 5.4402x ± 0.3514 |
| fanin_priority (blocking batch) | 0.0133 ± 0.0007 | 0.2111 ± 0.0265 | 0.0082 ± 0.0018 | 0.0215 ± 0.0022 | 0.3553 ± 0.0931 | 3380366.5000 ± 540966.5000 | 100.0000 ± 0.0000 | 0.9914 ± 0.0032 | 2.8113x ± 0.1064 | 29.3395x ± 3.7200 | 3.6620x ± 0.1064 |
| DependencyAware (blocking batch) | 0.0295 ± 0.0040 | 0.1880 ± 0.0484 | 0.0096 ± 0.0018 | 0.0391 ± 0.0057 | 0.3800 ± 0.0811 | 3147003.5000 ± 561859.0625 | 100.0000 ± 0.0000 | 0.9963 ± 0.0029 | 4.4895x ± 0.2312 | 26.2288x ± 8.5353 | 6.7314x ± 0.2282 |
| SJF (blocking batch) | 0.0168 ± 0.0048 | 0.1437 ± 0.0326 | 0.0093 ± 0.0018 | 0.0261 ± 0.0063 | 0.4137 ± 0.1103 | 2920340.5000 ± 533619.9375 | 100.0000 ± 0.0000 | 0.9950 ± 0.0042 | 2.9012x ± 0.2059 | 20.4413x ± 4.3327 | 5.2411x ± 0.3471 |
| FIFO (single-gate non-blocking) | 5.0968 ± 0.6323 | 17.2652 ± 2.4603 | 0.0040 ± 0.0002 | 5.1008 ± 0.6324 | 81.5995 ± 8.8995 | 14243.4824 ± 1268.8829 | 96.8295 ± 0.0422 | 0.9994 ± 0.0001 | 1407.5527x ± 102.2178 | 7611.8960x ± 728.1021 | 2349.8928x ± 169.0844 |
| fanin_priority (single-gate non-blocking) | 4.5924 ± 0.5523 | 59.7897 ± 7.3844 | 0.0038 ± 0.0009 | 4.5962 ± 0.5531 | 81.7459 ± 9.5938 | 14235.7158 ± 1329.1393 | 96.7001 ± 0.0800 | 0.9974 ± 0.0002 | 1246.6804x ± 123.6321 | 23100.9629x ± 3805.3623 | 1556.6975x ± 114.2579 |
| DependencyAware (single-gate non-blocking) | 11.3504 ± 1.1950 | 59.8233 ± 6.2207 | 0.0028 ± 0.0006 | 11.3532 ± 1.1956 | 107.0564 ± 10.7591 | 10839.5938 ± 880.0018 | 96.7659 ± 0.0721 | 0.9996 ± 0.0001 | 4471.6230x ± 280.9250 | 26100.4121x ± 2705.0596 | 6706.4399x ± 417.2559 |
| SJF (single-gate non-blocking) | 4.4374 ± 0.4243 | 33.0348 ± 3.2731 | 0.0035 ± 0.0003 | 4.4409 ± 0.4245 | 81.0594 ± 7.5982 | 14304.1484 ± 1119.2351 | 96.4639 ± 0.0333 | 0.9997 ± 0.0000 | 1321.1641x ± 44.5144 | 13443.5020x ± 2146.3408 | 2332.4319x ± 128.1096 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 2.7197x | 3.6729x | 3.7915x | 2.8196x | 1154.2656x | 1707.2698x | 3735.1653x | 1241.3081x |
| wl 1 | 2.3473x | 2.6142x | 2.2816x | 2.4500x | 952.6473x | 1057.6287x | 2128.1006x | 1076.9636x |
| wl 2 | 4.2119x | 2.4402x | 5.9656x | 3.1697x | 1771.2637x | 1089.8254x | 6035.9502x | 1485.8649x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0160 ms² | 0.0052 ms² | 0.0112 ms² | 0.0137 ms² | 697.1652 ms² | 302.1962 ms² | 1018.5877 ms² | 673.1918 ms² |
| wl 1 | 0.0136 ms² | 0.0077 ms² | 0.0137 ms² | 0.0058 ms² | 631.3596 ms² | 328.4954 ms² | 1139.1880 ms² | 347.7756 ms² |
| wl 2 | 0.0094 ms² | 0.0046 ms² | 0.0077 ms² | 0.0088 ms² | 364.8626 ms² | 375.9990 ms² | 702.1860 ms² | 512.3040 ms² |
