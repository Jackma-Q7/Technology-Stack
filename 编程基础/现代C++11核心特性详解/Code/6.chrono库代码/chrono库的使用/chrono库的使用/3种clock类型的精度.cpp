#include <chrono>
#include <iostream>

int main()
{
    std::cout << "system_clock "<< std::chrono::system_clock::period::den << std::endl;
    std::cout << "steady_clock " << std::chrono::steady_clock::period::den << std::endl;

    //精度 100纳秒
    std::cout << "system_clock " << (double)std::chrono::system_clock::period::num/(double)std::chrono::system_clock::period::den << std::endl;
    //精度 纳秒
    std::cout << "steady_clock " << (double)std::chrono::steady_clock::period::num / (double)std::chrono::steady_clock::period::den << std::endl;

}