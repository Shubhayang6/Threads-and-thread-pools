#include <iostream>
#include <thread>
using namespace std;

/* Every thread needs to have an initial function. */
void hello()
{
    cout << "Hello concurent world\n";
}

int main()
{
    thread t (hello);
    t.join();
}