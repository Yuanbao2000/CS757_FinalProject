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
    const auto default_file = "benchmark/c17.ckt";
    constexpr int default_batch_size = 512;
    const std::string ckt_path = (argc >= 2) ? argv[1] : default_file;
    const int batch_size = (argc >= 3) ? std::atoi(argv[2]) : default_batch_size;

    std::cout << "Circuit: " << ckt_path << "\n";
    std::cout << "Batch  : " << batch_size << "\n\n";
    cuda_warmup();

    const Circuit circuit = parse_ckt(ckt_path);
    const auto owned = circuit_to_tasks(circuit);

    std::vector<Task *> tasks;
    for (auto &t: owned) tasks.push_back(t.get());

    std::vector<Metrics> all_metrics;
    auto run_and_report = [&](Scheduler *sched) {
        cuda_warmup();
        float stream_ms = 0.f;
        run_scheduler(sched, tasks, batch_size, stream_ms);
        const auto m = compute_metrics(sched->name(), tasks, stream_ms);
        print_metrics(m);
        all_metrics.push_back(m);
    };

    {
        FIFOScheduler fifo;
        run_and_report(&fifo);
    }
    {
        PriorityScheduler prio;
        run_and_report(&prio);
    }
    {
        DependencyAwareScheduler dep;
        dep.precompute_downstream(tasks);
        run_and_report(&dep);
    }

    write_report(all_metrics, ckt_path, batch_size);

    return 0;
}
