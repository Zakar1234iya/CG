#pragma once
#ifndef __JOBSYSTEM_H__
#define __JOBSYSTEM_H__

#include <functional>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <memory>

class JobHandle {
    friend class JobSystem;
    std::shared_ptr<std::atomic<bool>> m_done;
public:
    JobHandle() : m_done(std::make_shared<std::atomic<bool>>(false)) {}
    bool IsDone() const { return m_done->load(); }
};

class JobSystem {
public:
    static void Initialize(int workerCount = 0);
    static JobHandle Submit(std::function<void()> fn, JobHandle dependency = {});
    static void WaitFor(JobHandle h);
    static void Shutdown();

private:
    struct Job {
        std::function<void()> fn;
        std::shared_ptr<std::atomic<bool>> dependencyDone;
    };

    static std::vector<std::thread> s_workers;
    static std::queue<Job> s_queue;
    static std::mutex s_mutex;
    static std::condition_variable s_cv;
    static std::atomic<bool> s_running;

    static void WorkerLoop();
};

#endif
