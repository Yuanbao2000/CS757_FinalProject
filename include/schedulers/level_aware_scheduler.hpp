#pragma once

#include "scheduler.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

// prioritizes tasks at earlier levels in the DAG (level-aware scheduling)
class LevelAwareScheduler : public Scheduler {
    std::vector<Task *> ready_queue;
    std::unordered_map<int, int> task_level;  // level in the DAG (0 = sources)

public:
    void precompute_downstream(const std::vector<Task *> &all_tasks) {
        // build adjacency list
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

        // topological sort to assign levels
        std::queue<int> q;
        for (const Task *t: all_tasks)
            if (in_degree[t->id] == 0)
                q.push(t->id);  // sources at level 0

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int child_id: children[curr]) {
                // child's level = max(child's current level, parent's level + 1)
                task_level[child_id] = std::max(task_level[child_id], task_level[curr] + 1);
                in_degree[child_id]--;
                if (in_degree[child_id] == 0)
                    q.push(child_id);
            }
        }
    }

    void submit(Task *t) override {
        ready_queue.push_back(t);
    }

    // pick task at earliest level (lowest level number)
    Task *next() override {
        auto it = std::min_element(
            ready_queue.begin(), ready_queue.end(),
            [this](Task *a, Task *b) {
                return task_level[a->id] < task_level[b->id];
            }
        );
        Task *t = *it;
        ready_queue.erase(it);
        return t;
    }

    [[nodiscard]] bool empty() const override { return ready_queue.empty(); }
    [[nodiscard]] std::string name() const override { return "LevelAware"; }
};
