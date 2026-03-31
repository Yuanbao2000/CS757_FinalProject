#pragma once
#include <cuda_runtime.h>
#include <vector>
#include <string>

enum class KernelType { COMPUTE_BOUND, MEMORY_BOUND, LATENCY_SENSITIVE };

struct Task {
    int id;
    int workload_id;
    int priority; // lower = higher priority
    float arrival_time_ms;
    KernelType type;

    // kernel parameters
    int param_N = 1024;
    int param_stride = 32;

    // DAG edges
    std::vector<int> dependencies; // task ids that must complete first
    int dep_remaining; // 0 = ready

    // CUDA handles (one stream per tasks)
    cudaStream_t stream;
    cudaEvent_t start_event;
    cudaEvent_t end_event;

    // result
    float wait_time_ms = 0.f;
    float exec_time_ms = 0.f;
    float finish_time_ms = 0.f;
};
