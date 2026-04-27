
#include <thread>
#include <condition_variable>
#include <mutex>
#include <iostream>

std::mutex g_mxt;
//条件变量
std::condition_variable g_cnd;
//共享资源
int g_cnt = 0;
//判断条件
bool g_flag = false;

void thread1Func()
{
    std::unique_lock<std::mutex> lock(g_mxt);
    g_cnd.wait(lock);

    if (g_flag)
    {
        std::cout << "thread 1 g_cnt " << g_cnt << std::endl;
        g_flag = false;
    }
    else
    {
        std::cout << "thread 1 g_flag is false" << std::endl;
    }
}

void thread2Func()
{
    std::unique_lock<std::mutex> lock(g_mxt);

    g_cnd.wait(lock);
    if (g_flag)
    {
        std::cout << "thread 2 g_cnt " << g_cnt << std::endl;
        g_flag = false;
    }
    else
    {
        std::cout << "thread 2 g_flag is false" << std::endl;
    }
}

int main()
{
    std::thread thread1(thread1Func);
    std::thread thread2(thread2Func);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    while (1)
    {
        //std::lock_guard<std::mutex> lock(g_mxt);
        ++g_cnt;
        if (18 == g_cnt)
        {
            g_flag = true;
            g_cnd.notify_all();
            break;
        }
    }

    thread1.join();
    thread2.join();
}

