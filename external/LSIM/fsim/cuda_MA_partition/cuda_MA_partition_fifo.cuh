#pragma once

#include <fsim/cuda_MA_partition/cuda_MA_partition.cuh>
#include <fsim/cuda_MA_partition/cuda_MA_simulation_fifo/gpu_simulation_fifo.cuh>

class CUDAMAPartitionerFIFO : public CUDAMAPartitioner {
public:
  void run(const size_t NUM_SIMULATION_RDS = 1, const int batch_size = 512);
};