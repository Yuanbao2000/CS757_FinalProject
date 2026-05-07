#pragma once

#include "task.h"
#include "scheduler.h"
#include <vector>

// max_concurrent: maximum number of tasks executing simultaneously (typically set to match GPU SM count or higher)
void run_scheduler(Scheduler *sched, const std::vector<Task *> &all_tasks, int batch_size,
                              float &out_stream_ms, int &out_max_concurrent);
