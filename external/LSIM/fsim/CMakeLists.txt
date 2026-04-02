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

add_library(fsim_MA_cuda_partition
  ./cuda_MA_partition/cuda_MA_partition.cu ./cuda_MA_partition/cuda_MA_partition.cuh
  ./cuda_MA_partition/cuda_MA_simulation/gpu_simulation.cu ./cuda_MA_partition/cuda_MA_simulation/gpu_simulation.cuh
  # CPU: 
  fault.cpp fault.hpp
  pattern.cpp pattern.hpp
  base_ppg.cpp base_ppg.hpp
  pi.cpp pi.hpp
  po.cpp po.hpp
  gate.cpp gate.hpp
  simulation.cpp simulation.hpp
)

target_link_libraries(fsim_MA_cuda_partition PRIVATE OpenMP::OpenMP_CXX)

if (FSIM_BUILD_CUDA)
  target_link_libraries(${PROJECT_NAME} INTERFACE ${CUBLAS_LIBRARIES})
  target_include_directories(${PROJECT_NAME} INTERFACE ${CUBLAS_INCLUDE_DIRS})
endif()

find_library(KAHYPAR_LIB kahypar PATHS /usr/local/lib)
include_directories(/usr/local/include)
if(KAHYPAR_LIB)
  target_link_libraries(fsim_MA_cuda_partition PRIVATE ${KAHYPAR_LIB})
endif()
message(STATUS "KAHYPAR_LIB: ${KAHYPAR_LIB}")

find_library(MT_KAHYPAR_LIB mtkahypar PATHS /usr/local/lib)
include_directories(/usr/local/include)
if(MT_KAHYPAR_LIB)
  target_link_libraries(fsim_MA_cuda_partition PRIVATE ${MT_KAHYPAR_LIB})
endif()
message(STATUS "MT_KAHYPAR_LIB: ${MT_KAHYPAR_LIB}")

target_compile_options(fsim PRIVATE
  -Wall -Wextra -Wfatal-errors -Wshadow -O3  
)

target_compile_options(fsim_MA_cuda_partition PRIVATE
  -Wall -Wextra -Wfatal-errors -Wshadow -lineinfo -O3 -DNDEBUG
)

# -----------------------------------------------------------------------------
# FIFO scheduler library
# -----------------------------------------------------------------------------
add_library(fsim_MA_cuda_partition_fifo
  ./cuda_MA_partition/cuda_MA_partition_fifo.cu
  ./cuda_MA_partition/cuda_MA_partition_fifo.cuh
  ./cuda_MA_partition/cuda_MA_simulation_fifo/gpu_simulation_fifo.cu
  ./cuda_MA_partition/cuda_MA_simulation_fifo/gpu_simulation_fifo.cuh
)

target_link_libraries(fsim_MA_cuda_partition_fifo PUBLIC fsim_MA_cuda_partition)
target_link_libraries(fsim_MA_cuda_partition_fifo PRIVATE OpenMP::OpenMP_CXX)

target_compile_options(fsim_MA_cuda_partition_fifo PRIVATE
  -Wall -Wextra -Wfatal-errors -Wshadow -lineinfo -O3 -DNDEBUG
)