#include <iostream>
#include <future>
#include <thread>

int g_cnt = 0;
std::promise<void> g_promiseObj;
void thread1Func()
{
    std::future<void> f = g_promiseObj.get_future();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    f.get();
    std::cout << "g_cnt " << g_cnt << std::endl;
}

int main()
{
    std::thread t1(thread1Func);

    while (true)
    {
        ++g_cnt;
        if (18 == g_cnt)
        {
            g_promiseObj.set_value();
            break;
        }
    }

    t1.join();
}