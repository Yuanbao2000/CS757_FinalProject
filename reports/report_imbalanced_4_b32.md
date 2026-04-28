# GPU Scheduler Group Report
Group: imbalanced_4 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_041313

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0409 | 0.1286 | 0.0150 | 0.0559 | 0.8500 | 2401749.7500 | 100.0000 | 0.9012 | 3.9610x | 11.1848x | 6.8894x |
| fanin_priority (blocking batch) | 0.0220 | 0.6258 | 0.0127 | 0.0347 | 0.7516 | 2495824.5000 | 100.0000 | 0.9856 | 2.9391x | 67.8937x | 3.7890x |
| DependencyAware (blocking batch) | 0.0503 | 0.4355 | 0.0118 | 0.0621 | 0.6680 | 2798982.5000 | 100.0000 | 0.9988 | 5.6845x | 44.9080x | 8.6341x |
| SJF (blocking batch) | 0.0245 | 0.4644 | 0.0112 | 0.0358 | 0.6731 | 2812181.2500 | 100.0000 | 0.8758 | 3.3852x | 48.8081x | 6.9933x |
| FIFO (single-gate non-blocking) | 10.6189 | 24.0595 | 0.0042 | 10.6231 | 186.4239 | 9519.6113 | 97.0627 | 0.8936 | 2832.9961x | 10535.1387x | 4987.7812x |
| fanin_priority (single-gate non-blocking) | 6.8511 | 167.7433 | 0.0039 | 6.8550 | 187.8351 | 9468.1748 | 96.8752 | 0.9916 | 1786.7078x | 55864.2305x | 2205.2153x |
| DependencyAware (single-gate non-blocking) | 22.4832 | 171.7448 | 0.0032 | 22.4864 | 247.3066 | 7209.9399 | 96.9178 | 0.9996 | 8026.1689x | 75894.0156x | 12015.2480x |
| SJF (single-gate non-blocking) | 8.8668 | 145.1454 | 0.0039 | 8.8707 | 190.0735 | 9359.7422 | 96.8468 | 0.8853 | 2329.4089x | 41197.9141x | 4887.7632x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0409 ± 0.0164 | 0.1286 ± 0.0519 | 0.0150 ± 0.0060 | 0.0559 ± 0.0224 | 0.8500 ± 0.3407 | 2401749.7500 ± 856128.8125 | 100.0000 ± 0.0000 | 0.9012 ± 0.0166 | 3.9610x ± 0.1584 | 11.1848x ± 1.2256 | 6.8894x ± 0.2546 |
| fanin_priority (blocking batch) | 0.0220 ± 0.0077 | 0.6258 ± 0.1747 | 0.0127 ± 0.0036 | 0.0347 ± 0.0110 | 0.7516 ± 0.2155 | 2495824.5000 ± 579374.4375 | 100.0000 ± 0.0000 | 0.9856 ± 0.0099 | 2.9391x ± 0.3684 | 67.8937x ± 21.0529 | 3.7890x ± 0.3696 |
| DependencyAware (blocking batch) | 0.0503 ± 0.0150 | 0.4355 ± 0.1299 | 0.0118 ± 0.0034 | 0.0621 ± 0.0184 | 0.6680 ± 0.1921 | 2798982.5000 ± 617963.2500 | 100.0000 ± 0.0000 | 0.9988 ± 0.0005 | 5.6845x ± 0.3122 | 44.9080x ± 6.9301 | 8.6341x ± 0.3987 |
| SJF (blocking batch) | 0.0245 ± 0.0080 | 0.4644 ± 0.1543 | 0.0112 ± 0.0036 | 0.0358 ± 0.0116 | 0.6731 ± 0.2153 | 2812181.2500 ± 661652.6250 | 100.0000 ± 0.0000 | 0.8758 ± 0.0184 | 3.3852x ± 0.1006 | 48.8081x ± 7.5585 | 6.9933x ± 0.2775 |
| FIFO (single-gate non-blocking) | 10.6189 ± 1.2731 | 24.0595 ± 2.9724 | 0.0042 ± 0.0002 | 10.6231 ± 1.2732 | 186.4239 ± 22.3338 | 9519.6113 ± 971.4639 | 97.0627 ± 0.0304 | 0.8936 ± 0.0027 | 2832.9961x ± 142.5043 | 10535.1387x ± 1092.3854 | 4987.7812x ± 259.6329 |
| fanin_priority (single-gate non-blocking) | 6.8511 ± 0.8616 | 167.7433 ± 21.2559 | 0.0039 ± 0.0005 | 6.8550 ± 0.8621 | 187.8351 ± 24.5188 | 9468.1748 ± 1039.0098 | 96.8752 ± 0.0746 | 0.9916 ± 0.0009 | 1786.7078x ± 160.7045 | 55864.2305x ± 7490.3940 | 2205.2153x ± 149.4783 |
| DependencyAware (single-gate non-blocking) | 22.4832 ± 3.2803 | 171.7448 ± 24.0369 | 0.0032 ± 0.0009 | 22.4864 ± 3.2812 | 247.3066 ± 35.2877 | 7209.9399 ± 853.2578 | 96.9178 ± 0.0398 | 0.9996 ± 0.0000 | 8026.1689x ± 746.1158 | 75894.0156x ± 6143.9131 | 12015.2480x ± 1078.1716 |
| SJF (single-gate non-blocking) | 8.8668 ± 1.1239 | 145.1454 ± 18.7821 | 0.0039 ± 0.0003 | 8.8707 ± 1.1242 | 190.0735 ± 24.4694 | 9359.7422 ± 1066.1366 | 96.8468 ± 0.0503 | 0.8853 ± 0.0075 | 2329.4089x ± 221.2805 | 41197.9141x ± 5601.9980 | 4887.7632x ± 559.3223 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 4.1097x | 9.0076x | 9.3610x | 4.5820x | 2655.8892x | 5973.4497x | 13642.3955x | 3533.4966x |
| wl 1 | 2.9000x | 3.5573x | 3.4784x | 3.1569x | 1907.4919x | 2095.5288x | 4335.6050x | 2129.5776x |
| wl 2 | 4.1631x | 2.7665x | 6.0749x | 3.4183x | 3012.0664x | 1690.2029x | 8683.9404x | 2357.0107x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0210 ms² | 0.0422 ms² | 0.0409 ms² | 0.0076 ms² | 878.2537 ms² | 2810.5068 ms² | 6035.2148 ms² | 691.5242 ms² |
| wl 1 | 0.0832 ms² | 0.0310 ms² | 0.0502 ms² | 0.0329 ms² | 3854.3442 ms² | 2157.3450 ms² | 7102.2471 ms² | 2692.3801 ms² |
| wl 2 | 0.0578 ms² | 0.0415 ms² | 0.0309 ms² | 0.0369 ms² | 2711.7891 ms² | 2780.8555 ms² | 4663.9951 ms² | 2997.1689 ms² |
