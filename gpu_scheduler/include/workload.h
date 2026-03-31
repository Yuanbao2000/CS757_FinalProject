#pragma once
#include "task.h"
#include <vector>
#include <string>

struct Workload {
    int id;
    std::string name;
    std::vector<Task *> tasks; // using a pointer here because tasks are owned by main

    // get all tasks that are ready to run
    std::vector<Task *> ready_tasks() const {
        std::vector<Task *> ready;
        for (Task *t: tasks)
            if (t->dep_remaining == 0)
                ready.push_back(t);
        return ready;
    }
};
