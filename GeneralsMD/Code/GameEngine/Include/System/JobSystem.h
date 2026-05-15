#pragma once
#ifndef __JOBSYSTEM_H__
#define __JOBSYSTEM_H__

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <memory>
#include <atomic>

/**
 * Job Handle - Returned from Submit() to track job completion
 */
struct JobHandle
{
    std::shared_ptr<std::atomic<bool>> m_done;

    JobHandle() : m_done(std::make_shared<std::atomic<bool>>(false)) {}

    bool IsDone() const { return m_done && m_done->load(); }
};

/**
 * JobSystem - Multi-threaded job dispatch (Phase 6)
 *
 * Submit work to be executed on worker threads.
 * Workers pull from a shared queue and execute jobs.
 * Use JobHandle to wait for completion.
 */
class JobSystem
{
public:
    struct Job
    {
        std::function<void()> fn;
        std::shared_ptr<std::atomic<bool>> dependencyDone;
        std::shared_ptr<std::atomic<bool>> done;  // Track completion status for this job
    };

    static std::vector<std::thread> s_workers;
    static std::queue<Job> s_queue;
    static std::mutex s_mutex;
    static std::condition_variable s_cv;
    static bool s_running;

public:
    static void Init(int workerCount = 0);
    static void Shutdown();
    static JobHandle Submit(std::function<void()> fn, JobHandle dependency = {});
    static void WaitFor(JobHandle handle);
    static void Flush();

private:
    static void WorkerLoop();
};

#endif // __JOBSYSTEM_H__