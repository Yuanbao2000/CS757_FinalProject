#pragma once
#include "task.h"
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include <ctime>

struct Metrics {
    std::string scheduler_name;

    // per-gate timing snapshot
    // {id, workload_id, priority, type_str, arrival, wait, exec, finish}
    std::vector<std::tuple<int,int,int,std::string,float,float,float,float>> task_snapshots;

    // per gate
    float avg_wait_ms = 0.f;
    float avg_exec_ms = 0.f;
    float avg_turnaround_ms = 0.f;        // avg_wait + avg_exec

    // overall
    float makespan_ms = 0.f;              // total wall clock time from time 0 to last task finishing
    float throughput_gates_per_sec = 0.f;
    float gpu_utilization = 0.f;          // total GPU busy time / makespan
    float max_wait_ms = 0.f;              // starvation indicator, longest any gate waited

    // multi-workload metrics used by group reports
    float jains_fairness = 0.f;
    float avg_slowdown = 0.f;
    float max_slowdown = 0.f;
    float weighted_avg_slowdown = 0.f;
    std::unordered_map<int, float> per_wl_avg_slowdown;
    std::unordered_map<int, float> per_wl_completion_variance;
};

Metrics compute_metrics(const std::string &sched_name,
                        const std::vector<Task *> &tasks,
                        float gpu_busy_ms,
                        float makespan_ms);

Metrics average_metrics(const std::string &sched_name, const std::vector<Metrics> &runs);

Metrics compute_stddev(const std::string &sched_name, const std::vector<Metrics> &runs, const Metrics &mean);

void print_metrics(const Metrics &m);

void write_report(const std::vector<Metrics> &results,
                  const std::vector<Metrics> &stds,
                  const std::string &circuit_name,
                  int batch_size,
                  int num_runs);

void write_report_for_group(const std::vector<Metrics> &results,
                  const std::vector<Metrics> &stds,
                  const std::string &group_name,
                  int batch_size,
                  int num_runs);
