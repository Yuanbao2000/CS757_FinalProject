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

void run_scheduler(Scheduler *sched, const std::vector<Task *> &all_tasks, const int batch_size = 512) {
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

int main(int argc, char **argv) {
    // Default to the tiny c17 if no file given, for quick testing
    std::string ckt_path = (argc >= 2) ? argv[1] : "benchmark/c17.ckt";
    int batch_size = (argc >= 3) ? std::atoi(argv[2]) : 512;

    std::cout << "Circuit: " << ckt_path << "\n";
    std::cout << "Batch  : " << batch_size << "\n\n";
    cuda_warmup();

    Circuit circuit = parse_ckt(ckt_path);
    auto owned = circuit_to_tasks(circuit);

    std::vector<Task *> tasks;
    for (auto &t: owned) tasks.push_back(t.get());

    std::vector<Metrics> all_metrics;
    {
        FIFOScheduler fifo;
        run_scheduler(&fifo, tasks, batch_size);
        auto m = compute_metrics(fifo.name(), tasks);
        print_metrics(m);
        all_metrics.push_back(m);
    }
    {
        PriorityScheduler prio;
        run_scheduler(&prio, tasks, batch_size);
        auto m = compute_metrics(prio.name(), tasks);
        print_metrics(m);
        all_metrics.push_back(m);
    }
    {
        DependencyAwareScheduler dep;
        dep.precompute_downstream(tasks);
        run_scheduler(&dep, tasks, batch_size);
        auto m = compute_metrics(dep.name(), tasks);
        print_metrics(m);
        all_metrics.push_back(m);
    }

    // write_report(all_metrics, ckt_path);

    return 0;
}
