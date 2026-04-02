#include "cuda_MA_partition_fifo.cuh"

// ---------------------------------------------------------------------------
// CUDAMAPartitionerFIFO::run()
//
// Replaces the level-by-level kernel dispatch with a global FIFO scheduler.
// All GPU memory (_invAdj_gpu, _patterns_gpu, etc.) is already allocated and
// populated by prepare_gpu_simulation() from the base class — we just reuse it.
// ---------------------------------------------------------------------------
void CUDAMAPartitionerFIFO::run(const size_t NUM_SIMULATION_RDS,
                                const int    batch_size)
{
  GPUSimulatorFIFO gpuSimulatorFIFO;

  gpuSimulatorFIFO.run_gpu_simulator_FIFO(
      // Circuit dimensions
      _num_PIs,
      _num_inner_gates,
      _num_POs,
      _sum_pi_gates_pos,
      _num_pattern,
      _num_rounds,
      _num_fault,
      // GPU pointers (already set up by prepare_gpu_simulation)
      _pi_gate_po_gate_type_gpu,
      _patterns_gpu,
      _pi_gate_po_output_res_gpu,
      // Host-side graph topology (needed for CPU ready-queue management)
      _adj,                  // fromGate -> toGate  (flat array)
      _adj_index_table,      // index table for _adj
      _invAdj,               // toGate  -> fromGate (flat array)
      _invAdj_index_table,   // index table for _invAdj
      // Device-side graph topology (passed to CUDA kernels)
      _invAdj_gpu,
      _invAdj_index_table_gpu,
      // Pattern data and rounds
      _patterns,
      NUM_SIMULATION_RDS,
      // FIFO batch size (scheduling knob)
      batch_size);

  cudaDeviceSynchronize();
}
