#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

int counter = 0;
mutex counterMutex; // mutex declaration

void increment()
{
    for (int i = 0; i < 100000; ++i)
    {
        lock_guard<mutex> lock(counterMutex); // Usage of RAII -- automatically unlocks mutex once loop is out of bound
        counter++;
    }
}

int main()
{
    vector<thread> threads;

    for (int i = 0; i < 5; ++i)
    {
        threads.emplace_back(increment);
    }

    for (auto &t : threads)
    {
        t.join();
    }

    cout << "Counter: " << counter << endl;
}