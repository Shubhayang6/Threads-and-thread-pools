#include <iostream>
#include <thread>
using namespace std;

void test(int x){
    cout <<"Hello from Thread"<<endl;;
    cout << "Argument passed in: "<<x<<endl;
}

int main()
{
    thread my_thread(&test, 100);
    my_thread.join();
    cout << "Hello from my main thread"<<endl;

    return 0;
}