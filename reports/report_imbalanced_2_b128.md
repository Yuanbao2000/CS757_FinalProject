# GPU Scheduler Group Report
Group: imbalanced_2 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_041440

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0002 | 0.0187 | 0.0126 | 0.0128 | 0.2331 | 3520546.5000 | 100.0000 | 0.9858 | 1.0124x | 2.0072x | 1.8500x |
| fanin_priority (blocking batch) | 0.0002 | 0.0162 | 0.0126 | 0.0128 | 0.2696 | 3181398.7500 | 100.0000 | 0.9771 | 1.0130x | 2.0570x | 1.8506x |
| DependencyAware (blocking batch) | 0.0002 | 0.0190 | 0.0140 | 0.0143 | 0.2887 | 3025272.5000 | 100.0000 | 0.9751 | 1.0124x | 2.0121x | 1.8501x |
| SJF (blocking batch) | 0.0002 | 0.0147 | 0.0134 | 0.0136 | 0.2900 | 3004787.5000 | 100.0000 | 0.9759 | 1.0100x | 1.8133x | 1.8476x |
| FIFO (single-gate non-blocking) | 1.1619 | 7.1656 | 0.0042 | 1.1661 | 38.9963 | 19447.7891 | 97.3953 | 0.9974 | 314.4963x | 2891.7734x | 544.3263x |
| fanin_priority (single-gate non-blocking) | 1.1483 | 7.3054 | 0.0041 | 1.1524 | 37.9656 | 19766.5117 | 97.2486 | 0.9975 | 306.2350x | 2690.0835x | 567.2134x |
| DependencyAware (single-gate non-blocking) | 1.7036 | 9.1511 | 0.0030 | 1.7066 | 41.3104 | 18007.9980 | 97.1264 | 0.9976 | 614.6559x | 3659.5059x | 1047.2905x |
| SJF (single-gate non-blocking) | 0.9977 | 6.5267 | 0.0039 | 1.0016 | 36.4372 | 20401.9023 | 97.2536 | 0.9972 | 275.3328x | 2851.9832x | 484.4978x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0002 ± 0.0001 | 0.0187 ± 0.0045 | 0.0126 ± 0.0042 | 0.0128 ± 0.0042 | 0.2331 ± 0.0911 | 3520546.5000 ± 989977.8125 | 100.0000 ± 0.0000 | 0.9858 ± 0.0032 | 1.0124x ± 0.0022 | 2.0072x ± 0.1800 | 1.8500x ± 0.0022 |
| fanin_priority (blocking batch) | 0.0002 ± 0.0001 | 0.0162 ± 0.0086 | 0.0126 ± 0.0044 | 0.0128 ± 0.0044 | 0.2696 ± 0.1255 | 3181398.7500 ± 1050243.0000 | 100.0000 ± 0.0000 | 0.9771 ± 0.0088 | 1.0130x ± 0.0090 | 2.0570x ± 0.7335 | 1.8506x ± 0.0090 |
| DependencyAware (blocking batch) | 0.0002 ± 0.0001 | 0.0190 ± 0.0074 | 0.0140 ± 0.0059 | 0.0143 ± 0.0060 | 0.2887 ± 0.1359 | 3025272.5000 ± 1077604.2500 | 100.0000 ± 0.0000 | 0.9751 ± 0.0158 | 1.0124x ± 0.0035 | 2.0121x ± 0.2872 | 1.8501x ± 0.0035 |
| SJF (blocking batch) | 0.0002 ± 0.0000 | 0.0147 ± 0.0033 | 0.0134 ± 0.0055 | 0.0136 ± 0.0055 | 0.2900 ± 0.1340 | 3004787.5000 ± 1077686.0000 | 100.0000 ± 0.0000 | 0.9759 ± 0.0142 | 1.0100x ± 0.0022 | 1.8133x ± 0.1787 | 1.8476x ± 0.0022 |
| FIFO (single-gate non-blocking) | 1.1619 ± 0.2670 | 7.1656 ± 1.7688 | 0.0042 ± 0.0002 | 1.1661 ± 0.2672 | 38.9963 ± 7.9428 | 19447.7891 ± 3235.7791 | 97.3953 ± 0.1956 | 0.9974 ± 0.0004 | 314.4963x ± 56.3411 | 2891.7734x ± 490.2306 | 544.3263x ± 97.1003 |
| fanin_priority (single-gate non-blocking) | 1.1483 ± 0.1771 | 7.3054 ± 1.1976 | 0.0041 ± 0.0002 | 1.1524 ± 0.1773 | 37.9656 ± 6.2088 | 19766.5117 ± 2813.0605 | 97.2486 ± 0.0794 | 0.9975 ± 0.0001 | 306.2350x ± 34.9016 | 2690.0835x ± 701.4291 | 567.2134x ± 48.7928 |
| DependencyAware (single-gate non-blocking) | 1.7036 ± 0.2199 | 9.1511 ± 1.3781 | 0.0030 ± 0.0007 | 1.7066 ± 0.2206 | 41.3104 ± 5.4003 | 18007.9980 ± 2026.7178 | 97.1264 ± 0.0940 | 0.9976 ± 0.0003 | 614.6559x ± 50.1271 | 3659.5059x ± 583.6046 | 1047.2905x ± 84.8567 |
| SJF (single-gate non-blocking) | 0.9977 ± 0.1395 | 6.5267 ± 0.8178 | 0.0039 ± 0.0002 | 1.0016 ± 0.1396 | 36.4372 ± 4.6889 | 20401.9023 ± 2218.0215 | 97.2536 ± 0.0804 | 0.9972 ± 0.0005 | 275.3328x ± 29.7911 | 2851.9832x ± 223.9073 | 484.4978x ± 63.4031 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 1.0000x | 1.0537x | 1.0000x | 1.0414x | 388.4786x | 299.2459x | 557.7155x | 346.0829x |
| wl 1 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 319.6155x | 297.8995x | 662.1007x | 262.3059x |
| wl 2 | 1.0295x | 1.0000x | 1.0297x | 1.0000x | 267.6898x | 317.0251x | 609.0028x | 245.1080x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0063 ms² | 0.0083 ms² | 0.0093 ms² | 0.0100 ms² | 179.4528 ms² | 130.6910 ms² | 152.7819 ms² | 131.1808 ms² |
| wl 1 | 0.0049 ms² | 0.0055 ms² | 0.0067 ms² | 0.0066 ms² | 133.7766 ms² | 116.1232 ms² | 127.4190 ms² | 101.6780 ms² |
| wl 2 | 0.0042 ms² | 0.0051 ms² | 0.0069 ms² | 0.0063 ms² | 101.8966 ms² | 113.1746 ms² | 115.9016 ms² | 102.2649 ms² |
