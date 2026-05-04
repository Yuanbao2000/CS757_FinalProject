#include <vector>
#include <cuda_runtime.h>
#include "task.h"
#include "scheduler.h"

extern void launch_kernel(const Task *t);

void notify_dependents(const Task *finished, Scheduler *sched,
                       const std::vector<Task *> &all_tasks, const float clock_ms) {
    for (Task *t: all_tasks) {
        for (const int dep_id: t->dependencies) {
            if (dep_id == finished->id) {
                t->dep_remaining--;
                // only submit if dependencies satisfied and arrival time has passed
                if (t->dep_remaining == 0 && t->arrival_time_ms <= clock_ms)
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

    // find max arrival time to know when all workloads have arrived
    float max_arrival = 0.f;
    for (const Task *t: all_tasks)
        max_arrival = std::max(max_arrival, t->arrival_time_ms);

    // submit ready tasks that have arrived (arrival_time_ms == 0)
    for (Task *t: all_tasks)
        if (t->dep_remaining == 0 && t->arrival_time_ms == 0.f)
            sched->submit(t);

    float clock_ms = 0.f;
    out_stream_ms = 0.f;
    int tasks_completed = 0;
    while (tasks_completed < all_tasks.size()) {
        // also check if future arrivals pending
        // check for newly arriving workloads
        for (Task *t: all_tasks)
            if (t->dep_remaining == 0 && t->arrival_time_ms > 0.f &&
                t->arrival_time_ms <= clock_ms && t->wait_time_ms == 0.f)
                sched->submit(t);

        // dequeue till hitting batch_size ready tasks
        std::vector<Task *> batch;
        while (!sched->empty() && batch.size() < batch_size)
            batch.push_back(sched->next());

        // if no tasks ready yet, advance clock to next arrival
        if (batch.empty()) {
            float next_arrival = max_arrival + 1.0f;
            for (Task *t: all_tasks)
                if (t->dep_remaining == 0 && t->wait_time_ms == 0.f && t->arrival_time_ms > clock_ms)
                    next_arrival = std::min(next_arrival, t->arrival_time_ms);
            if (next_arrival <= max_arrival) {
                clock_ms = next_arrival;
                continue;
            } else {
                break; // no more arrivals
            }
        }

        tasks_completed += static_cast<int>(batch.size());


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
            notify_dependents(t, sched, all_tasks, clock_ms);
    }
}
