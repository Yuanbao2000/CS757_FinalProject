class FIFOScheduler : public Scheduler {
    std::queue<Task*> q;
public:
    void submit(Task* t) override { q.push(t); }
    Task* next() override {
        auto t = q.front(); q.pop(); return t;
    }
    bool empty() const override { return q.empty(); }
    std::string name() const override { return "FIFO"; }
};