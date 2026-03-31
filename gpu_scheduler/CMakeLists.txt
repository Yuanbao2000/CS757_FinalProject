cmake_minimum_required(VERSION 3.18)
project(gpu_scheduler LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CUDA_STANDARD 17)

# Detect GPU architecture automatically, fallback to sm_75 (Turing) if not found
include(FindCUDA)
if (NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
    set(CMAKE_CUDA_ARCHITECTURES 75)  # Change to 86 for Ampere, 89 for Ada, etc.
endif ()

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/src/kernels
        ${CMAKE_SOURCE_DIR}/include/src/schedulers
)

set(KERNEL_SOURCES
        src/kernels/compute_bound.cu
        src/kernels/memory_bound.cu
        src/kernels/latency_sensitive.cu
)

set(CPP_SOURCES
        src/main.cpp
        src/metrics.cpp
        src/workload.cpp
        src/schedulers/fifo_scheduler.cpp
        src/schedulers/priority_scheduler.cpp
        src/schedulers/dependency_aware_scheduler.cpp
)

add_executable(gpu_scheduler
        ${KERNEL_SOURCES}
        ${CPP_SOURCES}
)

set_target_properties(gpu_scheduler PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON
)

target_compile_options(gpu_scheduler PRIVATE
        $<$<COMPILE_LANGUAGE:CUDA>:
        --expt-relaxed-constexpr
        -lineinfo
        >
)

target_link_libraries(gpu_scheduler PRIVATE
        cuda
        cudart
)