#include <chrono>
#include <iostream>
#include <thread>
int main()
{
    std::chrono::system_clock::duration d;
    std::chrono::steady_clock::duration s;

    //10s
    std::chrono::seconds s(10);
    std::chrono::minutes m(10);

    std::this_thread::sleep_for(std::chrono::seconds(100));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    //自定义有意义的时间单元

    typedef std::chrono::duration<long, std::ratio<1, 25>> fps_25;
    //40ms
    fps_25 f(1);
    fps_25 f2(2);

    while(1)
    {
        auto t = std::chrono::steady_clock::now();
        auto t1 = t + f;
        getData();
        std::this_thread::sleep_until(t1);

    }
    


}