#pragma once

#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class ThreadPool {
public:
    explicit ThreadPool(size_t numThreads);
    ~ThreadPool();

    void enqueue(function<void()> task);

private:
    vector<thread> workers; // worker threads
    queue<function<void()>> tasks; // shared task queue

    mutex mutex_; // protects the queue
    condition_variable cond_; // notify workers
    bool stop = false; // signal shutdown

    void workerThread();
};

inline ThreadPool::ThreadPool(size_t numThreads)
{
    // Creates the numThreads -> worker threads and each numThread runs workerThread
    for (size_t i = 0; i< numThreads; ++i)
    {
        workers.emplace_back(&ThreadPool::workerThread, this);
    }
}

inline void ThreadPool::workerThread()
{
    while(true){
        function<void()> task;

        {
            unique_lock<mutex> lock(mutex_);

            cond_.wait(lock, [this]{
                return stop || !tasks.empty();
            });

            if(stop && tasks.empty()) // pool stops or tasks exist -> then wake up
                return;
            
            task = move(tasks.front());
            tasks.pop();
        }

        task();
    }
}

inline void ThreadPool::enqueue(function<void()> task)
{
    {
        unique_lock<mutex> lock(mutex_);
        tasks.push(move(task));
    }

    cond_.notify_one();
}

inline ThreadPool::~ThreadPool()
{
    {
        unique_lock<mutex> lock(mutex_);
        stop = true;
    }

    cond_.notify_all();

    for (auto &t : workers)
        t.join();
}