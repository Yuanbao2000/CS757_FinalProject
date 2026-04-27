#include "metrics.h"
#include <iostream>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iomanip>

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

Metrics compute_metrics(const std::string &sched_name, const std::vector<Task *> &tasks, float stream_time_ms) {
    Metrics m;
    m.scheduler_name = sched_name;

    float sum_wait = 0, sum_exec = 0, sum_turnaround = 0;
    m.makespan_ms = 0.f;
    m.max_wait_ms = 0.f;
    const int n = static_cast<int>(tasks.size());

    for (const Task *t: tasks) {
        m.task_snapshots.emplace_back(
            t->id, t->workload_id, t->priority, gate_type_to_string(t->gate_type),
            t->arrival_time_ms, t->wait_time_ms, t->exec_time_ms, t->finish_time_ms
        );

        // metrics
        float turnaround = t->wait_time_ms + t->exec_time_ms;

        sum_wait += t->wait_time_ms;
        sum_exec += t->exec_time_ms;
        sum_turnaround += turnaround;

        m.max_wait_ms = std::max(m.max_wait_ms, t->wait_time_ms);
        m.makespan_ms = std::max(m.makespan_ms, t->finish_time_ms);
    }

    m.avg_wait_ms = sum_wait / static_cast<float>(n);
    m.avg_exec_ms = sum_exec / static_cast<float>(n);
    m.avg_turnaround_ms = sum_turnaround / static_cast<float>(n);
    m.throughput_tasks_per_sec = static_cast<float>(n) / (m.makespan_ms / 1000.f);
    m.gpu_utilization = (stream_time_ms > 0.f) ? sum_exec / stream_time_ms : 0.f;

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
    }

    avg.avg_wait_ms /= n;
    avg.max_wait_ms /= n;
    avg.avg_exec_ms /= n;
    avg.avg_turnaround_ms /= n;
    avg.makespan_ms /= n;
    avg.throughput_tasks_per_sec /= n;
    avg.gpu_utilization /= n;

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
    }

    auto sqrtn = [&](float &v) { v = std::sqrt(v / n); };
    sqrtn(sd.avg_wait_ms);
    sqrtn(sd.max_wait_ms);
    sqrtn(sd.avg_exec_ms);
    sqrtn(sd.avg_turnaround_ms);
    sqrtn(sd.makespan_ms);
    sqrtn(sd.throughput_tasks_per_sec);
    sqrtn(sd.gpu_utilization);

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
            "| Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |\n";
    f << "|---|---|---|---|---|---|---|---|\n";
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
                << " |\n";
    }

    /****************************************** standard deviation table ******************************************/
    f << "## Standard Deviation \n\n";
    f << "| Scheduler | Avg Wait (ms) | Max Wait (ms) | Avg Exec (ms) | Avg Turnaround (ms) "
            "| Makespan (ms) | Throughput (tasks/s) | GPU Util (%) |\n";
    f << "|---|---|---|---|---|---|---|---|\n";
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
                << " |\n";
    }

    f.close();
    std::cout << "\nReport written to: " << filename << "\n";
}
