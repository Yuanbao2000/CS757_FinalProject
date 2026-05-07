#pragma once

#include "scheduler.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

// prioritizes tasks at earlier levels in the DAG (level-aware scheduling)
class LevelAwareScheduler : public Scheduler {
    std::unordered_map<int, int> task_level;

    struct Compare {
        const std::unordered_map<int, int> &tl;

        Compare(const std::unordered_map<int, int> &task_level)
            : tl(task_level) {}

        bool operator()(const Task *a, const Task *b) const {
            return tl.at(a->id) > tl.at(b->id);  // higher level = lower priority (we want min-heap)
        }
    };

    std::priority_queue<Task*, std::vector<Task*>, Compare> pq;

public:
    LevelAwareScheduler() : pq(Compare(task_level)) {}

    void precompute_downstream(const std::vector<Task *> &all_tasks) {
        std::unordered_map<int, std::vector<int>> children;
        std::unordered_map<int, int> in_degree;

        for (const Task *t: all_tasks) {
            task_level[t->id] = 0;
            in_degree[t->id] = static_cast<int>(t->dependencies.size());
        }

        for (const Task *t: all_tasks) {
            for (int dep_id: t->dependencies) {
                children[dep_id].push_back(t->id);
            }
        }

        std::queue<int> q;
        for (const Task *t: all_tasks)
            if (in_degree[t->id] == 0)
                q.push(t->id);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int child_id: children[curr]) {
                task_level[child_id] = std::max(task_level[child_id], task_level[curr] + 1);
                in_degree[child_id]--;
                if (in_degree[child_id] == 0)
                    q.push(child_id);
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
    [[nodiscard]] std::string name() const override { return "LevelAware"; }
};