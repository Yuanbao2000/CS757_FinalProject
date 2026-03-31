#pragma once
#include "task.h"
#include <queue>

class Scheduler {
public:
    virtual ~Scheduler() = default;
    virtual void submit(Task* task) = 0;   // add to ready queue
    virtual Task* next() = 0;             // pick next to run
    virtual bool empty() const = 0;
    virtual std::string name() const = 0;
};
