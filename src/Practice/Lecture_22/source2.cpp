#include <iostream>
#include <thread>
#include <unistd.h>

void thread_function()
{
//    for(int i = 0; i < 10000; i++);
    sleep(1);
    std::cout<<"thread function Executing"<<std::endl;
}

int main()
{
    std::thread threadObj(thread_function);
    for(int i = 0; i < 10000; i++);
    std::cout<<"Display From MainThread"<<std::endl;
    threadObj.join();
    std::cout<<"Exit of Main function"<<std::endl;
    return 0;
}