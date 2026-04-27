#include <thread>
#include <condition_variable>
#include <mutex>
#include <iostream>

std::mutex g_mxt;
//条件变量
std::condition_variable g_cnd;
//共享资源
int g_cnt = 0;

bool g_flag = false;
//void thread1Func()
//{
//    //std::lock_guard<std::mutex> lock(g_mxt);
//    while (18 != g_cnt)
//    {
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }
//
//    std::cout << "g_cnt " << g_cnt;
//}
//
//int main()
//{   
//    std::thread thread1(thread1Func);
//    //std::lock_guard<std::mutex> lock(g_mxt);
//    while (1)
//    {
//        ++g_cnt;
//        if (18 == g_cnt)
//        {
//            break;
//        }
//    }
//
//    thread1.join();
//}

void thread1Func()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::unique_lock<std::mutex> lock(g_mxt);
    while (!g_flag)
    {
        g_cnd.wait(lock);
    }
    
    //g_cnd.wait(lock, [] {return g_flag; });

    std::cout << "g_cnt " << g_cnt << std::endl;
}

int main()
{   
    std::thread thread1(thread1Func);

    while (1)
    {
        //std::lock_guard<std::mutex> lock(g_mxt);
        g_mxt.lock();
        ++g_cnt;
        if (18 == g_cnt)
        {
            g_flag = true;
            g_mxt.unlock();

            g_cnd.notify_one();
            break;
        }

        g_mxt.unlock();
    }

    thread1.join();
}

