#include "latency_sensitive.hpp"

__global__ void vector_add_kernel(const float *a, const float *b, float *c, int N) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < N)
        c[i] = a[i] + b[i];
}

void launch_latency_sensitive(cudaStream_t stream, int N, float *d_a, float *d_b, float *d_c) {
    size_t bytes = N * sizeof(float);

    cudaMemsetAsync(d_a, 1, bytes, stream);
    cudaMemsetAsync(d_b, 1, bytes, stream);

    int threads = 256;
    int blocks = (N + threads - 1) / threads;

    vector_add_kernel<<<blocks, threads, 0, stream>>>(d_a, d_b, d_c, N);

    // No free - buffers are reused from pool
}
