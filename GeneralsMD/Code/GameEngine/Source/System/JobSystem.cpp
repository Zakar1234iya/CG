#include "System/JobSystem.h"

std::vector<std::thread> JobSystem::s_workers;
std::queue<JobSystem::Job> JobSystem::s_queue;
std::mutex JobSystem::s_mutex;
std::condition_variable JobSystem::s_cv;
std::atomic<bool> JobSystem::s_running(false);

void JobSystem::Initialize(int workerCount) {
    if (s_running.load()) return;
    s_running.store(true);
    if (workerCount <= 0) {
        workerCount = std::thread::hardware_concurrency() - 1;
        if (workerCount < 1) workerCount = 1;
    }
    s_workers.reserve(workerCount);
    for (int i = 0; i < workerCount; ++i) {
        s_workers.emplace_back(WorkerLoop);
    }
}

JobHandle JobSystem::Submit(std::function<void()> fn, JobHandle dependency) {
    JobHandle handle;
    {
        std::lock_guard<std::mutex> lock(s_mutex);
        Job job;
        job.fn = std::move(fn);
        job.dependencyDone = dependency.m_done;
        job.done = handle.m_done;  // Use the same done flag as the returned handle
        s_queue.push(std::move(job));
    }
    s_cv.notify_one();
    return handle;
}

void JobSystem::WaitFor(JobHandle h) {
    while (!h.IsDone()) {
        std::this_thread::yield();
    }
}

void JobSystem::Shutdown() {
    s_running.store(false);
    s_cv.notify_all();
    for (auto& t : s_workers) {
        if (t.joinable()) t.join();
    }
    s_workers.clear();
}

void JobSystem::WorkerLoop() {
    while (s_running.load()) {
        Job job;
        {
            std::unique_lock<std::mutex> lock(s_mutex);
            s_cv.wait(lock, [] {
                return !s_queue.empty() || !s_running.load();
            });
            if (!s_running.load() && s_queue.empty()) return;
            job = std::move(s_queue.front());
            s_queue.pop();
        }
        if (job.dependencyDone && !job.dependencyDone->load()) {
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            std::lock_guard<std::mutex> lock(s_mutex);
            s_queue.push(std::move(job));
            continue;
        }
        if (job.fn) job.fn();
        // Mark job as done after execution
        if (job.done) {
            job.done->store(true);
        }
    }
}
