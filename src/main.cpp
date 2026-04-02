#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <cuda_runtime.h>

#include "task.h"
#include "metrics.h"
#include "scheduler.h"
#include "fifo_scheduler.hpp"
#include "priority_scheduler.hpp"
#include "dependency_aware_scheduler.hpp"
#include "compute_bound.hpp"
#include "memory_bound.hpp"
#include "latency_sensitive.hpp"
#include "json.hpp"

using json = nlohmann::json;

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

void run_scheduler(Scheduler *sched, const std::vector<Task *> &all_tasks) {
    // reset timing fields in case re-running the same tasks
    for (Task *t: all_tasks) {
        t->wait_time_ms = 0.f;
        t->exec_time_ms = 0.f;
        t->finish_time_ms = 0.f;
        t->dep_remaining = static_cast<int>(t->dependencies.size());
    }

    // seed with tasks that are immediately ready (no dependencies)
    for (Task *t: all_tasks)
        if (t->dep_remaining == 0)
            sched->submit(t);

    float clock_ms = 0.f;

    while (!sched->empty()) {
        Task *t = sched->next();

        // tasks wait till GPU is free
        clock_ms = std::max(clock_ms, t->arrival_time_ms);
        t->wait_time_ms = clock_ms - t->arrival_time_ms;

        cudaEventRecord(t->start_event, t->stream);
        launch_kernel(t);
        cudaEventRecord(t->end_event, t->stream);
        cudaEventSynchronize(t->end_event); // non-preemptive (blocking CPU)

        cudaEventElapsedTime(&t->exec_time_ms, t->start_event, t->end_event);
        t->finish_time_ms = clock_ms + t->exec_time_ms;
        clock_ms = t->finish_time_ms;

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

std::vector<std::unique_ptr<Task> > load_tasks(const std::string &config_path) {
    std::ifstream f(config_path);
    if (!f) throw std::runtime_error("Cannot open config: " + config_path);

    json doc = json::parse(f);
    std::vector<std::unique_ptr<Task> > owned;

    for (const auto &wl: doc["workloads"]) {
        const int wl_id = wl["id"];
        for (const auto &jt: wl["tasks"]) {
            auto t = std::make_unique<Task>();
            t->id = jt["id"];
            t->workload_id = wl_id;
            t->priority = jt["priority"];
            t->arrival_time_ms = jt["arrival_ms"];
            t->type = parse_kernel_type(jt["type"]);
            t->param_N = jt.value("param_N", 1024);
            t->param_stride = jt.value("param_stride", 32);
            t->dep_remaining = 0;

            for (const int dep: jt["dependencies"])
                t->dependencies.push_back(dep);

            cudaStreamCreate(&t->stream);
            cudaEventCreate(&t->start_event);
            cudaEventCreate(&t->end_event);
            owned.push_back(std::move(t));
        }
    }
    return owned;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: gpu_scheduler --config <path/to/config.json>\n";
        return 1;
    }

    std::string config_path;
    for (int i = 1; i < argc - 1; ++i)
        if (std::string(argv[i]) == "--config")
            config_path = argv[i + 1];

    if (config_path.empty()) {
        std::cerr << "Missing --config argument\n";
        return 1;
    }

    std::cout << "Config: " << config_path << "\n";
    cuda_warmup();

    auto owned = load_tasks(config_path);
    std::vector<Task *> tasks;
    for (auto &t: owned) tasks.push_back(t.get());

    std::vector<Metrics> all_metrics;
    {
        FIFOScheduler s;
        run_scheduler(&s, tasks);
        auto m = compute_metrics(s.name(), tasks);
        print_metrics(m);
        all_metrics.push_back(m);
    }
    {
        PriorityScheduler s;
        run_scheduler(&s, tasks);
        auto m = compute_metrics(s.name(), tasks);
        print_metrics(m);
        all_metrics.push_back(m);
    }
    {
        DependencyAwareScheduler s;
        s.precompute_downstream(tasks);
        run_scheduler(&s, tasks);
        auto m = compute_metrics(s.name(), tasks);
        print_metrics(m);
        all_metrics.push_back(m);
    }

    write_report(all_metrics, config_path);

    return 0;
}
