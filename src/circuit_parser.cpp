#include "circuit_parser.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>

Circuit parse_ckt(const std::string &path) {
    std::ifstream f(path);
    if (!f.is_open())
        throw std::runtime_error("Cannot open circuit file: " + path);

    Circuit c;
    f >> c.num_PIs >> c.num_POs >> c.num_inner_gates >> c.num_wires;
    c.total_gates = c.num_PIs + c.num_inner_gates + c.num_POs;

    c.adj.resize(c.total_gates);
    c.invAdj.resize(c.total_gates);
    c.gate_type.assign(c.total_gates, -1);

    for (int i = 0; i < c.num_wires; i++) {
        int gate_0, pin_Y, num_post_gates;
        f >> gate_0 >> pin_Y >> num_post_gates;

        for (int j = 0; j < num_post_gates; j++) {
            int gate_tmp, pin_tmp;
            f >> gate_tmp >> pin_tmp;

            // gate_0 → gate_tmp
            c.adj[gate_0].push_back(gate_tmp);
            c.invAdj[gate_tmp].push_back(gate_0);
        }
    }

    // inner gates occupy indices [num_PIs, num_PIs + num_inner_gates)
    for (int i = c.num_PIs; i < c.num_PIs + c.num_inner_gates; i++) {
        f >> c.gate_type[i];
    }

    std::cout << "[parser] " << path
            << ", total=" << c.total_gates
            << " (PI=" << c.num_PIs
            << " inner=" << c.num_inner_gates
            << " PO=" << c.num_POs << ")\n";
    return c;
}

// fan_in == 0 or 1: LATENCY_SENSITIVE  (PI, INV, BUF)
// fan_in == 2 or 3: MEMORY_BOUND       (NAND2, NOR2, AND2)
// fan_in >= 4:      COMPUTE_BOUND      (NAND4, MUX, wide gates)
static KernelType fan_in_to_kernel_type(const int fan_in) {
    if (fan_in <= 1) return KernelType::LATENCY_SENSITIVE;
    if (fan_in <= 3) return KernelType::MEMORY_BOUND;
    return KernelType::COMPUTE_BOUND;
}

std::vector<std::unique_ptr<Task> > circuit_to_tasks(const Circuit &c, const int workload_id) {
    std::vector<std::unique_ptr<Task> > tasks;
    tasks.reserve(c.total_gates);

    for (int i = 0; i < c.total_gates; i++) {
        int fan_in = static_cast<int>(c.invAdj[i].size());
        const KernelType kt = fan_in_to_kernel_type(fan_in);
        const int param_N = 256 * std::max(1, fan_in);

        auto t = std::make_unique<Task>();
        t->id = i;
        t->workload_id = workload_id;
        t->priority = fan_in; // higher fan-in = higher priority
        t->arrival_time_ms = 0.f;
        t->type = kt;
        t->param_N = param_N;
        t->param_stride = 32;
        t->dep_remaining = fan_in;

        cudaStreamCreate(&t->stream);
        cudaEventCreate(&t->start_event);
        cudaEventCreate(&t->end_event);

        // wire dependencies
        for (int pred: c.invAdj[i])
            t->dependencies.push_back(pred);

        tasks.push_back(std::move(t));
    }

    std::cout << "[tasks]  workload_id=" << workload_id << ", " << tasks.size() << " tasks created\n";
    return tasks;
}
