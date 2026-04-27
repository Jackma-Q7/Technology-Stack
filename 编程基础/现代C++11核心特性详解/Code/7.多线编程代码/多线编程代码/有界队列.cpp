#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <future>
#include <chrono>
template<typename T>
class CBoundedQueue
{
public:
    CBoundedQueue(int maxSize) :m_iMaxSize(maxSize), m_iCnt(0)
    {

    }

    ~CBoundedQueue()
    {

    }

    void Put(const T& x)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        //有一个判断谓词,等价于while(!Pred){m_notFull.wait()}
        m_notFull.wait(lock, std::bind(&CBoundedQueue::CanPut, this));
        m_deqDatas.push_back(x);
        ++m_iCnt;
        if (m_iCnt > m_iMaxSize)
        {
            m_iCnt = m_iMaxSize;
        }

        lock.unlock();

        //m_notEmpty.notify_one();
        m_notEmpty.notify_all();
    }

    T Get()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        //有一个判断谓词,等价于while(!Pred){m_notEmpty.wait()}
        m_notEmpty.wait(lock, std::bind(&CBoundedQueue::CanGet,this));
        T front(m_deqDatas.front());
        m_deqDatas.pop_front();
        --m_iCnt;

        lock.unlock();

        //m_notFull.notify_one();
        m_notFull.notify_all();
        return front;
    }

    bool Empty() const
    {
        std::lock_guard<std::mutex> lock;
        return m_deqDatas.empty();
    }

    bool Full() const
    {
        std::lock_guard<std::mutex> lock;
        return m_iCnt == m_iMaxSize;
    }

private:
    //判断谓词
    bool CanPut() { return m_iCnt < m_iMaxSize; }
    bool CanGet() { return m_iCnt > 0; }
private:
    //计数
    int m_iCnt;
    //最大容量
    int m_iMaxSize;
    //容器类型为deque
    std::deque<T> m_deqDatas;
    //互斥量，对队列进行同步保护
    std::mutex m_mutex;
    //用于限制生产者线程
    std::condition_variable m_notFull;
    //用于限制消费者线程
    std::condition_variable m_notEmpty;
};

void c(CBoundedQueue<int> *d)
{
    auto threadid = std::this_thread::get_id();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    while (1)
    {
        int v = d->Get();
        std::cout << "thread id " << threadid << ",get value " << v << std::endl;
    }
}

int main()
{
    CBoundedQueue<int> d(10);

    std::future<void> ret = std::async(std::launch::async, c, &d);
    std::future<void> ret1 = std::async(std::launch::async, c, &d);


    for (int i = 0; i < 12; ++i)
    {
        d.Put(i);
        std::cout << "put data " << i << std::endl;
    }

    ret.wait();
    ret1.wait();
}