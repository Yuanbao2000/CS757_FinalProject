# GPU Scheduler Group Report
Group: imbalanced_5 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_041342

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0453 | 0.1291 | 0.0113 | 0.0566 | 0.9190 | 2674764.0000 | 100.0000 | 0.9988 | 5.5443x | 16.3077x | 10.2060x |
| fanin_priority (blocking batch) | 0.0216 | 0.6650 | 0.0114 | 0.0330 | 0.9582 | 2609632.5000 | 100.0000 | 0.9975 | 3.1289x | 65.9718x | 4.1744x |
| DependencyAware (blocking batch) | 0.0967 | 0.9770 | 0.0154 | 0.1121 | 1.1962 | 2347111.2500 | 100.0000 | 0.9996 | 8.6140x | 90.3844x | 14.5523x |
| SJF (blocking batch) | 0.0392 | 0.6683 | 0.0121 | 0.0512 | 0.9704 | 2628019.7500 | 100.0000 | 1.0000 | 4.6234x | 70.7028x | 10.3939x |
| FIFO (single-gate non-blocking) | 20.9847 | 43.2544 | 0.0042 | 20.9889 | 354.8918 | 6857.3164 | 96.6741 | 0.9999 | 5665.3809x | 19858.8848x | 10584.4336x |
| fanin_priority (single-gate non-blocking) | 10.5517 | 268.0091 | 0.0037 | 10.5554 | 350.5419 | 6916.8975 | 96.4849 | 0.9998 | 2851.7573x | 102593.5469x | 3640.7883x |
| DependencyAware (single-gate non-blocking) | 44.8916 | 376.9403 | 0.0030 | 44.8947 | 455.3226 | 5305.0186 | 96.7637 | 1.0000 | 17163.7637x | 173107.7969x | 28859.9375x |
| SJF (single-gate non-blocking) | 16.0752 | 250.0854 | 0.0035 | 16.0787 | 330.9297 | 7253.2827 | 96.8137 | 1.0000 | 4728.4004x | 95021.5234x | 10685.9824x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0453 ± 0.0064 | 0.1291 ± 0.0304 | 0.0113 ± 0.0018 | 0.0566 ± 0.0077 | 0.9190 ± 0.1553 | 2674764.0000 ± 379898.7500 | 100.0000 ± 0.0000 | 0.9988 ± 0.0005 | 5.5443x ± 0.1954 | 16.3077x ± 2.4964 | 10.2060x ± 0.3939 |
| fanin_priority (blocking batch) | 0.0216 ± 0.0054 | 0.6650 ± 0.1508 | 0.0114 ± 0.0026 | 0.0330 ± 0.0079 | 0.9582 ± 0.2344 | 2609632.5000 ± 441770.9688 | 100.0000 ± 0.0000 | 0.9975 ± 0.0009 | 3.1289x ± 0.1865 | 65.9718x ± 10.2549 | 4.1744x ± 0.1831 |
| DependencyAware (blocking batch) | 0.0967 ± 0.0374 | 0.9770 ± 0.5708 | 0.0154 ± 0.0079 | 0.1121 ± 0.0450 | 1.1962 ± 0.5926 | 2347111.2500 ± 723220.5000 | 100.0000 ± 0.0000 | 0.9996 ± 0.0007 | 8.6140x ± 1.1662 | 90.3844x ± 36.2998 | 14.5523x ± 1.8477 |
| SJF (blocking batch) | 0.0392 ± 0.0105 | 0.6683 ± 0.2051 | 0.0121 ± 0.0034 | 0.0512 ± 0.0139 | 0.9704 ± 0.2733 | 2628019.7500 ± 557541.5000 | 100.0000 ± 0.0000 | 1.0000 ± 0.0000 | 4.6234x ± 0.3823 | 70.7028x ± 13.4099 | 10.3939x ± 0.8783 |
| FIFO (single-gate non-blocking) | 20.9847 ± 2.7230 | 43.2544 ± 6.7045 | 0.0042 ± 0.0002 | 20.9889 ± 2.7232 | 354.8918 ± 45.4650 | 6857.3164 ± 739.6016 | 96.6741 ± 0.1357 | 0.9999 ± 0.0000 | 5665.3809x ± 391.2340 | 19858.8848x ± 846.8837 | 10584.4336x ± 748.4401 |
| fanin_priority (single-gate non-blocking) | 10.5517 ± 1.2941 | 268.0091 ± 30.6443 | 0.0037 ± 0.0003 | 10.5554 ± 1.2944 | 350.5419 ± 38.3259 | 6916.8975 ± 644.6134 | 96.4849 ± 0.0731 | 0.9998 ± 0.0000 | 2851.7573x ± 320.6382 | 102593.5469x ± 19766.2598 | 3640.7883x ± 315.3130 |
| DependencyAware (single-gate non-blocking) | 44.8916 ± 4.6952 | 376.9403 ± 35.4378 | 0.0030 ± 0.0007 | 44.8947 ± 4.6959 | 455.3226 ± 40.2224 | 5305.0186 ± 385.7683 | 96.7637 ± 0.0539 | 1.0000 ± 0.0000 | 17163.7637x ± 628.3414 | 173107.7969x ± 12479.6465 | 28859.9375x ± 1288.7750 |
| SJF (single-gate non-blocking) | 16.0752 ± 0.2509 | 250.0854 ± 3.8848 | 0.0035 ± 0.0000 | 16.0787 ± 0.2509 | 330.9297 ± 3.8630 | 7253.2827 ± 84.5059 | 96.8137 ± 0.0198 | 1.0000 ± 0.0000 | 4728.4004x ± 164.6432 | 95021.5234x ± 15165.0479 | 10685.9824x ± 455.8986 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 3.8587x | 6.0822x | 4.6717x | 3.9874x | 4107.5806x | 6100.5127x | 8716.6504x | 4029.2336x |
| wl 1 | 5.2896x | 3.1515x | 8.3605x | 4.6793x | 5540.9189x | 2746.1558x | 17291.8848x | 4820.3398x |
| wl 2 | 5.8818x | 2.7591x | 9.2245x | 4.6713x | 5919.2808x | 2513.0867x | 18120.8848x | 4765.1143x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.1010 ms² | 0.0687 ms² | 0.2646 ms² | 0.1238 ms² | 17891.2246 ms² | 10555.6660 ms² | 27611.2441 ms² | 14765.4551 ms² |
| wl 1 | 0.0581 ms² | 0.0391 ms² | 0.1901 ms² | 0.0661 ms² | 10024.8047 ms² | 5718.3081 ms² | 18264.6758 ms² | 7911.9248 ms² |
| wl 2 | 0.0560 ms² | 0.0648 ms² | 0.1778 ms² | 0.0696 ms² | 10097.4277 ms² | 9904.8486 ms² | 16591.2441 ms² | 8622.0967 ms² |
