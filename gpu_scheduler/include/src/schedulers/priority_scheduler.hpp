#pragma once
#include "scheduler.h"
#include <queue>
#include <vector>

struct PriorityCompare {
    // min-heap so lower priority runs first
    bool operator()(const Task *a, const Task *b) const {
        return a->priority > b->priority;
    }
};

class PriorityScheduler : public Scheduler {
    std::priority_queue<Task *, std::vector<Task *>, PriorityCompare> pq;

public:
    void submit(Task *t) override { pq.push(t); }

    Task *next() override {
        Task *t = pq.top();
        pq.pop();
        return t;
    }

    bool empty() const override { return pq.empty(); }
    std::string name() const override { return "Priority"; }
};
