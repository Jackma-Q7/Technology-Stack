#include <chrono>
#include <iostream>

int main()
{
    auto tp = std::chrono::system_clock::now();
    auto d = tp.time_since_epoch();

    std::cout << d.count() << std::endl;
    std::cout << time(NULL) << std::endl;

    time_t now = std::chrono::system_clock::to_time_t(tp);
    std::cout<<ctime(&now)<<std::endl;

    tm *info = localtime(&now);
    //2021-8-15 12:00:00

    char tmp[128] = { 0 };
    sprintf(tmp, "%d-%d-%d %d:%d:%d", info->tm_year + 1900, info->tm_mon + 1, info->tm_mday, info->tm_hour, info->tm_min, info->tm_sec);

    std::cout << tmp << std::endl;
}