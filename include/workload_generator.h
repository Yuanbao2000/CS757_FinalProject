#pragma once
#include "task.h"
#include <vector>
#include <memory>
#include <random>
#include <string>

// Generates realistic GPU workload patterns for scheduler evaluation

// Type 1: Inference Requests (latency-sensitive)
// Models: ML inference serving (GPT, BERT), real-time computer vision
// Characteristics: Small independent tasks, high arrival rate, high priority
std::vector<std::unique_ptr<Task>> generate_inference_workload(
    int workload_id,
    int &id_offset,
    int num_requests,
    float arrival_rate_per_sec,  // Requests per second (e.g., 50)
    int priority = 1,             // High priority
    int base_param_N = 2048       // Small matrices
);

// Type 2: Training Job (throughput-oriented)
// Models: ML training batches, scientific simulations
// Characteristics: Large batch of independent samples, low priority, can wait
std::vector<std::unique_ptr<Task>> generate_training_workload(
    int workload_id,
    int &id_offset,
    int batch_size,
    float arrival_time_ms,
    int priority = 3,             // Low priority
    int base_param_N = 6144       // Large matrices
);

// Type 3: Batch Processing
// Models: Video processing, data analytics, general compute
// Characteristics: Medium tasks, medium priority, arrive in waves
std::vector<std::unique_ptr<Task>> generate_batch_processing_workload(
    int workload_id,
    int &id_offset,
    int num_tasks,
    float arrival_start_ms,
    float arrival_window_ms,      // Tasks spread over this window
    int priority = 2,             // Medium priority
    KernelType type = KernelType::MEMORY_BOUND
);

// Helper: Get workload statistics for reporting
struct WorkloadStats {
    std::string name;
    int num_tasks;
    float avg_param_N;
    int min_priority;
    int max_priority;
    float arrival_span_ms;
};

WorkloadStats get_workload_stats(const std::vector<Task*> &tasks, const std::string &name);
