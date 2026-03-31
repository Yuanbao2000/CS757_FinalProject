## Prerequisites
- CUDA 12.x (`/usr/local/cuda`)
- GCC 13 (`/usr/bin/g++`)
- CMake 3.16+ and Ninja: `sudo apt install cmake ninja-build`

## Build & Run
```bash
make brun       # build and run
make rebuild    # clean and build
make clean      # remove build artifacts
```


### Result

```bash
ubuntu@persistent-einstein:~/andy/CS757_FinalProject/gpu_scheduler$ make brun
cmake --build cmake-build-debug --parallel 28
[3/3] Linking CXX executable gpu_scheduler
./cmake-build-debug/gpu_scheduler

---- Turnaround Validation ------------------------------------------------------------
ID   wait + exec       = turnaround     | computed        | diff     | pass?
------------------------------------------------------------------------------
0    0.000 + 9.743 = 9.743        | 9.743           | 0.0000   | PASSED
1    9.743 + 1.324 = 11.067       | 11.067          | 0.0000   | PASSED
2    11.067 + 0.280 = 11.347       | 11.347          | 0.0000   | PASSED
3    6.347 + 1.117 = 7.464        | 7.464           | 0.0000   | PASSED
4    7.464 + 0.099 = 7.563        | 7.563           | 0.0000   | PASSED
5    7.563 + 0.094 = 7.658        | 7.658           | 0.0000   | PASSED
6    2.658 + 0.333 = 2.990        | 2.990           | 0.0000   | PASSED
7    2.990 + 0.138 = 3.129        | 3.129           | 0.0000   | PASSED
8    3.129 + 0.426 = 3.555        | 3.555           | 0.0000   | PASSED

Result: ALL PASSED

=== FIFO Metrics ===
  Avg wait:           5.662 ms
  Avg exec:           1.506 ms
  Avg turnaround:     7.169 ms  (should = wait + exec)
  Makespan:          13.555 ms
  Throughput:        663.98 tasks/s
  GPU utilization:    100.0%
  Jain's fairness:   0.9948  (1.0 = perfectly fair)
  Turnaround check: PASSED

---- Turnaround Validation ------------------------------------------------------------
ID   wait + exec       = turnaround     | computed        | diff     | pass?
------------------------------------------------------------------------------
0    5.555 + 2.717 = 8.272        | 8.272           | 0.0000   | PASSED
1    8.272 + 1.295 = 9.567        | 9.567           | 0.0000   | PASSED
2    5.291 + 0.264 = 5.555        | 5.555           | 0.0000   | PASSED
3    0.000 + 0.104 = 0.104        | 0.104           | 0.0000   | PASSED
4    0.198 + 0.093 = 0.291        | 0.291           | 0.0000   | PASSED
5    0.104 + 0.093 = 0.198        | 0.198           | 0.0000   | PASSED
6    0.000 + 0.355 = 0.355        | 0.355           | 0.0000   | PASSED
7    0.355 + 0.139 = 0.495        | 0.495           | 0.0000   | PASSED
8    0.495 + 0.413 = 0.907        | 0.907           | 0.0000   | PASSED

Result: ALL PASSED

=== Priority Metrics ===
  Avg wait:           2.252 ms
  Avg exec:           0.608 ms
  Avg turnaround:     2.860 ms  (should = wait + exec)
  Makespan:          10.907 ms
  Throughput:        825.14 tasks/s
  GPU utilization:     50.2%
  Jain's fairness:   0.9278  (1.0 = perfectly fair)
  Turnaround check: PASSED

---- Turnaround Validation ------------------------------------------------------------
ID   wait + exec       = turnaround     | computed        | diff     | pass?
------------------------------------------------------------------------------
0    10.458 + 1.598 = 12.056       | 12.056          | 0.0000   | PASSED
1    12.056 + 1.297 = 13.354       | 13.354          | 0.0000   | PASSED
2    13.354 + 0.271 = 13.625       | 13.625          | 0.0000   | PASSED
3    8.625 + 1.071 = 9.696        | 9.696           | 0.0000   | PASSED
4    9.696 + 0.106 = 9.803        | 9.803           | 0.0000   | PASSED
5    9.803 + 0.103 = 9.906        | 9.906           | 0.0000   | PASSED
6    0.000 + 0.319 = 0.319        | 0.319           | 0.0000   | PASSED
7    0.319 + 0.138 = 0.458        | 0.458           | 0.0000   | PASSED
8    4.906 + 0.127 = 5.033        | 5.033           | 0.0000   | PASSED

Result: ALL PASSED

=== DependencyAware Metrics ===
  Avg wait:           7.691 ms
  Avg exec:           0.559 ms
  Avg turnaround:     8.250 ms  (should = wait + exec)
  Makespan:          15.033 ms
  Throughput:        598.69 tasks/s
  GPU utilization:     33.5%
  Jain's fairness:   0.9981  (1.0 = perfectly fair)
  Turnaround check: PASSED
```


