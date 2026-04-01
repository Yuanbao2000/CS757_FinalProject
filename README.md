# CS757 Final Project
This project studies latency, fairness, and throughput tradeoffs in non-preemptive shared GPU scheduling.

## External Code

We use the LSIM framework provided by course staff: https://github.com/Yi-Huaaa/LSIM (branch: ECE757)

This framework is used as a GPU execution backend. Our work focuses on scheduling policies and performance analysis.

## Our Work

- Implement scheduling policies (FIFO, priority-based, dependency-aware)

- Add metrics (latency, throughput, fairness)

- Run experiments and analyze tradeoffs


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


