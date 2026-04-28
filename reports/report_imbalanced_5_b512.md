# GPU Scheduler Group Report
Group: imbalanced_5 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_041733

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 | 0.0000 | 0.0222 | 0.0222 | 0.4853 | 5110326.5000 | 100.0000 | 0.9944 | 1.0000x | 1.0000x | 1.9279x |
| fanin_priority (blocking batch) | 0.0000 | 0.0000 | 0.0222 | 0.0222 | 0.4854 | 5241753.0000 | 100.0000 | 0.9946 | 1.0000x | 1.0000x | 1.9279x |
| DependencyAware (blocking batch) | 0.0000 | 0.0000 | 0.0234 | 0.0234 | 0.5272 | 4904355.5000 | 100.0000 | 0.9938 | 1.0000x | 1.0000x | 1.9279x |
| SJF (blocking batch) | 0.0000 | 0.0000 | 0.0232 | 0.0232 | 0.5097 | 4974319.0000 | 100.0000 | 0.9942 | 1.0000x | 1.0000x | 1.9279x |
| FIFO (single-gate non-blocking) | 10.8951 | 40.8669 | 0.0040 | 10.8991 | 353.0443 | 6880.9985 | 98.7339 | 0.9999 | 3087.4722x | 17546.3398x | 6149.8428x |
| fanin_priority (single-gate non-blocking) | 9.9061 | 44.2477 | 0.0041 | 9.9102 | 365.1934 | 6689.9556 | 98.7244 | 0.9999 | 2671.1191x | 17677.0977x | 5319.2539x |
| DependencyAware (single-gate non-blocking) | 16.4684 | 41.7699 | 0.0028 | 16.4712 | 385.3744 | 6271.8652 | 98.7038 | 1.0000 | 6269.6445x | 20059.8555x | 11903.2285x |
| SJF (single-gate non-blocking) | 9.8653 | 42.2593 | 0.0040 | 9.8693 | 347.2027 | 6986.4365 | 98.7373 | 0.9999 | 2758.3083x | 18868.2461x | 5226.9380x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0222 ± 0.0022 | 0.0222 ± 0.0022 | 0.4853 ± 0.0964 | 5110326.5000 ± 839701.4375 | 100.0000 ± 0.0000 | 0.9944 ± 0.0053 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.9279x ± 0.0000 |
| fanin_priority (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0222 ± 0.0057 | 0.0222 ± 0.0057 | 0.4854 ± 0.1361 | 5241753.0000 ± 1079080.3750 | 100.0000 ± 0.0000 | 0.9946 ± 0.0019 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.9279x ± 0.0000 |
| DependencyAware (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0234 ± 0.0058 | 0.0234 ± 0.0058 | 0.5272 ± 0.1694 | 4904355.5000 ± 1120335.0000 | 100.0000 ± 0.0000 | 0.9938 ± 0.0034 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.9279x ± 0.0000 |
| SJF (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0232 ± 0.0053 | 0.0232 ± 0.0053 | 0.5097 ± 0.1376 | 4974319.0000 ± 1003911.6875 | 100.0000 ± 0.0000 | 0.9942 ± 0.0034 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.9279x ± 0.0000 |
| FIFO (single-gate non-blocking) | 10.8951 ± 1.2539 | 40.8669 ± 4.3273 | 0.0040 ± 0.0002 | 10.8991 ± 1.2540 | 353.0443 ± 42.0175 | 6880.9985 ± 697.8876 | 98.7339 ± 0.0365 | 0.9999 ± 0.0000 | 3087.4722x ± 128.7105 | 17546.3398x ± 1200.0522 | 6149.8428x ± 262.5952 |
| fanin_priority (single-gate non-blocking) | 9.9061 ± 1.3914 | 44.2477 ± 5.5232 | 0.0041 ± 0.0004 | 9.9102 ± 1.3916 | 365.1934 ± 53.0957 | 6689.9556 ± 813.7426 | 98.7244 ± 0.0791 | 0.9999 ± 0.0000 | 2671.1191x ± 376.0471 | 17677.0977x ± 2540.1880 | 5319.2539x ± 639.1425 |
| DependencyAware (single-gate non-blocking) | 16.4684 ± 1.5437 | 41.7699 ± 4.0864 | 0.0028 ± 0.0005 | 16.4712 ± 1.5441 | 385.3744 ± 35.8512 | 6271.8652 ± 475.3248 | 98.7038 ± 0.0406 | 1.0000 ± 0.0000 | 6269.6445x ± 344.6677 | 20059.8555x ± 1366.4290 | 11903.2285x ± 639.4988 |
| SJF (single-gate non-blocking) | 9.8653 ± 1.1201 | 42.2593 ± 4.9881 | 0.0040 ± 0.0002 | 9.8693 ± 1.1201 | 347.2027 ± 40.7624 | 6986.4365 ± 631.5541 | 98.7373 ± 0.0291 | 0.9999 ± 0.0000 | 2758.3083x ± 277.2867 | 18868.2461x ± 1748.0067 | 5226.9380x ± 581.5706 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 4740.5215x | 2311.3425x | 5385.5811x | 1331.4084x |
| wl 1 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 4580.9580x | 2777.7336x | 6971.6240x | 2195.7791x |
| wl 2 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 2106.5696x | 2659.0171x | 6009.9663x | 3225.2739x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0194 ms² | 0.0213 ms² | 0.0237 ms² | 0.0217 ms² | 17389.5371 ms² | 15895.1797 ms² | 18792.8945 ms² | 14658.0732 ms² |
| wl 1 | 0.0126 ms² | 0.0137 ms² | 0.0158 ms² | 0.0142 ms² | 9757.8809 ms² | 9710.8867 ms² | 11073.3457 ms² | 8369.6709 ms² |
| wl 2 | 0.0106 ms² | 0.0119 ms² | 0.0131 ms² | 0.0120 ms² | 9829.3252 ms² | 11232.9482 ms² | 11653.7207 ms² | 9914.5605 ms² |
