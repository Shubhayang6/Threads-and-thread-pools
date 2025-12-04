#include "thread_pool.h"
#include <iostream>
using namespace std;

void work(int id)
{
    cout << "Task " << id << " running\n";
}

int main()
{
    ThreadPool pool(4);

    for (int i =0;i<10;++i)
    {
        pool.enqueue([i] {work(i);});
    }

    cout<< "Tasks queued\n";
}