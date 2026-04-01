#pragma once
#include <cuda_runtime.h>

// matrix multiply (increase N to stress compute)
__global__ void matmul_kernel(const float *A, const float *B, float *C, int N);

void launch_compute_bound(cudaStream_t stream, int N); // allocates & launches
