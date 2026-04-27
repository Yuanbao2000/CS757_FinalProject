#pragma once

#include "circuit_parser.h"
#include "task.h"
#include <cuda_runtime.h>
#include <vector>

struct GateBatchExecutor {
    int total_gates = 0;
    int num_inputs_entries = 0;

    int *d_gate_types = nullptr;
    int *d_gate_num_inputs = nullptr;
    int *d_gate_input_starts = nullptr;
    int *d_gate_inputs = nullptr;
    int *d_gate_work_units = nullptr;
    unsigned long long *d_gate_outputs = nullptr;
    int *d_batch_gate_ids = nullptr;
};

GateBatchExecutor create_gate_batch_executor(const Circuit &c, const std::vector<Task *> &tasks);

void destroy_gate_batch_executor(GateBatchExecutor &executor);

void reset_gate_batch_executor(GateBatchExecutor &executor, cudaStream_t stream);

void launch_gate_batch(cudaStream_t stream, GateBatchExecutor &executor, const std::vector<Task *> &batch);
