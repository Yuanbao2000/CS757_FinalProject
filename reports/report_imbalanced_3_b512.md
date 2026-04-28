# GPU Scheduler Group Report
Group: imbalanced_3 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_041649

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 | 0.0000 | 0.0177 | 0.0177 | 0.3819 | 4326521.0000 | 100.0000 | 0.9793 | 1.0000x | 1.0000x | 1.9782x |
| fanin_priority (blocking batch) | 0.0000 | 0.0000 | 0.0159 | 0.0159 | 0.3419 | 4833831.0000 | 100.0000 | 0.9824 | 1.0000x | 1.0000x | 1.9782x |
| DependencyAware (blocking batch) | 0.0000 | 0.0000 | 0.0176 | 0.0176 | 0.3801 | 4411386.0000 | 100.0000 | 0.9816 | 1.0000x | 1.0000x | 1.9782x |
| SJF (blocking batch) | 0.0000 | 0.0000 | 0.0178 | 0.0178 | 0.3960 | 4337950.5000 | 100.0000 | 0.9805 | 1.0000x | 1.0000x | 1.9782x |
| FIFO (single-gate non-blocking) | 4.5564 | 23.9478 | 0.0040 | 4.5604 | 166.3445 | 9778.9473 | 98.1689 | 0.9988 | 1264.4701x | 9499.8809x | 2584.1265x |
| fanin_priority (single-gate non-blocking) | 4.9646 | 23.6171 | 0.0041 | 4.9687 | 167.4502 | 9756.0332 | 98.1676 | 0.9988 | 1308.1522x | 9315.6191x | 2731.4536x |
| DependencyAware (single-gate non-blocking) | 7.7975 | 23.5900 | 0.0029 | 7.8004 | 180.9190 | 8942.8770 | 98.1126 | 0.9991 | 2976.8435x | 10971.3223x | 5858.2930x |
| SJF (single-gate non-blocking) | 4.4662 | 22.8885 | 0.0040 | 4.4702 | 161.0486 | 10045.4551 | 98.1162 | 0.9986 | 1218.2034x | 9685.7021x | 2397.7056x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0177 ± 0.0026 | 0.0177 ± 0.0026 | 0.3819 ± 0.0685 | 4326521.0000 ± 674033.5625 | 100.0000 ± 0.0000 | 0.9793 ± 0.0127 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.9782x ± 0.0000 |
| fanin_priority (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0159 ± 0.0020 | 0.0159 ± 0.0020 | 0.3419 ± 0.0632 | 4833831.0000 ± 733497.8125 | 100.0000 ± 0.0000 | 0.9824 ± 0.0038 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.9782x ± 0.0000 |
| DependencyAware (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0176 ± 0.0034 | 0.0176 ± 0.0034 | 0.3801 ± 0.0958 | 4411386.0000 ± 742790.7500 | 100.0000 ± 0.0000 | 0.9816 ± 0.0051 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.9782x ± 0.0000 |
| SJF (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0178 ± 0.0040 | 0.0178 ± 0.0040 | 0.3960 ± 0.1167 | 4337950.5000 ± 962321.7500 | 100.0000 ± 0.0000 | 0.9805 ± 0.0031 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.9782x ± 0.0000 |
| FIFO (single-gate non-blocking) | 4.5564 ± 0.5430 | 23.9478 ± 2.9750 | 0.0040 ± 0.0001 | 4.5604 ± 0.5432 | 166.3445 ± 19.8452 | 9778.9473 ± 991.9739 | 98.1689 ± 0.0308 | 0.9988 ± 0.0001 | 1264.4701x ± 66.5807 | 9499.8809x ± 1278.1783 | 2584.1265x ± 149.1797 |
| fanin_priority (single-gate non-blocking) | 4.9646 ± 0.6729 | 23.6171 ± 3.4629 | 0.0041 ± 0.0001 | 4.9687 ± 0.6730 | 167.4502 ± 23.4482 | 9756.0332 ± 1137.6586 | 98.1676 ± 0.0877 | 0.9988 ± 0.0007 | 1308.1522x ± 120.3911 | 9315.6191x ± 797.0070 | 2731.4536x ± 184.7373 |
| DependencyAware (single-gate non-blocking) | 7.7975 ± 0.7927 | 23.5900 ± 2.4649 | 0.0029 ± 0.0005 | 7.8004 ± 0.7932 | 180.9190 ± 16.3977 | 8942.8770 ± 668.2152 | 98.1126 ± 0.0843 | 0.9991 ± 0.0002 | 2976.8435x ± 170.8082 | 10971.3223x ± 922.0688 | 5858.2930x ± 371.8232 |
| SJF (single-gate non-blocking) | 4.4662 ± 0.3989 | 22.8885 ± 1.9288 | 0.0040 ± 0.0001 | 4.4702 ± 0.3989 | 161.0486 ± 14.5670 | 10045.4551 ± 742.7184 | 98.1162 ± 0.0642 | 0.9986 ± 0.0002 | 1218.2034x ± 60.3131 | 9685.7021x ± 546.1819 | 2397.7056x ± 164.0446 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 2155.0542x | 829.4621x | 2111.9009x | 872.1215x |
| wl 1 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 1551.4027x | 1367.6029x | 3145.6326x | 1132.6633x |
| wl 2 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 725.5532x | 1439.8726x | 3169.4883x | 1408.4362x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0089 ms² | 0.0077 ms² | 0.0097 ms² | 0.0108 ms² | 3006.1824 ms² | 2623.8037 ms² | 3147.1907 ms² | 2400.6472 ms² |
| wl 1 | 0.0040 ms² | 0.0035 ms² | 0.0044 ms² | 0.0047 ms² | 1775.1315 ms² | 1805.9883 ms² | 2019.1084 ms² | 1651.2158 ms² |
| wl 2 | 0.0075 ms² | 0.0064 ms² | 0.0081 ms² | 0.0091 ms² | 1762.8730 ms² | 2061.0007 ms² | 2276.1296 ms² | 1917.1410 ms² |
