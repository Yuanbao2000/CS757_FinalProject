#include <vector>
#include <memory>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <algorithm>
#include <cuda_runtime.h>

#include "task.h"
#include "metrics.h"
#include "scheduler.h"
#include "circuit_parser.h"
#include "gate_batch_executor.h"
#include "fifo_scheduler.hpp"
#include "priority_scheduler.hpp"
#include "dependency_aware_scheduler.hpp"
#include "sjf_scheduler.hpp"

struct RunAccounting {
    float gpu_busy_ms = 0.f;
    float makespan_ms = 0.f;
};

const std::vector<int> FUSED_LEVEL_GATE_LIMITS = {256, 1024, 2048};

// init CUDA context
void cuda_warmup() {
    float *d;
    cudaMalloc(reinterpret_cast<void **>(&d), sizeof(float));
    cudaFree(d);
    cudaDeviceSynchronize();
}

Circuit merge_circuits(const std::vector<Circuit> &circuits) {
    Circuit merged{};
    merged.num_PIs = 0;
    merged.num_POs = 0;
    merged.num_inner_gates = 0;
    merged.num_wires = 0;
    merged.total_gates = 0;

    for (const Circuit &c: circuits) {
        merged.num_PIs += c.num_PIs;
        merged.num_POs += c.num_POs;
        merged.num_inner_gates += c.num_inner_gates;
        merged.num_wires += c.num_wires;
        merged.total_gates += c.total_gates;
    }

    merged.adj.resize(merged.total_gates);
    merged.invAdj.resize(merged.total_gates);
    merged.gate_type.resize(merged.total_gates);
    merged.gate_num_inputs.resize(merged.total_gates);

    int offset = 0;
    for (const Circuit &c: circuits) {
        for (int i = 0; i < c.total_gates; i++) {
            for (const int succ: c.adj[i])
                merged.adj[i + offset].push_back(succ + offset);
            for (const int pred: c.invAdj[i])
                merged.invAdj[i + offset].push_back(pred + offset);
            merged.gate_type[i + offset] = c.gate_type[i];
            merged.gate_num_inputs[i + offset] = c.gate_num_inputs[i];
        }
        offset += c.total_gates;
    }

    return merged;
}

void notify_dependents(const Task *finished, Scheduler *sched,
                       const std::vector<Task *> &all_tasks, const float ready_time_ms) {
    for (Task *t: all_tasks) {
        for (const int dep_id: t->dependencies) {
            if (dep_id == finished->id) {
                t->dep_remaining--;
                if (t->dep_remaining == 0) {
                    t->arrival_time_ms = ready_time_ms;
                    sched->submit(t);
                }
            }
        }
    }
}

float merged_interval_duration_ms(std::vector<std::pair<float, float> > intervals) {
    if (intervals.empty())
        return 0.f;

    std::sort(intervals.begin(), intervals.end(),
              [](const auto &a, const auto &b) { return a.first < b.first; });

    float total = 0.f;
    float cur_start = intervals[0].first;
    float cur_end = intervals[0].second;
    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i].first <= cur_end) {
            cur_end = std::max(cur_end, intervals[i].second);
        } else {
            total += cur_end - cur_start;
            cur_start = intervals[i].first;
            cur_end = intervals[i].second;
        }
    }
    total += cur_end - cur_start;
    return total;
}

void run_scheduler(Scheduler *sched, const std::vector<Task *> &all_tasks,
                   const int batch_size, GateBatchExecutor &executor, RunAccounting &run) {
    // reset timing fields in case re-running the same tasks
    for (Task *t: all_tasks) {
        t->arrival_time_ms = 0.f;
        t->wait_time_ms = 0.f;
        t->exec_time_ms = 0.f;
        t->finish_time_ms = 0.f;
        t->dep_remaining = static_cast<int>(t->dependencies.size());
    }

    // submit ready tasks
    for (Task *t: all_tasks)
        if (t->dep_remaining == 0)
            sched->submit(t);

    cudaStream_t batch_stream = nullptr;
    cudaEvent_t batch_start_event = nullptr;
    cudaEvent_t batch_end_event = nullptr;
    cudaStreamCreate(&batch_stream);
    cudaEventCreate(&batch_start_event);
    cudaEventCreate(&batch_end_event);
    reset_gate_batch_executor(executor, batch_stream);
    cudaStreamSynchronize(batch_stream);

    const auto wall_start = std::chrono::steady_clock::now();
    const auto now_ms = [&]() -> float {
        return std::chrono::duration<float, std::milli>(
            std::chrono::steady_clock::now() - wall_start
        ).count();
    };
    std::vector<std::pair<float, float> > gpu_intervals;

    run.gpu_busy_ms = 0.f;
    run.makespan_ms = 0.f;
    while (!sched->empty()) {
        // dequeue till hitting batch_size ready tasks
        std::vector<Task *> batch;
        while (!sched->empty() && batch.size() < batch_size)
            batch.push_back(sched->next());


        // launch all tasks in the batch
        for (Task *t: batch) {
            t->wait_time_ms = 0.f;
        }

        const float host_launch_ms = now_ms();
        for (Task *t: batch)
            t->wait_time_ms = host_launch_ms - t->arrival_time_ms;
        cudaEventRecord(batch_start_event, batch_stream);
        launch_gate_batch(batch_stream, executor, batch);
        cudaEventRecord(batch_end_event, batch_stream);

        // sync the unified gate-batch kernel and assign one host-side service interval to all gates in the batch
        cudaEventSynchronize(batch_end_event);
        const float host_finish_ms = now_ms();
        const float batch_service_ms = host_finish_ms - host_launch_ms;
        for (Task *t: batch) {
            t->exec_time_ms = batch_service_ms;
            t->finish_time_ms = host_finish_ms;
        }
        gpu_intervals.emplace_back(host_launch_ms, host_finish_ms);

        // update dependents with completed tasks
        for (const Task *t: batch)
            notify_dependents(t, sched, all_tasks, host_finish_ms);
    }

    cudaEventDestroy(batch_start_event);
    cudaEventDestroy(batch_end_event);
    cudaStreamDestroy(batch_stream);
    run.makespan_ms = now_ms();
    run.gpu_busy_ms = merged_interval_duration_ms(gpu_intervals);
}

struct InFlightSlot {
    cudaStream_t stream = nullptr;
    cudaEvent_t start_event = nullptr;
    cudaEvent_t end_event = nullptr;
    std::vector<Task *> batch;
    float launch_time_ms = 0.f;
    bool busy = false;
};

void run_scheduler_nonblocking(Scheduler *sched, const std::vector<Task *> &all_tasks,
                               const int batch_size, GateBatchExecutor &executor, RunAccounting &run) {
    for (Task *t: all_tasks) {
        t->arrival_time_ms = 0.f;
        t->wait_time_ms = 0.f;
        t->exec_time_ms = 0.f;
        t->finish_time_ms = 0.f;
        t->dep_remaining = static_cast<int>(t->dependencies.size());
    }

    for (Task *t: all_tasks)
        if (t->dep_remaining == 0)
            sched->submit(t);

    cudaStream_t reset_stream = nullptr;
    cudaStreamCreate(&reset_stream);
    reset_gate_batch_executor(executor, reset_stream);
    cudaStreamSynchronize(reset_stream);
    cudaStreamDestroy(reset_stream);

    constexpr int STREAM_COUNT = 4;
    const int stream_count = STREAM_COUNT;
    std::vector<InFlightSlot> slots(stream_count);
    for (InFlightSlot &slot: slots) {
        cudaStreamCreate(&slot.stream);
        cudaEventCreate(&slot.start_event);
        cudaEventCreate(&slot.end_event);
    }

    const auto wall_start = std::chrono::steady_clock::now();
    const auto now_ms = [&]() -> float {
        return std::chrono::duration<float, std::milli>(
            std::chrono::steady_clock::now() - wall_start
        ).count();
    };

    std::vector<std::pair<float, float> > gpu_intervals;
    run.gpu_busy_ms = 0.f;
    run.makespan_ms = 0.f;
    int inflight_count = 0;

    while (!sched->empty() || inflight_count > 0) {
        bool made_progress = false;

        for (InFlightSlot &slot: slots) {
            if (sched->empty() || slot.busy)
                continue;

            const float launch_time_ms = now_ms();
            while (!sched->empty() && slot.batch.size() < static_cast<size_t>(std::max(1, batch_size))) {
                Task *task = sched->next();
                task->wait_time_ms = launch_time_ms - task->arrival_time_ms;
                slot.batch.push_back(task);
            }
            if (slot.batch.empty())
                continue;
            slot.busy = true;
            slot.launch_time_ms = launch_time_ms;

            cudaEventRecord(slot.start_event, slot.stream);
            launch_gate_batch(slot.stream, executor, slot.batch);
            cudaEventRecord(slot.end_event, slot.stream);
            inflight_count++;
            made_progress = true;
        }

        for (InFlightSlot &slot: slots) {
            if (!slot.busy)
                continue;

            const cudaError_t status = cudaEventQuery(slot.end_event);
            if (status == cudaSuccess) {
                const float finish_time_ms = now_ms();
                gpu_intervals.emplace_back(slot.launch_time_ms, finish_time_ms);
                const float batch_service_ms = finish_time_ms - slot.launch_time_ms;
                for (Task *task: slot.batch) {
                    task->exec_time_ms = batch_service_ms;
                    task->finish_time_ms = finish_time_ms;
                    notify_dependents(task, sched, all_tasks, finish_time_ms);
                }

                slot.batch.clear();
                slot.busy = false;
                inflight_count--;
                made_progress = true;
            }
        }

        if (!made_progress && inflight_count > 0) {
            for (InFlightSlot &slot: slots) {
                if (!slot.busy)
                    continue;
                cudaEventSynchronize(slot.end_event);
                break;
            }
        }
    }

    for (InFlightSlot &slot: slots) {
        cudaEventDestroy(slot.start_event);
        cudaEventDestroy(slot.end_event);
        cudaStreamDestroy(slot.stream);
    }
    run.makespan_ms = now_ms();
    run.gpu_busy_ms = merged_interval_duration_ms(gpu_intervals);
}

struct SingleGateInFlightSlot {
    cudaStream_t stream = nullptr;
    cudaEvent_t start_event = nullptr;
    cudaEvent_t end_event = nullptr;
    Task *task = nullptr;
    float launch_time_ms = 0.f;
    bool busy = false;
};

void run_scheduler_single_gate_nonblocking(Scheduler *sched, const std::vector<Task *> &all_tasks,
                                           GateBatchExecutor &executor, RunAccounting &run) {
    for (Task *t: all_tasks) {
        t->arrival_time_ms = 0.f;
        t->wait_time_ms = 0.f;
        t->exec_time_ms = 0.f;
        t->finish_time_ms = 0.f;
        t->dep_remaining = static_cast<int>(t->dependencies.size());
    }

    for (Task *t: all_tasks)
        if (t->dep_remaining == 0)
            sched->submit(t);

    cudaStream_t reset_stream = nullptr;
    cudaStreamCreate(&reset_stream);
    reset_gate_batch_executor(executor, reset_stream);
    cudaStreamSynchronize(reset_stream);
    cudaStreamDestroy(reset_stream);

    constexpr int STREAM_COUNT = 4;
    std::vector<SingleGateInFlightSlot> slots(STREAM_COUNT);
    for (SingleGateInFlightSlot &slot: slots) {
        cudaStreamCreate(&slot.stream);
        cudaEventCreate(&slot.start_event);
        cudaEventCreate(&slot.end_event);
    }

    const auto wall_start = std::chrono::steady_clock::now();
    const auto now_ms = [&]() -> float {
        return std::chrono::duration<float, std::milli>(
            std::chrono::steady_clock::now() - wall_start
        ).count();
    };

    std::vector<std::pair<float, float> > gpu_intervals;
    run.gpu_busy_ms = 0.f;
    run.makespan_ms = 0.f;
    int inflight_count = 0;

    while (!sched->empty() || inflight_count > 0) {
        bool made_progress = false;

        for (SingleGateInFlightSlot &slot: slots) {
            if (sched->empty() || slot.busy)
                continue;

            Task *task = sched->next();
            const float launch_time_ms = now_ms();
            task->wait_time_ms = launch_time_ms - task->arrival_time_ms;
            slot.task = task;
            slot.launch_time_ms = launch_time_ms;
            slot.busy = true;

            cudaEventRecord(slot.start_event, slot.stream);
            launch_single_gate(slot.stream, executor, task);
            cudaEventRecord(slot.end_event, slot.stream);
            inflight_count++;
            made_progress = true;
        }

        for (SingleGateInFlightSlot &slot: slots) {
            if (!slot.busy)
                continue;

            const cudaError_t status = cudaEventQuery(slot.end_event);
            if (status == cudaSuccess) {
                const float finish_time_ms = now_ms();
                gpu_intervals.emplace_back(slot.launch_time_ms, finish_time_ms);
                slot.task->exec_time_ms = finish_time_ms - slot.launch_time_ms;
                slot.task->finish_time_ms = finish_time_ms;
                notify_dependents(slot.task, sched, all_tasks, finish_time_ms);

                slot.task = nullptr;
                slot.busy = false;
                inflight_count--;
                made_progress = true;
            }
        }

        if (!made_progress && inflight_count > 0) {
            for (SingleGateInFlightSlot &slot: slots) {
                if (!slot.busy)
                    continue;
                cudaEventSynchronize(slot.end_event);
                break;
            }
        }
    }

    for (SingleGateInFlightSlot &slot: slots) {
        cudaEventDestroy(slot.start_event);
        cudaEventDestroy(slot.end_event);
        cudaStreamDestroy(slot.stream);
    }
    run.makespan_ms = now_ms();
    run.gpu_busy_ms = merged_interval_duration_ms(gpu_intervals);
}

void run_level_scheduler(const std::vector<Task *> &all_tasks,
                         GateBatchExecutor &executor,
                         RunAccounting &run) {
    for (Task *t: all_tasks) {
        t->arrival_time_ms = 0.f;
        t->wait_time_ms = 0.f;
        t->exec_time_ms = 0.f;
        t->finish_time_ms = 0.f;
        t->dep_remaining = static_cast<int>(t->dependencies.size());
    }

    FIFOScheduler sched;
    for (Task *t: all_tasks)
        if (t->dep_remaining == 0)
            sched.submit(t);

    cudaStream_t reset_stream = nullptr;
    cudaStreamCreate(&reset_stream);
    reset_gate_batch_executor(executor, reset_stream);
    cudaStreamSynchronize(reset_stream);
    cudaStreamDestroy(reset_stream);

    const auto wall_start = std::chrono::steady_clock::now();
    const auto now_ms = [&]() -> float {
        return std::chrono::duration<float, std::milli>(
            std::chrono::steady_clock::now() - wall_start
        ).count();
    };
    std::vector<std::pair<float, float> > gpu_intervals;
    run.gpu_busy_ms = 0.f;
    run.makespan_ms = 0.f;
    while (!sched.empty()) {
        std::vector<Task *> ready_wave;
        while (!sched.empty())
            ready_wave.push_back(sched.next());

        std::vector<cudaStream_t> streams(ready_wave.size(), nullptr);
        std::vector<cudaEvent_t> start_events(ready_wave.size(), nullptr);
        std::vector<cudaEvent_t> end_events(ready_wave.size(), nullptr);
        std::vector<float> host_launch_times(ready_wave.size(), 0.f);

        for (size_t i = 0; i < ready_wave.size(); i++) {
            cudaStreamCreate(&streams[i]);
            cudaEventCreate(&start_events[i]);
            cudaEventCreate(&end_events[i]);
            host_launch_times[i] = now_ms();
            ready_wave[i]->wait_time_ms = host_launch_times[i] - ready_wave[i]->arrival_time_ms;
            cudaEventRecord(start_events[i], streams[i]);
            launch_gate_batch(streams[i], executor, std::vector<Task *>{ready_wave[i]});
            cudaEventRecord(end_events[i], streams[i]);
        }

        float wave_barrier_finish_ms = 0.f;
        for (size_t i = 0; i < ready_wave.size(); i++) {
            cudaEventSynchronize(end_events[i]);
            const float host_finish_ms = now_ms();
            ready_wave[i]->exec_time_ms = host_finish_ms - host_launch_times[i];
            ready_wave[i]->finish_time_ms = host_finish_ms;
            wave_barrier_finish_ms = std::max(wave_barrier_finish_ms, host_finish_ms);
            gpu_intervals.emplace_back(host_launch_times[i], host_finish_ms);
        }

        for (const Task *t: ready_wave)
            notify_dependents(t, &sched, all_tasks, wave_barrier_finish_ms);

        for (size_t i = 0; i < ready_wave.size(); i++) {
            cudaEventDestroy(start_events[i]);
            cudaEventDestroy(end_events[i]);
            cudaStreamDestroy(streams[i]);
        }
    }
    run.makespan_ms = now_ms();
    run.gpu_busy_ms = merged_interval_duration_ms(gpu_intervals);
}

std::vector<Task *> collect_fusable_level_segment(
    Task *first,
    const std::vector<Task *> &task_by_id,
    const int gate_limit
) {
    std::vector<Task *> segment;
    if (first->gate_ids.empty() || static_cast<int>(first->gate_ids.size()) > gate_limit) {
        segment.push_back(first);
        return segment;
    }

    segment.push_back(first);
    Task *current = first;
    while (current->id + 1 >= 0 && current->id + 1 < static_cast<int>(task_by_id.size())) {
        Task *next = task_by_id[current->id + 1];
        if (next == nullptr ||
            next->workload_id != first->workload_id ||
            next->dependencies.size() != 1 ||
            next->dependencies[0] != current->id ||
            next->gate_ids.empty() ||
            static_cast<int>(next->gate_ids.size()) > gate_limit) {
            break;
        }
        segment.push_back(next);
        current = next;
    }
    return segment;
}

void run_level_fused_scheduler(const std::vector<Task *> &all_tasks,
                               GateBatchExecutor &executor,
                               const int gate_limit,
                               RunAccounting &run) {
    int max_task_id = -1;
    for (Task *t: all_tasks) {
        t->arrival_time_ms = 0.f;
        t->wait_time_ms = 0.f;
        t->exec_time_ms = 0.f;
        t->finish_time_ms = 0.f;
        t->dep_remaining = static_cast<int>(t->dependencies.size());
        max_task_id = std::max(max_task_id, t->id);
    }

    std::vector<Task *> task_by_id(max_task_id + 1, nullptr);
    for (Task *t: all_tasks)
        task_by_id[t->id] = t;

    FIFOScheduler sched;
    for (Task *t: all_tasks)
        if (t->dep_remaining == 0)
            sched.submit(t);

    cudaStream_t reset_stream = nullptr;
    cudaStreamCreate(&reset_stream);
    reset_gate_batch_executor(executor, reset_stream);
    cudaStreamSynchronize(reset_stream);
    cudaStreamDestroy(reset_stream);

    const auto wall_start = std::chrono::steady_clock::now();
    const auto now_ms = [&]() -> float {
        return std::chrono::duration<float, std::milli>(
            std::chrono::steady_clock::now() - wall_start
        ).count();
    };
    std::vector<std::pair<float, float> > gpu_intervals;
    run.gpu_busy_ms = 0.f;
    run.makespan_ms = 0.f;

    while (!sched.empty()) {
        std::vector<Task *> ready_wave;
        while (!sched.empty())
            ready_wave.push_back(sched.next());

        std::vector<std::vector<Task *> > segments;
        segments.reserve(ready_wave.size());
        for (Task *ready: ready_wave)
            segments.push_back(collect_fusable_level_segment(ready, task_by_id, gate_limit));

        float wave_barrier_finish_ms = 0.f;
        for (size_t i = 0; i < segments.size(); i++) {
            cudaStream_t stream = nullptr;
            cudaEvent_t start_event = nullptr;
            cudaEvent_t end_event = nullptr;
            cudaStreamCreate(&stream);
            cudaEventCreate(&start_event);
            cudaEventCreate(&end_event);

            const float host_launch_ms = now_ms();
            segments[i][0]->wait_time_ms = host_launch_ms - segments[i][0]->arrival_time_ms;
            for (size_t level_idx = 1; level_idx < segments[i].size(); level_idx++) {
                segments[i][level_idx]->arrival_time_ms = host_launch_ms;
                segments[i][level_idx]->wait_time_ms = 0.f;
            }
            cudaEventRecord(start_event, stream);
            if (segments[i].size() == 1 &&
                static_cast<int>(segments[i][0]->gate_ids.size()) > gate_limit) {
                launch_gate_batch(stream, executor, std::vector<Task *>{segments[i][0]});
            } else {
                launch_level_segment(stream, executor, segments[i]);
            }
            cudaEventRecord(end_event, stream);
            cudaEventSynchronize(end_event);
            const float host_finish_ms = now_ms();
            const float segment_service_ms = host_finish_ms - host_launch_ms;
            int segment_gate_count = 0;
            for (const Task *level: segments[i])
                segment_gate_count += static_cast<int>(level->gate_ids.size());

            float attributed_level_start_ms = host_launch_ms;
            for (size_t level_idx = 0; level_idx < segments[i].size(); level_idx++) {
                Task *level = segments[i][level_idx];
                const float gate_fraction = segment_gate_count > 0
                                                ? static_cast<float>(level->gate_ids.size()) / static_cast<float>(segment_gate_count)
                                                : 1.f / static_cast<float>(segments[i].size());
                level->arrival_time_ms = level_idx == 0 ? level->arrival_time_ms : attributed_level_start_ms;
                level->wait_time_ms = level_idx == 0 ? level->wait_time_ms : 0.f;
                level->exec_time_ms = level_idx + 1 == segments[i].size()
                                          ? host_finish_ms - attributed_level_start_ms
                                          : segment_service_ms * gate_fraction;
                level->finish_time_ms = attributed_level_start_ms + level->exec_time_ms;
                attributed_level_start_ms = level->finish_time_ms;
            }
            wave_barrier_finish_ms = std::max(wave_barrier_finish_ms, host_finish_ms);
            gpu_intervals.emplace_back(host_launch_ms, host_finish_ms);
            cudaEventDestroy(start_event);
            cudaEventDestroy(end_event);
            cudaStreamDestroy(stream);
        }

        for (const auto &segment: segments)
            notify_dependents(segment.back(), &sched, all_tasks, wave_barrier_finish_ms);
    }

    run.makespan_ms = now_ms();
    run.gpu_busy_ms = merged_interval_duration_ms(gpu_intervals);
}

std::vector<std::unique_ptr<Task> > expand_level_tasks_to_gate_tasks(const std::vector<Task *> &level_tasks,
                                                                     const Circuit &c) {
    std::vector<std::unique_ptr<Task> > expanded;
    expanded.reserve(c.total_gates);
    for (const Task *level_task: level_tasks) {
        for (const int gate_id: level_task->gate_ids) {
            auto gate_task = std::make_unique<Task>();
            gate_task->id = gate_id;
            gate_task->workload_id = level_task->workload_id;
            gate_task->priority = c.gate_num_inputs[gate_id];
            gate_task->gate_type = c.gate_type[gate_id];
            gate_task->arrival_time_ms = level_task->arrival_time_ms;
            gate_task->wait_time_ms = level_task->wait_time_ms;
            gate_task->exec_time_ms = level_task->exec_time_ms;
            gate_task->finish_time_ms = level_task->finish_time_ms;
            expanded.push_back(std::move(gate_task));
        }
    }
    return expanded;
}

int main(int argc, char **argv) {
    constexpr int NUM_RUNS = 10;
    const std::vector BATCH_SIZES = {32, 128, 512};

    const std::vector<std::string> CIRCUITS = {
        "benchmark/c17.ckt",
        "benchmark/c432.ckt",
        "benchmark/c499.ckt",
        "benchmark/c880.ckt",
        "benchmark/c1355.ckt",
        "benchmark/c1908.ckt",
        "benchmark/c2670.ckt",
        "benchmark/c3540.ckt",
        "benchmark/c5315.ckt",
        "benchmark/c6288.ckt",
        "benchmark/c7552.ckt",
    };
    const std::vector<std::pair<std::string, std::vector<std::string>>> GROUPS = {
        {"balanced_0", {"benchmark/c880.ckt", "benchmark/c1908.ckt", "benchmark/c2670.ckt"}},
        {"balanced_1", {"benchmark/c432.ckt", "benchmark/c499.ckt", "benchmark/c3540.ckt"}},
        {"imbalanced_2", {"benchmark/c432.ckt", "benchmark/c499.ckt", "benchmark/c880.ckt"}},
        {"imbalanced_3", {"benchmark/c1908.ckt", "benchmark/c2670.ckt", "benchmark/c3540.ckt"}},
        {"imbalanced_4", {"benchmark/c17.ckt", "benchmark/c1908.ckt", "benchmark/c7552.ckt"}},
        {"imbalanced_5", {"benchmark/c432.ckt", "benchmark/c3540.ckt", "benchmark/c7552.ckt"}},
    };

    // circuit_name, batch_size, averages, standard deviations
    std::vector<std::tuple<std::string, int, std::vector<Metrics>, std::vector<Metrics>>> all_results;
    cuda_warmup();

    for (const int batch_size: BATCH_SIZES) {
        for (const auto &circuit_path: CIRCUITS) {
            const std::string circuit_name = std::filesystem::path(circuit_path).stem().string();
            std::cout << "\n=== Circuit: " << circuit_name << "  batch=" << batch_size << " ===\n";

            // load one circuit into a single task pool
            Circuit c = parse_ckt(circuit_path);
            std::vector<std::unique_ptr<Task> > owned;
            auto circuit_tasks = circuit_to_tasks(c, 0, 0);
            for (auto &t: circuit_tasks)
                owned.push_back(std::move(t));

            std::vector<Task *> tasks;
            for (auto &t: owned) tasks.push_back(t.get());
            GateBatchExecutor executor = create_gate_batch_executor(c);
            std::vector<std::unique_ptr<Task> > owned_level;
            auto level_tasks_created = circuit_to_level_tasks(c, 0, 0, 0);
            for (auto &t: level_tasks_created)
                owned_level.push_back(std::move(t));
            std::vector<Task *> level_tasks;
            for (auto &t: owned_level)
                level_tasks.push_back(t.get());

            // 10 runs per scheduler
            std::vector<Metrics> fifo_runs, prio_runs, dep_runs, sjf_runs;
            std::vector<Metrics> fifo_sg_nb_runs, prio_sg_nb_runs, dep_sg_nb_runs, sjf_sg_nb_runs;
            std::vector<Metrics> fifo_nb_runs, prio_nb_runs, dep_nb_runs, sjf_nb_runs;

            for (int run = 0; run < NUM_RUNS; run++) {
                cuda_warmup();
                RunAccounting run_accounting;

                {
                    FIFOScheduler s;
                    run_scheduler(&s, tasks, batch_size, executor, run_accounting);
                    fifo_runs.push_back(compute_metrics("FIFO (batch blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    FaninPriorityScheduler s;
                    run_scheduler(&s, tasks, batch_size, executor, run_accounting);
                    prio_runs.push_back(compute_metrics("fanin_priority (batch blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    DependencyAwareScheduler s;
                    s.precompute_downstream(tasks);
                    run_scheduler(&s, tasks, batch_size, executor, run_accounting);
                    dep_runs.push_back(compute_metrics("DependencyAware (batch blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    SJFScheduler s;
                    run_scheduler(&s, tasks, batch_size, executor, run_accounting);
                    sjf_runs.push_back(compute_metrics("SJF (batch blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    FIFOScheduler s;
                    run_scheduler_single_gate_nonblocking(&s, tasks, executor, run_accounting);
                    fifo_sg_nb_runs.push_back(compute_metrics("FIFO (single-gate non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    FaninPriorityScheduler s;
                    run_scheduler_single_gate_nonblocking(&s, tasks, executor, run_accounting);
                    prio_sg_nb_runs.push_back(compute_metrics("fanin_priority (single-gate non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    DependencyAwareScheduler s;
                    s.precompute_downstream(tasks);
                    run_scheduler_single_gate_nonblocking(&s, tasks, executor, run_accounting);
                    dep_sg_nb_runs.push_back(compute_metrics("DependencyAware (single-gate non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    SJFScheduler s;
                    run_scheduler_single_gate_nonblocking(&s, tasks, executor, run_accounting);
                    sjf_sg_nb_runs.push_back(compute_metrics("SJF (single-gate non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    FIFOScheduler s;
                    run_scheduler_nonblocking(&s, tasks, batch_size, executor, run_accounting);
                    fifo_nb_runs.push_back(compute_metrics("FIFO (batch non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    FaninPriorityScheduler s;
                    run_scheduler_nonblocking(&s, tasks, batch_size, executor, run_accounting);
                    prio_nb_runs.push_back(compute_metrics("fanin_priority (batch non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    DependencyAwareScheduler s;
                    s.precompute_downstream(tasks);
                    run_scheduler_nonblocking(&s, tasks, batch_size, executor, run_accounting);
                    dep_nb_runs.push_back(compute_metrics("DependencyAware (batch non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    SJFScheduler s;
                    run_scheduler_nonblocking(&s, tasks, batch_size, executor, run_accounting);
                    sjf_nb_runs.push_back(compute_metrics("SJF (batch non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }
            }

            std::vector<Metrics> averaged = {
                average_metrics("FIFO (batch blocking)", fifo_runs),
                average_metrics("fanin_priority (batch blocking)", prio_runs),
                average_metrics("DependencyAware (batch blocking)", dep_runs),
                average_metrics("SJF (batch blocking)", sjf_runs),
                average_metrics("FIFO (single-gate non-blocking)", fifo_sg_nb_runs),
                average_metrics("fanin_priority (single-gate non-blocking)", prio_sg_nb_runs),
                average_metrics("DependencyAware (single-gate non-blocking)", dep_sg_nb_runs),
                average_metrics("SJF (single-gate non-blocking)", sjf_sg_nb_runs),
                average_metrics("FIFO (batch non-blocking)", fifo_nb_runs),
                average_metrics("fanin_priority (batch non-blocking)", prio_nb_runs),
                average_metrics("DependencyAware (batch non-blocking)", dep_nb_runs),
                average_metrics("SJF (batch non-blocking)", sjf_nb_runs),
            };

            std::vector<Metrics> stds = {
                compute_stddev("FIFO (batch blocking)", fifo_runs, averaged[0]),
                compute_stddev("fanin_priority (batch blocking)", prio_runs, averaged[1]),
                compute_stddev("DependencyAware (batch blocking)", dep_runs, averaged[2]),
                compute_stddev("SJF (batch blocking)", sjf_runs, averaged[3]),
                compute_stddev("FIFO (single-gate non-blocking)", fifo_sg_nb_runs, averaged[4]),
                compute_stddev("fanin_priority (single-gate non-blocking)", prio_sg_nb_runs, averaged[5]),
                compute_stddev("DependencyAware (single-gate non-blocking)", dep_sg_nb_runs, averaged[6]),
                compute_stddev("SJF (single-gate non-blocking)", sjf_sg_nb_runs, averaged[7]),
                compute_stddev("FIFO (batch non-blocking)", fifo_nb_runs, averaged[8]),
                compute_stddev("fanin_priority (batch non-blocking)", prio_nb_runs, averaged[9]),
                compute_stddev("DependencyAware (batch non-blocking)", dep_nb_runs, averaged[10]),
                compute_stddev("SJF (batch non-blocking)", sjf_nb_runs, averaged[11]),
            };


            all_results.emplace_back(circuit_name, batch_size, averaged, stds);

            for (const auto &m: averaged) print_metrics(m);
            write_report(averaged, stds, circuit_name, batch_size, NUM_RUNS);

            if (batch_size == BATCH_SIZES.front()) {
                std::vector<Metrics> level_runs;
                std::vector<std::vector<Metrics>> fused_runs(FUSED_LEVEL_GATE_LIMITS.size());
                for (int run = 0; run < NUM_RUNS; run++) {
                    cuda_warmup();
                    RunAccounting run_accounting;

                    run_level_scheduler(level_tasks, executor, run_accounting);
                    auto expanded = expand_level_tasks_to_gate_tasks(level_tasks, c);
                    std::vector<Task *> expanded_ptrs;
                    expanded_ptrs.reserve(expanded.size());
                    for (auto &t: expanded)
                        expanded_ptrs.push_back(t.get());
                    level_runs.push_back(compute_metrics("levelization", expanded_ptrs, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));

                    for (size_t i = 0; i < FUSED_LEVEL_GATE_LIMITS.size(); i++) {
                        const int gate_limit = FUSED_LEVEL_GATE_LIMITS[i];
                        run_level_fused_scheduler(level_tasks, executor, gate_limit, run_accounting);
                        auto fused_expanded = expand_level_tasks_to_gate_tasks(level_tasks, c);
                        std::vector<Task *> fused_expanded_ptrs;
                        fused_expanded_ptrs.reserve(fused_expanded.size());
                        for (auto &t: fused_expanded)
                            fused_expanded_ptrs.push_back(t.get());
                        fused_runs[i].push_back(compute_metrics("fused_level(" + std::to_string(gate_limit) + ")",
                                                                fused_expanded_ptrs,
                                                                run_accounting.gpu_busy_ms,
                                                                run_accounting.makespan_ms));
                    }
                }

                std::vector<Metrics> level_averaged = {
                    average_metrics("levelization", level_runs),
                };
                std::vector<Metrics> level_stds = {
                    compute_stddev("levelization", level_runs, level_averaged[0]),
                };
                for (size_t i = 0; i < FUSED_LEVEL_GATE_LIMITS.size(); i++) {
                    const std::string name = "fused_level(" + std::to_string(FUSED_LEVEL_GATE_LIMITS[i]) + ")";
                    level_averaged.push_back(average_metrics(name, fused_runs[i]));
                    level_stds.push_back(compute_stddev(name, fused_runs[i], level_averaged.back()));
                }
                write_level_report(level_averaged, level_stds, circuit_name, false, NUM_RUNS);
            }
            destroy_gate_batch_executor(executor);
        }

        for (const auto &[group_name, circuits]: GROUPS) {
            std::cout << "\n=== Group: " << group_name << "  batch=" << batch_size << " ===\n";

            std::vector<std::unique_ptr<Task>> owned;
            std::vector<Circuit> parsed_circuits;
            parsed_circuits.reserve(circuits.size());

            int offset = 0;
            for (int wl_id = 0; wl_id < static_cast<int>(circuits.size()); wl_id++) {
                parsed_circuits.push_back(parse_ckt(circuits[wl_id]));
                Circuit &c = parsed_circuits.back();
                auto wl_tasks = circuit_to_tasks(c, wl_id, offset);
                offset += c.total_gates;
                for (auto &task: wl_tasks)
                    owned.push_back(std::move(task));
            }

            std::vector<Task *> tasks;
            tasks.reserve(owned.size());
            for (auto &task: owned)
                tasks.push_back(task.get());
            Circuit merged_circuit = merge_circuits(parsed_circuits);
            GateBatchExecutor executor = create_gate_batch_executor(merged_circuit);
            std::vector<std::unique_ptr<Task> > owned_level;
            int level_id_offset = 0;
            int gate_offset = 0;
            for (int wl_id = 0; wl_id < static_cast<int>(parsed_circuits.size()); wl_id++) {
                auto wl_level_tasks = circuit_to_level_tasks(parsed_circuits[wl_id], wl_id, level_id_offset, gate_offset);
                level_id_offset += static_cast<int>(wl_level_tasks.size());
                gate_offset += parsed_circuits[wl_id].total_gates;
                for (auto &task: wl_level_tasks)
                    owned_level.push_back(std::move(task));
            }
            std::vector<Task *> level_tasks;
            level_tasks.reserve(owned_level.size());
            for (auto &task: owned_level)
                level_tasks.push_back(task.get());

            std::vector<Metrics> fifo_runs, prio_runs, dep_runs, sjf_runs;
            std::vector<Metrics> fifo_sg_nb_runs, prio_sg_nb_runs, dep_sg_nb_runs, sjf_sg_nb_runs;
            std::vector<Metrics> fifo_nb_runs, prio_nb_runs, dep_nb_runs, sjf_nb_runs;

            for (int run = 0; run < NUM_RUNS; run++) {
                cuda_warmup();
                RunAccounting run_accounting;

                {
                    FIFOScheduler s;
                    run_scheduler(&s, tasks, batch_size, executor, run_accounting);
                    fifo_runs.push_back(compute_metrics("FIFO (batch blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    FaninPriorityScheduler s;
                    run_scheduler(&s, tasks, batch_size, executor, run_accounting);
                    prio_runs.push_back(compute_metrics("fanin_priority (batch blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    DependencyAwareScheduler s;
                    s.precompute_downstream(tasks);
                    run_scheduler(&s, tasks, batch_size, executor, run_accounting);
                    dep_runs.push_back(compute_metrics("DependencyAware (batch blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    SJFScheduler s;
                    run_scheduler(&s, tasks, batch_size, executor, run_accounting);
                    sjf_runs.push_back(compute_metrics("SJF (batch blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    FIFOScheduler s;
                    run_scheduler_single_gate_nonblocking(&s, tasks, executor, run_accounting);
                    fifo_sg_nb_runs.push_back(compute_metrics("FIFO (single-gate non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    FaninPriorityScheduler s;
                    run_scheduler_single_gate_nonblocking(&s, tasks, executor, run_accounting);
                    prio_sg_nb_runs.push_back(compute_metrics("fanin_priority (single-gate non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    DependencyAwareScheduler s;
                    s.precompute_downstream(tasks);
                    run_scheduler_single_gate_nonblocking(&s, tasks, executor, run_accounting);
                    dep_sg_nb_runs.push_back(compute_metrics("DependencyAware (single-gate non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    SJFScheduler s;
                    run_scheduler_single_gate_nonblocking(&s, tasks, executor, run_accounting);
                    sjf_sg_nb_runs.push_back(compute_metrics("SJF (single-gate non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    FIFOScheduler s;
                    run_scheduler_nonblocking(&s, tasks, batch_size, executor, run_accounting);
                    fifo_nb_runs.push_back(compute_metrics("FIFO (batch non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    FaninPriorityScheduler s;
                    run_scheduler_nonblocking(&s, tasks, batch_size, executor, run_accounting);
                    prio_nb_runs.push_back(compute_metrics("fanin_priority (batch non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    DependencyAwareScheduler s;
                    s.precompute_downstream(tasks);
                    run_scheduler_nonblocking(&s, tasks, batch_size, executor, run_accounting);
                    dep_nb_runs.push_back(compute_metrics("DependencyAware (batch non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }

                {
                    SJFScheduler s;
                    run_scheduler_nonblocking(&s, tasks, batch_size, executor, run_accounting);
                    sjf_nb_runs.push_back(compute_metrics("SJF (batch non-blocking)", tasks, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));
                }
            }

            std::vector<Metrics> averaged = {
                average_metrics("FIFO (batch blocking)", fifo_runs),
                average_metrics("fanin_priority (batch blocking)", prio_runs),
                average_metrics("DependencyAware (batch blocking)", dep_runs),
                average_metrics("SJF (batch blocking)", sjf_runs),
                average_metrics("FIFO (single-gate non-blocking)", fifo_sg_nb_runs),
                average_metrics("fanin_priority (single-gate non-blocking)", prio_sg_nb_runs),
                average_metrics("DependencyAware (single-gate non-blocking)", dep_sg_nb_runs),
                average_metrics("SJF (single-gate non-blocking)", sjf_sg_nb_runs),
                average_metrics("FIFO (batch non-blocking)", fifo_nb_runs),
                average_metrics("fanin_priority (batch non-blocking)", prio_nb_runs),
                average_metrics("DependencyAware (batch non-blocking)", dep_nb_runs),
                average_metrics("SJF (batch non-blocking)", sjf_nb_runs),
            };

            std::vector<Metrics> stds = {
                compute_stddev("FIFO (batch blocking)", fifo_runs, averaged[0]),
                compute_stddev("fanin_priority (batch blocking)", prio_runs, averaged[1]),
                compute_stddev("DependencyAware (batch blocking)", dep_runs, averaged[2]),
                compute_stddev("SJF (batch blocking)", sjf_runs, averaged[3]),
                compute_stddev("FIFO (single-gate non-blocking)", fifo_sg_nb_runs, averaged[4]),
                compute_stddev("fanin_priority (single-gate non-blocking)", prio_sg_nb_runs, averaged[5]),
                compute_stddev("DependencyAware (single-gate non-blocking)", dep_sg_nb_runs, averaged[6]),
                compute_stddev("SJF (single-gate non-blocking)", sjf_sg_nb_runs, averaged[7]),
                compute_stddev("FIFO (batch non-blocking)", fifo_nb_runs, averaged[8]),
                compute_stddev("fanin_priority (batch non-blocking)", prio_nb_runs, averaged[9]),
                compute_stddev("DependencyAware (batch non-blocking)", dep_nb_runs, averaged[10]),
                compute_stddev("SJF (batch non-blocking)", sjf_nb_runs, averaged[11]),
            };

            write_report_for_group(averaged, stds, group_name, batch_size, NUM_RUNS);

            if (batch_size == BATCH_SIZES.front()) {
                std::vector<Metrics> level_runs;
                std::vector<std::vector<Metrics>> fused_runs(FUSED_LEVEL_GATE_LIMITS.size());
                for (int run = 0; run < NUM_RUNS; run++) {
                    cuda_warmup();
                    RunAccounting run_accounting;

                    run_level_scheduler(level_tasks, executor, run_accounting);
                    auto expanded = expand_level_tasks_to_gate_tasks(level_tasks, merged_circuit);
                    std::vector<Task *> expanded_ptrs;
                    expanded_ptrs.reserve(expanded.size());
                    for (auto &t: expanded)
                        expanded_ptrs.push_back(t.get());
                    level_runs.push_back(compute_metrics("levelization", expanded_ptrs, run_accounting.gpu_busy_ms, run_accounting.makespan_ms));

                    for (size_t i = 0; i < FUSED_LEVEL_GATE_LIMITS.size(); i++) {
                        const int gate_limit = FUSED_LEVEL_GATE_LIMITS[i];
                        run_level_fused_scheduler(level_tasks, executor, gate_limit, run_accounting);
                        auto fused_expanded = expand_level_tasks_to_gate_tasks(level_tasks, merged_circuit);
                        std::vector<Task *> fused_expanded_ptrs;
                        fused_expanded_ptrs.reserve(fused_expanded.size());
                        for (auto &t: fused_expanded)
                            fused_expanded_ptrs.push_back(t.get());
                        fused_runs[i].push_back(compute_metrics("fused_level(" + std::to_string(gate_limit) + ")",
                                                                fused_expanded_ptrs,
                                                                run_accounting.gpu_busy_ms,
                                                                run_accounting.makespan_ms));
                    }
                }

                std::vector<Metrics> level_averaged = {
                    average_metrics("levelization", level_runs),
                };
                std::vector<Metrics> level_stds = {
                    compute_stddev("levelization", level_runs, level_averaged[0]),
                };
                for (size_t i = 0; i < FUSED_LEVEL_GATE_LIMITS.size(); i++) {
                    const std::string name = "fused_level(" + std::to_string(FUSED_LEVEL_GATE_LIMITS[i]) + ")";
                    level_averaged.push_back(average_metrics(name, fused_runs[i]));
                    level_stds.push_back(compute_stddev(name, fused_runs[i], level_averaged.back()));
                }
                write_level_report(level_averaged, level_stds, group_name, true, NUM_RUNS);
            }
            destroy_gate_batch_executor(executor);
        }
    }

    return 0;
}
