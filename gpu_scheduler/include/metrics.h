struct Metrics {
    float avg_wait_time_ms;
    float avg_turnaround_ms; // wait + exec
    float throughput_tasks_per_sec;
    float gpu_utilization; // sum(exec_time) / total_wall_time
    float jains_fairness; // Jain's index on per-workload completion times
};

// Jain's Fairness Index: (sum(x))^2 / (n * sum(x^2))
float jains_index(const std::vector<float> &completions) {
    float sum = 0, sum_sq = 0;
    for (float x: completions) {
        sum += x;
        sum_sq += x * x;
    }
    int n = completions.size();
    return (sum * sum) / (n * sum_sq);
}
