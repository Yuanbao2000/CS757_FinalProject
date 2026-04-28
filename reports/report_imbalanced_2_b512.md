# GPU Scheduler Group Report
Group: imbalanced_2 | batch_size=512 | runs=10 (averaged)

Generated: 20260428_041636

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 | 0.0000 | 0.0122 | 0.0122 | 0.2138 | 3688732.7500 | 100.0000 | 0.9821 | 1.0000x | 1.0000x | 1.8377x |
| fanin_priority (blocking batch) | 0.0000 | 0.0000 | 0.0098 | 0.0098 | 0.1861 | 4027682.7500 | 100.0000 | 0.9816 | 1.0000x | 1.0000x | 1.8377x |
| DependencyAware (blocking batch) | 0.0000 | 0.0000 | 0.0095 | 0.0095 | 0.1785 | 4117375.2500 | 100.0000 | 0.9804 | 1.0000x | 1.0000x | 1.8377x |
| SJF (blocking batch) | 0.0000 | 0.0000 | 0.0109 | 0.0109 | 0.2236 | 3765028.0000 | 100.0000 | 0.9813 | 1.0000x | 1.0000x | 1.8377x |
| FIFO (single-gate non-blocking) | 0.9502 | 5.8100 | 0.0042 | 0.9543 | 34.1318 | 21479.0918 | 97.0665 | 0.9971 | 268.9680x | 2678.3997x | 484.5001x |
| fanin_priority (single-gate non-blocking) | 1.0157 | 6.1729 | 0.0039 | 1.0196 | 34.8725 | 21035.0566 | 97.0438 | 0.9974 | 290.4341x | 2105.5203x | 561.4586x |
| DependencyAware (single-gate non-blocking) | 1.5760 | 6.0407 | 0.0027 | 1.5788 | 39.3253 | 18688.7207 | 97.0071 | 0.9979 | 614.0162x | 2706.3118x | 1063.4075x |
| SJF (single-gate non-blocking) | 0.9248 | 5.8490 | 0.0039 | 0.9287 | 34.6486 | 21161.0000 | 97.0605 | 0.9970 | 250.0200x | 2511.8027x | 458.7940x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0122 ± 0.0047 | 0.0122 ± 0.0047 | 0.2138 ± 0.0762 | 3688732.7500 ± 745588.6250 | 100.0000 ± 0.0000 | 0.9821 ± 0.0110 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.8377x ± 0.0000 |
| fanin_priority (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0098 ± 0.0018 | 0.0098 ± 0.0018 | 0.1861 ± 0.0320 | 4027682.7500 ± 524835.6250 | 100.0000 ± 0.0000 | 0.9816 ± 0.0043 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.8377x ± 0.0000 |
| DependencyAware (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0095 ± 0.0003 | 0.0095 ± 0.0003 | 0.1785 ± 0.0091 | 4117375.2500 ± 204525.0000 | 100.0000 ± 0.0000 | 0.9804 ± 0.0031 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.8377x ± 0.0000 |
| SJF (blocking batch) | 0.0000 ± 0.0000 | 0.0000 ± 0.0000 | 0.0109 ± 0.0040 | 0.0109 ± 0.0040 | 0.2236 ± 0.1069 | 3765028.0000 ± 1031943.0000 | 100.0000 ± 0.0000 | 0.9813 ± 0.0050 | 1.0000x ± 0.0000 | 1.0000x ± 0.0000 | 1.8377x ± 0.0000 |
| FIFO (single-gate non-blocking) | 0.9502 ± 0.0208 | 5.8100 ± 0.1162 | 0.0042 ± 0.0001 | 0.9543 ± 0.0208 | 34.1318 ± 0.4359 | 21479.0918 ± 273.1260 | 97.0665 ± 0.0517 | 0.9971 ± 0.0001 | 268.9680x ± 10.2490 | 2678.3997x ± 137.6321 | 484.5001x ± 18.8020 |
| fanin_priority (single-gate non-blocking) | 1.0157 ± 0.0223 | 6.1729 ± 0.0971 | 0.0039 ± 0.0001 | 1.0196 ± 0.0223 | 34.8725 ± 0.9799 | 21035.0566 ± 557.1035 | 97.0438 ± 0.0634 | 0.9974 ± 0.0002 | 290.4341x ± 17.1627 | 2105.5203x ± 181.7403 | 561.4586x ± 34.2480 |
| DependencyAware (single-gate non-blocking) | 1.5760 ± 0.1218 | 6.0407 ± 0.6364 | 0.0027 ± 0.0003 | 1.5788 ± 0.1221 | 39.3253 ± 2.1392 | 18688.7207 ± 907.9054 | 97.0071 ± 0.0821 | 0.9979 ± 0.0002 | 614.0162x ± 31.6432 | 2706.3118x ± 342.8087 | 1063.4075x ± 51.2907 |
| SJF (single-gate non-blocking) | 0.9248 ± 0.0255 | 5.8490 ± 0.1828 | 0.0039 ± 0.0001 | 0.9287 ± 0.0255 | 34.6486 ± 0.5774 | 21161.0000 ± 344.8890 | 97.0605 ± 0.0738 | 0.9970 ± 0.0002 | 250.0200x ± 14.2423 | 2511.8027x ± 272.6683 | 458.7940x ± 29.8817 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 443.9115x | 220.5517x | 585.0298x | 205.6363x |
| wl 1 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 311.6719x | 296.8243x | 688.6285x | 280.8529x |
| wl 2 | 1.0000x | 1.0000x | 1.0000x | 1.0000x | 133.4687x | 325.5416x | 570.2119x | 250.6014x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0047 ms² | 0.0035 ms² | 0.0029 ms² | 0.0064 ms² | 128.6398 ms² | 107.6443 ms² | 139.4967 ms² | 112.6185 ms² |
| wl 1 | 0.0037 ms² | 0.0025 ms² | 0.0020 ms² | 0.0047 ms² | 94.7629 ms² | 96.4120 ms² | 116.8800 ms² | 89.9672 ms² |
| wl 2 | 0.0033 ms² | 0.0024 ms² | 0.0019 ms² | 0.0043 ms² | 73.4673 ms² | 93.4989 ms² | 101.5269 ms² | 90.9364 ms² |
