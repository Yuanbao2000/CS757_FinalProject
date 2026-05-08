#include <vector>
#include <memory>
#include <iostream>
#include <thread>
#include <cuda_runtime.h>
#include <random>

#include "task.h"
#include "metrics.h"
#include "scheduler.h"
#include "workload_generator.h"
#include "pooled_streams_runner.h"
#include "fifo_scheduler.hpp"
#include "priority_scheduler.hpp"
#include "high_fanout_scheduler.hpp"
#include "critical_path_scheduler.hpp"
#include "level_aware_scheduler.hpp"
#include "hybrid_scheduler.hpp"
#include "compute_bound.hpp"
#include "memory_bound.hpp"
#include "latency_sensitive.hpp"
#include "shortest_job_first.hpp"
#include "smallest_job_first.hpp"

// init CUDA context
void cuda_warmup() {
    float *d;
    cudaMalloc(&d, sizeof(float));
    cudaFree(d);
    cudaDeviceSynchronize();
}

void launch_kernel(const Task *t, int stream_idx, MemoryPool &mem_pool) {
    // Get pre-allocated buffers for this stream
    auto &buffers = mem_pool.get(stream_idx);

    switch (t->type) {
        case KernelType::COMPUTE_BOUND:
            launch_compute_bound(t->stream, t->param_N, buffers.buf1, buffers.buf2, buffers.buf3);
            break;
        case KernelType::MEMORY_BOUND:
            launch_memory_bound(t->stream, t->param_N, t->param_stride, buffers.buf1);
            break;
        case KernelType::LATENCY_SENSITIVE:
            launch_latency_sensitive(t->stream, t->param_N, buffers.buf1, buffers.buf2, buffers.buf3);
            break;
    }
}

int main(int argc, char **argv) {
    constexpr int NUM_RUNS = 10;
    const std::vector BATCH_SIZES = {32, 128, 512};

    // Realistic GPU workload scenarios
    // Each scenario tests different aspects of scheduler performance
    const std::vector<std::string> SCENARIOS = {
        "inference_only",      // Latency-sensitive only (high arrival rate)
        "mixed_latency_critical", // Inference + Training (tests latency vs throughput)
        "mixed_balanced",      // Even mix of all types
        "training_heavy",      // Throughput-oriented (large batches)
        "heterogeneous"        // Complex mix: multiple inference streams + training + batch
    };

    std::vector<std::tuple<std::string, int, std::vector<Metrics>, std::vector<Metrics>>> all_results;
    cuda_warmup();

    for (const int batch_size: BATCH_SIZES) {
        for (const auto &scenario: SCENARIOS) {
            std::cout << "\n=== Scenario: " << scenario << ", batch=" << batch_size << " ===\n";

            // Generate workload based on scenario
            std::vector<std::unique_ptr<Task>> owned;
            int offset = 0;

            if (scenario == "inference_only") {
                // High-throughput inference serving
                auto inf1 = generate_inference_workload(0, offset, 200, 1000.0f, 1, 2048);
                for (auto &t : inf1) owned.push_back(std::move(t));

            } else if (scenario == "mixed_latency_critical") {
                // Test latency-fairness tradeoff
                auto inf = generate_inference_workload(0, offset, 120, 500.0f, 1, 2048);
                for (auto &t : inf) owned.push_back(std::move(t));

                // 2 large training jobs (throughput-oriented, low priority)
                auto train1 = generate_training_workload(1, offset, 40, 500.0f, 3, 6144);
                auto train2 = generate_training_workload(2, offset, 40, 2000.0f, 3, 6144);
                for (auto &t : train1) owned.push_back(std::move(t));
                for (auto &t : train2) owned.push_back(std::move(t));

            } else if (scenario == "mixed_balanced") {
                // Balanced mix of workload types
                auto inf = generate_inference_workload(0, offset, 100, 400.0f, 1, 2048);
                for (auto &t : inf) owned.push_back(std::move(t));

                auto train = generate_training_workload(1, offset, 32, 1000.0f, 3, 6144);
                for (auto &t : train) owned.push_back(std::move(t));

                auto batch = generate_batch_processing_workload(2, offset, 20, 500.0f, 2000.0f, 2,
                                                                KernelType::MEMORY_BOUND);
                for (auto &t : batch) owned.push_back(std::move(t));

            } else if (scenario == "training_heavy") {
                // Large training batches dominate
                auto train1 = generate_training_workload(0, offset, 80, 0.0f, 3, 6144);
                auto train2 = generate_training_workload(1, offset, 80, 1000.0f, 3, 6144);
                auto train3 = generate_training_workload(2, offset, 40, 2000.0f, 3, 4096);
                for (auto &t : train1) owned.push_back(std::move(t));
                for (auto &t : train2) owned.push_back(std::move(t));
                for (auto &t : train3) owned.push_back(std::move(t));

                // Small inference load (tests if schedulers can serve latency-sensitive amidst heavy load)
                auto inf = generate_inference_workload(3, offset, 30, 200.0f, 1, 2048);
                for (auto &t : inf) owned.push_back(std::move(t));

            } else if (scenario == "heterogeneous") {
                // Complex realistic scenario: multiple streams competing
                // Inference stream 1 (user-facing API)
                auto inf1 = generate_inference_workload(0, offset, 60, 300.0f, 1, 2048);
                for (auto &t : inf1) owned.push_back(std::move(t));

                // Inference stream 2 (internal service)
                auto inf2 = generate_inference_workload(1, offset, 60, 350.0f, 2, 1536);
                for (auto &t : inf2) owned.push_back(std::move(t));

                // Training job
                auto train = generate_training_workload(2, offset, 60, 1500.0f, 4, 6144);
                for (auto &t : train) owned.push_back(std::move(t));

                // Batch processing (data pipeline)
                auto batch1 = generate_batch_processing_workload(3, offset, 15, 0.0f, 3000.0f, 2,
                                                                 KernelType::MEMORY_BOUND);
                for (auto &t : batch1) owned.push_back(std::move(t));

                // Compute-intensive batch job
                auto batch2 = generate_batch_processing_workload(4, offset, 25, 1000.0f, 2000.0f, 3,
                                                                 KernelType::COMPUTE_BOUND);
                for (auto &t : batch2) owned.push_back(std::move(t));
            }

            // Convert to raw pointers for scheduler
            std::vector<Task *> tasks;
            for (auto &t : owned) tasks.push_back(t.get());

            std::cout << "[Scenario] Total tasks: " << tasks.size() << "\n";

            // Create memory pool ONCE per scenario and reuse across all runs
            MemoryPool shared_pool;
            shared_pool.init(batch_size);

            // 10 runs per scheduler
            std::vector<Metrics> fifo_runs, smallest_job_runs, shortest_job_runs, prio_runs,
                    high_fanout_runs, critical_path_runs, level_aware_runs, hybrid_runs;

            for (int run = 0; run < NUM_RUNS; run++) {
                float stream_ms = 0.f;

                {
                    FIFOScheduler s;
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent, shared_pool);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    fifo_runs.push_back(m);
                }

                {
                    SmallestJobFirstScheduler s;
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent, shared_pool);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    smallest_job_runs.push_back(m);
                }

                {
                    ShortestJobFirstScheduler s;
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent, shared_pool);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    shortest_job_runs.push_back(m);
                }

                {
                    PriorityScheduler s;
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent, shared_pool);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    prio_runs.push_back(m);
                }

                // Dependency-aware schedulers need precomputation
                // For independent tasks, these will effectively reduce to other policies
                // but we keep them for completeness
                {
                    HighFanoutScheduler s;
                    s.precompute_downstream(tasks);
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent, shared_pool);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    high_fanout_runs.push_back(m);
                }

                {
                    CriticalPathScheduler s;
                    s.precompute_downstream(tasks);
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent, shared_pool);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    critical_path_runs.push_back(m);
                }

                {
                    LevelAwareScheduler s;
                    s.precompute_downstream(tasks);
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent, shared_pool);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    level_aware_runs.push_back(m);
                }

                {
                    HybridScheduler s;
                    s.precompute_downstream(tasks);
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent, shared_pool);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    hybrid_runs.push_back(m);
                }
            }

            // Compute averages
            std::vector averaged = {
                average_metrics("FIFO", fifo_runs),
                average_metrics("SmallestJobFirst", smallest_job_runs),
                average_metrics("ShortestJobFirst", shortest_job_runs),
                average_metrics("Priority", prio_runs),
                average_metrics("HighFanout", high_fanout_runs),
                average_metrics("CriticalPath", critical_path_runs),
                average_metrics("LevelAware", level_aware_runs),
                average_metrics("Hybrid", hybrid_runs),
            };

            // Compute standard deviations
            std::vector stds = {
                compute_stddev("FIFO", fifo_runs, averaged[0]),
                compute_stddev("SmallestJobFirst", smallest_job_runs, averaged[1]),
                compute_stddev("ShortestJobFirst", shortest_job_runs, averaged[2]),
                compute_stddev("Priority", prio_runs, averaged[3]),
                compute_stddev("HighFanout", high_fanout_runs, averaged[4]),
                compute_stddev("CriticalPath", critical_path_runs, averaged[5]),
                compute_stddev("LevelAware", level_aware_runs, averaged[6]),
                compute_stddev("Hybrid", hybrid_runs, averaged[7]),
            };

            all_results.emplace_back(scenario, batch_size, averaged, stds);

            // Print results
            for (const auto &m: averaged) print_metrics(m);

            // Write report
            write_report(averaged, stds, scenario, batch_size, NUM_RUNS);
        }
    }

    return 0;
}
