#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <thread>
#include <cuda_runtime.h>
#include "task.h"
#include "scheduler.h"

extern void launch_kernel(const Task *t);

void notify_dependents(const Task *finished, Scheduler *sched,
                       const std::vector<Task *> &all_tasks, const float clock_ms,
                       std::unordered_map<Task *, float> &ready_times,
                       std::unordered_set<Task *> &submitted) {
    for (Task *t: all_tasks) {
        for (const int dep_id: t->dependencies) {
            if (dep_id == finished->id) {
                t->dep_remaining--;
                // only submit if dependencies satisfied and arrival time has passed
                if (t->dep_remaining == 0 && t->arrival_time_ms <= clock_ms) {
                    // Track when task became ready
                    ready_times[t] = clock_ms;
                    submitted.insert(t);
                    sched->submit(t);
                }
            }
        }
    }
}

void run_scheduler(Scheduler *sched, const std::vector<Task *> &all_tasks,
                   const int batch_size, float &out_stream_ms) {
    // Reset timing fields
    for (Task *t: all_tasks) {
        t->wait_time_ms = 0.f;
        t->exec_time_ms = 0.f;
        t->finish_time_ms = 0.f;
        t->dep_remaining = static_cast<int>(t->dependencies.size());
    }

    // Start wall-clock timer
    auto start_time = std::chrono::high_resolution_clock::now();

    // Track when each task became ready (not just arrived)
    std::unordered_map<Task *, float> ready_times;
    std::unordered_set<Task *> submitted;

    // Submit ready tasks that arrive at t=0
    for (size_t i = 0; i < all_tasks.size(); i++) {
        Task *t = all_tasks[i];
        if (t->dep_remaining == 0 && t->arrival_time_ms == 0.f) {
            sched->submit(t);
            submitted.insert(t);
            ready_times[t] = 0.f; // Ready at wall-clock time 0
        }
    }

    out_stream_ms = 0.f;
    int tasks_completed = 0;

    while (tasks_completed < all_tasks.size()) {
        // Get current wall-clock time
        auto now = std::chrono::high_resolution_clock::now();
        float clock_ms = std::chrono::duration<float, std::milli>(now - start_time).count();

        // Check for newly arriving workloads
        for (size_t i = 0; i < all_tasks.size(); i++) {
            Task *t = all_tasks[i];
            if (!submitted.count(t) && t->dep_remaining == 0 &&
                t->arrival_time_ms > 0.f && t->arrival_time_ms <= clock_ms) {
                sched->submit(t);
                submitted.insert(t);
                ready_times[t] = clock_ms; // Became ready NOW
            }
        }

        // Dequeue batch
        std::vector<Task *> batch;
        while (!sched->empty() && batch.size() < batch_size)
            batch.push_back(sched->next());

        // If no tasks ready, check if we need to wait for arrivals
        if (batch.empty()) {
            float next_arrival = -1.f;
            for (size_t i = 0; i < all_tasks.size(); i++) {
                Task *t = all_tasks[i];
                if (!submitted.count(t) && t->dep_remaining == 0 && t->arrival_time_ms > clock_ms) {
                    if (next_arrival < 0.f || t->arrival_time_ms < next_arrival)
                        next_arrival = t->arrival_time_ms;
                }
            }

            if (next_arrival > 0.f) {
                // Sleep until next arrival
                float sleep_ms = next_arrival - clock_ms;
                if (sleep_ms > 0.f)
                    std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(sleep_ms));
                continue;
            } else {
                break; // No more tasks
            }
        }

        // Record batch launch time
        auto batch_start_time = std::chrono::high_resolution_clock::now();
        float batch_start_ms = std::chrono::duration<float, std::milli>(batch_start_time - start_time).count();

        // Launch all tasks in the batch
        for (Task *t: batch) {
            // Wait time = time from when task became READY to launch
            t->wait_time_ms = batch_start_ms - ready_times[t];

            cudaEventRecord(t->start_event, t->stream);
            launch_kernel(t);
            cudaEventRecord(t->end_event, t->stream);
        }

        // Sync all streams in the batch
        float batch_max_exec = 0.f;
        for (Task *t: batch) {
            cudaEventSynchronize(t->end_event);
            cudaEventElapsedTime(&t->exec_time_ms, t->start_event, t->end_event);

            // Track max execution time in this batch
            batch_max_exec = std::max(batch_max_exec, t->exec_time_ms);

            // Finish time in real wall-clock
            auto finish_time = std::chrono::high_resolution_clock::now();
            t->finish_time_ms = std::chrono::duration<float, std::milli>(finish_time - start_time).count();
        }

        // Accumulate GPU execution time
        // (We'll calculate available stream-time at the end)
        for (Task *t: batch) {
            out_stream_ms += t->exec_time_ms;
        }

        tasks_completed += static_cast<int>(batch.size());

        // Update dependents with completed tasks
        auto dep_check_time = std::chrono::high_resolution_clock::now();
        float dep_clock_ms = std::chrono::duration<float, std::milli>(dep_check_time - start_time).count();
        for (const Task *t: batch)
            notify_dependents(t, sched, all_tasks, dep_clock_ms, ready_times, submitted); // Pass ready_times
    }

    // Calculate total available stream-time
    // Sequential mode: batch_size concurrent streams active throughout execution
    float makespan = 0.f;
    for (const Task *t: all_tasks) {
        makespan = std::max(makespan, t->finish_time_ms);
    }
    out_stream_ms = makespan * static_cast<float>(batch_size);
}
