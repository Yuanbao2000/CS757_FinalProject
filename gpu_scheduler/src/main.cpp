void run_scheduler(Scheduler* sched, std::vector<Task*>& all_tasks) {
    // Seed scheduler with tasks that have no dependencies
    for (auto* t : all_tasks)
        if (t->dep_remaining == 0)
            sched->submit(t);

    float clock = 0.f; // simulated time in ms

    while (!sched->empty()) {
        Task* t = sched->next();

        t->wait_time_ms = clock - t->arrival_time_ms;

        // Record start, launch kernel, record end
        cudaEventRecord(t->start_event, t->stream);
        launch_kernel(t);               // dispatch based on t->type
        cudaEventRecord(t->end_event,  t->stream);

        // Block CPU until this kernel finishes (non-preemptive)
        cudaEventSynchronize(t->end_event);

        cudaEventElapsedTime(&t->exec_time_ms, t->start_event, t->end_event);
        t->finish_time_ms = clock + t->exec_time_ms;
        clock = t->finish_time_ms;

        // Unblock dependents (for dep-aware scheduler)
        notify_dependents(t, sched, all_tasks);
    }
}

int main(int argc, char** argv) {
    run_scheduler(&scheduler, &all_tasks);
    return 0;
}

