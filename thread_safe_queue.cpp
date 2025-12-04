#include <mutex>
#include <queue>
#include <condition_variable>
#include <functional>

using namespace std;

class TaskQueue
{
public:
    void push(function<void()> task)
    {
        unique_lock<mutex> lock(mutex_); // lock the mutex
        queue_.push(move(task));         // move new task in the queue
        cond_.notify_one();              // wake one waiting worker
    }

    function<void()> pop()
    {
        unique_lock<mutex> lock(mutex_);

        // Wait until queue is not empty
        cond_.wait(lock, [&]
                   { return !queue_.empty(); }); // if queue is empty => the thread sleeps and releases the mutex

        auto task = move(queue_.front()); // task is assigned with the front work. LIFO rule
        queue_.pop();                     // removed the task
        return task;
    }

private:
    queue<function<void()>> queue_;
    mutex mutex_;
    condition_variable cond_;
};

// nothing below -- dummy --
int main()
{
    return 0;
}