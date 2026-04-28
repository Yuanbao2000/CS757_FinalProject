#include "circuit_parser.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>

namespace {
constexpr int GATE_TYPE_PI = 9;
constexpr int GATE_TYPE_PO = 10;
}

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
    c.gate_num_inputs.assign(c.total_gates, 0);

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

    for (int i = 0; i < c.num_PIs; i++)
        c.gate_type[i] = GATE_TYPE_PI;
    for (int i = c.num_PIs + c.num_inner_gates; i < c.total_gates; i++)
        c.gate_type[i] = GATE_TYPE_PO;

    for (int i = 0; i < c.total_gates; i++)
        c.gate_num_inputs[i] = static_cast<int>(c.invAdj[i].size());

    std::cout << "[parser] " << path
            << ", total=" << c.total_gates
            << " (PI=" << c.num_PIs
            << " inner=" << c.num_inner_gates
            << " PO=" << c.num_POs << ")\n";
    return c;
}

std::vector<std::unique_ptr<Task> > circuit_to_tasks(const Circuit &c, const int workload_id, const int id_offset) {
    std::vector<std::unique_ptr<Task> > tasks;
    tasks.reserve(c.total_gates);

    for (int i = 0; i < c.total_gates; i++) {
        int fan_in = static_cast<int>(c.invAdj[i].size());
        const int param_N = 256 * std::max(1, fan_in);

        auto t = std::make_unique<Task>();
        t->id = i + id_offset;
        t->workload_id = workload_id;
        t->priority = fan_in;
        t->gate_type = c.gate_type[i];
        t->arrival_time_ms = 0.f;
        t->param_N = param_N;
        t->dep_remaining = fan_in;

        // wire dependencies
        for (int pred: c.invAdj[i])
            t->dependencies.push_back(pred + id_offset);

        tasks.push_back(std::move(t));
    }

    std::cout << "[tasks]  workload_id=" << workload_id << ", " << tasks.size() << " tasks created\n";
    return tasks;
}

std::vector<std::unique_ptr<Task> > circuit_to_level_tasks(const Circuit &c, const int workload_id, const int id_offset, const int gate_offset) {
    std::vector<int> level(c.total_gates, 0);
    int max_level = 0;
    for (int i = 0; i < c.total_gates; i++) {
        int gate_level = 0;
        for (const int pred: c.invAdj[i])
            gate_level = std::max(gate_level, level[pred] + 1);
        level[i] = gate_level;
        max_level = std::max(max_level, gate_level);
    }

    std::vector<std::vector<int> > gates_by_level(max_level + 1);
    for (int gate = 0; gate < c.total_gates; gate++)
        gates_by_level[level[gate]].push_back(gate);

    std::vector<std::unique_ptr<Task> > tasks;
    tasks.reserve(gates_by_level.size());

    for (int lvl = 0; lvl <= max_level; lvl++) {
        auto t = std::make_unique<Task>();
        t->id = id_offset + lvl;
        t->workload_id = workload_id;
        t->priority = max_level - lvl;
        t->gate_type = -1;
        t->arrival_time_ms = 0.f;
        t->dep_remaining = lvl == 0 ? 0 : 1;
        t->param_N = static_cast<int>(gates_by_level[lvl].size());
        t->gate_ids.reserve(gates_by_level[lvl].size());
        for (const int gate_id: gates_by_level[lvl])
            t->gate_ids.push_back(gate_id + gate_offset);
        if (lvl > 0)
            t->dependencies.push_back(id_offset + lvl - 1);
        tasks.push_back(std::move(t));
    }

    std::cout << "[level-tasks] workload_id=" << workload_id << ", " << tasks.size() << " tasks created\n";
    return tasks;
}
