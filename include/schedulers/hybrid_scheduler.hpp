#pragma once

#include "scheduler.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

// hybrid scheduler: combines critical path length + fan-in priority + downstream count
class HybridScheduler : public Scheduler {
    std::vector<Task *> ready_queue;
    std::unordered_map<int, int> longest_path;
    std::unordered_map<int, int> downstream_count;
    std::unordered_map<int, int> fan_in;

public:
    void precompute_downstream(const std::vector<Task *> &all_tasks) {
        // initialize
        for (const Task *t: all_tasks) {
            longest_path[t->id] = 0;
            downstream_count[t->id] = 0;
            fan_in[t->id] = static_cast<int>(t->dependencies.size());
        }

        // compute downstream count (immediate children)
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

        // compute longest path (critical path)
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
    }

    void submit(Task *t) override {
        ready_queue.push_back(t);
    }

    // hybrid score: weighted combination of factors
    Task *next() override {
        auto it = std::max_element(
            ready_queue.begin(), ready_queue.end(),
            [this](Task *a, Task *b) {
                // score = 0.5 * critical_path + 0.3 * fan_in + 0.2 * downstream_count
                float score_a = 0.5f * static_cast<float>(longest_path[a->id]) +
                                0.3f * static_cast<float>(fan_in[a->id]) +
                                0.2f * static_cast<float>(downstream_count[a->id]);
                float score_b = 0.5f * static_cast<float>(longest_path[b->id]) +
                                0.3f * static_cast<float>(fan_in[b->id]) +
                                0.2f * static_cast<float>(downstream_count[b->id]);
                return score_a < score_b;
            }
        );
        Task *t = *it;
        ready_queue.erase(it);
        return t;
    }

    [[nodiscard]] bool empty() const override { return ready_queue.empty(); }
    [[nodiscard]] std::string name() const override { return "Hybrid"; }
};
