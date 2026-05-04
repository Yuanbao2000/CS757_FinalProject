#pragma once
#include "task.h"
#include "scheduler.h"
#include <vector>

// Sequential batch dispatch runner - launches tasks in batches, then waits for
// entire batch to complete before launching the next batch.
//
// batch_size: maximum number of tasks to launch per batch
void run_scheduler(Scheduler *sched, const std::vector<Task *> &all_tasks,
                   int batch_size, float &out_stream_ms);
