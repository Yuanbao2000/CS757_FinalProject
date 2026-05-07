#pragma once

#include "scheduler.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

// prioritizes tasks on the longest path to any sink (critical path scheduling)
class CriticalPathScheduler : public Scheduler {
    std::unordered_map<int, int> longest_path;

    struct Compare {
        const std::unordered_map<int, int> &lp;

        Compare(const std::unordered_map<int, int> &longest_path)
            : lp(longest_path) {}

        bool operator()(const Task *a, const Task *b) const {
            return lp.at(a->id) < lp.at(b->id);  // shorter path = lower priority
        }
    };

    std::priority_queue<Task*, std::vector<Task*>, Compare> pq;

public:
    CriticalPathScheduler() : pq(Compare(longest_path)) {}

    void precompute_downstream(const std::vector<Task *> &all_tasks) {
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
        pq.push(t);
    }

    Task *next() override {
        Task *t = pq.top();
        pq.pop();
        return t;
    }

    [[nodiscard]] bool empty() const override { return pq.empty(); }
    [[nodiscard]] std::string name() const override { return "CriticalPath"; }
};