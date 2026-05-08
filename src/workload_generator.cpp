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
    int base_param_N,
    bool add_dependencies) {

    std::vector<std::unique_ptr<Task>> tasks;
    // Each request has 3 stages if dependencies enabled
    int total_tasks = add_dependencies ? (num_requests * 3) : num_requests;
    tasks.reserve(total_tasks);

    // Inter-arrival time follows exponential distribution (Poisson process)
    float mean_inter_arrival_ms = 1000.0f / arrival_rate_per_sec;
    std::exponential_distribution<float> inter_arrival(1.0f / mean_inter_arrival_ms);

    // Size variation: ±20% for realistic variability
    std::uniform_int_distribution<> size_variation(-base_param_N / 5, base_param_N / 5);

    float current_time = 0.0f;
    for (int i = 0; i < num_requests; i++) {
        if (add_dependencies) {
            // 3-stage pipeline: Preprocess -> Inference -> Postprocess
            int base_id = id_offset;

            // Stage 1: Preprocessing (memory-bound, small)
            auto t1 = std::make_unique<Task>();
            t1->id = id_offset++;
            t1->workload_id = workload_id;
            t1->priority = priority;
            t1->arrival_time_ms = current_time;
            t1->type = KernelType::MEMORY_BOUND;
            t1->param_N = std::max(512, base_param_N / 2 + size_variation(gen) / 2);
            t1->param_stride = 32;
            t1->dependencies.clear();
            t1->dep_remaining = 0;
            cudaEventCreate(&t1->start_event);
            cudaEventCreate(&t1->end_event);
            t1->stream = nullptr;

            // Stage 2: Inference (compute-bound, full size)
            auto t2 = std::make_unique<Task>();
            t2->id = id_offset++;
            t2->workload_id = workload_id;
            t2->priority = priority;
            t2->arrival_time_ms = current_time;
            t2->type = KernelType::COMPUTE_BOUND;
            t2->param_N = std::max(512, base_param_N + size_variation(gen));
            t2->param_stride = 32;
            t2->dependencies = {base_id};  // Depends on preprocessing
            t2->dep_remaining = 1;
            cudaEventCreate(&t2->start_event);
            cudaEventCreate(&t2->end_event);
            t2->stream = nullptr;

            // Stage 3: Postprocessing (memory-bound, small)
            auto t3 = std::make_unique<Task>();
            t3->id = id_offset++;
            t3->workload_id = workload_id;
            t3->priority = priority;
            t3->arrival_time_ms = current_time;
            t3->type = KernelType::MEMORY_BOUND;
            t3->param_N = std::max(512, base_param_N / 3 + size_variation(gen) / 2);
            t3->param_stride = 32;
            t3->dependencies = {base_id + 1};  // Depends on inference
            t3->dep_remaining = 1;
            cudaEventCreate(&t3->start_event);
            cudaEventCreate(&t3->end_event);
            t3->stream = nullptr;

            tasks.push_back(std::move(t1));
            tasks.push_back(std::move(t2));
            tasks.push_back(std::move(t3));

        } else {
            // Independent task (original behavior)
            auto t = std::make_unique<Task>();
            t->id = id_offset++;
            t->workload_id = workload_id;
            t->priority = priority;
            t->arrival_time_ms = current_time;
            t->type = (i % 10 < 7) ? KernelType::COMPUTE_BOUND : KernelType::MEMORY_BOUND;
            t->param_N = std::max(512, base_param_N + size_variation(gen));
            t->param_stride = 32;
            t->dependencies.clear();
            t->dep_remaining = 0;
            cudaEventCreate(&t->start_event);
            cudaEventCreate(&t->end_event);
            t->stream = nullptr;
            tasks.push_back(std::move(t));
        }

        // Generate next arrival time
        current_time += inter_arrival(gen);
    }

    std::cout << "[WorkloadGen] Inference: " << num_requests << " requests ("
              << total_tasks << " tasks), "
              << "rate=" << arrival_rate_per_sec << " req/s, "
              << "priority=" << priority << ", "
              << "deps=" << (add_dependencies ? "3-stage pipeline" : "independent") << "\n";

    return tasks;
}

std::vector<std::unique_ptr<Task>> generate_training_workload(
    int workload_id,
    int &id_offset,
    int batch_size,
    float arrival_time_ms,
    int priority,
    int base_param_N,
    bool add_dependencies) {

    std::vector<std::unique_ptr<Task>> tasks;
    // Each sample has 3 stages if dependencies enabled: forward->backward->optimizer
    int total_tasks = add_dependencies ? (batch_size * 3) : batch_size;
    tasks.reserve(total_tasks);

    // Size variation: ±15%
    std::uniform_int_distribution<> size_variation(-base_param_N / 7, base_param_N / 7);

    for (int i = 0; i < batch_size; i++) {
        if (add_dependencies) {
            // Training pipeline: Forward -> Backward -> Optimizer
            int base_id = id_offset;
            int param_size = std::max(2048, base_param_N + size_variation(gen));

            // Stage 1: Forward pass (compute-bound, full size)
            auto t1 = std::make_unique<Task>();
            t1->id = id_offset++;
            t1->workload_id = workload_id;
            t1->priority = priority;
            t1->arrival_time_ms = arrival_time_ms;
            t1->type = KernelType::COMPUTE_BOUND;
            t1->param_N = param_size;
            t1->param_stride = 32;
            t1->dependencies.clear();
            t1->dep_remaining = 0;
            cudaEventCreate(&t1->start_event);
            cudaEventCreate(&t1->end_event);
            t1->stream = nullptr;

            // Stage 2: Backward pass (compute-bound, full size)
            auto t2 = std::make_unique<Task>();
            t2->id = id_offset++;
            t2->workload_id = workload_id;
            t2->priority = priority;
            t2->arrival_time_ms = arrival_time_ms;
            t2->type = KernelType::COMPUTE_BOUND;
            t2->param_N = param_size;
            t2->param_stride = 32;
            t2->dependencies = {base_id};  // Depends on forward pass
            t2->dep_remaining = 1;
            cudaEventCreate(&t2->start_event);
            cudaEventCreate(&t2->end_event);
            t2->stream = nullptr;

            // Stage 3: Optimizer step (memory-bound, parameter updates)
            auto t3 = std::make_unique<Task>();
            t3->id = id_offset++;
            t3->workload_id = workload_id;
            t3->priority = priority;
            t3->arrival_time_ms = arrival_time_ms;
            t3->type = KernelType::MEMORY_BOUND;
            t3->param_N = param_size / 2;  // Smaller optimizer kernel
            t3->param_stride = 32;
            t3->dependencies = {base_id + 1};  // Depends on backward pass
            t3->dep_remaining = 1;
            cudaEventCreate(&t3->start_event);
            cudaEventCreate(&t3->end_event);
            t3->stream = nullptr;

            tasks.push_back(std::move(t1));
            tasks.push_back(std::move(t2));
            tasks.push_back(std::move(t3));

        } else {
            // Independent sample (original behavior)
            auto t = std::make_unique<Task>();
            t->id = id_offset++;
            t->workload_id = workload_id;
            t->priority = priority;
            t->arrival_time_ms = arrival_time_ms;
            t->type = KernelType::COMPUTE_BOUND;
            t->param_N = std::max(2048, base_param_N + size_variation(gen));
            t->param_stride = 32;
            t->dependencies.clear();
            t->dep_remaining = 0;
            cudaEventCreate(&t->start_event);
            cudaEventCreate(&t->end_event);
            t->stream = nullptr;
            tasks.push_back(std::move(t));
        }
    }

    std::cout << "[WorkloadGen] Training: " << batch_size << " samples ("
              << total_tasks << " tasks), "
              << "arrival=" << arrival_time_ms << "ms, "
              << "priority=" << priority << ", "
              << "deps=" << (add_dependencies ? "forward->backward->optimizer" : "independent") << "\n";

    return tasks;
}

std::vector<std::unique_ptr<Task>> generate_batch_processing_workload(
    int workload_id,
    int &id_offset,
    int num_tasks,
    float arrival_start_ms,
    float arrival_window_ms,
    int priority,
    KernelType type,
    bool add_dependencies,
    float dependency_prob) {

    std::vector<std::unique_ptr<Task>> tasks;

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
    std::uniform_real_distribution<float> dep_prob_dist(0.0f, 1.0f);

    if (add_dependencies) {
        // Map-reduce pattern: 70% map tasks, 30% reduce tasks
        int num_map = static_cast<int>(num_tasks * 0.7);
        int num_reduce = num_tasks - num_map;
        tasks.reserve(num_tasks);

        std::vector<int> map_task_ids;
        std::uniform_real_distribution<float> arrival_dist(0.0f, arrival_window_ms * 0.6);

        // Create map tasks (parallel, early arrivals)
        for (int i = 0; i < num_map; i++) {
            auto t = std::make_unique<Task>();
            t->id = id_offset++;
            t->workload_id = workload_id;
            t->priority = priority;
            t->arrival_time_ms = arrival_start_ms + arrival_dist(gen);
            t->type = type;
            t->param_N = std::max(512, base_param_N + size_variation(gen));

            if (type == KernelType::MEMORY_BOUND) {
                std::uniform_int_distribution<> stride_dist(32, 128);
                t->param_stride = stride_dist(gen);
            } else {
                t->param_stride = 32;
            }

            // Map tasks may have dependencies on each other with probability dependency_prob
            if (i > 0 && dep_prob_dist(gen) < dependency_prob) {
                std::uniform_int_distribution<> dep_idx_dist(0, static_cast<int>(map_task_ids.size()) - 1);
                int dep_task = map_task_ids[dep_idx_dist(gen)];
                t->dependencies = {dep_task};
                t->dep_remaining = 1;
            } else {
                t->dependencies.clear();
                t->dep_remaining = 0;
            }

            cudaEventCreate(&t->start_event);
            cudaEventCreate(&t->end_event);
            t->stream = nullptr;

            map_task_ids.push_back(t->id);
            tasks.push_back(std::move(t));
        }

        // Create reduce tasks (depend on multiple map tasks, later arrivals)
        std::uniform_real_distribution<float> reduce_arrival_dist(arrival_window_ms * 0.6, arrival_window_ms);
        std::uniform_int_distribution<> num_deps_dist(2, std::min(5, num_map));

        for (int i = 0; i < num_reduce; i++) {
            auto t = std::make_unique<Task>();
            t->id = id_offset++;
            t->workload_id = workload_id;
            t->priority = priority;
            t->arrival_time_ms = arrival_start_ms + reduce_arrival_dist(gen);
            t->type = type;
            t->param_N = std::max(512, base_param_N / 2 + size_variation(gen) / 2);  // Reduce tasks smaller
            t->param_stride = 32;

            // Reduce tasks depend on 2-5 random map tasks
            int num_deps = num_deps_dist(gen);
            std::vector<int> selected_deps;
            std::uniform_int_distribution<> map_idx_dist(0, num_map - 1);

            for (int j = 0; j < num_deps; j++) {
                int dep_idx = map_idx_dist(gen);
                int dep_id = map_task_ids[dep_idx];
                // Avoid duplicate dependencies
                if (std::find(selected_deps.begin(), selected_deps.end(), dep_id) == selected_deps.end()) {
                    selected_deps.push_back(dep_id);
                }
            }

            t->dependencies = selected_deps;
            t->dep_remaining = static_cast<int>(selected_deps.size());

            cudaEventCreate(&t->start_event);
            cudaEventCreate(&t->end_event);
            t->stream = nullptr;

            tasks.push_back(std::move(t));
        }

        std::cout << "[WorkloadGen] Batch: " << num_tasks << " tasks ("
                  << num_map << " map, " << num_reduce << " reduce), "
                  << "arrival=" << arrival_start_ms << "-" << (arrival_start_ms + arrival_window_ms) << "ms, "
                  << "priority=" << priority << ", "
                  << "type=" << (type == KernelType::COMPUTE_BOUND ? "compute" :
                                type == KernelType::MEMORY_BOUND ? "memory" : "latency") << ", "
                  << "deps=map-reduce\n";

    } else {
        // Independent tasks (original behavior)
        tasks.reserve(num_tasks);
        std::uniform_real_distribution<float> arrival_dist(0.0f, arrival_window_ms);

        for (int i = 0; i < num_tasks; i++) {
            auto t = std::make_unique<Task>();
            t->id = id_offset++;
            t->workload_id = workload_id;
            t->priority = priority;
            t->arrival_time_ms = arrival_start_ms + arrival_dist(gen);
            t->type = type;
            t->param_N = std::max(512, base_param_N + size_variation(gen));

            if (type == KernelType::MEMORY_BOUND) {
                std::uniform_int_distribution<> stride_dist(32, 128);
                t->param_stride = stride_dist(gen);
            } else {
                t->param_stride = 32;
            }

            t->dependencies.clear();
            t->dep_remaining = 0;
            cudaEventCreate(&t->start_event);
            cudaEventCreate(&t->end_event);
            t->stream = nullptr;

            tasks.push_back(std::move(t));
        }

        std::cout << "[WorkloadGen] Batch: " << num_tasks << " tasks, "
                  << "arrival=" << arrival_start_ms << "-" << (arrival_start_ms + arrival_window_ms) << "ms, "
                  << "priority=" << priority << ", "
                  << "type=" << (type == KernelType::COMPUTE_BOUND ? "compute" :
                                type == KernelType::MEMORY_BOUND ? "memory" : "latency") << ", "
                  << "deps=independent\n";
    }

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
