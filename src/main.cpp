#include <vector>
#include <memory>
#include <iostream>
#include <thread>
#include <cuda_runtime.h>
#include <random>

#include "task.h"
#include "metrics.h"
#include "scheduler.h"
#include "circuit_parser.h"
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
#include "memory_pool.h"

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

std::unique_ptr<Task> make_task(const int id, const int workload_id, const int priority,
                                const float arrival_ms, const KernelType type,
                                const int param_N = 1024, const int param_stride = 32) {
    auto t = std::make_unique<Task>();
    t->id = id;
    t->workload_id = workload_id;
    t->priority = priority;
    t->arrival_time_ms = arrival_ms;
    t->type = type;
    t->param_N = param_N;
    t->param_stride = param_stride;
    t->dep_remaining = 0;

    // Stream from pool, events per-task for timing
    t->stream = nullptr;
    cudaEventCreate(&t->start_event);
    cudaEventCreate(&t->end_event);

    return t;
}

KernelType parse_kernel_type(const std::string &s) {
    if (s == "compute") return KernelType::COMPUTE_BOUND;
    if (s == "memory") return KernelType::MEMORY_BOUND;
    if (s == "latency") return KernelType::LATENCY_SENSITIVE;
    throw std::runtime_error("Unexpected kernel type: " + s);
}

std::vector<float> generate_poisson_arrivals(int num_workloads, float avg_rate_per_sec) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::exponential_distribution<float> exp_dist(avg_rate_per_sec / 1000.0f); // convert to per-ms

    std::vector<float> arrivals(num_workloads);
    arrivals[0] = 0.0f; // First workload arrives at t=0

    for (int i = 1; i < num_workloads; i++) {
        float inter_arrival_ms = exp_dist(rng);
        arrivals[i] = arrivals[i - 1] + inter_arrival_ms;
    }

    return arrivals;
}

int main(int argc, char **argv) {
    constexpr int NUM_RUNS = 10;
    const std::vector BATCH_SIZES = {32, 128, 512};

    // workload groups
    const std::vector<std::pair<std::string, std::vector<std::string> > > GROUPS = {
        // HIGH PARALLELISM: 24 circuits (mix of small/medium), all arrive at t=0
        {
            "high_parallel", {
                // Small circuits
                "benchmark/c432.ckt", "benchmark/c432.ckt", "benchmark/c432.ckt",
                "benchmark/c499.ckt", "benchmark/c499.ckt", "benchmark/c499.ckt",
                // Medium circuits
                "benchmark/c880.ckt", "benchmark/c880.ckt", "benchmark/c880.ckt",
                "benchmark/c1355.ckt", "benchmark/c1355.ckt", "benchmark/c1355.ckt",
                "benchmark/c1908.ckt", "benchmark/c1908.ckt", "benchmark/c1908.ckt",
                // A few larger ones for variety
                "benchmark/c2670.ckt", "benchmark/c2670.ckt", "benchmark/c2670.ckt",
                "benchmark/c3540.ckt", "benchmark/c3540.ckt", "benchmark/c3540.ckt",
                "benchmark/c5315.ckt", "benchmark/c5315.ckt"
            }
        },

        // LOW PARALLELISM: Only 3 circuits
        {
            "low_parallel", {
                "benchmark/c880.ckt",
                "benchmark/c1908.ckt",
                "benchmark/c2670.ckt"
            }
        },

        // BALANCED: Similar-sized circuits to test scheduler performance without size bias
        {
            "balanced", {
                "benchmark/c432.ckt",
                "benchmark/c499.ckt",
                "benchmark/c880.ckt",
                "benchmark/c1355.ckt",
                "benchmark/c1908.ckt",
                "benchmark/c2670.ckt"
            }
        },

        // IMBALANCED: Extreme size variation to stress fairness metrics
        {
            "imbalanced", {
                "benchmark/c17.ckt",
                "benchmark/c17.ckt",
                "benchmark/c880.ckt",
                "benchmark/c1908.ckt",
                "benchmark/c5315.ckt",
                "benchmark/c7552.ckt"
            }
        },
    };

    // group_name, batch_size/max_concurrent, averages, standard deviations
    std::vector<std::tuple<std::string, int, std::vector<Metrics>, std::vector<Metrics> > > all_results;
    cuda_warmup();

    for (const int batch_size: BATCH_SIZES) {
        for (const auto &[group_name, circuits]: GROUPS) {
            std::cout << "\n=== Group: " << group_name << ",  batch=" << batch_size << " ===\n";

            // load all circuits in group into one flat task pool
            std::vector<std::unique_ptr<Task> > owned;
            int offset = 0;
            // circuit arrival time set to 0 for maximum overlap
            std::vector<float> circuit_arrivals(circuits.size(), 0.0f);

            for (int wl_id = 0; wl_id < circuits.size(); wl_id++) {
                Circuit c = parse_ckt(circuits[wl_id]);
                float circuit_start_ms = circuit_arrivals[wl_id];

                // Generate per-task arrivals within this circuit (staggered submission)
                std::vector<float> task_arrivals = generate_poisson_arrivals(c.total_gates, 100000.0f);

                // Create tasks with base arrival time (circuit_start_ms not used yet)
                auto wl_tasks = circuit_to_tasks(c, wl_id, offset, circuit_start_ms);

                offset += c.total_gates;
                for (auto &t: wl_tasks)
                    owned.push_back(std::move(t));
            }

            std::vector<Task *> tasks;
            for (auto &t: owned) tasks.push_back(t.get());

            // 10 runs per scheduler
            std::vector<Metrics> fifo_runs, smallest_job_runs, shortest_job_runs, prio_runs, high_fanout_runs,
                    critical_path_runs, level_aware_runs, hybrid_runs;

            for (int run = 0; run < NUM_RUNS; run++) {
                cuda_warmup();
                float stream_ms = 0.f;

                // concurrent dispatch mode
                {
                    FIFOScheduler s;
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    fifo_runs.push_back(m);
                }

                {
                    SmallestJobFirstScheduler s;
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    smallest_job_runs.push_back(m);
                }


                {
                    ShortestJobFirstScheduler s;
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    shortest_job_runs.push_back(m);
                }

                {
                    PriorityScheduler s;
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    prio_runs.push_back(m);
                }

                {
                    HighFanoutScheduler s;
                    s.precompute_downstream(tasks);
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    high_fanout_runs.push_back(m);
                }

                {
                    CriticalPathScheduler s;
                    s.precompute_downstream(tasks);
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    critical_path_runs.push_back(m);
                }

                {
                    LevelAwareScheduler s;
                    s.precompute_downstream(tasks);
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    level_aware_runs.push_back(m);
                }

                {
                    HybridScheduler s;
                    s.precompute_downstream(tasks);
                    int max_concurrent = 0;
                    run_scheduler(&s, tasks, batch_size, stream_ms, max_concurrent);
                    Metrics m = compute_metrics(s.name(), tasks, stream_ms, batch_size);
                    m.max_concurrent_streams = max_concurrent;
                    hybrid_runs.push_back(m);
                }
            }

            // avg for report
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

            // standard deviations
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

            all_results.emplace_back(group_name, batch_size, averaged, stds);

            for (const auto &m: averaged) print_metrics(m);

            // append mode to group name for report files
            std::string report_group_name = group_name;
            write_report(averaged, stds, report_group_name, batch_size, NUM_RUNS);
        }
    }

    return 0;
}
