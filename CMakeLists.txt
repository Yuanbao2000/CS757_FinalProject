cmake_minimum_required(VERSION 3.16)

project(gpu_scheduler LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_ARCHITECTURES 86)

# Find CUDA Toolkit (Windows/MSVC compatible)
find_package(CUDAToolkit REQUIRED)

# Project include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/kernels
    ${CMAKE_SOURCE_DIR}/include/schedulers
    ${CMAKE_SOURCE_DIR}/include/third_party
)

# Source files
set(KERNEL_SOURCES
    src/kernels/compute_bound.cu
    src/kernels/memory_bound.cu
    src/kernels/latency_sensitive.cu
)

set(CPP_SOURCES
    src/main.cpp
    src/metrics.cpp
    src/workload.cpp
    src/circuit_parser.cpp
    src/schedulers/fifo_scheduler.cpp
    src/schedulers/priority_scheduler.cpp
    src/schedulers/dependency_aware_scheduler.cpp
)

# Create the executable
add_executable(gpu_scheduler
    ${KERNEL_SOURCES}
    ${CPP_SOURCES}
)

# CUDA include + lib dirs must come AFTER add_executable
target_include_directories(gpu_scheduler PRIVATE ${CUDAToolkit_INCLUDE_DIRS})
target_link_directories(gpu_scheduler PRIVATE ${CUDAToolkit_LIBRARY_DIR})

# Link CUDA runtime
target_link_libraries(gpu_scheduler PRIVATE CUDA::cudart)

# CUDA compilation settings
set_target_properties(gpu_scheduler PROPERTIES
    CUDA_SEPARABLE_COMPILATION ON
)

target_compile_options(gpu_scheduler PRIVATE
    $<$<COMPILE_LANGUAGE:CUDA>:
        --expt-relaxed-constexpr
        -lineinfo
    >
)
