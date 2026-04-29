#include "metrics.h"
#include <iostream>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <set>
#include <unordered_map>

namespace {

std::string gate_type_to_string(const int gate_type) {
    switch (gate_type) {
        case 0: return "INV";
        case 1: return "AND";
        case 2: return "OR";
        case 3: return "XOR";
        case 4: return "NAND";
        case 5: return "NOR";
        case 6: return "XNOR";
        case 7: return "MUX";
        case 8: return "CLKBUF";
        case 9: return "PI";
        case 10: return "PO";
        default: return "UNKNOWN";
    }
}

}

Metrics compute_metrics(const std::string &sched_name,
                        const std::vector<Task *> &tasks,
                        const float gpu_busy_ms,
                        const float makespan_ms) {
    Metrics m;
    m.scheduler_name = sched_name;

    float sum_wait = 0, sum_exec = 0, sum_turnaround = 0;
    float sum_slowdown = 0, sum_weighted_slowdown = 0;
    m.makespan_ms = makespan_ms;
    m.max_wait_ms = 0.f;
    m.max_slowdown = 0.f;
    const int n = static_cast<int>(tasks.size());
    std::unordered_map<int, float> wl_max_completion;
    std::unordered_map<int, std::vector<float>> wl_slowdowns;
    std::unordered_map<int, std::vector<float>> wl_finish_times;

    for (const Task *t: tasks) {
        m.task_snapshots.emplace_back(
            t->id, t->workload_id, t->priority, gate_type_to_string(t->gate_type),
            t->arrival_time_ms, t->wait_time_ms, t->exec_time_ms, t->finish_time_ms
        );

        // per-gate metrics
        float turnaround = t->wait_time_ms + t->exec_time_ms;
        float exec_safe = std::max(t->exec_time_ms, 1e-4f);
        float slowdown = turnaround / exec_safe;
        float weighted_slowdown = slowdown * static_cast<float>(std::max(t->priority, 1));

        sum_wait += t->wait_time_ms;
        sum_exec += t->exec_time_ms;
        sum_turnaround += turnaround;
        sum_slowdown += slowdown;
        sum_weighted_slowdown += weighted_slowdown;

        m.max_wait_ms = std::max(m.max_wait_ms, t->wait_time_ms);
        m.max_slowdown = std::max(m.max_slowdown, slowdown);

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
    m.throughput_gates_per_sec =
        (m.makespan_ms > 0.f) ? static_cast<float>(n) / (m.makespan_ms / 1000.f) : 0.f;
    m.gpu_utilization =
        (m.makespan_ms > 0.f) ? (gpu_busy_ms / m.makespan_ms) : 0.f;

    float jain_sum = 0.f;
    float jain_sum_sq = 0.f;
    for (const auto &[id, completion]: wl_max_completion) {
        jain_sum += completion;
        jain_sum_sq += completion * completion;
    }
    const int wl_count = static_cast<int>(wl_max_completion.size());
    m.jains_fairness =
        (wl_count > 0 && jain_sum_sq > 0.f) ? (jain_sum * jain_sum) / (static_cast<float>(wl_count) * jain_sum_sq) : 0.f;

    for (const auto &[id, slowdowns]: wl_slowdowns) {
        float total = 0.f;
        for (const float slowdown: slowdowns)
            total += slowdown;
        m.per_wl_avg_slowdown[id] = total / static_cast<float>(slowdowns.size());
    }

    for (const auto &[id, finish_times]: wl_finish_times) {
        float mean = 0.f;
        float mean_sq = 0.f;
        for (const float finish: finish_times) {
            mean += finish;
            mean_sq += finish * finish;
        }
        mean /= static_cast<float>(finish_times.size());
        mean_sq /= static_cast<float>(finish_times.size());
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
        avg.throughput_gates_per_sec += m.throughput_gates_per_sec;
        avg.gpu_utilization += m.gpu_utilization;
        avg.jains_fairness += m.jains_fairness;
        avg.avg_slowdown += m.avg_slowdown;
        avg.max_slowdown += m.max_slowdown;
        avg.weighted_avg_slowdown += m.weighted_avg_slowdown;

        for (const auto &[id, value]: m.per_wl_avg_slowdown)
            avg.per_wl_avg_slowdown[id] += value;
        for (const auto &[id, value]: m.per_wl_completion_variance)
            avg.per_wl_completion_variance[id] += value;
    }

    avg.avg_wait_ms /= n;
    avg.max_wait_ms /= n;
    avg.avg_exec_ms /= n;
    avg.avg_turnaround_ms /= n;
    avg.makespan_ms /= n;
    avg.throughput_gates_per_sec /= n;
    avg.gpu_utilization /= n;
    avg.jains_fairness /= n;
    avg.avg_slowdown /= n;
    avg.max_slowdown /= n;
    avg.weighted_avg_slowdown /= n;

    for (auto &[id, value]: avg.per_wl_avg_slowdown)
        value /= n;
    for (auto &[id, value]: avg.per_wl_completion_variance)
        value /= n;

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
        sd.throughput_gates_per_sec += sq(m.throughput_gates_per_sec, mean.throughput_gates_per_sec);
        sd.gpu_utilization += sq(m.gpu_utilization, mean.gpu_utilization);
        sd.jains_fairness += sq(m.jains_fairness, mean.jains_fairness);
        sd.avg_slowdown += sq(m.avg_slowdown, mean.avg_slowdown);
        sd.max_slowdown += sq(m.max_slowdown, mean.max_slowdown);
        sd.weighted_avg_slowdown += sq(m.weighted_avg_slowdown, mean.weighted_avg_slowdown);
    }

    auto sqrtn = [&](float &v) { v = std::sqrt(v / n); };
    sqrtn(sd.avg_wait_ms);
    sqrtn(sd.max_wait_ms);
    sqrtn(sd.avg_exec_ms);
    sqrtn(sd.avg_turnaround_ms);
    sqrtn(sd.makespan_ms);
    sqrtn(sd.throughput_gates_per_sec);
    sqrtn(sd.gpu_utilization);
    sqrtn(sd.jains_fairness);
    sqrtn(sd.avg_slowdown);
    sqrtn(sd.max_slowdown);
    sqrtn(sd.weighted_avg_slowdown);

    return sd;
}

void print_metrics(const Metrics &m) {
    std::cout << "\n=== " << m.scheduler_name << " Metrics ===\n";
    std::printf("  Avg wait:              %10.4f ms\n", m.avg_wait_ms);
    std::printf("  Max wait:              %10.4f ms\n", m.max_wait_ms);
    std::printf("  Avg exec:              %10.4f ms\n", m.avg_exec_ms);
    std::printf("  Avg turnaround:        %10.4f ms\n", m.avg_turnaround_ms);
    std::printf("  Makespan:              %10.4f ms\n", m.makespan_ms);
    std::printf("  Throughput:            %10.4f gates/s\n", m.throughput_gates_per_sec);
    std::printf("  GPU utilization:       %10.4f%%\n", m.gpu_utilization * 100.f);
    std::printf("  Jain's fairness:       %8.4f\n", m.jains_fairness);
    std::printf("  Avg slowdown:          %10.4fx\n", m.avg_slowdown);
    std::printf("  Max slowdown:          %10.4fx\n", m.max_slowdown);
    std::printf("  Weighted slowdown:     %10.4fx\n", m.weighted_avg_slowdown);
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
    f << "Circuit: " << group_name << " | batch_size=" << batch_size << " | runs=" << num_runs << " (averaged)\n\n";
    f << "Generated: " << ts << "\n\n";

    /*********************************************** summary table ***********************************************/
    f << "## Summary\n\n";
    f << "| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) "
            "| Makespan (ms) | Throughput (gates/s) | GPU Util (%) |\n";
    f << "|---|---|---|---|---|---|---|---|\n";
    for (const auto &m: results) {
        f << std::fixed << std::setprecision(4);
        f << "| " << m.scheduler_name
                << " | " << m.avg_wait_ms
                << " | " << m.max_wait_ms
                << " | " << m.avg_exec_ms
                << " | " << m.avg_turnaround_ms
                << " | " << m.makespan_ms
                << " | " << m.throughput_gates_per_sec
                << " | " << m.gpu_utilization * 100.f
                << " |\n";
    }

    /****************************************** standard deviation table ******************************************/
    f << "## Standard Deviation \n\n";
    f << "| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) "
            "| Makespan (ms) | Throughput (gates/s) | GPU Util (%) |\n";
    f << "|---|---|---|---|---|---|---|---|\n";
    for (int i = 0; i < results.size(); i++) {
        const Metrics &m = results[i];
        const Metrics &sd = stds[i];
        f << std::fixed << std::setprecision(4);
        f << "| " << m.scheduler_name
                << " | " << m.avg_wait_ms << " ± " << sd.avg_wait_ms
                << " | " << m.max_wait_ms << " ± " << sd.max_wait_ms
                << " | " << m.avg_exec_ms << " ± " << sd.avg_exec_ms
                << " | " << m.avg_turnaround_ms << " ± " << sd.avg_turnaround_ms
                << " | " << m.makespan_ms << " ± " << sd.makespan_ms
                << " | " << m.throughput_gates_per_sec << " ± " << sd.throughput_gates_per_sec
                << " | " << m.gpu_utilization * 100.f << " ± " << sd.gpu_utilization * 100.f
                << " |\n";
    }

    f.close();
    std::cout << "\nReport written to: " << filename << "\n";
}

void write_report_for_group(const std::vector<Metrics> &results,
                  const std::vector<Metrics> &stds,
                  const std::string &group_name,
                  int batch_size,
                  int num_runs) {
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

    f << "# GPU Scheduler Group Report\n";
    f << "Group: " << group_name << " | batch_size=" << batch_size << " | runs=" << num_runs << " (averaged)\n\n";
    f << "Generated: " << ts << "\n\n";

    f << "## Summary\n\n";
    f << "| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) "
         "| Makespan (ms) | Throughput (gates/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |\n";
    f << "|---|---|---|---|---|---|---|---|---|---|---|---|\n";
    for (const auto &m: results) {
        f << std::fixed << std::setprecision(4);
        f << "| " << m.scheduler_name
          << " | " << m.avg_wait_ms
          << " | " << m.max_wait_ms
          << " | " << m.avg_exec_ms
          << " | " << m.avg_turnaround_ms
          << " | " << m.makespan_ms
          << " | " << m.throughput_gates_per_sec
          << " | " << m.gpu_utilization * 100.f
          << " | " << m.jains_fairness
          << " | " << m.avg_slowdown << "x"
          << " | " << m.max_slowdown << "x"
          << " | " << m.weighted_avg_slowdown << "x |\n";
    }

    f << "## Standard Deviation \n\n";
    f << "| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) "
         "| Makespan (ms) | Throughput (gates/s) | GPU Util (%) | Jain's | Avg Slowdown | Max Slowdown | Wtd Slowdown |\n";
    f << "|---|---|---|---|---|---|---|---|---|---|---|---|\n";
    for (int i = 0; i < results.size(); i++) {
        const Metrics &m = results[i];
        const Metrics &sd = stds[i];
        f << std::fixed << std::setprecision(4);
        f << "| " << m.scheduler_name
          << " | " << m.avg_wait_ms << " ± " << sd.avg_wait_ms
          << " | " << m.max_wait_ms << " ± " << sd.max_wait_ms
          << " | " << m.avg_exec_ms << " ± " << sd.avg_exec_ms
          << " | " << m.avg_turnaround_ms << " ± " << sd.avg_turnaround_ms
          << " | " << m.makespan_ms << " ± " << sd.makespan_ms
          << " | " << m.throughput_gates_per_sec << " ± " << sd.throughput_gates_per_sec
          << " | " << m.gpu_utilization * 100.f << " ± " << sd.gpu_utilization * 100.f
          << " | " << m.jains_fairness << " ± " << sd.jains_fairness
          << " | " << m.avg_slowdown << "x ± " << sd.avg_slowdown
          << " | " << m.max_slowdown << "x ± " << sd.max_slowdown
          << " | " << m.weighted_avg_slowdown << "x ± " << sd.weighted_avg_slowdown << " |\n";
    }

    std::set<int> all_wl_ids;
    for (const auto &m: results)
        for (const auto &[id, _]: m.per_wl_avg_slowdown)
            all_wl_ids.insert(id);

    f << "\n## Per-Workload Avg Slowdown\n\n";
    f << "| Workload |";
    for (const auto &m: results)
        f << " " << m.scheduler_name << " |";
    f << "\n|---|";
    for (size_t i = 0; i < results.size(); ++i)
        f << "---|";
    f << "\n";

    for (const int id: all_wl_ids) {
        f << "| wl " << id << " |";
        for (const auto &m: results) {
            const auto it = m.per_wl_avg_slowdown.find(id);
            if (it != m.per_wl_avg_slowdown.end())
                f << std::fixed << std::setprecision(4) << " " << it->second << "x |";
            else
                f << " — |";
        }
        f << "\n";
    }

    f << "\n## Per-Workload Completion Variance\n\n";
    f << "| Workload |";
    for (const auto &m: results)
        f << " " << m.scheduler_name << " |";
    f << "\n|---|";
    for (size_t i = 0; i < results.size(); ++i)
        f << "---|";
    f << "\n";

    for (const int id: all_wl_ids) {
        f << "| wl " << id << " |";
        for (const auto &m: results) {
            const auto it = m.per_wl_completion_variance.find(id);
            if (it != m.per_wl_completion_variance.end())
                f << std::fixed << std::setprecision(4) << " " << it->second << " ms² |";
            else
                f << " — |";
        }
        f << "\n";
    }

    f.close();
    std::cout << "\nGroup report written to: " << filename << "\n";
}
