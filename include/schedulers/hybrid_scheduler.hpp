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
        std::unordered_map<int, std::vector<int> > children;
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

    Task *next() override {
        // compute max values for normalization
        int max_path = 0, max_downstream = 0;
        for (Task *t: ready_queue) {
            max_path = std::max(max_path, longest_path[t->id]);
            max_downstream = std::max(max_downstream, downstream_count[t->id]);
        }

        // avoid division by zero
        if (max_path == 0) max_path = 1;
        if (max_downstream == 0) max_downstream = 1;

        auto it = std::max_element(

            // normalize to [0, 1]
            ready_queue.begin(), ready_queue.end(),
            [&](Task *a, Task *b) {
                // longer critical path is more important
                float norm_path_a = static_cast<float>(longest_path[a->id]) / max_path;
                float norm_path_b = static_cast<float>(longest_path[b->id]) / max_path;

                // higher downstream unblocks more tasks so it's prioritized
                float norm_down_a = static_cast<float>(downstream_count[a->id]) / max_downstream;
                float norm_down_b = static_cast<float>(downstream_count[b->id]) / max_downstream;

                float score_a = norm_path_a + norm_down_a;
                float score_b = norm_path_b + norm_down_b;
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
