# GPU Scheduler Group Report
Group: balanced_0 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_041429

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0031 | 0.0217 | 0.0138 | 0.0169 | 0.2713 | 4621407.5000 | 100.0000 | 0.9919 | 1.1758x | 2.5111x | 2.0806x |
| fanin_priority (blocking batch) | 0.0022 | 0.0489 | 0.0136 | 0.0158 | 0.2944 | 4319203.0000 | 100.0000 | 0.9882 | 1.1436x | 4.9824x | 1.9907x |
| DependencyAware (blocking batch) | 0.0038 | 0.0376 | 0.0155 | 0.0194 | 0.3203 | 4168798.0000 | 100.0000 | 0.9948 | 1.2166x | 3.1645x | 2.1471x |
| SJF (blocking batch) | 0.0031 | 0.0624 | 0.0172 | 0.0203 | 0.3216 | 4432518.0000 | 100.0000 | 0.9911 | 1.1444x | 4.0373x | 2.0537x |
| FIFO (single-gate non-blocking) | 3.6113 | 17.2818 | 0.0042 | 3.6155 | 87.4620 | 13443.5254 | 98.1333 | 0.9992 | 976.9657x | 7166.2764x | 1649.2181x |
| fanin_priority (single-gate non-blocking) | 3.6308 | 29.7409 | 0.0041 | 3.6348 | 86.8300 | 13517.2168 | 97.9897 | 0.9990 | 966.6374x | 12841.5176x | 1577.5889x |
| DependencyAware (single-gate non-blocking) | 6.8953 | 30.8747 | 0.0032 | 6.8985 | 108.4891 | 11116.4990 | 98.1756 | 0.9997 | 2335.7888x | 12660.9727x | 3843.2954x |
| SJF (single-gate non-blocking) | 3.3597 | 19.5122 | 0.0041 | 3.3637 | 85.1853 | 13710.7871 | 98.1319 | 0.9991 | 893.1198x | 8352.4531x | 1501.1980x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0031 ± 0.0006 | 0.0217 ± 0.0045 | 0.0138 ± 0.0040 | 0.0169 ± 0.0046 | 0.2713 ± 0.0950 | 4621407.5000 ± 1111767.1250 | 100.0000 ± 0.0000 | 0.9919 ± 0.0040 | 1.1758x ± 0.0186 | 2.5111x ± 0.2734 | 2.0806x ± 0.0248 |
| fanin_priority (blocking batch) | 0.0022 ± 0.0004 | 0.0489 ± 0.0100 | 0.0136 ± 0.0039 | 0.0158 ± 0.0043 | 0.2944 ± 0.1019 | 4319203.0000 ± 1215190.6250 | 100.0000 ± 0.0000 | 0.9882 ± 0.0070 | 1.1436x ± 0.0194 | 4.9824x ± 0.7693 | 1.9907x ± 0.0194 |
| DependencyAware (blocking batch) | 0.0038 ± 0.0009 | 0.0376 ± 0.0089 | 0.0155 ± 0.0052 | 0.0194 ± 0.0059 | 0.3203 ± 0.1439 | 4168798.0000 ± 1308676.7500 | 100.0000 ± 0.0000 | 0.9948 ± 0.0014 | 1.2166x ± 0.0259 | 3.1645x ± 0.4659 | 2.1471x ± 0.0316 |
| SJF (blocking batch) | 0.0031 ± 0.0029 | 0.0624 ± 0.0875 | 0.0172 ± 0.0131 | 0.0203 ± 0.0160 | 0.3216 ± 0.1946 | 4432518.0000 ± 1505508.5000 | 100.0000 ± 0.0000 | 0.9911 ± 0.0024 | 1.1444x ± 0.0675 | 4.0373x ± 2.8636 | 2.0537x ± 0.1514 |
| FIFO (single-gate non-blocking) | 3.6113 ± 0.5456 | 17.2818 ± 2.4322 | 0.0042 ± 0.0002 | 3.6155 ± 0.5457 | 87.4620 ± 13.4878 | 13443.5254 ± 1841.9558 | 98.1333 ± 0.0460 | 0.9992 ± 0.0002 | 976.9657x ± 72.5172 | 7166.2764x ± 546.5891 | 1649.2181x ± 119.8937 |
| fanin_priority (single-gate non-blocking) | 3.6308 ± 0.5280 | 29.7409 ± 4.5462 | 0.0041 ± 0.0001 | 3.6348 ± 0.5280 | 86.8300 ± 12.8814 | 13517.2168 ± 1765.2183 | 97.9897 ± 0.3975 | 0.9990 ± 0.0001 | 966.6374x ± 113.8691 | 12841.5176x ± 2265.8071 | 1577.5889x ± 140.9285 |
| DependencyAware (single-gate non-blocking) | 6.8953 ± 1.9071 | 30.8747 ± 8.2393 | 0.0032 ± 0.0009 | 6.8985 ± 1.9079 | 108.4891 ± 27.9611 | 11116.4990 ± 2007.4922 | 98.1756 ± 0.1894 | 0.9997 ± 0.0001 | 2335.7888x ± 279.5685 | 12660.9727x ± 1576.6733 | 3843.2954x ± 504.2095 |
| SJF (single-gate non-blocking) | 3.3597 ± 0.4434 | 19.5122 ± 2.6603 | 0.0041 ± 0.0001 | 3.3637 ± 0.4434 | 85.1853 ± 10.9573 | 13710.7871 ± 1550.9313 | 98.1319 ± 0.0544 | 0.9991 ± 0.0001 | 893.1198x ± 87.6909 | 8352.4531x ± 1440.1084 | 1501.1980x ± 162.7724 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 1.1477x | 1.2838x | 1.1094x | 1.2290x | 1120.7341x | 1157.3265x | 1803.9078x | 1076.1729x |
| wl 1 | 1.1025x | 1.1646x | 1.0509x | 1.0844x | 663.3384x | 776.6889x | 1398.6345x | 715.3387x |
| wl 2 | 1.2274x | 1.0569x | 1.3571x | 1.1280x | 1054.4116x | 957.1410x | 3090.5601x | 881.7397x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0056 ms² | 0.0059 ms² | 0.0086 ms² | 0.0061 ms² | 796.3087 ms² | 502.5908 ms² | 1181.0739 ms² | 544.2812 ms² |
| wl 1 | 0.0058 ms² | 0.0075 ms² | 0.0096 ms² | 0.0069 ms² | 735.0967 ms² | 540.1902 ms² | 1116.4437 ms² | 565.9331 ms² |
| wl 2 | 0.0024 ms² | 0.0027 ms² | 0.0034 ms² | 0.0053 ms² | 419.7480 ms² | 466.2671 ms² | 695.0465 ms² | 468.2157 ms² |
