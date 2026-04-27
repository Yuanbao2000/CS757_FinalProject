#include "gate_batch_executor.h"

#include <algorithm>
#include <stdexcept>
#include <vector>

namespace {

__device__ __forceinline__ unsigned long long mix_value(unsigned long long value, int gate_idx, int iter) {
    value ^= 0x9E3779B97F4A7C15ull + static_cast<unsigned long long>(gate_idx * 1315423911u + iter);
    value = (value << 13) | (value >> 51);
    return value;
}

__device__ __forceinline__ unsigned long long compute_gate_value(
    const int gate_idx,
    const int gate_type,
    const int num_inputs,
    const int *gate_input_starts,
    const int *gate_inputs,
    const unsigned long long *gate_outputs
) {
    const int start = gate_input_starts[gate_idx];

    switch (gate_type) {
        case 0: {
            return ~gate_outputs[gate_inputs[start]];
        }
        case 1: {
            unsigned long long value = gate_outputs[gate_inputs[start]];
            for (int i = 1; i < num_inputs; i++)
                value &= gate_outputs[gate_inputs[start + i]];
            return value;
        }
        case 2: {
            unsigned long long value = gate_outputs[gate_inputs[start]];
            for (int i = 1; i < num_inputs; i++)
                value |= gate_outputs[gate_inputs[start + i]];
            return value;
        }
        case 3: {
            unsigned long long value = gate_outputs[gate_inputs[start]];
            for (int i = 1; i < num_inputs; i++)
                value ^= gate_outputs[gate_inputs[start + i]];
            return value;
        }
        case 4: {
            unsigned long long value = gate_outputs[gate_inputs[start]];
            for (int i = 1; i < num_inputs; i++)
                value &= gate_outputs[gate_inputs[start + i]];
            return ~value;
        }
        case 5: {
            unsigned long long value = gate_outputs[gate_inputs[start]];
            for (int i = 1; i < num_inputs; i++)
                value |= gate_outputs[gate_inputs[start + i]];
            return ~value;
        }
        case 6: {
            unsigned long long value = gate_outputs[gate_inputs[start]];
            for (int i = 1; i < num_inputs; i++)
                value ^= gate_outputs[gate_inputs[start + i]];
            return ~value;
        }
        case 7: {
            const unsigned long long a = gate_outputs[gate_inputs[start]];
            const unsigned long long b = gate_outputs[gate_inputs[start + 1]];
            const unsigned long long s = gate_outputs[gate_inputs[start + 2]];
            return (s & b) | (~s & a);
        }
        case 8:
        case 10: {
            return gate_outputs[gate_inputs[start]];
        }
        case 9: {
            return gate_outputs[gate_idx];
        }
        default:
            return static_cast<unsigned long long>(gate_idx);
    }
}

__global__ void initialize_gate_outputs(unsigned long long *gate_outputs, const int total_gates, const int *gate_types) {
    const int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx >= total_gates)
        return;

    if (gate_types[idx] == 9) {
        gate_outputs[idx] = 0x9E3779B97F4A7C15ull ^ (0x1111111111111111ull * static_cast<unsigned long long>(idx + 1));
    } else {
        gate_outputs[idx] = 0ull;
    }
}

__global__ void _run_gate_graph(
    const int *batch_gate_ids,
    const int batch_size,
    const int *gate_types,
    const int *gate_num_inputs,
    const int *gate_input_starts,
    const int *gate_inputs,
    const int *gate_work_units,
    unsigned long long *gate_outputs
) {
    const int tb_idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (tb_idx >= batch_size)
        return;

    const int gate_idx = batch_gate_ids[tb_idx];
    const int gate_type = gate_types[gate_idx];
    const int num_inputs = gate_num_inputs[gate_idx];
    const int work_units = gate_work_units[gate_idx] > 0 ? gate_work_units[gate_idx] : 1;

    unsigned long long value = compute_gate_value(
        gate_idx, gate_type, num_inputs, gate_input_starts, gate_inputs, gate_outputs
    );

    for (int iter = 1; iter < work_units; iter++) {
        const unsigned long long recomputed = compute_gate_value(
            gate_idx, gate_type, num_inputs, gate_input_starts, gate_inputs, gate_outputs
        );
        value = mix_value(value ^ recomputed, gate_idx, iter);
    }

    gate_outputs[gate_idx] = value;
}

} // namespace

GateBatchExecutor create_gate_batch_executor(const Circuit &c, const std::vector<Task *> &tasks) {
    GateBatchExecutor executor;
    executor.total_gates = c.total_gates;

    std::vector<int> gate_input_starts(c.total_gates, 0);
    int total_inputs = 0;
    for (int i = 0; i < c.total_gates; i++) {
        gate_input_starts[i] = total_inputs;
        total_inputs += static_cast<int>(c.invAdj[i].size());
    }

    std::vector<int> gate_inputs;
    gate_inputs.reserve(total_inputs);
    for (int i = 0; i < c.total_gates; i++)
        for (const int pred: c.invAdj[i])
            gate_inputs.push_back(pred);

    std::vector<int> gate_work_units(c.total_gates, 1);
    for (const Task *task: tasks) {
        if (task->id < 0 || task->id >= c.total_gates)
            throw std::runtime_error("Task id out of range while building gate batch executor");
        gate_work_units[task->id] = std::max(task->param_N, 1);
    }

    executor.num_inputs_entries = total_inputs;

    cudaMalloc(reinterpret_cast<void **>(&executor.d_gate_types), c.total_gates * sizeof(int));
    cudaMalloc(reinterpret_cast<void **>(&executor.d_gate_num_inputs), c.total_gates * sizeof(int));
    cudaMalloc(reinterpret_cast<void **>(&executor.d_gate_input_starts), c.total_gates * sizeof(int));
    cudaMalloc(reinterpret_cast<void **>(&executor.d_gate_work_units), c.total_gates * sizeof(int));
    cudaMalloc(reinterpret_cast<void **>(&executor.d_gate_outputs), c.total_gates * sizeof(unsigned long long));
    cudaMalloc(reinterpret_cast<void **>(&executor.d_batch_gate_ids), c.total_gates * sizeof(int));
    if (total_inputs > 0)
        cudaMalloc(reinterpret_cast<void **>(&executor.d_gate_inputs), total_inputs * sizeof(int));

    cudaMemcpy(executor.d_gate_types, c.gate_type.data(), c.total_gates * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(executor.d_gate_num_inputs, c.gate_num_inputs.data(), c.total_gates * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(executor.d_gate_input_starts, gate_input_starts.data(), c.total_gates * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(executor.d_gate_work_units, gate_work_units.data(), c.total_gates * sizeof(int), cudaMemcpyHostToDevice);
    if (total_inputs > 0)
        cudaMemcpy(executor.d_gate_inputs, gate_inputs.data(), total_inputs * sizeof(int), cudaMemcpyHostToDevice);

    return executor;
}

void destroy_gate_batch_executor(GateBatchExecutor &executor) {
    cudaFree(executor.d_gate_types);
    cudaFree(executor.d_gate_num_inputs);
    cudaFree(executor.d_gate_input_starts);
    cudaFree(executor.d_gate_inputs);
    cudaFree(executor.d_gate_work_units);
    cudaFree(executor.d_gate_outputs);
    cudaFree(executor.d_batch_gate_ids);
    executor = {};
}

void reset_gate_batch_executor(GateBatchExecutor &executor, cudaStream_t stream) {
    constexpr int threads = 256;
    const int blocks = (executor.total_gates + threads - 1) / threads;
    initialize_gate_outputs<<<blocks, threads, 0, stream>>>(
        executor.d_gate_outputs, executor.total_gates, executor.d_gate_types
    );
}

void launch_gate_batch(cudaStream_t stream, GateBatchExecutor &executor, const std::vector<Task *> &batch) {
    std::vector<int> batch_gate_ids;
    batch_gate_ids.reserve(batch.size());
    for (const Task *task: batch)
        batch_gate_ids.push_back(task->id);

    cudaMemcpyAsync(
        executor.d_batch_gate_ids,
        batch_gate_ids.data(),
        batch_gate_ids.size() * sizeof(int),
        cudaMemcpyHostToDevice,
        stream
    );

    constexpr int threads = 256;
    const int blocks = static_cast<int>((batch_gate_ids.size() + threads - 1) / threads);
    _run_gate_graph<<<blocks, threads, 0, stream>>>(
        executor.d_batch_gate_ids,
        static_cast<int>(batch_gate_ids.size()),
        executor.d_gate_types,
        executor.d_gate_num_inputs,
        executor.d_gate_input_starts,
        executor.d_gate_inputs,
        executor.d_gate_work_units,
        executor.d_gate_outputs
    );
}
