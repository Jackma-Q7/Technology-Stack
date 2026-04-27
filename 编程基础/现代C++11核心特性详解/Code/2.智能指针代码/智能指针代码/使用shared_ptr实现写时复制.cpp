#include<memory>
#include<iostream>
#include<thread>
#include<mutex>
#include<vector>

typedef std::vector<int> IntList;
typedef std::shared_ptr<IntList> IntListPtr;
IntListPtr g_Ints;
std::mutex g_Mutex;

void read()
{
    IntListPtr IntsPtr;

    {
        std::lock_guard<std::mutex> lock(g_Mutex);
        IntsPtr = g_Ints;
    }

    //对共享数据IntList的读操作
    for (int i = 0; i < g_Ints->size(); ++i)
    {
        std::cout << (*g_Ints)[i] << std::endl;
    }
}

void write(int value)
{
    std::lock_guard<std::mutex> lock(g_Mutex);

    if (!g_Ints.unique())
    {
        g_Ints.reset(new IntList(*g_Ints));
    }

    //对共享数据IntList的写操作
    g_Ints->push_back(value);
}

void ReadThreadFunc()
{
    read();
}

void WriteThreadFunc()
{
    write(18);
}

int main()
{
    g_Ints = std::make_shared<IntList>();
    std::thread Read1(ReadThreadFunc);
    std::thread Read2(ReadThreadFunc);
    std::thread Read3(ReadThreadFunc);
    std::thread Read4(ReadThreadFunc);
    std::thread Read5(ReadThreadFunc);

    std::thread Write(WriteThreadFunc);
    //std::thread Write(WriteThreadFunc);
}