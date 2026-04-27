#include <thread>
#include <iostream>
#include <vector>
void func()
{
    std::cout << "before move " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "after move " << std::this_thread::get_id() << std::endl;
}

int main()
{
    std::vector<std::thread> vecThreads;
    std::thread t1(func);
    /*std::this_thread::sleep_for(std::chrono::seconds(1));
    std::thread t2(std::move(t1));
    t2.join();*/
    vecThreads.push_back(std::move(t1));
}