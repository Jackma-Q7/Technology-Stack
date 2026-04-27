#include <functional>
#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int add1(int a, int b, int c)
{
    return a + b + c;
}

class CTest
{
public:
    CTest(int v) :v_(v)
    {

    }

    int Add(int a)
    {
        return a + v_;
    }

private:
    int v_;
};

int main()
{   //1.将可调用对象的参数个数从多到少的转换
    std::function<int(int)> f = std::bind(add, std::placeholders::_1, 8);
    std::cout << f(10) << std::endl;

    std::function<int(int, int)> f2 = std::bind(add1, std::placeholders::_1, std::placeholders::_2, 18);
    std::cout << f2(10, 10) << std::endl;

    //std::function<int*(int)> f3 = std::bind(add, std::placeholders::_1, 118);
    std::function<float(int)> f4 = std::bind(add, std::placeholders::_1, 118);

    //2.将对象的成员函数转换成调用对象
    CTest c(0);
    /*std::function<int(int)>*/ auto f5 = std::bind(&CTest::Add, &c, std::placeholders::_1);
    std::cout << f5(111) << std::endl;
    std::system("pause");
}