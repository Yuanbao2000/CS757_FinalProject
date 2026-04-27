#pragma once
#include "scheduler.h"
#include <queue>
#include <vector>

struct PriorityCompare {
    // max-heap so higher fan-in priority runs first
    bool operator()(const Task *a, const Task *b) const {
        return a->priority < b->priority;
    }
};

class FaninPriorityScheduler : public Scheduler {
    std::priority_queue<Task *, std::vector<Task *>, PriorityCompare> pq;

public:
    void submit(Task *t) override { pq.push(t); }

    Task *next() override {
        Task *t = pq.top();
        pq.pop();
        return t;
    }

    [[nodiscard]] bool empty() const override { return pq.empty(); }
    [[nodiscard]] std::string name() const override { return "fanin_priority"; }
};
