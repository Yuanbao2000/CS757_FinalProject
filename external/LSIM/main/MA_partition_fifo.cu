#include <iostream>
#include <chrono>
#include <memory>
#include <vector>

// FIFO partitioner (inherits from CUDAMAPartitioner)
#include <fsim/cuda_MA_partition/cuda_MA_partition_fifo.cuh>

constexpr std::chrono::duration<double> chro_zero() {
  return std::chrono::duration<double>::zero();
}

int main(int argc, char *argv[]) {
  // Usage: MA_partition_fifo <ckt_path> <flst_path> <ptn_path> [batch_size]
  if (argc < 4) {
    std::cerr << "Usage: " << argv[0]
              << " <ckt_path> <flst_path> <ptn_path> [batch_size=512]"
              << std::endl;
    return 1;
  }

  std::string ckt_path(argv[1]);
  std::string flst_path(argv[2]);
  std::string ptn_path(argv[3]);

  // Optional batch_size argument — lets you sweep the scheduling knob
  // without recompiling.
  int batch_size = 512;
  if (argc >= 5) {
    batch_size = std::atoi(argv[4]);
    if (batch_size <= 0) {
      std::cerr << "batch_size must be > 0, got " << argv[4] << std::endl;
      return 1;
    }
  }

  std::cout << "=== FIFO Scheduler (batch_size=" << batch_size << ") ===" << std::endl;

  CUDAMAPartitionerFIFO partitioner;

  // Read circuit / fault / pattern files (reuses baseline implementation)
  partitioner.read(ckt_path, flst_path, ptn_path);

  // Allocate GPU memory and copy data (reuses baseline implementation)
  partitioner.prepare_gpu_simulation();

  // Run with FIFO scheduler
  const size_t NUM_SIMULATION_RDS = 1;
  partitioner.run(NUM_SIMULATION_RDS, batch_size);

  // Free memory
  partitioner.freeMem();

  return 0;
}
