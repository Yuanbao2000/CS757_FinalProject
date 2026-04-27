#include <vector>
#include <memory>
#include <iostream>
#include <filesystem>
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

void run_scheduler(Scheduler *sched, const std::vector<Task *> &all_tasks,
                   const int batch_size, GateBatchExecutor &executor, float &out_stream_ms) {
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
        }

        cudaEventRecord(batch_start_event, batch_stream);
        launch_gate_batch(batch_stream, executor, batch);
        cudaEventRecord(batch_end_event, batch_stream);

        // sync the unified gate-batch kernel and assign its execution cost to the selected gates
        float batch_exec_ms = 0.f;
        cudaEventSynchronize(batch_end_event);
        cudaEventElapsedTime(&batch_exec_ms, batch_start_event, batch_end_event);
        for (Task *t: batch) {
            t->exec_time_ms = batch_exec_ms;
            t->finish_time_ms = batch_start + batch_exec_ms;
        }
        // One unified gate-batch kernel is launched per scheduling round.
        out_stream_ms += batch_exec_ms;
        clock_ms = batch_start + batch_exec_ms;

        // update dependents with completed tasks
        for (const Task *t: batch)
            notify_dependents(t, sched, all_tasks, clock_ms);
    }

    cudaEventDestroy(batch_start_event);
    cudaEventDestroy(batch_end_event);
    cudaStreamDestroy(batch_stream);
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
            GateBatchExecutor executor = create_gate_batch_executor(c, tasks);

            // 10 runs per scheduler
            std::vector<Metrics> fifo_runs, prio_runs, dep_runs, sjf_runs;

            for (int run = 0; run < NUM_RUNS; run++) {
                cuda_warmup();
                float stream_ms = 0.f;

                {
                    FIFOScheduler s;
                    run_scheduler(&s, tasks, batch_size, executor, stream_ms);
                    fifo_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                }

                {
                    FaninPriorityScheduler s;
                    run_scheduler(&s, tasks, batch_size, executor, stream_ms);
                    prio_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                }

                {
                    DependencyAwareScheduler s;
                    s.precompute_downstream(tasks);
                    run_scheduler(&s, tasks, batch_size, executor, stream_ms);
                    dep_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                }

                {
                    SJFScheduler s;
                    run_scheduler(&s, tasks, batch_size, executor, stream_ms);
                    sjf_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                }
            }

            std::vector<Metrics> averaged = {
                average_metrics("FIFO", fifo_runs),
                average_metrics("fanin_priority", prio_runs),
                average_metrics("DependencyAware", dep_runs),
                average_metrics("SJF", sjf_runs),
            };

            std::vector<Metrics> stds = {
                compute_stddev("FIFO", fifo_runs, averaged[0]),
                compute_stddev("fanin_priority", prio_runs, averaged[1]),
                compute_stddev("DependencyAware", dep_runs, averaged[2]),
                compute_stddev("SJF", sjf_runs, averaged[3]),
            };


            all_results.emplace_back(circuit_name, batch_size, averaged, stds);

            for (const auto &m: averaged) print_metrics(m);
            write_report(averaged, stds, circuit_name, batch_size, NUM_RUNS);
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
            GateBatchExecutor executor = create_gate_batch_executor(merged_circuit, tasks);

            std::vector<Metrics> fifo_runs, prio_runs, dep_runs, sjf_runs;

            for (int run = 0; run < NUM_RUNS; run++) {
                cuda_warmup();
                float stream_ms = 0.f;

                {
                    FIFOScheduler s;
                    run_scheduler(&s, tasks, batch_size, executor, stream_ms);
                    fifo_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                }

                {
                    FaninPriorityScheduler s;
                    run_scheduler(&s, tasks, batch_size, executor, stream_ms);
                    prio_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                }

                {
                    DependencyAwareScheduler s;
                    s.precompute_downstream(tasks);
                    run_scheduler(&s, tasks, batch_size, executor, stream_ms);
                    dep_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                }

                {
                    SJFScheduler s;
                    run_scheduler(&s, tasks, batch_size, executor, stream_ms);
                    sjf_runs.push_back(compute_metrics(s.name(), tasks, stream_ms));
                }
            }

            std::vector<Metrics> averaged = {
                average_metrics("FIFO", fifo_runs),
                average_metrics("fanin_priority", prio_runs),
                average_metrics("DependencyAware", dep_runs),
                average_metrics("SJF", sjf_runs),
            };

            std::vector<Metrics> stds = {
                compute_stddev("FIFO", fifo_runs, averaged[0]),
                compute_stddev("fanin_priority", prio_runs, averaged[1]),
                compute_stddev("DependencyAware", dep_runs, averaged[2]),
                compute_stddev("SJF", sjf_runs, averaged[3]),
            };

            write_report_for_group(averaged, stds, group_name, batch_size, NUM_RUNS);
            destroy_gate_batch_executor(executor);
        }
    }

    return 0;
}
