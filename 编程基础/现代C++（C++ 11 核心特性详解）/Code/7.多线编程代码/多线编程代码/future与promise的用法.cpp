#include <iostream>
#include <future>
#include <thread>
void thread1Func(std::promise<int> promiseObj)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    promiseObj.set_value(18);
}

int main()
{
    std::promise<int> promiseObj;
    std::future<int> f = promiseObj.get_future();

    std::thread t1(thread1Func, std::move(promiseObj));

    std::cout << f.get() << std::endl;
    t1.join();
}