#include <thread>
#include <condition_variable>
#include <mutex>
#include <deque>
#include <iostream>
#include <future>
template<typename T>
class UnBoundedQueue
{
public:
    UnBoundedQueue()
    {
    }

    void Put(const T&x)
    {
        //这个lock用于对生产者间的同步

        {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_deqDatas.push_back(x);
        }


        //信号量用于生产者，消费者间的同步
        //m_notEmpty.notify_one();
        m_notEmpty.notify_all();
    }

    T Get()
    {
        //这个lock用于配合信号量的使用，
        std::unique_lock<std::mutex> lock(m_mutex);
        /*当后面的lambda返回false时，则信号量进入wait，此时自动释放lock
        *等待到信号量后，则再获取lock
        */
        m_notEmpty.wait(lock, [this] {return !m_deqDatas.empty(); });
        T front(m_deqDatas.front());
        m_deqDatas.pop_front();

        return front;
    }

    bool Empty()
    {
        //这个lock用于对消费者，生产者线程的互斥
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_deqDatas.empty();
    }

    size_t Size()
    {
        //这个lock用于对消费者，生产者线程的互斥
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_deqDatas.size();
    }


private:
    std::deque<T> m_deqDatas;
    //互斥量，对队列进行同步保护
    std::mutex m_mutex;
    //用于限制消费者线程
    std::condition_variable m_notEmpty;

};

void c(UnBoundedQueue<int> *d)
{
    auto threadid = std::this_thread::get_id();
    while (1)
    {
        int i = d->Get();
        std::cout << "thread id " << threadid << ",get value " << i << std::endl;
    }
}

int main()
{
    UnBoundedQueue<int> d;

    std::future<void> ret = std::async(std::launch::async, c, &d);
    std::future<void> ret1 = std::async(std::launch::async, c, &d);

    for (int i = 0; i < 10; ++i)
    {
        d.Put(i);
        std::cout << "put data " << i << std::endl;
    }

    ret.wait();
}