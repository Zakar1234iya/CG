#include "JobSystem.h"
#include <iostream>
#include <thread>

std::vector<std::thread> JobSystem::s_workers;
std::queue<JobSystem::Job> JobSystem::s_queue;
std::mutex JobSystem::s_mutex;
std::condition_variable JobSystem::s_cv;
bool JobSystem::s_running = false;

void JobSystem::Init(int workerCount)
{
    if (workerCount == 0)
        workerCount = std::thread::hardware_concurrency() - 1;

    s_running = true;
    for (int i = 0; i < workerCount; ++i) {
        s_workers.emplace_back(WorkerLoop);
    }
}

void JobSystem::Shutdown()
{
    s_running = false;
    s_cv.notify_all();
    for (auto& thread : s_workers) {
        if (thread.joinable())
            thread.join();
    }
    s_workers.clear();
}

JobHandle JobSystem::Submit(std::function<void()> fn, JobHandle dependency)
{
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

void JobSystem::WaitFor(JobHandle handle)
{
    if (!handle.m_done)
        return;

    while (!handle.m_done->load()) {
        std::this_thread::yield();
    }
}

void JobSystem::Flush()
{
    std::unique_lock<std::mutex> lock(s_mutex);
    s_cv.wait(lock, [] { return s_queue.empty(); });
}

void JobSystem::WorkerLoop()
{
    while (s_running) {
        Job job;
        {
            std::unique_lock<std::mutex> lock(s_mutex);
            s_cv.wait(lock, [] { return !s_queue.empty() || !s_running; });
            if (!s_running || s_queue.empty())
                continue;
            job = std::move(s_queue.front());
            s_queue.pop();
        }
        if (job.fn) job.fn();
        // Mark job as done after execution
        if (job.done) {
            job.done->store(true);
        }
    }
}