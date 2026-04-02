#ifndef MA_GPU_SIMULATION_FIFO_H
#define MA_GPU_SIMULATION_FIFO_H

#include <chrono>
#include <thread>
#include <assert.h>
#include <climits>
#include <fstream>
#include <iostream>
#include <limits>
#include <omp.h>
#include <queue>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <cmath>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <cublas_v2.h>
#include <cassert>
#include <fsim/fsim.hpp>

// error checking macro
#define cudaCheckErrorsFIFO(msg) \
    do { \
        cudaError_t __err = cudaGetLastError(); \
        if (__err != cudaSuccess) { \
            fprintf(stderr, "Fatal error: %s (%s at %s:%d)\n", \
                msg, cudaGetErrorString(__err), \
                __FILE__, __LINE__); \
            fprintf(stderr, "*** FAILED - ABORTING\n"); \
            exit(1); \
        } \
    } while (0)

#define CUDA_CHECK_FIFO(call) \
    do { \
        cudaError_t err = call; \
        if (err != cudaSuccess) { \
            fprintf(stderr, "CUDA Error in %s at line %d: %s\n", __FILE__, __LINE__, cudaGetErrorString(err)); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)

// -----------------------------------------------------------------------
// CUDA kernel for executing a batch of gates (arbitrary gate indices)
// Different from baseline: takes an explicit list of gate indices instead
// of a contiguous level range.
// -----------------------------------------------------------------------
__global__ void _run_gate_DSP_fifo(
    const int  *batch_gate_indices,   // [batch_size] global gate indices to execute
    const int   batch_size,
    const int  *_invAdj_gpu,
    const int  *_invAdj_index_table_gpu,
    const int  *_pi_gate_po_gate_type_gpu,
    uint32_t   *_pi_gate_po_output_res_gpu,
    const uint32_t *_patterns_gpu,
    const size_t rd,
    const int   _num_PIs);

// -----------------------------------------------------------------------
// GPUSimulatorFIFO: same gate-logic as baseline, new scheduling strategy
//
// Scheduling strategy:
//   - CPU maintains a ready queue (all input-dependencies satisfied)
//   - At each step, dequeue up to `batch_size` gates -> one kernel launch
//   - After kernel returns, update in-degrees of successors; newly-ready
//     gates are enqueued (global FIFO order within each wave)
//   - This continues until all gates are processed
//
// The batch_size knob lets you explore the latency/throughput tradeoff:
//   - Small batch  -> fine-grained scheduling, more kernel launches (overhead)
//   - Large batch  -> coarser scheduling, fewer launches, higher GPU util
// -----------------------------------------------------------------------
class GPUSimulatorFIFO {

public:
  // Entry point — mirrors the baseline GPUSimulator interface so the caller
  // only needs to swap the class name.
  void run_gpu_simulator_FIFO(
      const int   num_PIs,
      const int   num_inner_gates,
      const int   num_POs,
      const int   sum_pi_gates_pos,
      const int   num_pattern,
      const size_t num_rounds,
      const int   num_fault,
      const int  *_pi_gate_po_gate_type_gpu,
      const uint32_t *_patterns_gpu,
      uint32_t   *_pi_gate_po_output_res_gpu,
      // graph topology (host side — needed for ready-queue management)
      const int  *adj_host,              // flat adjacency list  (fromGate->toGate)
      const int  *adj_index_table_host,  // index table for adj
      const int  *invAdj_host,           // flat inv-adj list    (toGate->fromGate)
      const int  *invAdj_index_table_host,
      // graph topology (device side — passed straight to the kernel)
      const int  *_invAdj_gpu,
      const int  *_invAdj_index_table_gpu,
      const std::vector<Pattern> &_patterns,
      const size_t NUM_SIMULATION_RDS,
      const int   batch_size = 512);    // <-- scheduling knob

private:
  int _num_PIs;
  int _num_inner_gates;
  int _num_POs;
  int _sum_pi_gates_pos;
  int _num_pattern;
  size_t _num_rounds;
  int _num_fault;

  void _run_gates_FIFO(
      const int  *adj_host,
      const int  *adj_index_table_host,
      const int  *invAdj_host,
      const int  *invAdj_index_table_host,
      const int  *_invAdj_gpu,
      const int  *_invAdj_index_table_gpu,
      const int  *_pi_gate_po_gate_type_gpu,
      const uint32_t *_patterns_gpu,
      const std::vector<Pattern> &_patterns,
      uint32_t   *_pi_gate_po_output_res_gpu,
      const int   batch_size);
};

#endif  // MA_GPU_SIMULATION_FIFO_H
