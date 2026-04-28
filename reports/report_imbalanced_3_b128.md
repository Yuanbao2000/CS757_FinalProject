# GPU Scheduler Group Report
Group: imbalanced_3 | batch_size=128 | runs=10 (averaged)

Generated: 20260428_041453

## Summary

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0025 | 0.0257 | 0.0160 | 0.0185 | 0.3838 | 4355702.0000 | 100.0000 | 0.9839 | 1.1290x | 2.4857x | 2.1712x |
| fanin_priority (blocking batch) | 0.0028 | 0.0567 | 0.0153 | 0.0180 | 0.3986 | 4334694.0000 | 100.0000 | 0.9814 | 1.1579x | 4.1919x | 2.1606x |
| DependencyAware (blocking batch) | 0.0043 | 0.0389 | 0.0154 | 0.0197 | 0.3809 | 4397620.0000 | 100.0000 | 0.9786 | 1.2358x | 3.2397x | 2.3558x |
| SJF (blocking batch) | 0.0026 | 0.0530 | 0.0163 | 0.0189 | 0.3994 | 4403087.0000 | 100.0000 | 0.9878 | 1.1538x | 4.2567x | 2.2705x |
| FIFO (single-gate non-blocking) | 5.8224 | 23.1240 | 0.0040 | 5.8264 | 164.7209 | 9891.7969 | 98.1137 | 0.9988 | 1618.9836x | 9649.7422x | 3109.7632x |
| fanin_priority (single-gate non-blocking) | 6.1654 | 40.8450 | 0.0041 | 6.1695 | 169.0365 | 9685.2246 | 98.1942 | 0.9992 | 1696.1428x | 16539.7734x | 3011.3862x |
| DependencyAware (single-gate non-blocking) | 10.2717 | 43.0699 | 0.0028 | 10.2745 | 185.8968 | 8702.2686 | 98.1042 | 0.9992 | 3978.5298x | 20136.8398x | 7298.8828x |
| SJF (single-gate non-blocking) | 5.9409 | 39.4298 | 0.0040 | 5.9449 | 159.8376 | 10123.8213 | 98.2107 | 0.9993 | 1659.2961x | 13475.6611x | 3173.2095x |
## Standard Deviation 

| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) | Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |
|---|---|---|---|---|---|---|---|---|---|---|---|
| FIFO (blocking batch) | 0.0025 ± 0.0004 | 0.0257 ± 0.0068 | 0.0160 ± 0.0029 | 0.0185 ± 0.0032 | 0.3838 ± 0.0876 | 4355702.0000 ± 759525.1250 | 100.0000 ± 0.0000 | 0.9839 ± 0.0039 | 1.1290x ± 0.0112 | 2.4857x ± 0.2358 | 2.1712x ± 0.0133 |
| fanin_priority (blocking batch) | 0.0028 ± 0.0005 | 0.0567 ± 0.0174 | 0.0153 ± 0.0030 | 0.0180 ± 0.0035 | 0.3986 ± 0.1228 | 4334694.0000 ± 1013462.5000 | 100.0000 ± 0.0000 | 0.9814 ± 0.0126 | 1.1579x ± 0.0173 | 4.1919x ± 0.6621 | 2.1606x ± 0.0200 |
| DependencyAware (blocking batch) | 0.0043 ± 0.0009 | 0.0389 ± 0.0071 | 0.0154 ± 0.0036 | 0.0197 ± 0.0044 | 0.3809 ± 0.0907 | 4397620.0000 ± 765024.5625 | 100.0000 ± 0.0000 | 0.9786 ± 0.0171 | 1.2358x ± 0.0128 | 3.2397x ± 0.2837 | 2.3558x ± 0.0225 |
| SJF (blocking batch) | 0.0026 ± 0.0004 | 0.0530 ± 0.0136 | 0.0163 ± 0.0047 | 0.0189 ± 0.0051 | 0.3994 ± 0.1423 | 4403087.0000 ± 1081215.5000 | 100.0000 ± 0.0000 | 0.9878 ± 0.0046 | 1.1538x ± 0.0123 | 4.2567x ± 0.5621 | 2.2705x ± 0.0254 |
| FIFO (single-gate non-blocking) | 5.8224 ± 0.7686 | 23.1240 ± 3.4516 | 0.0040 ± 0.0001 | 5.8264 ± 0.7687 | 164.7209 ± 20.9524 | 9891.7969 ± 1069.5720 | 98.1137 ± 0.0707 | 0.9988 ± 0.0002 | 1618.9836x ± 118.2028 | 9649.7422x ± 1444.4846 | 3109.7632x ± 225.6480 |
| fanin_priority (single-gate non-blocking) | 6.1654 ± 0.8213 | 40.8450 ± 4.7234 | 0.0041 ± 0.0003 | 6.1695 ± 0.8215 | 169.0365 ± 25.3983 | 9685.2246 ± 1191.3818 | 98.1942 ± 0.0723 | 0.9992 ± 0.0001 | 1696.1428x ± 230.8823 | 16539.7734x ± 2957.6470 | 3011.3862x ± 333.4607 |
| DependencyAware (single-gate non-blocking) | 10.2717 ± 0.8905 | 43.0699 ± 3.8355 | 0.0028 ± 0.0004 | 10.2745 ± 0.8909 | 185.8968 ± 16.4837 | 8702.2686 ± 652.3567 | 98.1042 ± 0.0319 | 0.9992 ± 0.0000 | 3978.5298x ± 236.9142 | 20136.8398x ± 694.1425 | 7298.8828x ± 425.4030 |
| SJF (single-gate non-blocking) | 5.9409 ± 0.5483 | 39.4298 ± 3.7310 | 0.0040 ± 0.0002 | 5.9449 ± 0.5484 | 159.8376 ± 14.6738 | 10123.8213 ± 762.1582 | 98.2107 ± 0.0306 | 0.9993 ± 0.0000 | 1659.2961x ± 120.7729 | 13475.6611x ± 1721.9355 | 3173.2095x ± 250.5194 |

## Per-Workload Avg Slowdown

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 1.0882x | 1.2032x | 1.0921x | 1.1153x | 1214.8655x | 1393.9890x | 2346.6028x | 1429.1335x |
| wl 1 | 1.1762x | 1.2811x | 1.4689x | 1.2638x | 1924.3867x | 2067.5593x | 5402.0205x | 1929.3203x |
| wl 2 | 1.1091x | 1.0502x | 1.1163x | 1.0867x | 1541.5344x | 1532.4788x | 3525.1726x | 1544.1604x |

## Per-Workload Completion Variance

| Workload | FIFO (blocking batch) | fanin_priority (blocking batch) | DependencyAware (blocking batch) | SJF (blocking batch) | FIFO (single-gate non-blocking) | fanin_priority (single-gate non-blocking) | DependencyAware (single-gate non-blocking) | SJF (single-gate non-blocking) |
|---|---|---|---|---|---|---|---|---|
| wl 0 | 0.0092 ms² | 0.0092 ms² | 0.0098 ms² | 0.0117 ms² | 2993.4734 ms² | 2417.7649 ms² | 3545.8274 ms² | 2462.1130 ms² |
| wl 1 | 0.0045 ms² | 0.0054 ms² | 0.0037 ms² | 0.0060 ms² | 1760.8877 ms² | 2108.4775 ms² | 2030.6986 ms² | 1797.1868 ms² |
| wl 2 | 0.0073 ms² | 0.0084 ms² | 0.0076 ms² | 0.0092 ms² | 1752.7985 ms² | 2377.2358 ms² | 2489.6519 ms² | 1904.8617 ms² |
