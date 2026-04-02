## Prerequisites
- CUDA 12.x (`/usr/local/cuda`)
- GCC 13 (`/usr/bin/g++`)
- CMake 3.16+ and Ninja: `sudo apt install cmake ninja-build`

## Build & Run
```bash
make
sh scripts/run_experiments.sh
```


### Result

```bash
ubuntu@persistent-einstein:~/andy/CS757_FinalProject/gpu_scheduler$ make brun
cmake --build cmake-build-debug --parallel 28
[3/3] Linking CXX executable gpu_scheduler
./cmake-build-debug/gpu_scheduler

=== FIFO Metrics ===
  Avg wait:           5.874 ms
  Avg exec:           1.530 ms
  Avg turnaround:     7.404 ms
  Makespan:          13.769 ms
  Throughput:        653.66 tasks/s
  GPU utilization:    100.0%
  Jain's fairness:   0.9951

=== Priority Metrics ===
  Avg wait:           2.255 ms
  Avg exec:           0.613 ms
  Avg turnaround:     2.868 ms
  Makespan:          10.883 ms
  Throughput:        827.00 tasks/s
  GPU utilization:     50.7%
  Jain's fairness:   0.9286

=== DependencyAware Metrics ===
  Avg wait:           7.685 ms
  Avg exec:           0.555 ms
  Avg turnaround:     8.241 ms
  Makespan:          14.999 ms
  Throughput:        600.03 tasks/s
  GPU utilization:     33.3%
  Jain's fairness:   0.9982
```


