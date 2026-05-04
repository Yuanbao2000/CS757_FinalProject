#include <vector>
#include <unordered_set>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cuda_runtime.h>
#include "task.h"
#include "scheduler.h"

extern void launch_kernel(const Task *t);

void notify_dependents_concurrent(const Task *finished, Scheduler *sched,
                                  const std::vector<Task *> &all_tasks,
                                  const float clock_ms,
                                  std::unordered_set<Task *> &ready_to_submit) {
    for (Task *t: all_tasks) {
        for (const int dep_id: t->dependencies) {
            if (dep_id == finished->id) {
                t->dep_remaining--;
                // mark as ready if dependencies satisfied and arrival time has passed
                if (t->dep_remaining == 0 && t->arrival_time_ms <= clock_ms) {
                    ready_to_submit.insert(t);
                }
            }
        }
    }
}

void run_scheduler_concurrent(Scheduler *sched, const std::vector<Task *> &all_tasks,
                              const int max_concurrent, float &out_stream_ms) {
    // reset timing fields
    for (Task *t: all_tasks) {
        t->wait_time_ms = 0.f;
        t->exec_time_ms = 0.f;
        t->finish_time_ms = 0.f;
        t->dep_remaining = static_cast<int>(t->dependencies.size());
    }

    // find max arrival time
    float max_arrival = 0.f;
    for (const Task *t: all_tasks)
        max_arrival = std::max(max_arrival, t->arrival_time_ms);

    // submit initial ready tasks (arrival_time_ms == 0)
    for (Task *t: all_tasks)
        if (t->dep_remaining == 0 && t->arrival_time_ms == 0.f)
            sched->submit(t);

    std::unordered_set<Task *> in_flight; // tasks currently executing on GPU
    std::unordered_set<Task *> ready_to_submit; // tasks whose dependencies just completed
    int tasks_completed = 0;

    // use high-resolution timer for wall-clock time
    auto start_time = std::chrono::high_resolution_clock::now();
    float clock_ms = 0.f;
    out_stream_ms = 0.f;

    while (tasks_completed < all_tasks.size()) {
        // update clock to current wall time
        auto now = std::chrono::high_resolution_clock::now();
        clock_ms = std::chrono::duration<float, std::milli>(now - start_time).count();

        // check for newly arriving workloads
        for (Task *t: all_tasks) {
            if (t->dep_remaining == 0 && t->arrival_time_ms > 0.f &&
                t->arrival_time_ms <= clock_ms && t->wait_time_ms == 0.f) {
                sched->submit(t);
            }
        }

        // submit any tasks that became ready due to dependency completion
        for (Task *t: ready_to_submit) {
            sched->submit(t);
        }
        ready_to_submit.clear();

        // launch new tasks up to concurrency limit
        while (!sched->empty() && in_flight.size() < max_concurrent) {
            Task *t = sched->next();
            t->wait_time_ms = clock_ms - t->arrival_time_ms;

            cudaEventRecord(t->start_event, t->stream);
            launch_kernel(t);
            cudaEventRecord(t->end_event, t->stream);

            in_flight.insert(t);
        }

        // poll for completed tasks (non-blocking)
        std::vector<Task *> completed;
        for (Task *t: in_flight) {
            cudaError_t status = cudaEventQuery(t->end_event);
            if (status == cudaSuccess) {
                // task completed
                cudaEventElapsedTime(&t->exec_time_ms, t->start_event, t->end_event);
                t->finish_time_ms = clock_ms;
                completed.push_back(t);

                // accumulate stream-time for utilization calculation
                out_stream_ms += t->exec_time_ms;
            } else if (status != cudaErrorNotReady) {
                // actual error (not just "not ready yet")
                cudaGetLastError(); // clear error
            }
        }

        // process completed tasks
        for (Task *t: completed) {
            in_flight.erase(t);
            tasks_completed++;
            notify_dependents_concurrent(t, sched, all_tasks, clock_ms, ready_to_submit);
        }

        // if nothing is in flight and nothing is ready, advance clock to next arrival
        if (in_flight.empty() && sched->empty() && ready_to_submit.empty()) {
            if (tasks_completed < all_tasks.size()) {
                float next_arrival = max_arrival + 1.0f;
                for (Task *t: all_tasks) {
                    if (t->dep_remaining == 0 && t->wait_time_ms == 0.f && t->arrival_time_ms > clock_ms) {
                        next_arrival = std::min(next_arrival, t->arrival_time_ms);
                    }
                }
                if (next_arrival <= max_arrival) {
                    // sleep until next arrival to avoid busy-waiting
                    auto sleep_duration = std::chrono::duration<float, std::milli>(next_arrival - clock_ms);
                    std::this_thread::sleep_for(sleep_duration);
                }
            }
        }

        // small yield to avoid busy-wait spinning
        if (!in_flight.empty()) {
            std::this_thread::yield();
        }
    }

    // final sync to ensure all CUDA operations complete
    cudaDeviceSynchronize();
}
