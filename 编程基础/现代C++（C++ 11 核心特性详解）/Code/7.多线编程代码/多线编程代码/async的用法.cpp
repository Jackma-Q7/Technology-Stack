#include <iostream>
#include <future>
#include <chrono>
int func(int v)
{
    std::cout << "this is func,thread id " <<std::this_thread::get_id()<< std::endl;
    return v;
}

int main()
{
    std::cout << "main thread id " << std::this_thread::get_id() << std::endl;
    std::future<int> ret = std::async(std::launch::deferred,func, 18);
    std::cout << "return value " << ret.get() << std::endl;
    
}