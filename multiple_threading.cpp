#include <iostream>
#include <thread>
#include <vector>

using namespace std;

// Overview of how data race occurs

void work(int id)
{
    cout << "Hello from worker thread " << id << endl;
}

int main()
{
    vector<thread> threads;

    // Create 5 threads
    for (int i = 0; i < 5; ++i)
    {
        threads.emplace_back(work, i);
    }

    cout << "Hello from main thread!" << endl;

    // Wait for all threads
    for (auto &t : threads)
    {
        t.join();
    }

    return 0;
}
