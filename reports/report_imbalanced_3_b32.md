# GPU Scheduler Group Report
Group: imbalanced_3 | batch_size=32 | runs=10 (averaged)

Generated: 20260428_041257

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0278 | 0.1010 | 0.0117 | 0.0395 | 0.6886 | 2611584.5000 | 100.0000 | 0.9928 | 3.6587x | 11.2588x | 6.7589x |
| fanin_priority (blocking batch) | 0.0289 | 0.5146 | 0.0117 | 0.0406 | 0.7227 | 2526830.2500 | 100.0000 | 0.9851 | 3.6331x | 55.8091x | 4.6837x |
| DependencyAware (blocking batch) | 0.0520 | 0.3773 | 0.0120 | 0.0640 | 0.6867 | 2634142.5000 | 100.0000 | 0.9936 | 5.6881x | 41.7823x | 10.0466x |
| SJF (blocking batch) | 0.0258 | 0.3184 | 0.0107 | 0.0366 | 0.6038 | 2807455.5000 | 100.0000 | 0.9984 | 3.5229x | 42.9875x | 7.8974x |
| FIFO (single-gate non-blocking) | 8.8269 | 23.9795 | 0.0040 | 8.8310 | 161.2190 | 10035.7969 | 96.5022 | 0.9988 | 2476.2983x | 10283.6650x | 4668.2573x |
| fanin_priority (single-gate non-blocking) | 9.1674 | 137.7375 | 0.0036 | 9.1710 | 161.0954 | 10042.7588 | 96.3939 | 0.9968 | 2487.4370x | 60874.9883x | 3035.8357x |
| DependencyAware (single-gate non-blocking) | 21.1346 | 140.3668 | 0.0029 | 21.1375 | 210.4111 | 7698.8242 | 96.5336 | 0.9994 | 8183.6733x | 62078.4258x | 14581.3486x |
| SJF (single-gate non-blocking) | 8.2981 | 97.8030 | 0.0035 | 8.3015 | 161.9803 | 10005.5801 | 96.7045 | 0.9999 | 2537.7349x | 34118.2812x | 5668.4146x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0278 ± 0.0080 | 0.1010 ± 0.0262 | 0.0117 ± 0.0043 | 0.0395 ± 0.0122 | 0.6886 ± 0.2761 | 2611584.5000 ± 711778.7500 | 100.0000 ± 0.0000 | 0.9928 ± 0.0035 | 3.6587x ± 0.1301 | 11.2588x ± 1.5007 | 6.7589x ± 0.2118 |
| fanin_priority (blocking batch) | 0.0289 ± 0.0114 | 0.5146 ± 0.2024 | 0.0117 ± 0.0048 | 0.0406 ± 0.0162 | 0.7227 ± 0.3190 | 2526830.2500 ± 700737.1250 | 100.0000 ± 0.0000 | 0.9851 ± 0.0051 | 3.6331x ± 0.2554 | 55.8091x ± 13.2008 | 4.6837x ± 0.2523 |
| DependencyAware (blocking batch) | 0.0520 ± 0.0202 | 0.3773 ± 0.1536 | 0.0120 ± 0.0048 | 0.0640 ± 0.0250 | 0.6867 ± 0.2789 | 2634142.5000 ± 742739.3125 | 100.0000 ± 0.0000 | 0.9936 ± 0.0051 | 5.6881x ± 0.3009 | 41.7823x ± 9.5329 | 10.0466x ± 0.4317 |
| SJF (blocking batch) | 0.0258 ± 0.0082 | 0.3184 ± 0.0917 | 0.0107 ± 0.0029 | 0.0366 ± 0.0110 | 0.6038 ± 0.1577 | 2807455.5000 ± 569205.2500 | 100.0000 ± 0.0000 | 0.9984 ± 0.0016 | 3.5229x ± 0.1846 | 42.9875x ± 8.2731 | 7.8974x ± 0.5309 |
| FIFO (single-gate non-blocking) | 8.8269 ± 0.8032 | 23.9795 ± 3.0591 | 0.0040 ± 0.0001 | 8.8310 ± 0.8033 | 161.2190 ± 14.5952 | 10035.7969 ± 752.6595 | 96.5022 ± 0.0667 | 0.9988 ± 0.0002 | 2476.2983x ± 100.0879 | 10283.6650x ± 794.3882 | 4668.2573x ± 210.2437 |
| fanin_priority (single-gate non-blocking) | 9.1674 ± 0.8499 | 137.7375 ± 12.2738 | 0.0036 ± 0.0003 | 9.1710 ± 0.8501 | 161.0954 ± 14.4325 | 10042.7588 ± 753.0356 | 96.3939 ± 0.0643 | 0.9968 ± 0.0007 | 2487.4370x ± 175.8916 | 60874.9883x ± 5863.5220 | 3035.8357x ± 164.2880 |
| DependencyAware (single-gate non-blocking) | 21.1346 ± 2.0123 | 140.3668 ± 13.7188 | 0.0029 ± 0.0005 | 21.1375 ± 2.0128 | 210.4111 ± 20.8253 | 7698.8242 ± 621.8176 | 96.5336 ± 0.2357 | 0.9994 ± 0.0001 | 8183.6733x ± 567.3580 | 62078.4258x ± 6104.7017 | 14581.3486x ± 1014.5577 |
| SJF (single-gate non-blocking) | 8.2981 ± 0.8510 | 97.8030 ± 10.4939 | 0.0035 ± 0.0003 | 8.3015 ± 0.8513 | 161.9803 ± 16.5292 | 10005.5801 ± 831.5356 | 96.7045 ± 0.0399 | 0.9999 ± 0.0000 | 2537.7349x ± 202.9760 | 34118.2812x ± 7460.9126 | 5668.4146x ± 557.1278 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 2.6300x | 3.5655x | 3.1376x | 2.7960x | 1720.6090x | 2197.7007x | 4036.1992x | 1962.8793x |
| wl 1 | 4.3142x | 6.6904x | 7.8748x | 4.5400x | 2848.4465x | 4781.0400x | 11440.0049x | 3324.7710x |
| wl 2 | 3.5517x | 1.3979x | 5.0076x | 3.0379x | 2478.5281x | 898.3605x | 7298.6455x | 2166.9236x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0445 ms² | 0.0337 ms² | 0.0441 ms² | 0.0237 ms² | 2852.8835 ms² | 1318.5266 ms² | 4653.7241 ms² | 2051.7344 ms² |
| wl 1 | 0.0232 ms² | 0.0210 ms² | 0.0274 ms² | 0.0313 ms² | 1694.2979 ms² | 1199.7864 ms² | 3105.9805 ms² | 2656.3640 ms² |
| wl 2 | 0.0288 ms² | 0.0187 ms² | 0.0331 ms² | 0.0221 ms² | 1653.9371 ms² | 1150.2281 ms² | 3445.8289 ms² | 1855.9490 ms² |
