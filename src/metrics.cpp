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

Metrics compute_metrics(const std::string &sched_name,
                        const std::vector<Task *> &tasks) {
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
        float slowdown = t->exec_time_ms > 0.f ? turnaround / t->exec_time_ms : 1.f;
        // priority=1 is highest, so weight = 1/priority  penalizes high-priority starvation more
        float w_slowdown = slowdown * (1.f / static_cast<float>(t->priority));

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
    m.gpu_utilization = sum_exec / m.makespan_ms; // 0–1 range

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

void write_report(const std::vector<Metrics> &results, const std::string &ckt_path) {
    // extract config name
    std::string config_name = ckt_path;
    const auto slash = config_name.rfind('/');
    if (slash != std::string::npos) config_name = config_name.substr(slash + 1);
    const auto dot = config_name.rfind('.');
    if (dot != std::string::npos) config_name = config_name.substr(0, dot);

    // timestamp filename report
    std::time_t now = std::time(nullptr);
    char ts[32];
    std::strftime(ts, sizeof(ts), "%Y%m%d_%H%M%S", std::localtime(&now));
    std::filesystem::create_directories("reports");
    const std::string filename = "reports/report_" + config_name + "_" + ts + ".md";

    std::ofstream f(filename);
    if (!f) {
        std::cerr << "Failed to write report: " << filename << "\n";
        return;
    }

    f << "# GPU Scheduler Report\n";
    f << "ckt path: " << ckt_path << "\n\n";
    f << "Generated: " << ts << "\n\n";

    /*********************************************** task overview ***********************************************/
    f << "\n## Per-Task Details\n";
    for (const auto &m : results) {
        f << "\n<details>\n<summary><b>" << m.scheduler_name << "</b></summary>\n\n";
        f << "| Task | Workload | Priority | Type | Arrival (ms) | Wait (ms) | Exec (ms) | Finish (ms) | Slowdown |\n";
        f << "|---|---|---|---|---|---|---|---|---|\n";

        auto sorted = m.task_snapshots;
        std::sort(sorted.begin(), sorted.end(),
                  [](const auto &a, const auto &b) { return std::get<0>(a) < std::get<0>(b); });

        for (const auto &[id, wl_id, prio, type, arrival, wait, exec, finish] : sorted) {
            const float slowdown = (exec > 0.f) ? (wait + exec) / exec : 1.f;
            f << std::fixed
              << "| " << id
              << " | wl " << wl_id
              << " | " << prio
              << " | " << type
              << std::setprecision(3)
              << " | " << arrival
              << " | " << wait
              << " | " << exec
              << " | " << finish
              << std::setprecision(2)
              << " | " << slowdown << "x"
              << " |\n";
        }
        f << "\n</details>\n";
        f << "\n\n";
    }

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
