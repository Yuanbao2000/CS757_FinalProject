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

// Map actual gate types from circuit files to kernel types
// Gate types: 0=INV/BUF, 1=simple, 2=2-input, 4=3-input, 5=4-input, 6=complex
static KernelType gate_type_to_kernel(int gate_type, int fan_in) {
    switch (gate_type) {
        case 0: // INV, BUF - simple 1-input gates
        case 1: // Simple gates
            return KernelType::LATENCY_SENSITIVE;
        case 2: // 2-input gates (NAND2, NOR2, AND2, OR2)
        case 4: // 3-input gates
            return KernelType::MEMORY_BOUND;
        case 5: // 4-input gates
        case 6: // Complex gates (MUX, large fan-in)
            return KernelType::COMPUTE_BOUND;
        default:
            // Fallback to fan-in heuristic for unknown types
            if (fan_in <= 1) return KernelType::LATENCY_SENSITIVE;
            if (fan_in <= 3) return KernelType::MEMORY_BOUND;
            return KernelType::COMPUTE_BOUND;
    }
}

std::vector<std::unique_ptr<Task> > circuit_to_tasks(const Circuit &c, const int workload_id, const int id_offset,
                                                     const float arrival_offset_ms) {
    std::vector<std::unique_ptr<Task> > tasks;
    tasks.reserve(c.total_gates);

    for (int i = 0; i < c.total_gates; i++) {
        int fan_in = static_cast<int>(c.invAdj[i].size());
        // Use actual gate type if available (inner gates only), otherwise use fan-in
        int gate_type = (i >= c.num_PIs && i < c.num_PIs + c.num_inner_gates) ? c.gate_type[i] : -1;
        const KernelType kt = gate_type_to_kernel(gate_type, fan_in);
        const int param_N = 256 * std::max(1, fan_in);

        auto t = std::make_unique<Task>();
        t->id = i + id_offset;
        t->workload_id = workload_id;
        t->priority = fan_in; // higher fan-in = higher priority
        t->arrival_time_ms = arrival_offset_ms;
        t->type = kt;
        t->param_N = param_N;
        t->param_stride = 32;
        t->dep_remaining = fan_in;

        // No per-task stream (pool provides), but need per-task events for timing
        t->stream = nullptr;
        cudaEventCreate(&t->start_event);
        cudaEventCreate(&t->end_event);

        // wire dependencies
        for (int pred: c.invAdj[i])
            t->dependencies.push_back(pred + id_offset);

        tasks.push_back(std::move(t));
    }

    std::cout << "[tasks]  workload_id=" << workload_id << ", " << tasks.size() << " tasks created\n";
    return tasks;
}
