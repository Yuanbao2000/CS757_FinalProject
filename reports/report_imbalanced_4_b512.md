# GPU Scheduler Group Report
Group: imbalanced_4 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_041704

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 | 0.0000 | 0.0186 | 0.0186 | 0.3310 | 5529371.5000 | 100.0000 | 0.8612 | 1.0000x | 1.0000x | 1.8306x |
| fanin_priority (blocking batch) | 0.0000 | 0.0000 | 0.0165 | 0.0165 | 0.3087 | 5897716.0000 | 100.0000 | 0.8534 | 1.0000x | 1.0000x | 1.8306x |
| DependencyAware (blocking batch) | 0.0000 | 0.0000 | 0.0181 | 0.0181 | 0.3230 | 5730106.5000 | 100.0000 | 0.8630 | 1.0000x | 1.0000x | 1.8306x |
| SJF (blocking batch) | 0.0000 | 0.0000 | 0.0185 | 0.0185 | 0.3503 | 5515458.0000 | 100.0000 | 0.8561 | 1.0000x | 1.0000x | 1.8306x |
| FIFO (single-gate non-blocking) | 5.7654 | 25.4935 | 0.0041 | 5.7695 | 193.1853 | 9199.7480 | 98.8434 | 0.8920 | 1613.6355x | 10282.9902x | 3043.9163x |
| fanin_priority (single-gate non-blocking) | 5.4393 | 25.7192 | 0.0039 | 5.4432 | 191.5156 | 9250.2051 | 98.8481 | 0.9250 | 1539.8866x | 10763.3809x | 2854.3413x |
| DependencyAware (single-gate non-blocking) | 8.7197 | 25.2499 | 0.0031 | 8.7228 | 211.3469 | 8403.9238 | 98.7061 | 0.9351 | 3163.2957x | 11876.9346x | 5613.3545x |
| SJF (single-gate non-blocking) | 5.3324 | 24.0914 | 0.0041 | 5.3365 | 189.4865 | 9353.3516 | 98.7464 | 0.8958 | 1438.9739x | 10232.2881x | 2622.3325x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0186 ± 0.0032 | 0.0186 ± 0.0032 | 0.3310 ± 0.0755 | 5529371.5000 ± 1042910.1875 | 100.0000 ± 0.0000 | 0.8612 ± 0.0166 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.8306x ± 0.0000 |
| fanin_priority (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0165 ± 0.0029 | 0.0165 ± 0.0029 | 0.3087 ± 0.0673 | 5897716.0000 ± 1026925.7500 | 100.0000 ± 0.0000 | 0.8534 ± 0.0223 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.8306x ± 0.0000 |
| DependencyAware (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0181 ± 0.0039 | 0.0181 ± 0.0039 | 0.3230 ± 0.0940 | 5730106.5000 ± 1068996.2500 | 100.0000 ± 0.0000 | 0.8630 ± 0.0181 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.8306x ± 0.0000 |
| SJF (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0185 ± 0.0057 | 0.0185 ± 0.0057 | 0.3503 ± 0.1302 | 5515458.0000 ± 1397890.3750 | 100.0000 ± 0.0000 | 0.8561 ± 0.0208 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.8306x ± 0.0000 |
| FIFO (single-gate non-blocking) | 5.7654 ± 0.7160 | 25.4935 ± 4.1669 | 0.0041 ± 0.0002 | 5.7695 ± 0.7162 | 193.1853 ± 23.8274 | 9199.7480 ± 1019.6112 | 98.8434 ± 0.0466 | 0.8920 ± 0.0118 | 1613.6355x ± 82.5025 | 10282.9902x ± 1522.9105 | 3043.9163x ± 145.0256 |
| fanin_priority (single-gate non-blocking) | 5.4393 ± 0.5993 | 25.7192 ± 3.0421 | 0.0039 ± 0.0002 | 5.4432 ± 0.5994 | 191.5156 ± 20.9022 | 9250.2051 ± 889.3354 | 98.8481 ± 0.0307 | 0.9250 ± 0.0041 | 1539.8866x ± 204.1517 | 10763.3809x ± 1356.4535 | 2854.3413x ± 330.5067 |
| DependencyAware (single-gate non-blocking) | 8.7197 ± 1.1195 | 25.2499 ± 2.9596 | 0.0031 ± 0.0009 | 8.7228 ± 1.1204 | 211.3469 ± 26.2526 | 8403.9238 ± 882.0674 | 98.7061 ± 0.1439 | 0.9351 ± 0.0025 | 3163.2957x ± 246.7239 | 11876.9346x ± 978.5597 | 5613.3545x ± 437.3058 |
| SJF (single-gate non-blocking) | 5.3324 ± 0.6219 | 24.0914 ± 2.7414 | 0.0041 ± 0.0001 | 5.3365 ± 0.6220 | 189.4865 ± 21.2868 | 9353.3516 ± 909.0991 | 98.7464 ± 0.2239 | 0.8958 ± 0.0033 | 1438.9739x ± 125.1669 | 10232.2881x ± 933.8123 | 2622.3325x ± 270.0128 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 2446.4097x | 1521.2317x | 3409.7495x | 816.2935x |
| wl 1 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 2576.5759x | 1186.9865x | 2534.5684x | 876.0432x |
| wl 2 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 1421.5461x | 1607.7318x | 3281.6797x | 1552.4773x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0010 ms² | 0.0009 ms² | 0.0010 ms² | 0.0012 ms² | 904.2136 ms² | 898.2621 ms² | 1332.0377 ms² | 693.8531 ms² |
| wl 1 | 0.0102 ms² | 0.0090 ms² | 0.0099 ms² | 0.0125 ms² | 4108.6104 ms² | 3465.5383 ms² | 4458.5156 ms² | 3332.5281 ms² |
| wl 2 | 0.0072 ms² | 0.0063 ms² | 0.0070 ms² | 0.0088 ms² | 2891.6011 ms² | 2918.0984 ms² | 3411.9211 ms² | 2853.4341 ms² |
