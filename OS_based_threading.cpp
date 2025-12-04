// OS decides which thread to run first -- very basic implementation
#include <iostream>
#include <thread>
using namespace std;

void work()
{
    cout << "Hello from worker thread!\n";
}

int main()
{
    thread t(work); // executes the work function
    cout << "Hello from main thread!\n";

    t.join();
}