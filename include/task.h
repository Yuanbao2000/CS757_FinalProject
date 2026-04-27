#pragma once
#include <vector>
#include <string>

struct Task {
    int id;
    int workload_id;
    int priority; // larger = higher priority
    int gate_type = -1;
    float arrival_time_ms;

    // synthetic work units for the unified gate-batch kernel
    int param_N = 1024;

    // DAG edges
    std::vector<int> dependencies; // task ids that must complete first
    int dep_remaining; // 0 = ready

    // result
    float wait_time_ms = 0.f;
    float exec_time_ms = 0.f;
    float finish_time_ms = 0.f;
};
