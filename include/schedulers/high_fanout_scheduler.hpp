#pragma once

#include "scheduler.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

// prioritizes tasks with the most immediate downstream dependents (high fan-out first)
class HighFanoutScheduler : public Scheduler {
    std::unordered_map<int, int> downstream_count;

    struct Compare {
        const std::unordered_map<int, int> &dc;

        Compare(const std::unordered_map<int, int> &downstream_count)
            : dc(downstream_count) {}

        bool operator()(const Task *a, const Task *b) const {
            return dc.at(a->id) < dc.at(b->id);  // less downstream = lower priority
        }
    };

    std::priority_queue<Task*, std::vector<Task*>, Compare> pq;

public:
    HighFanoutScheduler() : pq(Compare(downstream_count)) {}  // initialize pq with comparator!

    void precompute_downstream(const std::vector<Task *> &all_tasks) {
        // count how many tasks list it as a dependency
        for (const Task *t: all_tasks)
            downstream_count[t->id] = 0;

        for (const Task *t: all_tasks)
            for (int dep_id: t->dependencies)
                downstream_count[dep_id]++;
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
    [[nodiscard]] std::string name() const override { return "HighFanout"; }
};