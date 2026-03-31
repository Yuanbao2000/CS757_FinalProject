#pragma once
#include <cuda_runtime.h>

// stride access (increase N and stride to stress memory bandwidth)
__global__ void stride_access_kernel(float* data, int N, int stride);

void launch_memory_bound(cudaStream_t stream, int N, int stride);
