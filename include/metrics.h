#pragma once
#include "task.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <ctime>

struct Metrics {
    std::string scheduler_name;

    // per-task timing snapshot
    // {id, workload_id, priority, type_str, arrival, wait, exec, finish}
    std::vector<std::tuple<int,int,int,std::string,float,float,float,float>> task_snapshots;

    // per task
    float avg_wait_ms = 0.f;
    float avg_exec_ms = 0.f;
    float avg_turnaround_ms = 0.f;        // avg_wait + avg_exec

    // overall
    float makespan_ms = 0.f;              // total wall clock time from time 0 to last task finishing
    float throughput_tasks_per_sec = 0.f;
    float gpu_utilization = 0.f;          // sum(exec) / makespan

    // fairness
    float jains_fairness = 0.f;           // Jain's index on per-workload completion times (1.0 = perfect)
    float avg_slowdown = 0.f;             // avg(turnaround / exec) across all tasks
    float max_slowdown = 0.f;             // worst single-task relative unfairness (starvation signal)
    float weighted_avg_slowdown = 0.f;    // avg(slowdown * priority); high-priority starvation penalized more
    float max_wait_ms = 0.f;              // starvation indicator, longest any task waited
    float completion_time_variance = 0.f; // Low variance = predictable scheduling

    // avg slowdown per workload
    std::unordered_map<int, float> per_wl_avg_slowdown;
    // variance of finish times within each workload; low = predictable, high = stragglers
    std::unordered_map<int, float> per_wl_completion_variance;
};

Metrics compute_metrics(const std::string &sched_name, const std::vector<Task *> &tasks);

void print_metrics(const Metrics &m);

void write_report(const std::vector<Metrics> &results, const std::string &config_path);
