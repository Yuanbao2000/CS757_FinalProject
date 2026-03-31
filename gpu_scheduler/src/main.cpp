#include <iostream>
#include <vector>
#include <memory>
#include <cuda_runtime.h>

#include "task.h"
#include "workload.h"
#include "scheduler.h"
#include "fifo_scheduler.hpp"
#include "priority_scheduler.hpp"
#include "dependency_aware_scheduler.hpp"
#include "compute_bound.hpp"
#include "memory_bound.hpp"
#include "latency_sensitive.hpp"

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
        t->wait_time_ms = clock_ms - t->arrival_time_ms;

        cudaEventRecord(t->start_event, t->stream);
        launch_kernel(t);
        cudaEventRecord(t->end_event, t->stream);

        // non-preemptive (block CPU)
        cudaEventSynchronize(t->end_event);

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

void free_task(Task *t) {
    cudaStreamDestroy(t->stream);
    cudaEventDestroy(t->start_event);
    cudaEventDestroy(t->end_event);
    delete t;
}

void print_results(const std::string &sched_name,
                   const std::vector<Task *> &tasks) {
    std::cout << "\n=== " << sched_name << " Results ===\n";
    std::printf("%-4s %-4s %-18s %-10s %-10s %-10s\n",
                "ID", "WL", "Type", "Wait(ms)", "Exec(ms)", "Finish(ms)");
    std::cout << std::string(56, '-') << "\n";

    float total_wait = 0, total_exec = 0;
    for (Task *t: tasks) {
        const char *type_str =
                t->type == KernelType::COMPUTE_BOUND
                    ? "COMPUTE_BOUND"
                    : t->type == KernelType::MEMORY_BOUND
                          ? "MEMORY_BOUND"
                          : "LATENCY_SENSITIVE";
        std::printf("%-4d %-4d %-18s %-10.3f %-10.3f %-10.3f\n",
                    t->id, t->workload_id, type_str,
                    t->wait_time_ms, t->exec_time_ms, t->finish_time_ms);
        total_wait += t->wait_time_ms;
        total_exec += t->exec_time_ms;
    }

    const int n = static_cast<int>(tasks.size());
    const float makespan = tasks.back()->finish_time_ms;
    std::printf("\nAvg wait: %.3f ms | Avg exec: %.3f ms | "
                "Throughput: %.2f tasks/s | GPU util: %.1f%%\n",
                total_wait / static_cast<float>(n),
                total_exec / static_cast<float>(n),
                static_cast<float>(n) / (makespan / 1000.f),
                100.f * total_exec / makespan);
}

int main() {
    std::vector<std::unique_ptr<Task> > owned;

    // compute-heavy (training tasks)
    owned.push_back(make_task(0, 0, 2, 0.f, KernelType::COMPUTE_BOUND, 1024));
    owned.push_back(make_task(1, 0, 2, 0.f, KernelType::COMPUTE_BOUND, 1024));
    owned.push_back(make_task(2, 0, 2, 0.f, KernelType::MEMORY_BOUND, 1 << 24, 32));

    // latency-sensitive (inference tasks), higher priority
    owned.push_back(make_task(3, 1, 1, 5.f, KernelType::LATENCY_SENSITIVE, 1024));
    owned.push_back(make_task(4, 1, 1, 5.f, KernelType::LATENCY_SENSITIVE, 1024));
    owned.push_back(make_task(5, 1, 1, 5.f, KernelType::LATENCY_SENSITIVE, 1024));

    // mixed with a dependency chain: task 8 depends on 6 and 7
    owned.push_back(make_task(6, 2, 3, 10.f, KernelType::COMPUTE_BOUND, 512));
    owned.push_back(make_task(7, 2, 3, 10.f, KernelType::MEMORY_BOUND, 1 << 22, 16));
    owned.push_back(make_task(8, 2, 3, 10.f, KernelType::LATENCY_SENSITIVE, 2048));
    owned[8]->dependencies = {6, 7};
    owned[8]->dep_remaining = 2;

    std::vector<Task *> tasks;
    for (auto &t: owned) tasks.push_back(t.get());

    // Workload descriptors (optional, useful for per-workload fairness metrics later)
    Workload wl0{0, "ComputeHeavy", {tasks[0], tasks[1], tasks[2]}};
    Workload wl1{1, "LatencySensitive", {tasks[3], tasks[4], tasks[5]}};
    Workload wl2{2, "Mixed_WithDeps", {tasks[6], tasks[7], tasks[8]}};

    {
        FIFOScheduler fifo;
        run_scheduler(&fifo, tasks);
        print_results(fifo.name(), tasks);
    }

    {
        PriorityScheduler prio;
        run_scheduler(&prio, tasks);
        print_results(prio.name(), tasks);
    }

    {
        DependencyAwareScheduler dep;
        dep.precompute_downstream(tasks);
        run_scheduler(&dep, tasks);
        print_results(dep.name(), tasks);
    }

    return 0;
}
