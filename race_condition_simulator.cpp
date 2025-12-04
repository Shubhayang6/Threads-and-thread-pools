#include <iostream>
#include <thread>
#include <vector>
using namespace std;

int counter = 0;

void counter_increment()
{
    for (int i = 0; i < 100000; ++i)
    {
        counter++;
    }
}

int main()
{
    vector<thread> threads;

    for (int i = 0; i < 5; ++i)
    {
        threads.emplace_back(counter_increment);
    }

    for (auto &t : threads)
    {
        t.join();
    }

    cout << "Counter: " << counter << endl;
}