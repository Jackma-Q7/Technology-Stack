#include <mutex>
#include <thread>
#include <iostream>

int g_cnt = 0;
std::mutex g_mutex;
//std::lock_guard<std::mutex> lock(g_mutex);//RAII
void func(int c)
{
    for (int i = 0; i < c; ++i)
    {
        //g_mutex.lock();
        {
            std::lock_guard<std::mutex> lock(g_mutex);
            g_cnt++;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    }
}

int main()
{
    std::thread t1(func,100);
    std::thread t2(func,100);
    t1.join();
    t2.join();

    std::cout << g_cnt << std::endl;
}