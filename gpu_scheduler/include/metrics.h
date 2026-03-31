#pragma once
#include "task.h"
#include "workload.h"
#include <vector>
#include <string>

struct Metrics {
    std::string scheduler_name;

    // per task
    float avg_wait_ms = 0.f;
    float avg_exec_ms = 0.f;
    float avg_turnaround_ms = 0.f; // avg_wait + avg_exec

    // overall
    float makespan_ms = 0.f; // finish time of last task
    float throughput_tasks_per_sec = 0.f;
    float gpu_utilization = 0.f; // sum(exec) / makespan

    // fairness: Jain's index on per-workload completion times (1.0 = perfect)
    float jains_fairness = 0.f;

    // validation
    bool turnaround_check_passed = false; // wait + exec must equal turnaround for all tasks
};

Metrics compute_metrics(const std::string &sched_name,
                        const std::vector<Task *> &tasks);

void print_metrics(const Metrics &m);
