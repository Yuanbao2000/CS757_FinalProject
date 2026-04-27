#pragma once
#include "task.h"
#include <vector>
#include <string>
#include <tuple>
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
    float max_wait_ms = 0.f;              // starvation indicator, longest any task waited
};

Metrics compute_metrics(const std::string &sched_name, const std::vector<Task *> &tasks, float stream_time_ms);

Metrics average_metrics(const std::string &sched_name, const std::vector<Metrics> &runs);

Metrics compute_stddev(const std::string &sched_name, const std::vector<Metrics> &runs, const Metrics &mean);

void print_metrics(const Metrics &m);

void write_report(const std::vector<Metrics> &results,
                  const std::vector<Metrics> &stds,
                  const std::string &group_name,
                  int batch_size,
                  int num_runs);
