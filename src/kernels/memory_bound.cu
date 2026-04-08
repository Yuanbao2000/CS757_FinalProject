#include "memory_bound.hpp"

__global__ void stride_access_kernel(float *data, int N, int stride) {
    int idx = (blockIdx.x * blockDim.x + threadIdx.x) * stride;
    if (idx < N)
        // read-modify-write
        data[idx] = data[idx] * 2.0f + 1.0f;
}

void launch_memory_bound(cudaStream_t stream, int N, int stride) {
    float *d_data;
    cudaMalloc(&d_data, N * sizeof(float));
    cudaMemsetAsync(d_data, 0, N * sizeof(float), stream);

    int threads = 256;
    // each thread accesses one element (strided), so logical threads = N/stride
    int logical_threads = (N + stride - 1) / stride;
    int blocks = (logical_threads + threads - 1) / threads;

    stride_access_kernel<<<blocks, threads, 0, stream>>>(d_data, N, stride);

    cudaFreeAsync(d_data, stream);
}
