# GPU Scheduler Group Report
Group: imbalanced_4 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_041508

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0038 | 0.0265 | 0.0174 | 0.0212 | 0.3814 | 4994162.0000 | 100.0000 | 0.8542 | 1.2036x | 2.5146x | 2.1219x |
| fanin_priority (blocking batch) | 0.0022 | 0.0713 | 0.0158 | 0.0180 | 0.3555 | 5119705.5000 | 100.0000 | 0.8863 | 1.1263x | 5.5255x | 1.9580x |
| DependencyAware (blocking batch) | 0.0064 | 0.0912 | 0.0157 | 0.0221 | 0.3349 | 5399239.5000 | 100.0000 | 0.9238 | 1.3814x | 6.9386x | 2.3113x |
| SJF (blocking batch) | 0.0030 | 0.1079 | 0.0152 | 0.0182 | 0.3352 | 5417897.0000 | 100.0000 | 0.8806 | 1.1791x | 7.5301x | 2.1801x |
| FIFO (single-gate non-blocking) | 6.8835 | 23.3120 | 0.0041 | 6.8876 | 180.6429 | 9771.5693 | 98.7901 | 0.8941 | 1946.1194x | 10469.2998x | 3413.9062x |
| fanin_priority (single-gate non-blocking) | 5.8021 | 53.3612 | 0.0040 | 5.8061 | 183.2768 | 9629.2266 | 98.6888 | 0.9475 | 1602.9368x | 22381.1250x | 2660.2917x |
| DependencyAware (single-gate non-blocking) | 12.6865 | 87.8478 | 0.0028 | 12.6893 | 214.7936 | 8239.7852 | 98.6683 | 0.9752 | 4882.6636x | 41992.3281x | 7661.1211x |
| SJF (single-gate non-blocking) | 6.7353 | 82.5647 | 0.0042 | 6.7394 | 185.7723 | 9523.5449 | 98.6028 | 0.9072 | 1802.3375x | 29614.2715x | 3415.9126x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0038 ± 0.0008 | 0.0265 ± 0.0069 | 0.0174 ± 0.0051 | 0.0212 ± 0.0058 | 0.3814 ± 0.1239 | 4994162.0000 ± 1251450.6250 | 100.0000 ± 0.0000 | 0.8542 ± 0.0188 | 1.2036x ± 0.0250 | 2.5146x ± 0.2293 | 2.1219x ± 0.0267 |
| fanin_priority (blocking batch) | 0.0022 ± 0.0004 | 0.0713 ± 0.0165 | 0.0158 ± 0.0029 | 0.0180 ± 0.0033 | 0.3555 ± 0.0702 | 5119705.5000 ± 968593.1875 | 100.0000 ± 0.0000 | 0.8863 ± 0.0242 | 1.1263x ± 0.0079 | 5.5255x ± 0.8918 | 1.9580x ± 0.0078 |
| DependencyAware (blocking batch) | 0.0064 ± 0.0010 | 0.0912 ± 0.0173 | 0.0157 ± 0.0028 | 0.0221 ± 0.0038 | 0.3349 ± 0.0678 | 5399239.5000 ± 826839.4375 | 100.0000 ± 0.0000 | 0.9238 ± 0.0196 | 1.3814x ± 0.0248 | 6.9386x ± 1.2533 | 2.3113x ± 0.0255 |
| SJF (blocking batch) | 0.0030 ± 0.0006 | 0.1079 ± 0.0259 | 0.0152 ± 0.0031 | 0.0182 ± 0.0037 | 0.3352 ± 0.0711 | 5417897.0000 ± 908258.5000 | 100.0000 ± 0.0000 | 0.8806 ± 0.0151 | 1.1791x ± 0.0102 | 7.5301x ± 0.8294 | 2.1801x ± 0.0155 |
| FIFO (single-gate non-blocking) | 6.8835 ± 0.6159 | 23.3120 ± 2.3240 | 0.0041 ± 0.0001 | 6.8876 ± 0.6160 | 180.6429 ± 16.5923 | 9771.5693 ± 734.2814 | 98.7901 ± 0.0145 | 0.8941 ± 0.0033 | 1946.1194x ± 77.2875 | 10469.2998x ± 736.1105 | 3413.9062x ± 128.7869 |
| fanin_priority (single-gate non-blocking) | 5.8021 ± 0.5397 | 53.3612 ± 4.7351 | 0.0040 ± 0.0002 | 5.8061 ± 0.5398 | 183.2768 ± 16.5049 | 9629.2266 ± 717.2166 | 98.6888 ± 0.0121 | 0.9475 ± 0.0030 | 1602.9368x ± 143.5302 | 22381.1250x ± 4153.1846 | 2660.2917x ± 201.7605 |
| DependencyAware (single-gate non-blocking) | 12.6865 ± 1.3331 | 87.8478 ± 8.7174 | 0.0028 ± 0.0005 | 12.6893 ± 1.3337 | 214.7936 ± 23.7436 | 8239.7852 ± 710.5726 | 98.6683 ± 0.0392 | 0.9752 ± 0.0014 | 4882.6636x ± 197.0756 | 41992.3281x ± 2683.1860 | 7661.1211x ± 351.7822 |
| SJF (single-gate non-blocking) | 6.7353 ± 0.7157 | 82.5647 ± 9.1762 | 0.0042 ± 0.0004 | 6.7394 ± 0.7161 | 185.7723 ± 19.4756 | 9523.5449 ± 834.6807 | 98.6028 ± 0.2556 | 0.9072 ± 0.0084 | 1802.3375x ± 167.5848 | 29614.2715x ± 5851.5210 | 3415.9126x ± 354.9759 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 1.1784x | 1.6407x | 1.7947x | 1.5072x | 1973.4968x | 3233.6782x | 7007.2866x | 2773.2192x |
| wl 1 | 1.1005x | 1.2037x | 1.1313x | 1.2845x | 1099.1047x | 1583.5695x | 2825.2996x | 1845.7367x |
| wl 2 | 1.2236x | 1.1069x | 1.4257x | 1.1559x | 2108.3162x | 1592.1310x | 5258.3081x | 1785.3698x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0015 ms² | 0.0016 ms² | 0.0026 ms² | 0.0013 ms² | 819.7191 ms² | 998.2855 ms² | 2288.9666 ms² | 733.1606 ms² |
| wl 1 | 0.0124 ms² | 0.0107 ms² | 0.0099 ms² | 0.0086 ms² | 3566.5657 ms² | 2824.6426 ms² | 4877.1572 ms² | 2919.1562 ms² |
| wl 2 | 0.0088 ms² | 0.0077 ms² | 0.0062 ms² | 0.0064 ms² | 2511.1289 ms² | 2653.2532 ms² | 3452.9727 ms² | 2682.7820 ms² |
