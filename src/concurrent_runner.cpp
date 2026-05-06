#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cuda_runtime.h>
#include "task.h"
#include "scheduler.h"

extern void launch_kernel(const Task *t);

struct StreamSlot {
    cudaStream_t stream;
    Task *current_task = nullptr;
    bool available = true;
};

void notify_dependents_concurrent(const Task *finished, Scheduler *sched,
                                  const std::vector<Task *> &all_tasks,
                                  const float clock_ms,
                                  std::unordered_set<Task *> &ready_to_submit) {
    for (Task *t: all_tasks) {
        for (const int dep_id: t->dependencies) {
            if (dep_id == finished->id) {
                t->dep_remaining--;
                if (t->dep_remaining == 0 && t->arrival_time_ms <= clock_ms) {
                    ready_to_submit.insert(t);
                }
            }
        }
    }
}

void run_scheduler_concurrent(Scheduler *sched, const std::vector<Task *> &all_tasks,
                              const int max_concurrent, float &out_stream_ms) {
    // Reset timing fields
    for (Task *t: all_tasks) {
        t->wait_time_ms = 0.f;
        t->exec_time_ms = 0.f;
        t->finish_time_ms = 0.f;
        t->dep_remaining = static_cast<int>(t->dependencies.size());
    }

    // Create stream pool
    std::vector<StreamSlot> stream_pool(max_concurrent);
    for (int i = 0; i < max_concurrent; i++) {
        cudaStreamCreate(&stream_pool[i].stream);
    }

    // Start wall-clock timer, this is our time=0 reference point
    auto start_time = std::chrono::high_resolution_clock::now();

    // Track when each task became READY (not arrived, but ready to schedule)
    // This is crucial for correct wait time calculation
    std::unordered_map<Task*, float> ready_times;  // wall-clock time when task became ready
    std::vector<bool> submitted(all_tasks.size(), false);
    std::unordered_set<Task *> ready_to_submit;

    int tasks_completed = 0;
    out_stream_ms = 0.f;

    // Submit initial ready tasks (arrival_time_ms == 0, no dependencies)
    for (size_t i = 0; i < all_tasks.size(); i++) {
        Task *t = all_tasks[i];
        if (t->dep_remaining == 0 && t->arrival_time_ms == 0.f) {
            sched->submit(t);
            submitted[i] = true;
            ready_times[t] = 0.f;  // Ready at wall-clock time 0
        }
    }

    while (tasks_completed < all_tasks.size()) {
        // Get current wall-clock time (elapsed since start_time)
        auto now = std::chrono::high_resolution_clock::now();
        float clock_ms = std::chrono::duration<float, std::milli>(now - start_time).count();

        // Check for newly arriving workloads
        // arrival_time_ms is a simulated offset from t=0, so we check if wall-clock >= offset
        for (size_t i = 0; i < all_tasks.size(); i++) {
            Task *t = all_tasks[i];
            if (!submitted[i] && t->dep_remaining == 0 &&
                t->arrival_time_ms > 0.f && t->arrival_time_ms <= clock_ms) {
                sched->submit(t);
                submitted[i] = true;
                ready_times[t] = clock_ms;  // Became ready NOW (at current wall-clock)
            }
        }

        // Submit tasks that became ready due to dependency completion
        for (Task *t: ready_to_submit) {
            // Re-get time in case loop took a while
            auto ready_now = std::chrono::high_resolution_clock::now();
            float ready_ms = std::chrono::duration<float, std::milli>(ready_now - start_time).count();
            ready_times[t] = ready_ms;
            // Mark submitted so the arrival-time loop won't re-submit it
            for (size_t i = 0; i < all_tasks.size(); i++) {
                if (all_tasks[i] == t) { submitted[i] = true; break; }
            }
            sched->submit(t);
        }
        ready_to_submit.clear();

        // Launch tasks on available streams
        for (auto &slot : stream_pool) {
            if (slot.available && !sched->empty()) {
                Task *t = sched->next();

                // Get current wall-clock time for this launch
                auto launch_time = std::chrono::high_resolution_clock::now();
                float launch_ms = std::chrono::duration<float, std::milli>(launch_time - start_time).count();

                // Wait time = time from when task became READY to when it launched
                // NOT from arrival time (tasks can arrive but still be blocked by dependencies)
                t->wait_time_ms = launch_ms - ready_times[t];

                // Launch kernel on pool stream
                cudaEventRecord(t->start_event, slot.stream);

                cudaStream_t orig_stream = t->stream;
                t->stream = slot.stream;
                launch_kernel(t);
                t->stream = orig_stream;

                cudaEventRecord(t->end_event, slot.stream);

                slot.current_task = t;
                slot.available = false;
            }
        }

        // Check for completions (non-blocking)
        int completed_this_iter = 0;
        for (auto &slot : stream_pool) {
            if (!slot.available && slot.current_task != nullptr) {
                cudaError_t status = cudaStreamQuery(slot.stream);

                if (status == cudaSuccess) {
                    Task *t = slot.current_task;

                    // Get actual GPU execution time
                    cudaEventElapsedTime(&t->exec_time_ms, t->start_event, t->end_event);

                    // Record finish time (wall-clock)
                    auto finish_time = std::chrono::high_resolution_clock::now();
                    t->finish_time_ms = std::chrono::duration<float, std::milli>(finish_time - start_time).count();

                    tasks_completed++;
                    completed_this_iter++;

                    // Notify dependent tasks (they may become ready)
                    notify_dependents_concurrent(t, sched, all_tasks, t->finish_time_ms, ready_to_submit);

                    // Free the slot
                    slot.current_task = nullptr;
                    slot.available = true;

                } else if (status != cudaErrorNotReady) {
                    cudaGetLastError();  // Clear error
                }
            }
        }

        // Adaptive polling: sleep if nothing to do
        if (completed_this_iter == 0) {
            bool all_busy = true;
            for (const auto &slot : stream_pool) {
                if (slot.available) {
                    all_busy = false;
                    break;
                }
            }

            // Check if waiting for future arrivals
            bool waiting_for_arrival = false;
            if (sched->empty() && !all_busy) {
                auto check_time = std::chrono::high_resolution_clock::now();
                float check_ms = std::chrono::duration<float, std::milli>(check_time - start_time).count();
                for (size_t i = 0; i < all_tasks.size(); i++) {
                    Task *t = all_tasks[i];
                    if (!submitted[i] && t->dep_remaining == 0 && t->arrival_time_ms > check_ms) {
                        waiting_for_arrival = true;
                        break;
                    }
                }
            }

            if (all_busy || waiting_for_arrival) {
                std::this_thread::sleep_for(std::chrono::microseconds(50));
            }
        }
    }

    // Final sync
    cudaDeviceSynchronize();

    // Calculate total available stream-time
    // For concurrent mode with stream pooling:
    // We have max_concurrent streams available throughout the entire run
    // So available stream-time = makespan × max_concurrent
    float makespan = 0.f;
    for (const Task *t : all_tasks) {
        makespan = std::max(makespan, t->finish_time_ms);
    }
    out_stream_ms = makespan * static_cast<float>(max_concurrent);

    // Cleanup
    for (auto &slot : stream_pool) {
        cudaStreamDestroy(slot.stream);
    }
}