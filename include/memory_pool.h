#pragma once
#include <cuda_runtime.h>
#include <vector>
#include <stdexcept>

// Pre-allocated memory pool for kernel launches
// Eliminates per-launch allocation overhead
struct MemoryPool {
    // Maximum N for compute_bound matrices (supports up to 8192x8192)
    static constexpr int MAX_MATRIX_N = 8192;
    // Maximum N for memory_bound linear buffers (2M elements)
    static constexpr int MAX_LINEAR_N = 2 * 1024 * 1024;

    // For compute_bound: needs 3 buffers of N*N*sizeof(float)
    // For memory_bound: needs 1 buffer of N*sizeof(float)
    // For latency_sensitive: needs 3 buffers of N*sizeof(float)
    // We allocate for the largest case (compute_bound matrix)

    struct BufferSet {
        float *buf1; // General purpose buffer 1
        float *buf2; // General purpose buffer 2
        float *buf3; // General purpose buffer 3
        size_t size1; // Size in bytes of buf1
        size_t size2; // Size in bytes of buf2
        size_t size3; // Size in bytes of buf3
    };

    std::vector<BufferSet> buffers; // One per stream

    // Initialize memory pool for num_streams
    void init(int num_streams) {
        buffers.resize(num_streams);

        // Allocate for worst case: compute_bound needs MAX_MATRIX_N*MAX_MATRIX_N*sizeof(float) for 3 buffers
        size_t max_matrix_bytes = static_cast<size_t>(MAX_MATRIX_N) * MAX_MATRIX_N * sizeof(float);

        for (int i = 0; i < num_streams; i++) {
            cudaMalloc(&buffers[i].buf1, max_matrix_bytes);
            cudaMalloc(&buffers[i].buf2, max_matrix_bytes);
            cudaMalloc(&buffers[i].buf3, max_matrix_bytes);

            buffers[i].size1 = max_matrix_bytes;
            buffers[i].size2 = max_matrix_bytes;
            buffers[i].size3 = max_matrix_bytes;

            // Check for allocation errors
            cudaError_t err = cudaGetLastError();
            if (err != cudaSuccess) {
                throw std::runtime_error("Memory pool allocation failed: " +
                                         std::string(cudaGetErrorString(err)));
            }
        }
    }

    // Get buffer set for stream index
    BufferSet &get(int stream_idx) {
        return buffers[stream_idx];
    }

    // Cleanup
    void cleanup() {
        for (auto &buf_set: buffers) {
            if (buf_set.buf1) cudaFree(buf_set.buf1);
            if (buf_set.buf2) cudaFree(buf_set.buf2);
            if (buf_set.buf3) cudaFree(buf_set.buf3);
        }
        buffers.clear();
    }

    ~MemoryPool() {
        cleanup();
    }
};
