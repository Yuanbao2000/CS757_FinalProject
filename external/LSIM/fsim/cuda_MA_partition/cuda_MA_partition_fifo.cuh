#pragma once

// Include the baseline partitioner — we inherit everything from it.
#include <fsim/cuda_MA_partition/cuda_MA_partition.cuh>
#include "./cuda_MA_simulation_fifo/gpu_simulation_fifo.cuh"

// ---------------------------------------------------------------------------
// CUDAMAPartitionerFIFO
//
// Inherits all data structures and GPU memory management from the baseline
// CUDAMAPartitioner.  Only run() is overridden to use the FIFO scheduler.
//
// Usage (drop-in replacement):
//   CUDAMAPartitionerFIFO p;
//   p.read(ckt, flst, ptn);
//   p.prepare_gpu_simulation();   // unchanged — reuses baseline
//   p.run(NUM_RDS, batch_size);   // new overload with batch_size knob
//   p.freeMem();
// ---------------------------------------------------------------------------
class CUDAMAPartitionerFIFO : public CUDAMAPartitioner {
public:
  // Override run() — extra batch_size parameter (default 512).
  // The original run(NUM_RDS) signature is also preserved below so that
  // the binary can be built with the same main() pattern.
  void run(const size_t NUM_SIMULATION_RDS = 1,
           const int    batch_size         = 512);
};
