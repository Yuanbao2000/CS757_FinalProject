#pragma once
#include <cuda_runtime.h>

// low latency op (keep N small (~1024) to simualte latency-sensitive inference ops)
__global__ void vector_add_kernel(const float* a, const float* b, float* c, int N);

void launch_latency_sensitive(cudaStream_t stream, int N);
