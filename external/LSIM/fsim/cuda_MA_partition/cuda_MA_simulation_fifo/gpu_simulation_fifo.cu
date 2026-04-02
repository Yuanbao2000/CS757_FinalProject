#include "./gpu_simulation_fifo.cuh"

constexpr int  _NUM_THREADS_FIFO  = 512;
constexpr uint32_t UINT32T_BITS_FIFO = std::numeric_limits<uint32_t>::digits;

// -----------------------------------------------------------------------
// Device helper functions — identical logic to baseline gpu_simulation.cu
// Redeclared here with a _fifo suffix so this translation unit is fully
// self-contained and does NOT create ODR conflicts with the baseline.
// -----------------------------------------------------------------------

__device__ __forceinline__
void _apply_INV_fifo(const int gate_idx,
                     const int *_invAdj_gpu,
                     const int *_invAdj_index_table_gpu,
                     uint32_t  *_pi_gate_po_output_res_gpu)
{
  const int s_loc = _invAdj_index_table_gpu[2*gate_idx+0];
  _pi_gate_po_output_res_gpu[gate_idx] =
      ~_pi_gate_po_output_res_gpu[_invAdj_gpu[s_loc]];
}

__device__ __forceinline__
void _apply_AND_fifo(const int gate_idx,
                     const int *_invAdj_gpu,
                     const int *_invAdj_index_table_gpu,
                     uint32_t  *_pi_gate_po_output_res_gpu)
{
  const int s_loc = _invAdj_index_table_gpu[2*gate_idx+0];
  const int e_loc = _invAdj_index_table_gpu[2*gate_idx+1];
  uint32_t ret = _pi_gate_po_output_res_gpu[_invAdj_gpu[s_loc]];
  for (int n = s_loc+1; n < e_loc; n++)
    ret &= _pi_gate_po_output_res_gpu[_invAdj_gpu[n]];
  _pi_gate_po_output_res_gpu[gate_idx] = ret;
}

__device__ __forceinline__
void _apply_OR_fifo(const int gate_idx,
                    const int *_invAdj_gpu,
                    const int *_invAdj_index_table_gpu,
                    uint32_t  *_pi_gate_po_output_res_gpu)
{
  const int s_loc = _invAdj_index_table_gpu[2*gate_idx+0];
  const int e_loc = _invAdj_index_table_gpu[2*gate_idx+1];
  uint32_t ret = _pi_gate_po_output_res_gpu[_invAdj_gpu[s_loc]];
  for (int n = s_loc+1; n < e_loc; n++)
    ret |= _pi_gate_po_output_res_gpu[_invAdj_gpu[n]];
  _pi_gate_po_output_res_gpu[gate_idx] = ret;
}

__device__ __forceinline__
void _apply_XOR_fifo(const int gate_idx,
                     const int *_invAdj_gpu,
                     const int *_invAdj_index_table_gpu,
                     uint32_t  *_pi_gate_po_output_res_gpu)
{
  const int s_loc = _invAdj_index_table_gpu[2*gate_idx+0];
  const int e_loc = _invAdj_index_table_gpu[2*gate_idx+1];
  uint32_t ret = _pi_gate_po_output_res_gpu[_invAdj_gpu[s_loc]];
  for (int n = s_loc+1; n < e_loc; n++)
    ret ^= _pi_gate_po_output_res_gpu[_invAdj_gpu[n]];
  _pi_gate_po_output_res_gpu[gate_idx] = ret;
}

__device__ __forceinline__
void _apply_NAND_fifo(const int gate_idx,
                      const int *_invAdj_gpu,
                      const int *_invAdj_index_table_gpu,
                      uint32_t  *_pi_gate_po_output_res_gpu)
{
  const int s_loc = _invAdj_index_table_gpu[2*gate_idx+0];
  const int e_loc = _invAdj_index_table_gpu[2*gate_idx+1];
  uint32_t ret = _pi_gate_po_output_res_gpu[_invAdj_gpu[s_loc]];
  for (int n = s_loc+1; n < e_loc; n++)
    ret &= _pi_gate_po_output_res_gpu[_invAdj_gpu[n]];
  _pi_gate_po_output_res_gpu[gate_idx] = ~ret;
}

__device__ __forceinline__
void _apply_NOR_fifo(const int gate_idx,
                     const int *_invAdj_gpu,
                     const int *_invAdj_index_table_gpu,
                     uint32_t  *_pi_gate_po_output_res_gpu)
{
  const int s_loc = _invAdj_index_table_gpu[2*gate_idx+0];
  const int e_loc = _invAdj_index_table_gpu[2*gate_idx+1];
  uint32_t ret = _pi_gate_po_output_res_gpu[_invAdj_gpu[s_loc]];
  for (int n = s_loc+1; n < e_loc; n++)
    ret |= _pi_gate_po_output_res_gpu[_invAdj_gpu[n]];
  _pi_gate_po_output_res_gpu[gate_idx] = ~ret;
}

__device__ __forceinline__
void _apply_XNOR_fifo(const int gate_idx,
                      const int *_invAdj_gpu,
                      const int *_invAdj_index_table_gpu,
                      uint32_t  *_pi_gate_po_output_res_gpu)
{
  const int s_loc = _invAdj_index_table_gpu[2*gate_idx+0];
  const int e_loc = _invAdj_index_table_gpu[2*gate_idx+1];
  uint32_t ret = _pi_gate_po_output_res_gpu[_invAdj_gpu[s_loc]];
  for (int n = s_loc+1; n < e_loc; n++)
    ret ^= _pi_gate_po_output_res_gpu[_invAdj_gpu[n]];
  _pi_gate_po_output_res_gpu[gate_idx] = ~ret;
}

__device__ __forceinline__
void _apply_MUX_fifo(const int gate_idx,
                     const int *_invAdj_gpu,
                     const int *_invAdj_index_table_gpu,
                     uint32_t  *_pi_gate_po_output_res_gpu)
{
  const int s_loc = _invAdj_index_table_gpu[2*gate_idx+0];
  const uint32_t a = _pi_gate_po_output_res_gpu[_invAdj_gpu[s_loc+0]];
  const uint32_t b = _pi_gate_po_output_res_gpu[_invAdj_gpu[s_loc+1]];
  const uint32_t s = _pi_gate_po_output_res_gpu[_invAdj_gpu[s_loc+2]];
  _pi_gate_po_output_res_gpu[gate_idx] = (s & b) | (a & ~s);
}

__device__ __forceinline__
void _apply_CLKBUF_fifo(const int gate_idx,
                        const int *_invAdj_gpu,
                        const int *_invAdj_index_table_gpu,
                        uint32_t  *_pi_gate_po_output_res_gpu)
{
  const int s_loc = _invAdj_index_table_gpu[2*gate_idx+0];
  _pi_gate_po_output_res_gpu[gate_idx] =
      _pi_gate_po_output_res_gpu[_invAdj_gpu[s_loc]];
}

__device__ __forceinline__
void _apply_PI_fifo(const int gate_idx,
                    uint32_t  *_pi_gate_po_output_res_gpu,
                    const uint32_t pattern_val)
{
  _pi_gate_po_output_res_gpu[gate_idx] = pattern_val;
}

__device__ __forceinline__
void _apply_PO_fifo(const int gate_idx,
                    const int *_invAdj_gpu,
                    const int *_invAdj_index_table_gpu,
                    uint32_t  *_pi_gate_po_output_res_gpu)
{
  const int s_loc = _invAdj_index_table_gpu[2*gate_idx+0];
  _pi_gate_po_output_res_gpu[gate_idx] =
      _pi_gate_po_output_res_gpu[_invAdj_gpu[s_loc]];
}

// -----------------------------------------------------------------------
// Main FIFO kernel: each thread handles one gate from the batch.
// The gate indices are explicitly supplied (not a contiguous level range).
// -----------------------------------------------------------------------
__global__ void _run_gate_DSP_fifo(
    const int  *batch_gate_indices,
    const int   batch_size,
    const int  *_invAdj_gpu,
    const int  *_invAdj_index_table_gpu,
    const int  *_pi_gate_po_gate_type_gpu,
    uint32_t   *_pi_gate_po_output_res_gpu,
    const uint32_t *_patterns_gpu,
    const size_t rd,
    const int   _num_PIs)
{
  int t_idx = blockDim.x * blockIdx.x + threadIdx.x;
  if (t_idx >= batch_size) return;

  int gate_idx = batch_gate_indices[t_idx];
  int type     = _pi_gate_po_gate_type_gpu[gate_idx];

  switch (type) {
    case 0:
      _apply_INV_fifo(gate_idx, _invAdj_gpu, _invAdj_index_table_gpu,
                      _pi_gate_po_output_res_gpu);
      break;
    case 1:
      _apply_AND_fifo(gate_idx, _invAdj_gpu, _invAdj_index_table_gpu,
                      _pi_gate_po_output_res_gpu);
      break;
    case 2:
      _apply_OR_fifo(gate_idx, _invAdj_gpu, _invAdj_index_table_gpu,
                     _pi_gate_po_output_res_gpu);
      break;
    case 3:
      _apply_XOR_fifo(gate_idx, _invAdj_gpu, _invAdj_index_table_gpu,
                      _pi_gate_po_output_res_gpu);
      break;
    case 4:
      _apply_NAND_fifo(gate_idx, _invAdj_gpu, _invAdj_index_table_gpu,
                       _pi_gate_po_output_res_gpu);
      break;
    case 5:
      _apply_NOR_fifo(gate_idx, _invAdj_gpu, _invAdj_index_table_gpu,
                      _pi_gate_po_output_res_gpu);
      break;
    case 6:
      _apply_XNOR_fifo(gate_idx, _invAdj_gpu, _invAdj_index_table_gpu,
                       _pi_gate_po_output_res_gpu);
      break;
    case 7:
      _apply_MUX_fifo(gate_idx, _invAdj_gpu, _invAdj_index_table_gpu,
                      _pi_gate_po_output_res_gpu);
      break;
    case 8:
      _apply_CLKBUF_fifo(gate_idx, _invAdj_gpu, _invAdj_index_table_gpu,
                         _pi_gate_po_output_res_gpu);
      break;
    case 9:
      _apply_PI_fifo(gate_idx, _pi_gate_po_output_res_gpu,
                     _patterns_gpu[_num_PIs * rd + gate_idx]);
      break;
    case 10:
      _apply_PO_fifo(gate_idx, _invAdj_gpu, _invAdj_index_table_gpu,
                     _pi_gate_po_output_res_gpu);
      break;
    case 11:
    default:
      break;
  }
}

// -----------------------------------------------------------------------
// CPU-side FIFO scheduling loop
// -----------------------------------------------------------------------
void GPUSimulatorFIFO::_run_gates_FIFO(
    const int  *adj_host,
    const int  *adj_index_table_host,
    const int  *invAdj_host,
    const int  *invAdj_index_table_host,
    const int  *_invAdj_gpu,
    const int  *_invAdj_index_table_gpu,
    const int  *_pi_gate_po_gate_type_gpu,
    const uint32_t *_patterns_gpu,
    const std::vector<Pattern> &_patterns,
    uint32_t   *_pi_gate_po_output_res_gpu,
    const int   batch_size)
{
  // ---- Build in-degree table from host invAdj ----
  std::vector<int> indegree(_sum_pi_gates_pos, 0);
  for (int g = 0; g < _sum_pi_gates_pos; g++) {
    int s = invAdj_index_table_host[2*g+0];
    int e = invAdj_index_table_host[2*g+1];
    indegree[g] = e - s;
  }

  // ---- Seed the FIFO ready queue with all gates that have indegree == 0 ----
  // In this circuit representation that is exactly the PIs (level 0).
  std::queue<int> ready;
  for (int g = 0; g < _sum_pi_gates_pos; g++) {
    if (indegree[g] == 0) ready.push(g);
  }

  // ---- Allocate device buffer for one batch of gate indices ----
  int *batch_gpu = nullptr;
  CUDA_CHECK_FIFO(cudaMalloc(&batch_gpu, batch_size * sizeof(int)));

  // Host-side staging buffer (reused across batches)
  std::vector<int> batch_host;
  batch_host.reserve(batch_size);

  // CUDA timing events
  cudaEvent_t ev_start, ev_stop;
  CUDA_CHECK_FIFO(cudaEventCreate(&ev_start));
  CUDA_CHECK_FIFO(cudaEventCreate(&ev_stop));

  int batch_id = 0;
  int gates_done = 0;

  // ---- FIFO scheduling loop ----
  // We do ONE simulation round (rd = 0). The outer NUM_SIMULATION_RDS loop
  // is handled by the caller (run_gpu_simulator_FIFO).
  const size_t rd = 0;

  while (!ready.empty()) {
    // Dequeue up to batch_size gates
    batch_host.clear();
    while (!ready.empty() && (int)batch_host.size() < batch_size) {
      batch_host.push_back(ready.front());
      ready.pop();
    }

    const int cur_batch = (int)batch_host.size();

    // Copy batch indices to device
    CUDA_CHECK_FIFO(cudaMemcpy(batch_gpu, batch_host.data(),
                               cur_batch * sizeof(int),
                               cudaMemcpyHostToDevice));

    // Launch kernel
    const int num_threads = (cur_batch < _NUM_THREADS_FIFO) ? cur_batch : _NUM_THREADS_FIFO;
    const int num_blocks  = (cur_batch + _NUM_THREADS_FIFO - 1) / _NUM_THREADS_FIFO;

    CUDA_CHECK_FIFO(cudaEventRecord(ev_start));

    _run_gate_DSP_fifo<<<num_blocks, num_threads>>>(
        batch_gpu, cur_batch,
        _invAdj_gpu, _invAdj_index_table_gpu,
        _pi_gate_po_gate_type_gpu,
        _pi_gate_po_output_res_gpu,
        _patterns_gpu, rd, _num_PIs);

    CUDA_CHECK_FIFO(cudaEventRecord(ev_stop));
    CUDA_CHECK_FIFO(cudaEventSynchronize(ev_stop));

    float ms = 0.0f;
    CUDA_CHECK_FIFO(cudaEventElapsedTime(&ms, ev_start, ev_stop));
    printf("Batch %4d | Gates: %8d | Runtime: %8.3f us\n",
           batch_id, cur_batch, ms * 1000.0f);

    // ---- Update in-degrees and enqueue newly-ready successors ----
    // This runs on the CPU after the kernel has returned (non-preemptive:
    // we wait for the kernel to finish before deciding what to run next).
    for (int g : batch_host) {
      int s = adj_index_table_host[2*g+0];
      int e = adj_index_table_host[2*g+1];
      for (int idx = s; idx < e; idx++) {
        int succ = adj_host[idx];
        indegree[succ]--;
        if (indegree[succ] == 0) {
          ready.push(succ);
        }
      }
    }

    gates_done += cur_batch;
    batch_id++;
  }

  printf("FIFO scheduling complete: %d gates in %d batches (batch_size=%d)\n",
         gates_done, batch_id, batch_size);

  CUDA_CHECK_FIFO(cudaEventDestroy(ev_start));
  CUDA_CHECK_FIFO(cudaEventDestroy(ev_stop));
  CUDA_CHECK_FIFO(cudaFree(batch_gpu));
}

// -----------------------------------------------------------------------
// Public entry point
// -----------------------------------------------------------------------
void GPUSimulatorFIFO::run_gpu_simulator_FIFO(
    const int   num_PIs,
    const int   num_inner_gates,
    const int   num_POs,
    const int   sum_pi_gates_pos,
    const int   num_pattern,
    const size_t num_rounds,
    const int   num_fault,
    const int  *_pi_gate_po_gate_type_gpu,
    const uint32_t *_patterns_gpu,
    uint32_t   *_pi_gate_po_output_res_gpu,
    const int  *adj_host,
    const int  *adj_index_table_host,
    const int  *invAdj_host,
    const int  *invAdj_index_table_host,
    const int  *_invAdj_gpu,
    const int  *_invAdj_index_table_gpu,
    const std::vector<Pattern> &_patterns,
    const size_t NUM_SIMULATION_RDS,
    const int   batch_size)
{
  _num_PIs          = num_PIs;
  _num_inner_gates  = num_inner_gates;
  _num_POs          = num_POs;
  _sum_pi_gates_pos = sum_pi_gates_pos;
  _num_pattern      = num_pattern;
  _num_rounds       = num_rounds;
  _num_fault        = num_fault;

  for (size_t rd = 0; rd < NUM_SIMULATION_RDS; rd++) {
    _run_gates_FIFO(adj_host, adj_index_table_host,
                    invAdj_host, invAdj_index_table_host,
                    _invAdj_gpu, _invAdj_index_table_gpu,
                    _pi_gate_po_gate_type_gpu,
                    _patterns_gpu,
                    _patterns,
                    _pi_gate_po_output_res_gpu,
                    batch_size);
  }
}
