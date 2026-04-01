#include "metrics.h"
#include <iostream>
#include <cmath>
#include <numeric>
#include <unordered_map>

Metrics compute_metrics(const std::string &sched_name,
                        const std::vector<Task *> &tasks) {
    Metrics m;
    m.scheduler_name = sched_name;

    float sum_wait = 0, sum_exec = 0, sum_turnaround = 0;
    m.makespan_ms = 0.f;

    for (const Task *t: tasks) {
        sum_wait += t->wait_time_ms;
        sum_exec += t->exec_time_ms;
        sum_turnaround += (t->wait_time_ms + t->exec_time_ms);
        if (t->finish_time_ms > m.makespan_ms)
            m.makespan_ms = t->finish_time_ms;
    }

    const int n = static_cast<int>(tasks.size());
    m.avg_wait_ms = sum_wait / static_cast<float>(n);
    m.avg_exec_ms = sum_exec / static_cast<float>(n);
    m.avg_turnaround_ms = sum_turnaround / static_cast<float>(n);

    m.throughput_tasks_per_sec = static_cast<float>(n) / (m.makespan_ms / 1000.f);
    m.gpu_utilization = sum_exec / m.makespan_ms; // 0–1 range

    // Jain's fairness index on per-workload max completion time
    // J = (sum(x))^2 / (n * sum(x^2))
    std::unordered_map<int, float> wl_completion;
    for (const Task *t: tasks)
        wl_completion[t->workload_id] =
                std::max(wl_completion[t->workload_id], t->finish_time_ms);

    float jain_sum = 0, jain_sum_sq = 0;
    for (auto &[id, ct]: wl_completion) {
        jain_sum += ct;
        jain_sum_sq += ct * ct;
    }
    const int wl_count = static_cast<int>(wl_completion.size());
    m.jains_fairness = (jain_sum * jain_sum) / (static_cast<float>(wl_count) * jain_sum_sq);

    return m;
}

void print_metrics(const Metrics &m) {
    std::cout << "\n=== " << m.scheduler_name << " Metrics ===\n";
    std::printf("  Avg wait:        %8.3f ms\n", m.avg_wait_ms);
    std::printf("  Avg exec:        %8.3f ms\n", m.avg_exec_ms);
    std::printf("  Avg turnaround:  %8.3f ms\n", m.avg_turnaround_ms);
    std::printf("  Makespan:        %8.3f ms\n", m.makespan_ms);
    std::printf("  Throughput:      %8.2f tasks/s\n", m.throughput_tasks_per_sec);
    std::printf("  GPU utilization: %8.1f%%\n", m.gpu_utilization * 100.f);
    std::printf("  Jain's fairness: %8.4f\n", m.jains_fairness);
}
