# GPU Scheduler Group Report
Group: imbalanced_2 | batch_size=512 | runs=10 (averaged)

Generated: 20260505_185257

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (gates/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (batch blocking) | 1.6406 | 5.4257 | 0.0235 | 1.6641 | 29.4942 | 24856.3320 | 1.5379 | 0.9942 | 71.4634x | 181.1559x | 139.3637x |
| fanin_priority (batch blocking) | 1.6906 | 5.5365 | 0.0255 | 1.7161 | 30.5227 | 24029.2520 | 1.7113 | 0.9941 | 69.1344x | 178.2545x | 134.6079x |
| DependencyAware (batch blocking) | 2.1922 | 6.4506 | 0.0260 | 2.2182 | 33.9395 | 21603.2305 | 1.4106 | 0.9955 | 81.8593x | 180.5174x | 151.3694x |
| SJF (batch blocking) | 1.6827 | 5.4672 | 0.0247 | 1.7074 | 30.4361 | 24166.2227 | 1.6101 | 0.9941 | 70.0912x | 189.3174x | 136.7156x |
| FIFO (single-gate non-blocking) | 2.1358 | 6.2192 | 0.0740 | 2.2098 | 33.6597 | 21840.4492 | 77.7817 | 0.9971 | 53.3218x | 387.7508x | 88.7350x |
| fanin_priority (single-gate non-blocking) | 1.5221 | 26.7071 | 0.0731 | 1.5952 | 33.3409 | 21996.6270 | 77.7134 | 0.9907 | 21.7264x | 367.9091x | 28.2355x |
| DependencyAware (single-gate non-blocking) | 4.1117 | 28.1136 | 0.0924 | 4.2041 | 42.7977 | 17135.3965 | 76.9332 | 1.0000 | 50.5420x | 492.2328x | 77.1642x |
| SJF (single-gate non-blocking) | 1.6353 | 12.4016 | 0.0752 | 1.7104 | 34.4793 | 21273.6055 | 77.5134 | 0.9719 | 35.7330x | 596.1078x | 58.1144x |
| FIFO (batch non-blocking) | 1.6391 | 5.4656 | 0.0313 | 1.6703 | 29.6246 | 24755.6680 | 1.8102 | 0.9939 | 60.9910x | 146.8869x | 119.6789x |
| fanin_priority (batch non-blocking) | 1.6627 | 5.5010 | 0.0479 | 1.7105 | 30.3247 | 24219.6406 | 2.5032 | 0.9940 | 40.0854x | 96.7351x | 79.4377x |
| DependencyAware (batch non-blocking) | 1.6703 | 5.5960 | 0.5689 | 2.2392 | 34.3515 | 21373.2227 | 14.0433 | 0.9952 | 10.5108x | 65.2868x | 21.8053x |
| SJF (batch non-blocking) | 1.6662 | 5.5393 | 0.0467 | 1.7129 | 30.1809 | 24342.6152 | 2.3915 | 0.9944 | 41.8321x | 99.5530x | 82.9988x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (gates/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (batch blocking) | 1.6406 ± 0.0244 | 5.4257 ± 0.1139 | 0.0235 ± 0.0031 | 1.6641 ± 0.0261 | 29.4942 ± 0.3738 | 24856.3320 ± 314.9079 | 1.5379 ± 0.1607 | 0.9942 ± 0.0003 | 71.4634x ± 6.4475 | 181.1559x ± 17.6640 | 139.3637x ± 12.6632 |
| fanin_priority (batch blocking) | 1.6906 ± 0.0454 | 5.5365 ± 0.1672 | 0.0255 ± 0.0043 | 1.7161 ± 0.0490 | 30.5227 ± 0.7531 | 24029.2520 ± 581.6680 | 1.7113 ± 0.1866 | 0.9941 ± 0.0007 | 69.1344x ± 7.0525 | 178.2545x ± 23.2752 | 134.6079x ± 13.5334 |
| DependencyAware (batch blocking) | 2.1922 ± 0.0636 | 6.4506 ± 0.2838 | 0.0260 ± 0.0033 | 2.2182 ± 0.0648 | 33.9395 ± 0.5663 | 21603.2305 ± 360.1942 | 1.4106 ± 0.1168 | 0.9955 ± 0.0002 | 81.8593x ± 7.4966 | 180.5174x ± 25.9900 | 151.3694x ± 13.5237 |
| SJF (batch blocking) | 1.6827 ± 0.0669 | 5.4672 ± 0.2023 | 0.0247 ± 0.0045 | 1.7074 ± 0.0708 | 30.4361 ± 1.9172 | 24166.2227 ± 1317.8402 | 1.6101 ± 0.2771 | 0.9941 ± 0.0004 | 70.0912x ± 7.9975 | 189.3174x ± 13.6272 | 136.7156x ± 15.7841 |
| FIFO (single-gate non-blocking) | 2.1358 ± 0.0813 | 6.2192 ± 0.2191 | 0.0740 ± 0.0044 | 2.2098 ± 0.0855 | 33.6597 ± 1.8969 | 21840.4492 ± 1130.9166 | 77.7817 ± 0.1962 | 0.9971 ± 0.0003 | 53.3218x ± 0.9402 | 387.7508x ± 17.6745 | 88.7350x ± 1.7542 |
| fanin_priority (single-gate non-blocking) | 1.5221 ± 0.0895 | 26.7071 ± 0.7757 | 0.0731 ± 0.0018 | 1.5952 ± 0.0911 | 33.3409 ± 0.7763 | 21996.6270 ± 497.5511 | 77.7134 ± 0.1426 | 0.9907 ± 0.0005 | 21.7264x ± 0.5079 | 367.9091x ± 16.1224 | 28.2355x ± 0.4882 |
| DependencyAware (single-gate non-blocking) | 4.1117 ± 0.0848 | 28.1136 ± 0.7781 | 0.0924 ± 0.0022 | 4.2041 ± 0.0868 | 42.7977 ± 0.9513 | 17135.3965 ± 373.4202 | 76.9332 ± 0.1288 | 1.0000 ± 0.0000 | 50.5420x ± 0.5174 | 492.2328x ± 32.0233 | 77.1642x ± 0.6535 |
| SJF (single-gate non-blocking) | 1.6353 ± 0.0433 | 12.4016 ± 0.5023 | 0.0752 ± 0.0020 | 1.7104 ± 0.0450 | 34.4793 ± 0.9049 | 21273.6055 ± 552.9672 | 77.5134 ± 0.2007 | 0.9719 ± 0.0010 | 35.7330x ± 0.4546 | 596.1078x ± 37.1150 | 58.1144x ± 0.8141 |
| FIFO (batch non-blocking) | 1.6391 ± 0.0416 | 5.4656 ± 0.1781 | 0.0313 ± 0.0039 | 1.6703 ± 0.0430 | 29.6246 ± 0.6776 | 24755.6680 ± 556.9425 | 1.8102 ± 0.1775 | 0.9939 ± 0.0004 | 60.9910x ± 2.5113 | 146.8869x ± 10.9582 | 119.6789x ± 4.9134 |
| fanin_priority (batch non-blocking) | 1.6627 ± 0.0650 | 5.5010 ± 0.2482 | 0.0479 ± 0.0030 | 1.7105 ± 0.0661 | 30.3247 ± 1.3909 | 24219.6406 ± 1045.4299 | 2.5032 ± 0.2245 | 0.9940 ± 0.0007 | 40.0854x ± 2.2301 | 96.7351x ± 4.8611 | 79.4377x ± 4.2760 |
| DependencyAware (batch non-blocking) | 1.6703 ± 0.0755 | 5.5960 ± 0.4682 | 0.5689 ± 0.0468 | 2.2392 ± 0.1204 | 34.3515 ± 1.4155 | 21373.2227 ± 849.9471 | 14.0433 ± 0.4373 | 0.9952 ± 0.0010 | 10.5108x ± 0.2839 | 65.2868x ± 13.4703 | 21.8053x ± 0.6856 |
| SJF (batch non-blocking) | 1.6662 ± 0.1070 | 5.5393 ± 0.4513 | 0.0467 ± 0.0066 | 1.7129 ± 0.1132 | 30.1809 ± 1.5246 | 24342.6152 ± 1103.6498 | 2.3915 ± 0.1845 | 0.9944 ± 0.0005 | 41.8321x ± 2.9709 | 99.5530x ± 11.2219 | 82.9988x ± 5.9288 |

## Per-Workload Avg Slowdown

| Workload | FIFO (batch blocking) | fanin_priority (batch blocking) | DependencyAware (batch blocking) | SJF (batch blocking) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) | FIFO (batch non-blocking) | fanin_priority (batch non-blocking) | DependencyAware (batch non-blocking) | SJF (batch non-blocking) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| wl 0 | 58.4605x | 57.0991x | 70.2545x | 58.3818x | 40.0213x | 23.7636x | 39.3085x | 36.9364x | 49.7288x | 32.9571x | 9.2947x | 34.4743x |
| wl 1 | 84.0602x | 80.9014x | 94.4430x | 81.2774x | 58.3476x | 26.6239x | 52.3427x | 34.0457x | 71.0130x | 44.8334x | 9.3374x | 46.8094x |
| wl 2 | 68.7432x | 66.5295x | 78.3437x | 67.7696x | 56.9139x | 16.5796x | 55.5581x | 36.4078x | 59.3557x | 40.3441x | 12.1637x | 42.0373x |

## Per-Workload Completion Variance

| Workload | FIFO (batch blocking) | fanin_priority (batch blocking) | DependencyAware (batch blocking) | SJF (batch blocking) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) | FIFO (batch non-blocking) | fanin_priority (batch non-blocking) | DependencyAware (batch non-blocking) | SJF (batch non-blocking) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| wl 0 | 103.4487 ms² | 110.2992 ms² | 122.4869 ms² | 110.2119 ms² | 130.1660 ms² | 119.7700 ms² | 173.9385 ms² | 156.5198 ms² | 103.4631 ms² | 108.4434 ms² | 124.8252 ms² | 108.3638 ms² |
| wl 1 | 81.4069 ms² | 86.7335 ms² | 97.3966 ms² | 86.5880 ms² | 94.9397 ms² | 48.3333 ms² | 151.7615 ms² | 34.2066 ms² | 81.0955 ms² | 84.7906 ms² | 98.1535 ms² | 85.6066 ms² |
| wl 2 | 76.2537 ms² | 81.2374 ms² | 90.7518 ms² | 81.0240 ms² | 72.9209 ms² | 104.0972 ms² | 126.3720 ms² | 110.2528 ms² | 76.1551 ms² | 79.4662 ms² | 92.2124 ms² | 80.1598 ms² |
