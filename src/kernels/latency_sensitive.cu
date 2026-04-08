#include "latency_sensitive.hpp"

__global__ void vector_add_kernel(const float *a, const float *b, float *c, int N) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < N)
        c[i] = a[i] + b[i];
}

void launch_latency_sensitive(cudaStream_t stream, int N) {
    size_t bytes = N * sizeof(float);
    float *d_a, *d_b, *d_c;
    cudaMalloc(&d_a, bytes);
    cudaMalloc(&d_b, bytes);
    cudaMalloc(&d_c, bytes);

    cudaMemsetAsync(d_a, 1, bytes, stream);
    cudaMemsetAsync(d_b, 1, bytes, stream);

    int threads = 256;
    int blocks = (N + threads - 1) / threads;

    vector_add_kernel<<<blocks, threads, 0, stream>>>(d_a, d_b, d_c, N);

    cudaFreeAsync(d_a, stream);
    cudaFreeAsync(d_b, stream);
    cudaFreeAsync(d_c, stream);
}
