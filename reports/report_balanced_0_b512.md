# GPU Scheduler Group Report
Group: balanced_0 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_041625

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 | 0.0000 | 0.0144 | 0.0144 | 0.2309 | 5017998.5000 | 100.0000 | 0.9930 | 1.0000x | 1.0000x | 1.8471x |
| fanin_priority (blocking batch) | 0.0000 | 0.0000 | 0.0128 | 0.0128 | 0.2251 | 5171431.0000 | 100.0000 | 0.9903 | 1.0000x | 1.0000x | 1.8471x |
| DependencyAware (blocking batch) | 0.0000 | 0.0000 | 0.0150 | 0.0150 | 0.2617 | 4550986.5000 | 100.0000 | 0.9921 | 1.0000x | 1.0000x | 1.8471x |
| SJF (blocking batch) | 0.0000 | 0.0000 | 0.0130 | 0.0130 | 0.2433 | 4975445.0000 | 100.0000 | 0.9895 | 1.0000x | 1.0000x | 1.8471x |
| FIFO (single-gate non-blocking) | 2.4109 | 15.6761 | 0.0040 | 2.4150 | 79.3975 | 14518.8770 | 98.0883 | 0.9993 | 682.5120x | 7412.0391x | 1309.8534x |
| fanin_priority (single-gate non-blocking) | 2.3006 | 16.2259 | 0.0040 | 2.3047 | 80.1364 | 14371.0723 | 98.0909 | 0.9992 | 628.0438x | 5851.1152x | 1285.3755x |
| DependencyAware (single-gate non-blocking) | 4.3744 | 16.6551 | 0.0027 | 4.3771 | 93.6883 | 12311.6807 | 98.0291 | 0.9994 | 1756.7576x | 7970.3389x | 3071.1177x |
| SJF (single-gate non-blocking) | 2.1769 | 16.6300 | 0.0041 | 2.1810 | 80.0523 | 14382.5684 | 98.0894 | 0.9990 | 620.8875x | 7233.4932x | 1125.9131x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0144 ± 0.0012 | 0.0144 ± 0.0012 | 0.2309 ± 0.0205 | 5017998.5000 ± 375857.6562 | 100.0000 ± 0.0000 | 0.9930 ± 0.0017 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.8471x ± 0.0000 |
| fanin_priority (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0128 ± 0.0023 | 0.0128 ± 0.0023 | 0.2251 ± 0.0254 | 5171431.0000 ± 519943.7500 | 100.0000 ± 0.0000 | 0.9903 ± 0.0043 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.8471x ± 0.0000 |
| DependencyAware (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0150 ± 0.0026 | 0.0150 ± 0.0026 | 0.2617 ± 0.0508 | 4550986.5000 ± 797086.7500 | 100.0000 ± 0.0000 | 0.9921 ± 0.0051 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.8471x ± 0.0000 |
| SJF (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0130 ± 0.0019 | 0.0130 ± 0.0019 | 0.2433 ± 0.0702 | 4975445.0000 ± 861422.3125 | 100.0000 ± 0.0000 | 0.9895 ± 0.0047 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.8471x ± 0.0000 |
| FIFO (single-gate non-blocking) | 2.4109 ± 0.0720 | 15.6761 ± 0.2522 | 0.0040 ± 0.0001 | 2.4150 ± 0.0720 | 79.3975 ± 3.2518 | 14518.8770 ± 542.0975 | 98.0883 ± 0.0531 | 0.9993 ± 0.0001 | 682.5120x ± 37.4088 | 7412.0391x ± 267.0402 | 1309.8534x ± 69.3100 |
| fanin_priority (single-gate non-blocking) | 2.3006 ± 0.0368 | 16.2259 ± 0.2463 | 0.0040 ± 0.0002 | 2.3047 ± 0.0366 | 80.1364 ± 1.9337 | 14371.0723 ± 334.3279 | 98.0909 ± 0.0490 | 0.9992 ± 0.0002 | 628.0438x ± 33.0871 | 5851.1152x ± 353.8743 | 1285.3755x ± 62.3419 |
| DependencyAware (single-gate non-blocking) | 4.3744 ± 0.2163 | 16.6551 ± 1.0775 | 0.0027 ± 0.0001 | 4.3771 ± 0.2164 | 93.6883 ± 4.5033 | 12311.6807 ± 547.0906 | 98.0291 ± 0.0720 | 0.9994 ± 0.0001 | 1756.7576x ± 46.5652 | 7970.3389x ± 384.7442 | 3071.1177x ± 77.7584 |
| SJF (single-gate non-blocking) | 2.1769 ± 0.0711 | 16.6300 ± 0.7412 | 0.0041 ± 0.0005 | 2.1810 ± 0.0711 | 80.0523 ± 1.4174 | 14382.5684 ± 252.0107 | 98.0894 ± 0.0501 | 0.9990 ± 0.0004 | 620.8875x ± 43.5591 | 7233.4932x ± 287.0316 | 1125.9131x ± 96.5934 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 1244.1940x | 500.1541x | 1652.5613x | 467.8366x |
| wl 1 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 565.8318x | 471.7043x | 1360.1008x | 495.6326x |
| wl 2 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 434.6998x | 775.2728x | 2010.3969x | 766.3801x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0036 ms² | 0.0035 ms² | 0.0054 ms² | 0.0041 ms² | 627.7676 ms² | 490.0457 ms² | 735.7781 ms² | 488.9703 ms² |
| wl 1 | 0.0038 ms² | 0.0037 ms² | 0.0059 ms² | 0.0046 ms² | 581.3459 ms² | 515.9395 ms² | 717.0508 ms² | 507.1537 ms² |
| wl 2 | 0.0018 ms² | 0.0017 ms² | 0.0027 ms² | 0.0018 ms² | 330.2450 ms² | 400.3553 ms² | 436.2354 ms² | 406.8525 ms² |
