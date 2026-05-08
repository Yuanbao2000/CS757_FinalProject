#include "workload_generator.h"
#include <iostream>
#include <algorithm>
#include <cmath>

// Random number generator (thread-safe static)
static std::random_device rd;
static std::mt19937 gen(rd());

std::vector<std::unique_ptr<Task>> generate_inference_workload(
    int workload_id,
    int &id_offset,
    int num_requests,
    float arrival_rate_per_sec,
    int priority,
    int base_param_N) {

    std::vector<std::unique_ptr<Task>> tasks;
    tasks.reserve(num_requests);

    // Inter-arrival time follows exponential distribution (Poisson process)
    float mean_inter_arrival_ms = 1000.0f / arrival_rate_per_sec;
    std::exponential_distribution<float> inter_arrival(1.0f / mean_inter_arrival_ms);

    // Size variation: ±20% for realistic variability
    std::uniform_int_distribution<> size_variation(-base_param_N / 5, base_param_N / 5);

    float current_time = 0.0f;
    for (int i = 0; i < num_requests; i++) {
        auto t = std::make_unique<Task>();
        t->id = id_offset++;
        t->workload_id = workload_id;
        t->priority = priority;
        t->arrival_time_ms = current_time;

        // Inference is typically compute-bound (matrix ops) or memory-bound (attention)
        // Mix 70% compute, 30% memory for realism
        t->type = (i % 10 < 7) ? KernelType::COMPUTE_BOUND : KernelType::MEMORY_BOUND;
        t->param_N = std::max(512, base_param_N + size_variation(gen));
        t->param_stride = 32;

        // Independent tasks - no dependencies!
        t->dependencies.clear();
        t->dep_remaining = 0;

        // Events for timing
        t->stream = nullptr;
        cudaEventCreate(&t->start_event);
        cudaEventCreate(&t->end_event);

        tasks.push_back(std::move(t));

        // Generate next arrival time
        current_time += inter_arrival(gen);
    }

    std::cout << "[WorkloadGen] Inference: " << num_requests << " requests, "
              << "rate=" << arrival_rate_per_sec << " req/s, "
              << "priority=" << priority << ", "
              << "avg_N=" << base_param_N << "\n";

    return tasks;
}

std::vector<std::unique_ptr<Task>> generate_training_workload(
    int workload_id,
    int &id_offset,
    int batch_size,
    float arrival_time_ms,
    int priority,
    int base_param_N) {

    std::vector<std::unique_ptr<Task>> tasks;
    tasks.reserve(batch_size);

    // Size variation: ±15%
    std::uniform_int_distribution<> size_variation(-base_param_N / 7, base_param_N / 7);

    for (int i = 0; i < batch_size; i++) {
        auto t = std::make_unique<Task>();
        t->id = id_offset++;
        t->workload_id = workload_id;
        t->priority = priority;
        t->arrival_time_ms = arrival_time_ms;  // All samples arrive together

        // Training is compute-intensive (backprop, matrix multiply)
        t->type = KernelType::COMPUTE_BOUND;
        t->param_N = std::max(2048, base_param_N + size_variation(gen));
        t->param_stride = 32;

        // Independent samples in batch - no dependencies!
        t->dependencies.clear();
        t->dep_remaining = 0;

        // Events for timing
        t->stream = nullptr;
        cudaEventCreate(&t->start_event);
        cudaEventCreate(&t->end_event);

        tasks.push_back(std::move(t));
    }

    std::cout << "[WorkloadGen] Training: " << batch_size << " samples, "
              << "arrival=" << arrival_time_ms << "ms, "
              << "priority=" << priority << ", "
              << "avg_N=" << base_param_N << "\n";

    return tasks;
}

std::vector<std::unique_ptr<Task>> generate_batch_processing_workload(
    int workload_id,
    int &id_offset,
    int num_tasks,
    float arrival_start_ms,
    float arrival_window_ms,
    int priority,
    KernelType type) {

    std::vector<std::unique_ptr<Task>> tasks;
    tasks.reserve(num_tasks);

    // Tasks arrive uniformly within the window
    std::uniform_real_distribution<float> arrival_dist(0.0f, arrival_window_ms);

    // Size distribution based on type
    int base_param_N;
    switch (type) {
        case KernelType::COMPUTE_BOUND:
            base_param_N = 4096;
            break;
        case KernelType::MEMORY_BOUND:
            base_param_N = 16384;
            break;
        case KernelType::LATENCY_SENSITIVE:
            base_param_N = 8192;
            break;
    }

    std::uniform_int_distribution<> size_variation(-base_param_N / 4, base_param_N / 4);

    for (int i = 0; i < num_tasks; i++) {
        auto t = std::make_unique<Task>();
        t->id = id_offset++;
        t->workload_id = workload_id;
        t->priority = priority;
        t->arrival_time_ms = arrival_start_ms + arrival_dist(gen);
        t->type = type;
        t->param_N = std::max(512, base_param_N + size_variation(gen));

        // Memory-bound tasks use varied stride patterns
        if (type == KernelType::MEMORY_BOUND) {
            std::uniform_int_distribution<> stride_dist(32, 128);
            t->param_stride = stride_dist(gen);
        } else {
            t->param_stride = 32;
        }

        // Independent tasks - no dependencies!
        t->dependencies.clear();
        t->dep_remaining = 0;

        // Events for timing
        t->stream = nullptr;
        cudaEventCreate(&t->start_event);
        cudaEventCreate(&t->end_event);

        tasks.push_back(std::move(t));
    }

    std::cout << "[WorkloadGen] Batch: " << num_tasks << " tasks, "
              << "arrival=" << arrival_start_ms << "-" << (arrival_start_ms + arrival_window_ms) << "ms, "
              << "priority=" << priority << ", "
              << "type=" << (type == KernelType::COMPUTE_BOUND ? "compute" :
                            type == KernelType::MEMORY_BOUND ? "memory" : "latency") << "\n";

    return tasks;
}

WorkloadStats get_workload_stats(const std::vector<Task*> &tasks, const std::string &name) {
    WorkloadStats stats;
    stats.name = name;
    stats.num_tasks = static_cast<int>(tasks.size());

    if (tasks.empty()) {
        stats.avg_param_N = 0;
        stats.min_priority = 0;
        stats.max_priority = 0;
        stats.arrival_span_ms = 0;
        return stats;
    }

    float sum_param_N = 0;
    int min_prio = tasks[0]->priority;
    int max_prio = tasks[0]->priority;
    float min_arrival = tasks[0]->arrival_time_ms;
    float max_arrival = tasks[0]->arrival_time_ms;

    for (const auto* t : tasks) {
        sum_param_N += t->param_N;
        min_prio = std::min(min_prio, t->priority);
        max_prio = std::max(max_prio, t->priority);
        min_arrival = std::min(min_arrival, t->arrival_time_ms);
        max_arrival = std::max(max_arrival, t->arrival_time_ms);
    }

    stats.avg_param_N = sum_param_N / stats.num_tasks;
    stats.min_priority = min_prio;
    stats.max_priority = max_prio;
    stats.arrival_span_ms = max_arrival - min_arrival;

    return stats;
}
