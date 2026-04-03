#pragma once
#include "task.h"
#include <string>
#include <vector>
#include <memory>

struct Circuit {
    int num_PIs;
    int num_POs;
    int num_inner_gates;
    int num_wires;
    int total_gates; // num_PIs + num_inner_gates + num_POs

    std::vector<std::vector<int> > adj; // list of successor gate ids
    std::vector<std::vector<int> > invAdj; // list of predecessor gate ids

    // GateType enum
    std::vector<int> gate_type;
};

Circuit parse_ckt(const std::string &path);

std::vector<std::unique_ptr<Task> > circuit_to_tasks(const Circuit &c, int workload_id = 0);
