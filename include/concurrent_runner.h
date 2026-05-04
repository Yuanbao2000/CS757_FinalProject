#pragma once

#include "task.h"
#include "scheduler.h"
#include <vector>

// launches tasks as soon as they're ready without blocking on batch completion,
// allows multiple tasks to execute simultaneously on the GPU, improving utilization.
//
// max_concurrent: maximum number of tasks executing simultaneously (typically set to match GPU SM count or higher)
void run_scheduler_concurrent(Scheduler *sched, const std::vector<Task *> &all_tasks, int max_concurrent,
                              float &out_stream_ms);
