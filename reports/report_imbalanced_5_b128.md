# GPU Scheduler Group Report
Group: imbalanced_5 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_041537

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0094 | 0.0476 | 0.0186 | 0.0280 | 0.5366 | 4681079.5000 | 100.0000 | 0.9961 | 1.4889x | 3.9065x | 2.7831x |
| fanin_priority (blocking batch) | 0.0043 | 0.1374 | 0.0183 | 0.0227 | 0.5721 | 4423302.5000 | 100.0000 | 0.9938 | 1.2248x | 8.6840x | 2.1590x |
| DependencyAware (blocking batch) | 0.0157 | 0.1830 | 0.0183 | 0.0340 | 0.5091 | 4861912.5000 | 100.0000 | 0.9956 | 1.8134x | 12.7347x | 3.1938x |
| SJF (blocking batch) | 0.0070 | 0.1896 | 0.0173 | 0.0243 | 0.5101 | 4977147.0000 | 100.0000 | 0.9943 | 1.3967x | 12.9674x | 2.8211x |
| FIFO (single-gate non-blocking) | 14.6662 | 38.3143 | 0.0040 | 14.6702 | 335.0561 | 7174.8843 | 98.6242 | 0.9999 | 4261.5737x | 17822.5391x | 7962.6313x |
| fanin_priority (single-gate non-blocking) | 9.9274 | 127.0291 | 0.0040 | 9.9314 | 341.3427 | 7076.7812 | 98.4622 | 0.9999 | 2636.7676x | 58460.4180x | 4389.8755x |
| DependencyAware (single-gate non-blocking) | 29.4873 | 232.5554 | 0.0029 | 29.4902 | 418.6621 | 5776.4526 | 98.6174 | 1.0000 | 11288.0732x | 106932.8281x | 19305.8320x |
| SJF (single-gate non-blocking) | 13.8116 | 199.7509 | 0.0040 | 13.8156 | 357.4602 | 6808.8711 | 98.6263 | 0.9998 | 3729.8208x | 69955.2031x | 7685.4429x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0094 ± 0.0014 | 0.0476 ± 0.0061 | 0.0186 ± 0.0031 | 0.0280 ± 0.0046 | 0.5366 ± 0.1315 | 4681079.5000 ± 859477.1250 | 100.0000 ± 0.0000 | 0.9961 ± 0.0029 | 1.4889x ± 0.0184 | 3.9065x ± 0.5544 | 2.7831x ± 0.0303 |
| fanin_priority (blocking batch) | 0.0043 ± 0.0009 | 0.1374 ± 0.0265 | 0.0183 ± 0.0037 | 0.0227 ± 0.0045 | 0.5721 ± 0.1535 | 4423302.5000 ± 876426.1250 | 100.0000 ± 0.0000 | 0.9938 ± 0.0034 | 1.2248x ± 0.0280 | 8.6840x ± 2.1140 | 2.1590x ± 0.0289 |
| DependencyAware (blocking batch) | 0.0157 ± 0.0020 | 0.1830 ± 0.0279 | 0.0183 ± 0.0026 | 0.0340 ± 0.0045 | 0.5091 ± 0.1054 | 4861912.5000 ± 720631.5000 | 100.0000 ± 0.0000 | 0.9956 ± 0.0030 | 1.8134x ± 0.0571 | 12.7347x ± 2.3626 | 3.1938x ± 0.0657 |
| SJF (blocking batch) | 0.0070 ± 0.0014 | 0.1896 ± 0.0419 | 0.0173 ± 0.0038 | 0.0243 ± 0.0051 | 0.5101 ± 0.1471 | 4977147.0000 ± 968890.4375 | 100.0000 ± 0.0000 | 0.9943 ± 0.0027 | 1.3967x ± 0.0331 | 12.9674x ± 2.8594 | 2.8211x ± 0.0858 |
| FIFO (single-gate non-blocking) | 14.6662 ± 0.7898 | 38.3143 ± 3.9277 | 0.0040 ± 0.0001 | 14.6702 ± 0.7899 | 335.0561 ± 14.1301 | 7174.8843 ± 282.5163 | 98.6242 ± 0.0251 | 0.9999 ± 0.0000 | 4261.5737x ± 105.3029 | 17822.5391x ± 746.1062 | 7962.6313x ± 200.3568 |
| fanin_priority (single-gate non-blocking) | 9.9274 ± 0.7493 | 127.0291 ± 8.6983 | 0.0040 ± 0.0001 | 9.9314 ± 0.7493 | 341.3427 ± 30.3889 | 7076.7812 ± 514.0149 | 98.4622 ± 0.0159 | 0.9999 ± 0.0000 | 2636.7676x ± 173.3073 | 58460.4180x ± 6486.4692 | 4389.8755x ± 247.8469 |
| DependencyAware (single-gate non-blocking) | 29.4873 ± 2.5542 | 232.5554 ± 18.5808 | 0.0029 ± 0.0005 | 29.4902 ± 2.5546 | 418.6621 ± 40.7917 | 5776.4526 ± 451.0783 | 98.6174 ± 0.0289 | 1.0000 ± 0.0000 | 11288.0732x ± 741.3943 | 106932.8281x ± 4981.2783 | 19305.8320x ± 1243.1160 |
| SJF (single-gate non-blocking) | 13.8116 ± 1.9686 | 199.7509 ± 28.8328 | 0.0040 ± 0.0002 | 13.8156 ± 1.9688 | 357.4602 ± 46.0541 | 6808.8711 ± 737.3259 | 98.6263 ± 0.0228 | 0.9998 ± 0.0000 | 3729.8208x ± 574.9193 | 69955.2031x ± 19428.9336 | 7685.4429x ± 1183.9567 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 1.3350x | 1.7257x | 1.3115x | 1.4410x | 2873.2969x | 4942.7441x | 5949.7603x | 3406.3696x |
| wl 1 | 1.4787x | 1.2675x | 1.6060x | 1.4192x | 4149.8965x | 2586.6445x | 10260.6357x | 3762.6829x |
| wl 2 | 1.5129x | 1.1417x | 1.9827x | 1.3795x | 4488.2402x | 2383.4026x | 12472.1914x | 3751.8608x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0257 ms² | 0.0225 ms² | 0.0249 ms² | 0.0287 ms² | 15607.6689 ms² | 10886.0625 ms² | 23950.5508 ms² | 17809.3008 ms² |
| wl 1 | 0.0160 ms² | 0.0146 ms² | 0.0156 ms² | 0.0129 ms² | 8696.2656 ms² | 5930.4663 ms² | 14750.0293 ms² | 8319.5518 ms² |
| wl 2 | 0.0143 ms² | 0.0155 ms² | 0.0126 ms² | 0.0131 ms² | 8767.6230 ms² | 9300.3369 ms² | 13874.8672 ms² | 10745.5156 ms² |
