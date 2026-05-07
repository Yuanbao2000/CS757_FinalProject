#pragma once

#include "scheduler.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

// hybrid scheduler: combines critical path length + downstream count
class HybridScheduler : public Scheduler {
    std::unordered_map<int, int> longest_path;
    std::unordered_map<int, int> downstream_count;
    int max_path;
    int max_downstream;

    struct TaskScore {
        Task *task;
        float score;

        bool operator<(const TaskScore &other) const {
            return score < other.score;  // lower score = lower priority
        }
    };

    std::priority_queue<TaskScore> pq;

public:
    HybridScheduler() : max_path(1), max_downstream(1) {}

    void precompute_downstream(const std::vector<Task *> &all_tasks) {
        // Initialize
        for (const Task *t: all_tasks) {
            longest_path[t->id] = 0;
            downstream_count[t->id] = 0;
        }

        // Compute downstream count
        std::unordered_map<int, std::vector<int>> children;
        std::unordered_map<int, int> out_degree;

        for (const Task *t: all_tasks) {
            out_degree[t->id] = 0;
            for (int dep_id: t->dependencies) {
                children[dep_id].push_back(t->id);
                downstream_count[dep_id]++;
                out_degree[dep_id]++;
            }
        }

        // Compute longest path (critical path)
        std::queue<int> q;
        for (const Task *t: all_tasks)
            if (out_degree[t->id] == 0)
                q.push(t->id);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            const Task *curr_task = nullptr;
            for (const Task *t: all_tasks) {
                if (t->id == curr) {
                    curr_task = t;
                    break;
                }
            }

            if (!curr_task) continue;

            for (int pred_id: curr_task->dependencies) {
                longest_path[pred_id] = std::max(
                    longest_path[pred_id],
                    longest_path[curr] + 1
                );
                out_degree[pred_id]--;
                if (out_degree[pred_id] == 0)
                    q.push(pred_id);
            }
        }

        // Compute max values for normalization
        max_path = 1;
        max_downstream = 1;
        for (const Task *t: all_tasks) {
            max_path = std::max(max_path, longest_path[t->id]);
            max_downstream = std::max(max_downstream, downstream_count[t->id]);
        }
    }

    void submit(Task *t) override {
        // Compute score once at submission time
        float norm_path = static_cast<float>(longest_path[t->id]) / max_path;
        float norm_downstream = static_cast<float>(downstream_count[t->id]) / max_downstream;
        float score = norm_path + norm_downstream;

        pq.push({t, score});
    }

    Task *next() override {
        Task *t = pq.top().task;
        pq.pop();
        return t;
    }

    [[nodiscard]] bool empty() const override { return pq.empty(); }
    [[nodiscard]] std::string name() const override { return "Hybrid"; }
};