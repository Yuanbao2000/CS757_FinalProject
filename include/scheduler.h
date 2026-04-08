#pragma once
#include "task.h"
#include <string>

class Scheduler {
public:
    virtual ~Scheduler() = default;

    virtual void submit(Task *task) = 0;

    virtual Task *next() = 0;

    [[nodiscard]] virtual bool empty() const = 0;

    [[nodiscard]] virtual std::string name() const = 0;
};
