#include "metrics.h"
#include <iostream>
#include <cmath>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <set>
#include <sstream>

Metrics compute_metrics(const std::string &sched_name, const std::vector<Task *> &tasks, float stream_time_ms) {
    Metrics m;
    m.scheduler_name = sched_name;

    float sum_wait = 0, sum_exec = 0, sum_turnaround = 0;
    float sum_slowdown = 0, sum_weighted_slowdown = 0;
    m.makespan_ms = 0.f;
    m.max_wait_ms = 0.f;
    m.max_slowdown = 0.f;

    // per-workload accumulators for slowdown and finish times
    std::unordered_map<int, float> wl_max_completion;
    std::unordered_map<int, std::vector<float> > wl_slowdowns;
    std::unordered_map<int, std::vector<float> > wl_finish_times;
    const int n = static_cast<int>(tasks.size());

    for (const Task *t: tasks) {
        // per task snapshot
        const char *type_str = "?";
        switch (t->type) {
            case KernelType::COMPUTE_BOUND: type_str = "compute";
                break;
            case KernelType::MEMORY_BOUND: type_str = "memory";
                break;
            case KernelType::LATENCY_SENSITIVE: type_str = "latency";
                break;
        }
        m.task_snapshots.emplace_back(
            t->id, t->workload_id, t->priority, std::string(type_str),
            t->arrival_time_ms, t->wait_time_ms, t->exec_time_ms, t->finish_time_ms
        );

        // metrics
        float turnaround = t->wait_time_ms + t->exec_time_ms;
        float exec_safe = std::max(t->exec_time_ms, 1e-4f); // prevent division by zero
        float slowdown = turnaround / exec_safe;
        // priority=1 is highest, so weight = 1/priority  penalizes high-priority starvation more
        int prio_safe = std::max(t->priority, 1); // PI gates have priority 0
        float w_slowdown = slowdown * (1.f / static_cast<float>(prio_safe));

        sum_wait += t->wait_time_ms;
        sum_exec += t->exec_time_ms;
        sum_turnaround += turnaround;
        sum_slowdown += slowdown;
        sum_weighted_slowdown += w_slowdown;

        m.max_wait_ms = std::max(m.max_wait_ms, t->wait_time_ms);
        m.max_slowdown = std::max(m.max_slowdown, slowdown);
        m.makespan_ms = std::max(m.makespan_ms, t->finish_time_ms);

        wl_max_completion[t->workload_id] =
                std::max(wl_max_completion[t->workload_id], t->finish_time_ms);
        wl_slowdowns[t->workload_id].push_back(slowdown);
        wl_finish_times[t->workload_id].push_back(t->finish_time_ms);
    }

    m.avg_wait_ms = sum_wait / static_cast<float>(n);
    m.avg_exec_ms = sum_exec / static_cast<float>(n);
    m.avg_turnaround_ms = sum_turnaround / static_cast<float>(n);
    m.avg_slowdown = sum_slowdown / static_cast<float>(n);
    m.weighted_avg_slowdown = sum_weighted_slowdown / static_cast<float>(n);
    m.throughput_tasks_per_sec = static_cast<float>(n) / (m.makespan_ms / 1000.f);
    // m.gpu_utilization = sum_exec / m.makespan_ms; // 0–1 range
    m.gpu_utilization = (stream_time_ms > 0.f) ? sum_exec / stream_time_ms : 0.f;

    // Jain's fairness index on per-workload max completion time
    // J = (sum(x))^2 / (n * sum(x^2))
    float jain_sum = 0, jain_sum_sq = 0;
    for (auto &[id, ct]: wl_max_completion) {
        jain_sum += ct;
        jain_sum_sq += ct * ct;
    }
    const int wl_count = static_cast<int>(wl_max_completion.size());
    m.jains_fairness = (jain_sum * jain_sum) / (static_cast<float>(wl_count) * jain_sum_sq);

    // per-workload avg slowdown
    for (auto &[id, slowdowns]: wl_slowdowns) {
        float s = 0;
        for (float v: slowdowns) s += v;
        m.per_wl_avg_slowdown[id] = s / static_cast<float>(slowdowns.size());
    }

    // per-workload completion time variance: σ² = mean(x^2) - mean(x)^2
    for (auto &[id, times]: wl_finish_times) {
        float mean = 0, mean_sq = 0;
        for (float t: times) {
            mean += t;
            mean_sq += t * t;
        }
        mean /= static_cast<float>(times.size());
        mean_sq /= static_cast<float>(times.size());
        m.per_wl_completion_variance[id] = mean_sq - mean * mean;
    }

    return m;
}

Metrics average_metrics(const std::string &sched_name, const std::vector<Metrics> &runs) {
    Metrics avg;
    avg.scheduler_name = sched_name;
    const auto n = static_cast<float>(runs.size());

    for (const auto &m: runs) {
        avg.avg_wait_ms += m.avg_wait_ms;
        avg.max_wait_ms += m.max_wait_ms;
        avg.avg_exec_ms += m.avg_exec_ms;
        avg.avg_turnaround_ms += m.avg_turnaround_ms;
        avg.makespan_ms += m.makespan_ms;
        avg.throughput_tasks_per_sec += m.throughput_tasks_per_sec;
        avg.gpu_utilization += m.gpu_utilization;
        avg.jains_fairness += m.jains_fairness;
        avg.avg_slowdown += m.avg_slowdown;
        avg.max_slowdown += m.max_slowdown;
        avg.weighted_avg_slowdown += m.weighted_avg_slowdown;

        for (auto &[id, s]: m.per_wl_avg_slowdown)
            avg.per_wl_avg_slowdown[id] += s;
        for (auto &[id, v]: m.per_wl_completion_variance)
            avg.per_wl_completion_variance[id] += v;
    }

    avg.avg_wait_ms /= n;
    avg.max_wait_ms /= n;
    avg.avg_exec_ms /= n;
    avg.avg_turnaround_ms /= n;
    avg.makespan_ms /= n;
    avg.throughput_tasks_per_sec /= n;
    avg.gpu_utilization /= n;
    avg.jains_fairness /= n;
    avg.avg_slowdown /= n;
    avg.max_slowdown /= n;
    avg.weighted_avg_slowdown /= n;

    for (auto &[id, s]: avg.per_wl_avg_slowdown) s /= n;
    for (auto &[id, v]: avg.per_wl_completion_variance) v /= n;

    return avg;
}

Metrics compute_stddev(const std::string &sched_name,
                       const std::vector<Metrics> &runs,
                       const Metrics &mean) {
    Metrics sd;
    sd.scheduler_name = sched_name;
    const auto n = static_cast<float>(runs.size());

    for (const auto &m: runs) {
        auto sq = [](const float a, const float b) { return (a - b) * (a - b); };
        sd.avg_wait_ms += sq(m.avg_wait_ms, mean.avg_wait_ms);
        sd.max_wait_ms += sq(m.max_wait_ms, mean.max_wait_ms);
        sd.avg_exec_ms += sq(m.avg_exec_ms, mean.avg_exec_ms);
        sd.avg_turnaround_ms += sq(m.avg_turnaround_ms, mean.avg_turnaround_ms);
        sd.makespan_ms += sq(m.makespan_ms, mean.makespan_ms);
        sd.throughput_tasks_per_sec += sq(m.throughput_tasks_per_sec, mean.throughput_tasks_per_sec);
        sd.gpu_utilization += sq(m.gpu_utilization, mean.gpu_utilization);
        sd.jains_fairness += sq(m.jains_fairness, mean.jains_fairness);
        sd.avg_slowdown += sq(m.avg_slowdown, mean.avg_slowdown);
        sd.weighted_avg_slowdown += sq(m.weighted_avg_slowdown, mean.weighted_avg_slowdown);
    }

    auto sqrtn = [&](float &v) { v = std::sqrt(v / n); };
    sqrtn(sd.avg_wait_ms);
    sqrtn(sd.max_wait_ms);
    sqrtn(sd.avg_exec_ms);
    sqrtn(sd.avg_turnaround_ms);
    sqrtn(sd.makespan_ms);
    sqrtn(sd.throughput_tasks_per_sec);
    sqrtn(sd.gpu_utilization);
    sqrtn(sd.jains_fairness);
    sqrtn(sd.avg_slowdown);
    sqrtn(sd.weighted_avg_slowdown);

    return sd;
}

void print_metrics(const Metrics &m) {
    std::cout << "\n=== " << m.scheduler_name << " Metrics ===\n";
    std::printf("  Avg wait:              %8.3f ms\n", m.avg_wait_ms);
    std::printf("  Max wait:              %8.3f ms\n", m.max_wait_ms);
    std::printf("  Avg exec:              %8.3f ms\n", m.avg_exec_ms);
    std::printf("  Avg turnaround:        %8.3f ms\n", m.avg_turnaround_ms);
    std::printf("  Makespan:              %8.3f ms\n", m.makespan_ms);
    std::printf("  Throughput:            %8.2f tasks/s\n", m.throughput_tasks_per_sec);
    std::printf("  GPU utilization:       %8.2f%%\n", m.gpu_utilization * 100.f);
    std::printf("  Jain's fairness:       %8.4f\n", m.jains_fairness);
    std::printf("  Avg slowdown:          %8.2fx\n", m.avg_slowdown);
    std::printf("  Max slowdown:          %8.2fx\n", m.max_slowdown);
    std::printf("  Weighted avg slowdown: %8.2fx\n", m.weighted_avg_slowdown);

    std::cout << "  Per-workload avg slowdown:\n";
    for (auto &[id, s]: m.per_wl_avg_slowdown)
        std::printf("    wl %d: %6.2fx\n", id, s);

    std::cout << "  Per-workload completion variance:\n";
    for (auto &[id, v]: m.per_wl_completion_variance)
        std::printf("    wl %d: %6.3f ms²\n", id, v);
}

void write_report(const std::vector<Metrics> &results,
                  const std::vector<Metrics> &stds,
                  const std::string &group_name,
                  int batch_size,
                  int num_runs) {
    // timestamp filename report
    std::time_t now = std::time(nullptr);
    char ts[32];
    std::strftime(ts, sizeof(ts), "%Y%m%d_%H%M%S", std::localtime(&now));
    std::filesystem::create_directories("reports");
    const std::string filename = "reports/report_" + group_name + "_b" + std::to_string(batch_size) + ".md";

    std::ofstream f(filename);
    if (!f) {
        std::cerr << "Failed to write report: " << filename << "\n";
        return;
    }

    f << "# GPU Scheduler Report\n";
    f << "Group: " << group_name << " | batch_size=" << batch_size << " | runs=" << num_runs << " (averaged)\n\n";
    f << "Generated: " << ts << "\n\n";

    /*********************************************** summary table ***********************************************/
    f << "## Summary\n\n";
    f << "| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) "
            "| Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |\n";
    f << "|---|---|---|---|---|---|---|---|---|---|---|---|\n";
    for (const auto &m: results) {
        f << std::fixed;
        f << "| " << m.scheduler_name
                << std::setprecision(3)
                << " | " << m.avg_wait_ms
                << " | " << m.max_wait_ms
                << " | " << m.avg_exec_ms
                << " | " << m.avg_turnaround_ms
                << " | " << m.makespan_ms
                << std::setprecision(2)
                << " | " << m.throughput_tasks_per_sec
                << " | " << m.gpu_utilization * 100.f
                << std::setprecision(4)
                << " | " << m.jains_fairness
                << std::setprecision(2)
                << " | " << m.avg_slowdown << "x"
                << " | " << m.max_slowdown << "x"
                << " | " << m.weighted_avg_slowdown << "x"
                << " |\n";
    }

    /****************************************** standard deviation table ******************************************/
    f << "## Standard Deviation \n\n";
    f << "| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) "
            "| Makespan (ms) | Throughput (tasks/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |\n";
    f << "|---|---|---|---|---|---|---|---|---|---|---|---|\n";
    for (int i = 0; i < results.size(); i++) {
        const Metrics &m = results[i];
        const Metrics &sd = stds[i];
        f << std::fixed << std::setprecision(2);
        f << "| " << m.scheduler_name
                << " | " << m.avg_wait_ms << " ± " << sd.avg_wait_ms
                << " | " << m.max_wait_ms << " ± " << sd.max_wait_ms
                << " | " << m.avg_exec_ms << " ± " << sd.avg_exec_ms
                << " | " << m.avg_turnaround_ms << " ± " << sd.avg_turnaround_ms
                << " | " << m.makespan_ms << " ± " << sd.makespan_ms
                << " | " << m.throughput_tasks_per_sec << " ± " << sd.throughput_tasks_per_sec
                << " | " << m.gpu_utilization * 100.f << " ± " << sd.gpu_utilization * 100.f
                << " | " << m.jains_fairness
                << " | " << m.avg_slowdown << "x ± " << sd.avg_slowdown
                << " | " << m.max_slowdown << "x"
                << " | " << m.weighted_avg_slowdown << "x ± " << sd.weighted_avg_slowdown
                << " |\n";
    }

    /*************************************** per-workload slowdown table ***************************************/
    f << "\n## Per-Workload Avg Slowdown\n\n";

    // collect all workload ids seen across all schedulers
    std::set<int> all_wl_ids;
    for (const auto &m: results)
        for (auto &[id, _]: m.per_wl_avg_slowdown)
            all_wl_ids.insert(id);

    // header row
    f << "| Workload |";
    for (const auto &m: results) f << " " << m.scheduler_name << " |";
    f << "\n|---|";
    for (size_t i = 0; i < results.size(); ++i) f << "---|";
    f << "\n";

    for (int id: all_wl_ids) {
        f << "| wl " << id << " |";
        for (const auto &m: results) {
            auto it = m.per_wl_avg_slowdown.find(id);
            if (it != m.per_wl_avg_slowdown.end())
                f << std::fixed << std::setprecision(2) << " " << it->second << "x |";
            else
                f << " — |";
        }
        f << "\n";
    }

    /********************************** per-workload completion variance table **********************************/
    f << "\n## Per-Workload Completion Variance\n\n";
    f << "| Workload |";
    for (const auto &m: results) f << " " << m.scheduler_name << " |";
    f << "\n|---|";
    for (size_t i = 0; i < results.size(); ++i) f << "---|";
    f << "\n";

    for (int id: all_wl_ids) {
        f << "| wl " << id << " |";
        for (const auto &m: results) {
            auto it = m.per_wl_completion_variance.find(id);
            if (it != m.per_wl_completion_variance.end())
                f << std::fixed << std::setprecision(3) << " " << it->second << " ms² |";
            else
                f << " — |";
        }
        f << "\n";
    }

    f.close();
    std::cout << "\nReport written to: " << filename << "\n";
}
