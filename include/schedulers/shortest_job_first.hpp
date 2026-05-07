#pragma once
#include "scheduler.h"
#include <queue>
#include <vector>

struct ShortestJobFirstCompare {
    bool operator()(const Task* a, const Task* b) const {
        // Estimate execution time = param_N * kernel_type_weight
        float est_a = estimate_exec_time(a);
        float est_b = estimate_exec_time(b);
        return est_a > est_b;   // min-heap (shortest first)
    }

private:
    static float estimate_exec_time(const Task* t) {
        float type_weight;
        switch (t->type) {
            case KernelType::LATENCY_SENSITIVE:
                type_weight = 1.0f;   // Fast: simple 1-input gates (INV, BUF)
                break;
            case KernelType::MEMORY_BOUND:
                type_weight = 3.0f;   // Medium: 2-3 input gates (NAND, NOR, AND, OR)
                break;
            case KernelType::COMPUTE_BOUND:
                type_weight = 8.0f;   // Slow: 4+ input gates, complex (MUX, large fan-in)
                break;
            default:
                type_weight = 1.0f;
                break;
        }
        return static_cast<float>(t->param_N) * type_weight;
    }
};

class ShortestJobFirstScheduler : public Scheduler {
    std::priority_queue<Task*, std::vector<Task*>, ShortestJobFirstCompare> pq;

public:
    void submit(Task* t) override { pq.push(t); }

    Task* next() override {
        Task* t = pq.top();
        pq.pop();
        return t;
    }

    bool empty() const override { return pq.empty(); }
    std::string name() const override { return "ShortestJobFirst"; }
};
