# CMakeLists.txt in the fsim directory
# Fault simulation - CPU version
add_library(fsim
  fault.cpp fault.hpp
  pattern.cpp pattern.hpp
  base_ppg.cpp base_ppg.hpp
  pi.cpp pi.hpp
  po.cpp po.hpp
  gate.cpp gate.hpp
  simulation.cpp simulation.hpp
)

# Original baseline CUDA target
add_library(fsim_MA_cuda_partition
  ./cuda_MA_partition/cuda_MA_partition.cu ./cuda_MA_partition/cuda_MA_partition.cuh
  ./cuda_MA_partition/cuda_MA_simulation/gpu_simulation.cu ./cuda_MA_partition/cuda_MA_simulation/gpu_simulation.cuh
  fault.cpp fault.hpp
  pattern.cpp pattern.hpp
  base_ppg.cpp base_ppg.hpp
  pi.cpp pi.hpp
  po.cpp po.hpp
  gate.cpp gate.hpp
  simulation.cpp simulation.hpp
)

# New FIFO CUDA target
add_library(fsim_MA_cuda_fifo
  ./cuda_MA_partition/cuda_MA_partition.cu ./cuda_MA_partition/cuda_MA_partition.cuh
  ./cuda_MA_partition/cuda_MA_simulation/gpu_simulation_fifo.cu ./cuda_MA_partition/cuda_MA_simulation/gpu_simulation_fifo.cuh
  fault.cpp fault.hpp
  pattern.cpp pattern.hpp
  base_ppg.cpp base_ppg.hpp
  pi.cpp pi.hpp
  po.cpp po.hpp
  gate.cpp gate.hpp
  simulation.cpp simulation.hpp
)

# -----------------------------------------------------------------------------
# Link OpenMP for CUDA targets
# -----------------------------------------------------------------------------
target_link_libraries(fsim_MA_cuda_partition PRIVATE OpenMP::OpenMP_CXX)
target_link_libraries(fsim_MA_cuda_fifo PRIVATE OpenMP::OpenMP_CXX)

# -----------------------------------------------------------------------------
# Add cuBLAS library if necessary
# -----------------------------------------------------------------------------
if (FSIM_BUILD_CUDA)
  target_link_libraries(${PROJECT_NAME} INTERFACE ${CUBLAS_LIBRARIES})
  target_include_directories(${PROJECT_NAME} INTERFACE ${CUBLAS_INCLUDE_DIRS})
endif()

# Set compiler flags for the "fsim" library
target_compile_options(fsim PRIVATE
  -Wall
  -Wextra
  -Wfatal-errors
  -Wshadow
  -O3
)

target_compile_options(fsim_MA_cuda_partition PRIVATE
  -Wall
  -Wextra
  -Wfatal-errors
  -Wshadow
  -lineinfo
  -O3
  -DNDEBUG
)

target_compile_options(fsim_MA_cuda_fifo PRIVATE
  -Wall
  -Wextra
  -Wfatal-errors
  -Wshadow
  -lineinfo
  -O3
  -DNDEBUG
)