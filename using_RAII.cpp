#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

mutex lock_mutex;
// auto thread_id = this_thread::get_id();

void test(int x, int y)
{
    lock_guard lock(lock_mutex);
    cout << "Hello from Thread" << endl;
    cout << "Argument passed in: " << x << endl;
    cout << "The sum is: " << x + y << endl;
}

int main()
{

    auto RAII = [](int y)
    {
        lock_guard lock(lock_mutex);
        cout << "The J-thread id is: " << this_thread::get_id() << endl;
        cout << "RAII Index: " << y << endl;
    };

    vector<jthread> J_threads;

    for (int i = 0; i < 10; ++i)
    {
        J_threads.push_back(jthread(RAII, i));
    }

/* Since j_threads are included we need not perform separate joins. */

    // for (int i = 0; i < 10; ++i)
    // {
    //     threads[i].join();
    // }

    auto lambda = [](int x)
    {
        lock_guard lock(lock_mutex);
        cout << "Hello from the lambda function with value: " << x << endl;
    };

    thread my_thread(&test, 100, 200);
    thread lambda_thread(lambda, 500);

    my_thread.join();
    lambda_thread.join();

    cout << "Hello from my main thread" << endl;

    return 0;
}