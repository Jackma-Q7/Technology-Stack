#include <chrono>
#include <iostream>
#include <thread>
int main()
{
    auto before = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto after = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> d = after - before;
    std::cout << d.count() << std::endl;

}