#include <chrono>
#include <iostream>
using namespace std;
using namespace chrono;
int main()
{
    //三种clock及它们的duration和time_point
    /*std::chrono::system_clock s;
    std::chrono::steady_clock st;
    std::chrono::high_resolution_clock h;

    std::chrono::system_clock::duration sd;
    std::chrono::steady_clock::duration std;
    std::chrono::high_resolution_clock::duration hd;

    std::chrono::system_clock::time_point stp;
    std::chrono::steady_clock::time_point sttp;
    std::chrono::high_resolution_clock::time_point hdtp;*/

    //获取当前时间
    auto tp = std::chrono::system_clock::now();
    //从纪元时间到现在的毫秒数
    auto md = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
    long ms = md.count() % 1000;


    //格式化时间
    time_t now = std::chrono::system_clock::to_time_t(tp);
    tm *info = localtime(&now);
    char timefmt[128] = { 0 };
    sprintf(timefmt, "%d-%d-%d %d:%d:%d %d", info->tm_year + 1900, info->tm_mon + 1, info->tm_mday, info->tm_hour, info->tm_min, info->tm_sec, ms);
    std::cout << timefmt << std::endl;
}