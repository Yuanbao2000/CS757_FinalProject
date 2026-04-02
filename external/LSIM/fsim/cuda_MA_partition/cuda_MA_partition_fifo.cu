#include "cuda_MA_partition_fifo.cuh"

void CUDAMAPartitionerFIFO::run(const size_t NUM_SIMULATION_RDS, const int batch_size) {
  GPUSimulatorFIFO gpuSimulatorFIFO;

  gpuSimulatorFIFO.run_gpu_simulator_FIFO(
      _num_PIs,
      _num_inner_gates,
      _num_POs,
      _sum_pi_gates_pos,
      _num_pattern,
      _num_rounds,
      _num_fault,
      _pi_gate_po_gate_type_gpu,
      _patterns_gpu,
      _pi_gate_po_output_res_gpu,
      _adj,
      _adj_index_table,
      _invAdj,
      _invAdj_index_table,
      _invAdj_gpu,
      _invAdj_index_table_gpu,
      _patterns,
      NUM_SIMULATION_RDS,
      batch_size);

  cudaDeviceSynchronize();
}