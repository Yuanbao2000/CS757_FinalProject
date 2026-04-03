#include <vector>
#include <memory>
#include <iostream>
#include <cuda_runtime.h>

#include "task.h"
#include "metrics.h"
#include "scheduler.h"
#include "circuit_parser.h"
#include "fifo_scheduler.hpp"
#include "priority_scheduler.hpp"
#include "dependency_aware_scheduler.hpp"
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

void notify_dependents(const Task *finished, Scheduler *sched,
                       const std::vector<Task *> &all_tasks) {
    for (Task *t: all_tasks) {
        for (const int dep_id: t->dependencies) {
            if (dep_id == finished->id) {
                t->dep_remaining--;
                if (t->dep_remaining == 0)
                    sched->submit(t);
            }
        }
    }
}

void run_scheduler(Scheduler *sched, const std::vector<Task *> &all_tasks, const int batch_size, float &out_stream_ms) {
    // reset timing fields in case re-running the same tasks
    for (Task *t: all_tasks) {
        t->wait_time_ms = 0.f;
        t->exec_time_ms = 0.f;
        t->finish_time_ms = 0.f;
        t->dep_remaining = static_cast<int>(t->dependencies.size());
    }

    // submit ready tasks
    for (Task *t: all_tasks)
        if (t->dep_remaining == 0)
            sched->submit(t);

    float clock_ms = 0.f;
    out_stream_ms = 0.f;
    while (!sched->empty()) {
        // dequeue till hitting batch_size ready tasks
        std::vector<Task *> batch;
        while (!sched->empty() && batch.size() < batch_size)
            batch.push_back(sched->next());


        // launch all tasks in the batch
        const float batch_start = clock_ms;
        for (Task *t: batch) {
            t->wait_time_ms = batch_start - t->arrival_time_ms;
            cudaEventRecord(t->start_event, t->stream);
            launch_kernel(t);
            cudaEventRecord(t->end_event, t->stream);
        }

        // sync all streams in the batch
        float batch_max_exec = 0.f;
        for (Task *t: batch) {
            cudaEventSynchronize(t->end_event);
            cudaEventElapsedTime(&t->exec_time_ms, t->start_event, t->end_event);
            t->finish_time_ms = batch_start + t->exec_time_ms;
            batch_max_exec = std::max(batch_max_exec, t->exec_time_ms);
        }
        // actual slots used this batch × wall time of this batch
        out_stream_ms += batch_max_exec * static_cast<float>(batch.size());
        // clock advances with the slwowest batch
        clock_ms = batch_start + batch_max_exec;

        // update dependents with completed tasks
        for (const Task *t: batch)
            notify_dependents(t, sched, all_tasks);
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

    // group_name, batch_size, averages, standard deviations
    std::vector<std::tuple<std::string, int, std::vector<Metrics>, std::vector<Metrics>>> all_results;
    cuda_warmup();

    for (const int batch_size: BATCH_SIZES) {
        for (const auto &[group_name, circuits]: GROUPS) {
            std::cout << "\n=== Group: " << group_name << "  batch=" << batch_size << " ===\n";

            // load all circuits in group into one flat task pool
            std::vector<std::unique_ptr<Task> > owned;
            int offset = 0;
            for (int wl_id = 0; wl_id < circuits.size(); wl_id++) {
                Circuit c = parse_ckt(circuits[wl_id]);
                auto wl_tasks = circuit_to_tasks(c, wl_id, offset);
                offset += c.total_gates;
                for (auto &t: wl_tasks)
                    owned.push_back(std::move(t));
            }

            std::vector<Task *> tasks;
            for (auto &t: owned) tasks.push_back(t.get());

            // 10 runs per scheduler
            std::vector<Metrics> fifo_runs, prio_runs, dep_runs;

            for (int run = 0; run < NUM_RUNS; run++) {
                cuda_warmup();
                float stream_ms = 0.f;

                {
                    FIFOScheduler s;
                    run_scheduler(&s, tasks, batch_size, stream_ms);
                    fifo_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                }

                {
                    PriorityScheduler s;
                    run_scheduler(&s, tasks, batch_size, stream_ms);
                    prio_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                }

                {
                    DependencyAwareScheduler s;
                    s.precompute_downstream(tasks);
                    run_scheduler(&s, tasks, batch_size, stream_ms);
                    dep_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                }
            }

            // avg for report
            std::vector averaged = {
                average_metrics("FIFO", fifo_runs),
                average_metrics("Priority", prio_runs),
                average_metrics("DependencyAware", dep_runs),
            };

            // standard deviations
            std::vector stds = {
                compute_stddev("FIFO", fifo_runs, averaged[0]),
                compute_stddev("Priority", prio_runs, averaged[1]),
                compute_stddev("DependencyAware", dep_runs, averaged[2]),
            };

            all_results.emplace_back(group_name, batch_size, averaged, stds);

            for (const auto &m: averaged) print_metrics(m);
            write_report(averaged, stds, group_name, batch_size, NUM_RUNS);
        }
    }

    return 0;
}
