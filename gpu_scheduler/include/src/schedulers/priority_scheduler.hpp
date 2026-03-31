struct PriorityCompare {
    bool operator()(Task* a, Task* b) {
        return a->priority > b->priority; // min-heap on priority
    }
};

class PriorityScheduler : public Scheduler {
    std::priority_queue<Task*, std::vector<Task*>, PriorityCompare> pq;
public:
    void submit(Task* t) override { pq.push(t); }
    Task* next() override {
        auto t = pq.top(); pq.pop(); return t;
    }
    bool empty() const override { return pq.empty(); }
    std::string name() const override { return "Priority"; }
};