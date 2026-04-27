#include <thread>
#include <iostream>

void func()
{
    std::cout << "t1 thread id:"<<std::this_thread::get_id() << std::endl;
}

void func1(int a)
{
    std::cout << "a " << a <<" "<<std::this_thread::get_id() << std::endl;
}

struct CTest
{
    void Print(int a)
    {
        std::cout << "in CTest a " << a << " "<<std::this_thread::get_id() << std::endl;
    }
};

/*int main()
{
    std::thread t([] {std::cout << "t thread id:"<<std::this_thread::get_id() << std::endl; });
    std::thread t1(func);
    std::thread t2(func1, 18);
    CTest c;
    std::thread t3(&CTest::Print, &c, 118);
    std::thread t4(std::bind(&CTest::Print, &c, 118));
    t.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}*/

int main()
{
    std::thread t([] {std::cout << "t thread id:" << std::this_thread::get_id() << std::endl; });
    t.join();
    
}