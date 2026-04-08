#pragma once
#include "scheduler.h"
#include <vector>
#include <unordered_map>
#include <algorithm>

// dependency aware scheduler picks tasks with the most downstream dependents

class DependencyAwareScheduler : public Scheduler {
    std::vector<Task *> ready_queue;
    std::unordered_map<int, int> downstream_count;

public:
    void precompute_downstream(const std::vector<Task *> &all_tasks) {
        // count how many tasks list it as a dependency
        for (const Task *t: all_tasks)
            downstream_count[t->id] = 0;

        for (const Task *t: all_tasks)
            for (int dep_id: t->dependencies)
                downstream_count[dep_id]++;
    }

    void submit(Task *t) override {
        ready_queue.push_back(t);
    }

    // pick the ready task with the highest downstream count
    Task *next() override {
        auto it = std::max_element(
            ready_queue.begin(), ready_queue.end(),
            [this](Task *a, Task *b) {
                return downstream_count[a->id] < downstream_count[b->id];
            }
        );
        Task *t = *it;
        ready_queue.erase(it);
        return t;
    }

    [[nodiscard]] bool empty() const override { return ready_queue.empty(); }
    [[nodiscard]] std::string name() const override { return "DependencyAware"; }
};
