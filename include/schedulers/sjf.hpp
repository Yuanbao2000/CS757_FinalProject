#pragma once
#include "scheduler.h"
#include <queue>
#include <vector>

struct SJFCompare {
    bool operator()(const Task* a, const Task* b) const {
        return a->param_N > b->param_N;   // min-heap
    }
};

class SJFScheduler : public Scheduler {
    std::priority_queue<Task*, std::vector<Task*>, SJFCompare> pq;

public:
    void submit(Task* t) override { pq.push(t); }

    Task* next() override {
        Task* t = pq.top();
        pq.pop();
        return t;
    }

    bool empty() const override { return pq.empty(); }
    std::string name() const override { return "SJF"; }
};
