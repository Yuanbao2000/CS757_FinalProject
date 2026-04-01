#include "compute_bound.hpp"
#include <cstdio>

#define TILE_SIZE 16

__global__ void matmul_kernel(const float *A, const float *B, float *C, int N) {
    __shared__ float tileA[TILE_SIZE][TILE_SIZE];
    __shared__ float tileB[TILE_SIZE][TILE_SIZE];

    int row = blockIdx.y * TILE_SIZE + threadIdx.y;
    int col = blockIdx.x * TILE_SIZE + threadIdx.x;
    float sum = 0.f;

    for (int t = 0; t < (N + TILE_SIZE - 1) / TILE_SIZE; ++t) {
        int aCol = t * TILE_SIZE + threadIdx.x;
        int bRow = t * TILE_SIZE + threadIdx.y;

        tileA[threadIdx.y][threadIdx.x] = (row < N && aCol < N) ? A[row * N + aCol] : 0.f;
        tileB[threadIdx.y][threadIdx.x] = (bRow < N && col < N) ? B[bRow * N + col] : 0.f;
        __syncthreads();

        for (int k = 0; k < TILE_SIZE; ++k)
            sum += tileA[threadIdx.y][k] * tileB[k][threadIdx.x];
        __syncthreads();
    }

    if (row < N && col < N)
        C[row * N + col] = sum;
}

void launch_compute_bound(cudaStream_t stream, int N) {
    size_t bytes = N * N * sizeof(float);
    float *dA, *dB, *dC;
    cudaMalloc(&dA, bytes);
    cudaMalloc(&dB, bytes);
    cudaMalloc(&dC, bytes);

    // initialize with 1s for simplicity
    cudaMemsetAsync(dA, 1, bytes, stream);
    cudaMemsetAsync(dB, 1, bytes, stream);

    dim3 block(TILE_SIZE, TILE_SIZE);
    dim3 grid((N + TILE_SIZE - 1) / TILE_SIZE,
              (N + TILE_SIZE - 1) / TILE_SIZE);

    matmul_kernel<<<grid, block, 0, stream>>>(dA, dB, dC, N);

    cudaFreeAsync(dA, stream);
    cudaFreeAsync(dB, stream);
    cudaFreeAsync(dC, stream);
}
