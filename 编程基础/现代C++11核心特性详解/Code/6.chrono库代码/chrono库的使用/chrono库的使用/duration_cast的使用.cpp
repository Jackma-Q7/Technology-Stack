#include <chrono>
#include <iostream>
#include <thread>
int main()
{
    auto t1 = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto t2 = std::chrono::steady_clock::now();

    std::chrono::duration<double, std::milli> d = t2 - t1;
    //std::chrono::duration<long long, std::milli> d1 = std::chrono::duration_cast<std::chrono::duration<long long, std::milli>>(t2 - t1);
    std::chrono::duration<long long, std::milli> d1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    
    std::chrono::minutes m(10);
    std::chrono::seconds s = m;
    std::chrono::milliseconds ms = m;
    std::chrono::seconds s1 = std::chrono::duration_cast<std::chrono::seconds>(ms);
}