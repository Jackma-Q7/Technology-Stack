#include <chrono>
#include <iostream>
int main()
{
    std::chrono::system_clock::time_point t;
    std::chrono::steady_clock::time_point t1;

    auto t1 = std::chrono::system_clock::now();
}