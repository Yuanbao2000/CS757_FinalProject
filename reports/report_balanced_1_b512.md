# GPU Scheduler Group Report
Group: balanced_1 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_041633

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 | 0.0000 | 0.0166 | 0.0166 | 0.3939 | 3323187.5000 | 100.0000 | 0.9728 | 1.0000x | 1.0000x | 2.0185x |
| fanin_priority (blocking batch) | 0.0000 | 0.0000 | 0.0139 | 0.0139 | 0.3382 | 3939658.0000 | 100.0000 | 0.9665 | 1.0000x | 1.0000x | 2.0185x |
| DependencyAware (blocking batch) | 0.0000 | 0.0000 | 0.0142 | 0.0142 | 0.3495 | 3806619.2500 | 100.0000 | 0.9683 | 1.0000x | 1.0000x | 2.0185x |
| SJF (blocking batch) | 0.0000 | 0.0000 | 0.0140 | 0.0140 | 0.3585 | 3624176.0000 | 100.0000 | 0.9599 | 1.0000x | 1.0000x | 2.0185x |
| FIFO (single-gate non-blocking) | 2.3820 | 10.1800 | 0.0041 | 2.3861 | 94.4314 | 12732.8877 | 97.4784 | 0.9961 | 654.9829x | 4483.1133x | 1319.2068x |
| fanin_priority (single-gate non-blocking) | 2.4662 | 10.3659 | 0.0041 | 2.4703 | 94.8703 | 12705.0889 | 97.5083 | 0.9972 | 664.2355x | 4503.3071x | 1392.0825x |
| DependencyAware (single-gate non-blocking) | 3.9559 | 11.3775 | 0.0031 | 3.9589 | 105.6970 | 11401.3398 | 97.3955 | 0.9974 | 1446.5074x | 5030.2451x | 2917.1438x |
| SJF (single-gate non-blocking) | 2.6555 | 10.9804 | 0.0041 | 2.6595 | 99.7811 | 12144.7910 | 97.4852 | 0.9962 | 712.1128x | 4535.9580x | 1433.4226x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0166 ± 0.0044 | 0.0166 ± 0.0044 | 0.3939 ± 0.1374 | 3323187.5000 ± 902844.6250 | 100.0000 ± 0.0000 | 0.9728 ± 0.0085 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 2.0185x ± 0.0000 |
| fanin_priority (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0139 ± 0.0052 | 0.0139 ± 0.0052 | 0.3382 ± 0.1308 | 3939658.0000 ± 1115815.1250 | 100.0000 ± 0.0000 | 0.9665 ± 0.0073 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 2.0185x ± 0.0000 |
| DependencyAware (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0142 ± 0.0043 | 0.0142 ± 0.0043 | 0.3495 ± 0.1306 | 3806619.2500 ± 1091912.8750 | 100.0000 ± 0.0000 | 0.9683 ± 0.0086 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 2.0185x ± 0.0000 |
| SJF (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0140 ± 0.0041 | 0.0140 ± 0.0041 | 0.3585 ± 0.1173 | 3624176.0000 ± 963591.6875 | 100.0000 ± 0.0000 | 0.9599 ± 0.0216 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 2.0185x ± 0.0000 |
| FIFO (single-gate non-blocking) | 2.3820 ± 0.2677 | 10.1800 ± 1.0052 | 0.0041 ± 0.0001 | 2.3861 ± 0.2677 | 94.4314 ± 10.6849 | 12732.8877 ± 1254.1869 | 97.4784 ± 0.0735 | 0.9961 ± 0.0008 | 654.9829x ± 33.7643 | 4483.1133x ± 484.1274 | 1319.2068x ± 68.8889 |
| fanin_priority (single-gate non-blocking) | 2.4662 ± 0.3249 | 10.3659 ± 1.2347 | 0.0041 ± 0.0001 | 2.4703 ± 0.3250 | 94.8703 ± 12.0389 | 12705.0889 ± 1357.2054 | 97.5083 ± 0.0551 | 0.9972 ± 0.0001 | 664.2355x ± 64.2304 | 4503.3071x ± 607.3044 | 1392.0825x ± 102.6946 |
| DependencyAware (single-gate non-blocking) | 3.9559 ± 0.4930 | 11.3775 ± 1.5979 | 0.0031 ± 0.0007 | 3.9589 ± 0.4937 | 105.6970 ± 13.1063 | 11401.3398 ± 1229.8074 | 97.3955 ± 0.0888 | 0.9974 ± 0.0005 | 1446.5074x ± 109.5538 | 5030.2451x ± 280.4246 | 2917.1438x ± 213.5083 |
| SJF (single-gate non-blocking) | 2.6555 ± 0.4086 | 10.9804 ± 1.6613 | 0.0041 ± 0.0002 | 2.6595 ± 0.4088 | 99.7811 ± 14.4041 | 12144.7910 ± 1587.5784 | 97.4852 ± 0.1401 | 0.9962 ± 0.0009 | 712.1128x ± 78.3647 | 4535.9580x ± 196.6173 | 1433.4226x ± 179.1314 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 1167.6628x | 613.1146x | 1221.3536x | 466.2256x |
| wl 1 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 821.9554x | 547.1832x | 1149.8674x | 681.6468x |
| wl 2 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 481.5620x | 714.2935x | 1595.5444x | 779.0959x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0127 ms² | 0.0101 ms² | 0.0103 ms² | 0.0101 ms² | 1098.5950 ms² | 981.2134 ms² | 1238.6520 ms² | 1137.2664 ms² |
| wl 1 | 0.0094 ms² | 0.0074 ms² | 0.0077 ms² | 0.0074 ms² | 902.3264 ms² | 921.6786 ms² | 1095.6743 ms² | 974.6071 ms² |
| wl 2 | 0.0084 ms² | 0.0067 ms² | 0.0071 ms² | 0.0070 ms² | 591.2482 ms² | 640.8163 ms² | 782.1320 ms² | 704.2206 ms² |
