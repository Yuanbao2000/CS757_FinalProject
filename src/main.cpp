#include <vector>
#include <memory>
#include <iostream>
#include <thread>
#include <cuda_runtime.h>

#include "task.h"
#include "metrics.h"
#include "scheduler.h"
#include "circuit_parser.h"
#include "sequential_runner.h"
#include "concurrent_runner.h"
#include "fifo_scheduler.hpp"
#include "priority_scheduler.hpp"
#include "high_fanout_scheduler.hpp"
#include "critical_path_scheduler.hpp"
#include "level_aware_scheduler.hpp"
#include "hybrid_scheduler.hpp"
#include "compute_bound.hpp"
#include "memory_bound.hpp"
#include "latency_sensitive.hpp"

// init CUDA context
void cuda_warmup() {
    float *d;
    cudaMalloc(&d, sizeof(float));
    cudaFree(d);
    cudaDeviceSynchronize();
}

void launch_kernel(const Task *t) {
    switch (t->type) {
        case KernelType::COMPUTE_BOUND:
            launch_compute_bound(t->stream, t->param_N);
            break;
        case KernelType::MEMORY_BOUND:
            launch_memory_bound(t->stream, t->param_N, t->param_stride);
            break;
        case KernelType::LATENCY_SENSITIVE:
            launch_latency_sensitive(t->stream, t->param_N);
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

    cudaStreamCreate(&t->stream);
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

int main(int argc, char **argv) {
    constexpr int NUM_RUNS = 10;
    const std::vector BATCH_SIZES = {32, 128, 512};

     // max tasks in flight simultaneously for concurrent mode
    const std::vector MAX_CONCURRENT = {32, 128, 512};

    // sequential or concurrent mode
    std::string mode = "concurrent"; // default
    if (argc > 1) {
        mode = argv[1];
    }

    // workload groups
    const std::vector<std::pair<std::string, std::vector<std::string> > > GROUPS = {
        // balanced (gate counts roughly equal across groups)
        {"balanced_0", {"benchmark/c880.ckt", "benchmark/c1908.ckt", "benchmark/c2670.ckt"}},
        {"balanced_1", {"benchmark/c432.ckt", "benchmark/c499.ckt", "benchmark/c3540.ckt"}},
        // imbalanced (mix of different circuit sizes to stress fairness)
        {"imbalanced_2", {"benchmark/c432.ckt", "benchmark/c499.ckt", "benchmark/c880.ckt"}},
        {"imbalanced_3", {"benchmark/c1908.ckt", "benchmark/c2670.ckt", "benchmark/c3540.ckt"}},
        {"imbalanced_4", {"benchmark/c17.ckt", "benchmark/c1908.ckt", "benchmark/c7552.ckt"}},
        {"imbalanced_5", {"benchmark/c432.ckt", "benchmark/c3540.ckt", "benchmark/c7552.ckt"}},
    };

    // group_name, batch_size/max_concurrent, averages, standard deviations
    std::vector<std::tuple<std::string, int, std::vector<Metrics>, std::vector<Metrics> > > all_results;
    cuda_warmup();

    std::cout << "Running in " << mode << " mode\n";

    const std::vector<int> &config_params = (mode == "concurrent") ? MAX_CONCURRENT : BATCH_SIZES;

    for (const int config_value: config_params) {
        for (const auto &[group_name, circuits]: GROUPS) {
            const std::string config_label = mode == "concurrent" ? "concurrent" : "sequential";
            std::cout << "\n=== Group: " << group_name << "  " << config_label << "=" << config_value << " ===\n";

            // load all circuits in group into one flat task pool
            std::vector<std::unique_ptr<Task> > owned;
            int offset = 0;
            for (int wl_id = 0; wl_id < circuits.size(); wl_id++) {
                Circuit c = parse_ckt(circuits[wl_id]);

                // sequential arrival with 10ms gaps
                float arrival_ms = static_cast<float>(wl_id) * 10.0f;
                // or try late arrival for small circuits (latency-sensitive workloads)
                // if (c.total_gates < 100) arrival_ms += 20.0f;

                auto wl_tasks = circuit_to_tasks(c, wl_id, offset, arrival_ms);
                offset += c.total_gates;
                for (auto &t: wl_tasks)
                    owned.push_back(std::move(t));
            }

            std::vector<Task *> tasks;
            for (auto &t: owned) tasks.push_back(t.get());

            // 10 runs per scheduler
            std::vector<Metrics> fifo_runs, prio_runs, high_fanout_runs, critical_path_runs, level_aware_runs,
                    hybrid_runs;

            for (int run = 0; run < NUM_RUNS; run++) {
                cuda_warmup();
                float stream_ms = 0.f;

                if (mode == "concurrent") {
                    // concurrent dispatch mode
                    {
                        FIFOScheduler s;
                        run_scheduler_concurrent(&s, tasks, config_value, stream_ms);
                        fifo_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                    }

                    {
                        PriorityScheduler s;
                        run_scheduler_concurrent(&s, tasks, config_value, stream_ms);
                        prio_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                    }

                    {
                        HighFanoutScheduler s;
                        s.precompute_downstream(tasks);
                        run_scheduler_concurrent(&s, tasks, config_value, stream_ms);
                        high_fanout_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                    }

                    {
                        CriticalPathScheduler s;
                        s.precompute_downstream(tasks);
                        run_scheduler_concurrent(&s, tasks, config_value, stream_ms);
                        critical_path_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                    }

                    {
                        LevelAwareScheduler s;
                        s.precompute_downstream(tasks);
                        run_scheduler_concurrent(&s, tasks, config_value, stream_ms);
                        level_aware_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                    }

                    {
                        HybridScheduler s;
                        s.precompute_downstream(tasks);
                        run_scheduler_concurrent(&s, tasks, config_value, stream_ms);
                        hybrid_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                    }
                } else {
                    // sequential batch dispatch mode
                    {
                        FIFOScheduler s;
                        run_scheduler(&s, tasks, config_value, stream_ms);
                        fifo_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                    }

                    {
                        PriorityScheduler s;
                        run_scheduler(&s, tasks, config_value, stream_ms);
                        prio_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                    }

                    {
                        HighFanoutScheduler s;
                        s.precompute_downstream(tasks);
                        run_scheduler(&s, tasks, config_value, stream_ms);
                        high_fanout_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                    }

                    {
                        CriticalPathScheduler s;
                        s.precompute_downstream(tasks);
                        run_scheduler(&s, tasks, config_value, stream_ms);
                        critical_path_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                    }

                    {
                        LevelAwareScheduler s;
                        s.precompute_downstream(tasks);
                        run_scheduler(&s, tasks, config_value, stream_ms);
                        level_aware_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                    }

                    {
                        HybridScheduler s;
                        s.precompute_downstream(tasks);
                        run_scheduler(&s, tasks, config_value, stream_ms);
                        hybrid_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                    }
                }
            }

            // avg for report
            std::vector averaged = {
                average_metrics("FIFO", fifo_runs),
                average_metrics("Priority", prio_runs),
                average_metrics("HighFanout", high_fanout_runs),
                average_metrics("CriticalPath", critical_path_runs),
                average_metrics("LevelAware", level_aware_runs),
                average_metrics("Hybrid", hybrid_runs),
            };

            // standard deviations
            std::vector stds = {
                compute_stddev("FIFO", fifo_runs, averaged[0]),
                compute_stddev("Priority", prio_runs, averaged[1]),
                compute_stddev("HighFanout", high_fanout_runs, averaged[2]),
                compute_stddev("CriticalPath", critical_path_runs, averaged[3]),
                compute_stddev("LevelAware", level_aware_runs, averaged[4]),
                compute_stddev("Hybrid", hybrid_runs, averaged[5]),
            };

            all_results.emplace_back(group_name, config_value, averaged, stds);

            for (const auto &m: averaged) print_metrics(m);

            // append mode to group name for report files
            std::string report_group_name = group_name + "_" + mode;
            write_report(averaged, stds, report_group_name, config_value, NUM_RUNS);
        }
    }

    return 0;
}
