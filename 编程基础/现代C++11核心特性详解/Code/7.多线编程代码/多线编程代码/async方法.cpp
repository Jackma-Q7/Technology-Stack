#include <chrono>
#include <future>
#include <iostream>
#include <thread>

int func()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << std::this_thread::get_id() << std::endl;
    return 18;
}

int main()
{
    std::cout << "main thread id " << std::this_thread::get_id() << std::endl;
    //auto f = std::async(std::launch::async, func);
    auto f = std::async(func);
    std::cout << f.get() << std::endl;
}