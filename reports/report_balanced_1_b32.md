# GPU Scheduler Group Report
Group: balanced_1 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_041240

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0126 | 0.0483 | 0.0098 | 0.0224 | 0.4547 | 2907839.2500 | 100.0000 | 0.9843 | 2.3622x | 6.3315x | 4.5209x |
| fanin_priority (blocking batch) | 0.0126 | 0.2638 | 0.0109 | 0.0235 | 0.4934 | 2633661.5000 | 100.0000 | 0.9963 | 2.2092x | 32.4805x | 3.3735x |
| DependencyAware (blocking batch) | 0.0231 | 0.2215 | 0.0115 | 0.0346 | 0.5213 | 2589316.7500 | 100.0000 | 0.9902 | 3.1357x | 24.7486x | 6.1415x |
| SJF (blocking batch) | 0.0125 | 0.1598 | 0.0105 | 0.0229 | 0.4941 | 2683377.5000 | 100.0000 | 0.9765 | 2.2392x | 18.6542x | 4.6826x |
| FIFO (single-gate non-blocking) | 4.2785 | 11.9061 | 0.0040 | 4.2826 | 96.1026 | 12554.9512 | 96.3403 | 0.9964 | 1195.0818x | 5235.6045x | 2297.0256x |
| fanin_priority (single-gate non-blocking) | 3.7728 | 58.5863 | 0.0037 | 3.7765 | 94.4565 | 12756.6309 | 96.3994 | 0.9996 | 1039.7035x | 23023.0410x | 1521.6619x |
| DependencyAware (single-gate non-blocking) | 8.8278 | 63.5922 | 0.0031 | 8.8309 | 116.2664 | 10361.1309 | 96.3905 | 0.9990 | 3192.1802x | 24407.4316x | 6286.3086x |
| SJF (single-gate non-blocking) | 3.9491 | 39.6764 | 0.0036 | 3.9527 | 93.5469 | 12820.1748 | 96.3231 | 0.9941 | 1148.4408x | 12279.2959x | 2447.0239x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0126 ± 0.0044 | 0.0483 ± 0.0188 | 0.0098 ± 0.0037 | 0.0224 ± 0.0081 | 0.4547 ± 0.1866 | 2907839.2500 ± 735598.7500 | 100.0000 ± 0.0000 | 0.9843 ± 0.0046 | 2.3622x ± 0.0442 | 6.3315x ± 0.6848 | 4.5209x ± 0.0604 |
| fanin_priority (blocking batch) | 0.0126 ± 0.0044 | 0.2638 ± 0.0869 | 0.0109 ± 0.0037 | 0.0235 ± 0.0080 | 0.4934 ± 0.1738 | 2633661.5000 ± 661277.7500 | 100.0000 ± 0.0000 | 0.9963 ± 0.0011 | 2.2092x ± 0.1533 | 32.4805x ± 7.4122 | 3.3735x ± 0.1611 |
| DependencyAware (blocking batch) | 0.0231 ± 0.0082 | 0.2215 ± 0.0862 | 0.0115 ± 0.0044 | 0.0346 ± 0.0125 | 0.5213 ± 0.2095 | 2589316.7500 ± 789064.8125 | 100.0000 ± 0.0000 | 0.9902 ± 0.0030 | 3.1357x ± 0.0771 | 24.7486x ± 9.5490 | 6.1415x ± 0.1020 |
| SJF (blocking batch) | 0.0125 ± 0.0056 | 0.1598 ± 0.0837 | 0.0105 ± 0.0045 | 0.0229 ± 0.0102 | 0.4941 ± 0.2011 | 2683377.5000 ± 712435.4375 | 100.0000 ± 0.0000 | 0.9765 ± 0.0061 | 2.2392x ± 0.1451 | 18.6542x ± 2.0385 | 4.6826x ± 0.1330 |
| FIFO (single-gate non-blocking) | 4.2785 ± 0.5716 | 11.9061 ± 1.4355 | 0.0040 ± 0.0002 | 4.2826 ± 0.5719 | 96.1026 ± 12.4764 | 12554.9512 ± 1411.5410 | 96.3403 ± 0.0607 | 0.9964 ± 0.0004 | 1195.0818x ± 73.3747 | 5235.6045x ± 417.1710 | 2297.0256x ± 148.9752 |
| fanin_priority (single-gate non-blocking) | 3.7728 ± 0.4595 | 58.5863 ± 7.1523 | 0.0037 ± 0.0003 | 3.7765 ± 0.4597 | 94.4565 ± 11.8076 | 12756.6309 ± 1351.4585 | 96.3994 ± 0.0770 | 0.9996 ± 0.0001 | 1039.7035x ± 88.6069 | 23023.0410x ± 3482.3262 | 1521.6619x ± 94.1397 |
| DependencyAware (single-gate non-blocking) | 8.8278 ± 1.0868 | 63.5922 ± 7.9505 | 0.0031 ± 0.0007 | 8.8309 ± 1.0876 | 116.2664 ± 14.3354 | 10361.1309 ± 1093.2465 | 96.3905 ± 0.0739 | 0.9990 ± 0.0001 | 3192.1802x ± 316.0498 | 24407.4316x ± 4354.1279 | 6286.3086x ± 621.7482 |
| SJF (single-gate non-blocking) | 3.9491 ± 0.4673 | 39.6764 ± 5.4493 | 0.0036 ± 0.0003 | 3.9527 ± 0.4676 | 93.5469 ± 9.2591 | 12820.1748 ± 1112.8286 | 96.3231 ± 0.1127 | 0.9941 ± 0.0007 | 1148.4408x ± 65.9434 | 12279.2959x ± 2342.0400 | 2447.0239x ± 170.0867 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 2.0699x | 3.9829x | 2.6524x | 2.0820x | 956.0377x | 1969.7195x | 2301.6367x | 834.7740x |
| wl 1 | 2.3695x | 3.3577x | 3.1172x | 2.1733x | 1196.2535x | 1539.9084x | 3000.8337x | 1093.8660x |
| wl 2 | 2.4276x | 1.4229x | 3.2538x | 2.2972x | 1250.1522x | 660.7203x | 3461.2129x | 1239.0156x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0205 ms² | 0.0207 ms² | 0.0265 ms² | 0.0328 ms² | 1172.7278 ms² | 740.8722 ms² | 1486.2727 ms² | 1291.8048 ms² |
| wl 1 | 0.0162 ms² | 0.0142 ms² | 0.0209 ms² | 0.0143 ms² | 960.7144 ms² | 551.5714 ms² | 1267.7065 ms² | 681.1876 ms² |
| wl 2 | 0.0122 ms² | 0.0126 ms² | 0.0181 ms² | 0.0150 ms² | 624.3430 ms² | 540.8402 ms² | 996.4324 ms² | 616.2396 ms² |
