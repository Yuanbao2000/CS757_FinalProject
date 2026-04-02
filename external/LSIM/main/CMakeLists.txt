# CMakeLists.txt in the main directory

add_executable(simple simple.cpp)
add_executable(MA_cuda_partition MA_partition.cu)
<<<<<<< HEAD
add_executable(MA_cuda_fifo MA_fifo.cu)
=======
add_executable(MA_cuda_partition_fifo MA_partition_fifo.cu)
>>>>>>> 2e6b045f1660cb5ac12411bb0cd898bc7eb25a0d

# Link fsim libraries
target_link_libraries(simple PRIVATE fsim)
target_link_libraries(MA_cuda_partition PRIVATE fsim_MA_cuda_partition)
<<<<<<< HEAD
target_link_libraries(MA_cuda_fifo PRIVATE fsim_MA_cuda_fifo)
=======
target_link_libraries(MA_cuda_partition_fifo PRIVATE fsim_MA_cuda_partition_fifo)
>>>>>>> 2e6b045f1660cb5ac12411bb0cd898bc7eb25a0d

# Set compiler flags for the "simple" target
target_compile_options(simple PRIVATE
  -Wall
  -Wextra
  -Wfatal-errors
  -Wshadow
  -O3
)

<<<<<<< HEAD
# Set compiler flags for baseline CUDA
=======
# Set compiler flags for the baseline target
>>>>>>> 2e6b045f1660cb5ac12411bb0cd898bc7eb25a0d
target_compile_options(MA_cuda_partition PRIVATE
  -Wall
  -Wextra
  -Wfatal-errors
  -Wshadow
  -lineinfo
  -O3
)

<<<<<<< HEAD
# Set compiler flags for FIFO CUDA
target_compile_options(MA_cuda_fifo PRIVATE
=======
# Set compiler flags for the FIFO target
target_compile_options(MA_cuda_partition_fifo PRIVATE
>>>>>>> 2e6b045f1660cb5ac12411bb0cd898bc7eb25a0d
  -Wall
  -Wextra
  -Wfatal-errors
  -Wshadow
  -lineinfo
  -O3
)