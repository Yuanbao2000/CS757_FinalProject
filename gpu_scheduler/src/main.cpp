#include <iostream>
#include <vector>
#include <cuda_runtime.h>

#include "task.h"
#include "fifo_scheduler.hpp"
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
    // Seed with tasks that are immediately ready (no dependencies)
    for (Task *t: all_tasks)
        if (t->dep_remaining == 0)
            sched->submit(t);

    float clock_ms = 0.f;

    while (!sched->empty()) {
        Task *t = sched->next();

        // Task had to wait until GPU was free
        t->wait_time_ms = clock_ms - t->arrival_time_ms;

        cudaEventRecord(t->start_event, t->stream);
        launch_kernel(t);
        cudaEventRecord(t->end_event, t->stream);

        // Block CPU until kernel finishes — this enforces non-preemption
        cudaEventSynchronize(t->end_event);

        cudaEventElapsedTime(&t->exec_time_ms, t->start_event, t->end_event);
        t->finish_time_ms = clock_ms + t->exec_time_ms;
        clock_ms = t->finish_time_ms;

        notify_dependents(t, sched, all_tasks);
    }
}

Task *make_task(int id, int workload_id, int priority,
                float arrival_ms, KernelType type) {
    Task *t = new Task();
    t->id = id;
    t->workload_id = workload_id;
    t->priority = priority;
    t->arrival_time_ms = arrival_ms;
    t->type = type;
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
    std::cout << "ID  WL  Type              Wait(ms)  Exec(ms)  Finish(ms)\n";
    std::cout << "-------------------------------------------------------\n";

    float total_wait = 0, total_exec = 0;
    for (Task *t: tasks) {
        const char *type_str =
                t->type == KernelType::COMPUTE_BOUND
                    ? "COMPUTE_BOUND    "
                    : t->type == KernelType::MEMORY_BOUND
                          ? "MEMORY_BOUND     "
                          : "LATENCY_SENSITIVE";
        std::printf("%2d  %2d  %s  %8.3f  %8.3f  %10.3f\n",
                    t->id, t->workload_id, type_str,
                    t->wait_time_ms, t->exec_time_ms, t->finish_time_ms);
        total_wait += t->wait_time_ms;
        total_exec += t->exec_time_ms;
    }
    std::printf("\nAvg wait: %.3f ms | Avg exec: %.3f ms | "
                "GPU util: %.1f%%\n",
                total_wait / static_cast<float>(tasks.size()),
                total_exec / static_cast<float>(tasks.size()),
                100.f * total_exec / (total_wait + total_exec));
}

int main() {
    // Build simple test workload: 2 workloads, 3 tasks each
    const std::vector tasks = {
        // Workload 0: compute heavy
        make_task(0, 0, 1, 0.f, KernelType::COMPUTE_BOUND),
        make_task(1, 0, 1, 0.f, KernelType::COMPUTE_BOUND),
        make_task(2, 0, 1, 0.f, KernelType::MEMORY_BOUND),

        // Workload 1: latency sensitive
        make_task(3, 1, 2, 5.f, KernelType::LATENCY_SENSITIVE),
        make_task(4, 1, 2, 5.f, KernelType::LATENCY_SENSITIVE),
        make_task(5, 1, 2, 5.f, KernelType::LATENCY_SENSITIVE),
    };

    // tunable params
    tasks[0]->param_N = 1024;
    tasks[1]->param_N = 1024;
    tasks[2]->param_N = 1 << 24;
    tasks[2]->param_stride = 32;
    tasks[3]->param_N = 1024;
    tasks[4]->param_N = 1024;
    tasks[5]->param_N = 1024;

    FIFOScheduler fifo;
    run_scheduler(&fifo, tasks);
    print_results("FIFO", tasks);

    for (Task *t: tasks) free_task(t);
    return 0;
}
