#pragma once

#include "scheduler.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

// prioritizes tasks on the longest path to any sink (critical path scheduling)
class CriticalPathScheduler : public Scheduler {
    std::vector<Task *> ready_queue;
    std::unordered_map<int, int> longest_path;  // max path length from this task to any sink

public:
    void precompute_downstream(const std::vector<Task *> &all_tasks) {
        // build adjacency list for topological traversal
        std::unordered_map<int, std::vector<int>> children;
        std::unordered_map<int, int> out_degree;

        for (const Task *t: all_tasks) {
            longest_path[t->id] = 0;
            out_degree[t->id] = 0;
        }

        for (const Task *t: all_tasks) {
            for (int dep_id: t->dependencies) {
                children[dep_id].push_back(t->id);
                out_degree[dep_id]++;
            }
        }

        // reverse topological sort (start from sinks, work backward)
        std::queue<int> q;
        for (const Task *t: all_tasks)
            if (out_degree[t->id] == 0)
                q.push(t->id);  // sinks have path length 0

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // find task pointer
            const Task *curr_task = nullptr;
            for (const Task *t: all_tasks) {
                if (t->id == curr) {
                    curr_task = t;
                    break;
                }
            }

            if (!curr_task) continue;

            // update predecessors' longest path
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
        auto it = std::max_element(
            ready_queue.begin(), ready_queue.end(),
            [this](Task *a, Task *b) {
                return longest_path[a->id] < longest_path[b->id];
            }
        );
        Task *t = *it;
        ready_queue.erase(it);
        return t;
    }

    [[nodiscard]] bool empty() const override { return ready_queue.empty(); }
    [[nodiscard]] std::string name() const override { return "CriticalPath"; }
};
