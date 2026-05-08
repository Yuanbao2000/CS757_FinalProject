#pragma once
#include "task.h"
#include <vector>
#include <memory>
#include <random>
#include <string>

// Generates realistic GPU workload patterns for scheduler evaluation

// Type 1: Inference Requests (latency-sensitive)
// Models: ML inference serving (GPT, BERT), real-time computer vision
// Characteristics: Small tasks with pipeline dependencies (preprocess->infer->postprocess)
std::vector<std::unique_ptr<Task>> generate_inference_workload(
    int workload_id,
    int &id_offset,
    int num_requests,
    float arrival_rate_per_sec,  // Requests per second (e.g., 50)
    int priority = 1,             // High priority
    int base_param_N = 2048,      // Small matrices
    bool add_dependencies = true  // Create 3-stage pipeline per request
);

// Type 2: Training Job (throughput-oriented)
// Models: ML training batches, scientific simulations
// Characteristics: Large batch with forward->backward->update dependencies
std::vector<std::unique_ptr<Task>> generate_training_workload(
    int workload_id,
    int &id_offset,
    int batch_size,
    float arrival_time_ms,
    int priority = 3,             // Low priority
    int base_param_N = 6144,      // Large matrices
    bool add_dependencies = true  // Create forward->backward->optimizer chain
);

// Type 3: Batch Processing
// Models: Video processing, data analytics, general compute
// Characteristics: Medium tasks with map-reduce or pipeline dependencies
std::vector<std::unique_ptr<Task>> generate_batch_processing_workload(
    int workload_id,
    int &id_offset,
    int num_tasks,
    float arrival_start_ms,
    float arrival_window_ms,      // Tasks spread over this window
    int priority = 2,             // Medium priority
    KernelType type = KernelType::MEMORY_BOUND,
    bool add_dependencies = true, // Create map-reduce pattern
    float dependency_prob = 0.3   // Probability of cross-task dependencies
);

// Type 4: Critical Path Heavy (favors CriticalPathScheduler)
// Models: Long sequential pipelines with competing independent tasks
// Characteristics: Deep dependency chains (10-15 stages), mixed task sizes
std::vector<std::unique_ptr<Task>> generate_critical_path_workload(
    int workload_id,
    int &id_offset,
    int num_chains,              // Number of parallel chains
    int chain_length,            // Depth of each chain (e.g., 12)
    int num_independent,         // Competing independent tasks
    float arrival_time_ms,
    int priority = 2
);

// Type 5: High Fanout DAG (favors HighFanoutScheduler)
// Models: Data processing with scatter-gather patterns
// Characteristics: Few roots → many intermediate → few sinks (diamond/hourglass)
std::vector<std::unique_ptr<Task>> generate_high_fanout_workload(
    int workload_id,
    int &id_offset,
    int num_roots,               // Starting tasks (e.g., 3)
    int fanout_per_root,         // Tasks spawned per root (e.g., 25)
    int num_sinks,               // Final join tasks (e.g., 5)
    float arrival_time_ms,
    int priority = 2
);

// Type 6: Multi-Level Pipeline (favors LevelAwareScheduler)
// Models: Multi-stage data pipeline with clear levels
// Characteristics: Strict level dependencies, many tasks per level
std::vector<std::unique_ptr<Task>> generate_multi_level_workload(
    int workload_id,
    int &id_offset,
    int num_levels,              // Number of pipeline stages (e.g., 4)
    int tasks_per_level,         // Tasks at each level (e.g., 30)
    float arrival_time_ms,
    int priority = 2
);

// Type 7: Complex DAG Mix (favors HybridScheduler)
// Models: Realistic workload with mixed DAG patterns
// Characteristics: Combines critical paths, fanout, and independent tasks
std::vector<std::unique_ptr<Task>> generate_complex_dag_workload(
    int workload_id,
    int &id_offset,
    float arrival_time_ms,
    int priority = 2
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
