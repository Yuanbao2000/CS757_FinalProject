#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cassert>
#include <cuda_runtime.h>
#include <iomanip>
#include <iostream>

#include "task.h"
#include "scheduler.h"

extern void launch_kernel(const Task *t);

struct StreamSlot {
    cudaStream_t stream;
    Task *current_task = nullptr;
    bool available = true;
};

void notify_dependents(const Task *finished, Scheduler *sched,
                       const std::unordered_map<int, std::vector<Task *> > &dependents_map,
                       const float clock_ms,
                       std::unordered_set<Task *> &ready_to_submit,
                       std::unordered_map<Task *, float> &ready_times) {
    // O(1) lookup + iterate only actual dependents (not all tasks!)
    auto it = dependents_map.find(finished->id);
    if (it == dependents_map.end()) return; // No dependents

    for (Task *t: it->second) {
        t->dep_remaining--;
        if (t->dep_remaining == 0 && t->arrival_time_ms <= clock_ms) {
            ready_to_submit.insert(t);
            ready_times[t] = clock_ms;
        }
    }
}

void run_scheduler(Scheduler *sched, const std::vector<Task *> &all_tasks,
                   const int batch_size, float &out_stream_ms, int &out_max_concurrent) {
    // Build task ID lookup map for validation
    std::unordered_map<int, Task *> id_to_task;
    for (Task *t: all_tasks) {
        id_to_task[t->id] = t;
    }

    // Build reverse dependency map: task_id -> list of tasks that depend on it
    // This avoids O(N²) scan in notify_dependents
    std::unordered_map<int, std::vector<Task *> > dependents_map;
    for (Task *t: all_tasks) {
        for (int dep_id: t->dependencies) {
            dependents_map[dep_id].push_back(t);
        }
    }

    // Reset timing fields
    for (Task *t: all_tasks) {
        t->wait_time_ms = 0.f;
        t->exec_time_ms = 0.f;
        t->finish_time_ms = 0.f;
        t->dep_remaining = static_cast<int>(t->dependencies.size());
    }

    // Create stream pool
    std::vector<StreamSlot> stream_pool(batch_size);
    for (int i = 0; i < batch_size; i++) {
        cudaStreamCreate(&stream_pool[i].stream);
    }

    // Track per-stream busy time (sum of exec times on each stream)
    std::vector<float> stream_busy_time(batch_size, 0.0f);

    // Start wall-clock timer, this is our time=0 reference point
    auto start_time = std::chrono::high_resolution_clock::now();

    // Track when each task became READY (not arrived, but ready to schedule)
    // This is crucial for correct wait time calculation
    std::unordered_map<Task *, float> ready_times; // wall-clock time when task became ready
    std::vector<bool> submitted(all_tasks.size(), false);
    std::unordered_set<Task *> ready_to_submit;

    int max_concurrent_streams = 0;
    int tasks_completed = 0;
    out_stream_ms = 0.f;

    // Submit initial ready tasks (arrival_time_ms == 0, no dependencies)
    for (size_t i = 0; i < all_tasks.size(); i++) {
        Task *t = all_tasks[i];
        if (t->dep_remaining == 0 && t->arrival_time_ms == 0.f) {
            sched->submit(t);
            submitted[i] = true;
            ready_times[t] = 0.f; // Ready at wall-clock time 0
        }
    }

    // auto last_debug_time = std::chrono::high_resolution_clock::now();
    // int iterations_no_ready = 0;  // Scheduler queue empty
    // int iterations_all_busy = 0;  // All streams busy
    // int total_iterations = 0;

    while (tasks_completed < all_tasks.size()) {
        // Get current wall-clock time (elapsed since start_time)
        auto now = std::chrono::high_resolution_clock::now();
        float clock_ms = std::chrono::duration<float, std::milli>(now - start_time).count();

        // // Periodic debug snapshot (every 50ms)
        // auto time_since_debug = std::chrono::duration<float, std::milli>(now - last_debug_time).count();
        // if (time_since_debug > 50.0f) {
        //     // Count how many tasks are ready in the scheduler queue
        //     int queue_size = 0;
        //     // You'll need to add a size() method to your Scheduler interface
        //     // For now, just print what we know:
        //
        //     int ready_count = static_cast<int>(ready_to_submit.size());
        //     int running_count = 0;
        //     for (const auto& slot : stream_pool) {
        //         if (!slot.available) running_count++;
        //     }
        //
        //     std::cout << "[" << sched->name() << " @" << std::fixed << std::setprecision(1)
        //               << clock_ms << "ms] Running: " << running_count << "/" << batch_size
        //               << ", Ready: " << ready_count
        //               << ", Completed: " << tasks_completed << "/" << all_tasks.size() << "\n";
        //
        //     last_debug_time = now;
        // }

        // Check for newly arriving workloads
        // arrival_time_ms is a simulated offset from t=0, so we check if wall-clock >= offset
        for (size_t i = 0; i < all_tasks.size(); i++) {
            Task *t = all_tasks[i];
            if (!submitted[i] && t->dep_remaining == 0 &&
                t->arrival_time_ms > 0.f && t->arrival_time_ms <= clock_ms) {
                sched->submit(t);
                submitted[i] = true;
                ready_times[t] = t->arrival_time_ms;
            }
        }

        // Submit tasks that became ready due to dependency completion
        for (Task *t: ready_to_submit) {
            // Find index
            int idx = -1;
            for (int i = 0; i < all_tasks.size(); i++) {
                if (all_tasks[i] == t) {
                    idx = i;
                    break;
                }
            }
            // Ready time already recorded in notify_dependents
            if (idx >= 0 && !submitted[idx]) {
                submitted[idx] = true;
                sched->submit(t);
            }
        }
        ready_to_submit.clear();

        // // Count idle reasons
        // bool scheduler_empty = sched->empty();
        // bool all_slots_busy = true;
        // for (const auto &slot: stream_pool) {
        //     if (slot.available) {
        //         all_slots_busy = false;
        //         break;
        //     }
        // }
        //
        // if (scheduler_empty && !all_slots_busy) {
        //     iterations_no_ready++;  // Streams idle because no tasks ready
        // }
        // if (all_slots_busy) {
        //     iterations_all_busy++;  // All streams working
        // }

        // Launch tasks on available streams
        for (auto &slot: stream_pool) {
            if (slot.available && !sched->empty()) {
                Task *t = sched->next();

                // Get current wall-clock time for this launch
                auto launch_time = std::chrono::high_resolution_clock::now();
                float launch_ms = std::chrono::duration<float, std::milli>(launch_time - start_time).count();

                // Wait time = time from when task became READY to when it launched
                // NOT from arrival time (tasks can arrive but still be blocked by dependencies)
                t->wait_time_ms = launch_ms - ready_times[t];

                // Validate dependencies satisfied before launch
#ifndef NDEBUG
                for (int dep_id: t->dependencies) {
                    Task *dep = id_to_task.at(dep_id);
                    assert(dep->finish_time_ms > 0 && "Dependency not completed before launch");
                    assert(dep->finish_time_ms <= launch_ms && "Dependency finished after launch (time travel!)");
                }
#endif

                // Launch kernel on pool stream
                cudaEventRecord(t->start_event, slot.stream);

                t->stream = slot.stream;
                launch_kernel(t);

                cudaEventRecord(t->end_event, slot.stream);

                slot.current_task = t;
                slot.available = false;
            }
        }

        int current_running = 0;
        for (const auto& slot : stream_pool) {
            if (!slot.available) current_running++;
        }
        max_concurrent_streams = std::max(max_concurrent_streams, current_running);

        // Check for completions (non-blocking)
        int completed_this_iter = 0;
        for (int slot_idx = 0; slot_idx < stream_pool.size(); slot_idx++) {
            auto &slot = stream_pool[slot_idx];
            if (!slot.available && slot.current_task != nullptr) {
                cudaError_t status = cudaStreamQuery(slot.stream);

                if (status == cudaSuccess) {
                    Task *t = slot.current_task;

                    // Get actual GPU execution time
                    cudaEventElapsedTime(&t->exec_time_ms, t->start_event, t->end_event);

                    // Track this stream's busy time
                    stream_busy_time[slot_idx] += t->exec_time_ms;

                    // Record finish time (wall-clock)
                    auto finish_time = std::chrono::high_resolution_clock::now();
                    t->finish_time_ms = std::chrono::duration<float, std::milli>(finish_time - start_time).count();

                    tasks_completed++;
                    completed_this_iter++;

                    // Notify dependent tasks (they may become ready)
                    notify_dependents(t, sched, dependents_map, t->finish_time_ms, ready_to_submit, ready_times);

                    // Free the slot
                    slot.current_task = nullptr;
                    slot.available = true;
                } else if (status != cudaErrorNotReady) {
                    cudaGetLastError(); // Clear error
                }
            }
        }

        // Adaptive polling: sleep if nothing to do
        if (completed_this_iter == 0) {
            bool all_busy = true;
            for (const auto &slot: stream_pool) {
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

    // Validate all tasks completed
    assert(tasks_completed == all_tasks.size() && "Not all tasks completed");

    // Calculate makespan for utilization metrics
    float makespan = 0.f;
    for (const Task *t: all_tasks) {
        makespan = std::max(makespan, t->finish_time_ms);
    }

    // For percentage: util = sum(exec) / (makespan * batch_size) gives 0-1 fraction
    // e.g., 0.85 = 85% of available stream-time was used
    out_stream_ms = makespan * static_cast<float>(batch_size);
    out_max_concurrent = max_concurrent_streams;

    // Cleanup
    for (auto &slot: stream_pool) {
        cudaStreamDestroy(slot.stream);
    }
}
