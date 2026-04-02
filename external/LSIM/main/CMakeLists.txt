# CMakeLists.txt in the main directory
add_executable(simple simple.cpp)
add_executable(MA_cuda_partition MA_partition.cu)
add_executable(MA_cuda_partition_fifo MA_partition_fifo.cu)

# Link fsim libraries
target_link_libraries(simple PRIVATE fsim)
target_link_libraries(MA_cuda_partition PRIVATE fsim_MA_cuda_partition)
target_link_libraries(MA_cuda_partition_fifo PRIVATE fsim_MA_cuda_partition_fifo)

# Set compiler flags for the "simple" target
target_compile_options(simple PRIVATE
  -Wall
  -Wextra
  -Wfatal-errors
  -Wshadow
  -O3
)

# Set compiler flags for the baseline target
target_compile_options(MA_cuda_partition PRIVATE
  -Wall
  -Wextra
  -Wfatal-errors
  -Wshadow
  -lineinfo
  -O3
)

# Set compiler flags for the FIFO target
target_compile_options(MA_cuda_partition_fifo PRIVATE
  -Wall
  -Wextra
  -Wfatal-errors
  -Wshadow
  -lineinfo
  -O3
)