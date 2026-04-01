cmake_minimum_required(VERSION 3.16)

set(CMAKE_CUDA_COMPILER /usr/local/cuda/bin/nvcc CACHE FILEPATH "" FORCE)
set(CMAKE_CUDA_HOST_COMPILER /usr/bin/g++ CACHE FILEPATH "" FORCE)
set(CMAKE_CUDA_ARCHITECTURES 86)

project(gpu_scheduler LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CUDA_STANDARD 17)

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/src/kernels
        ${CMAKE_SOURCE_DIR}/include/src/schedulers
        /usr/local/cuda/include
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