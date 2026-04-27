#include <functional>
#include <iostream>

int add(int a, int b)
{
    return a + b;
}

struct CAdd
{
    int operator()(int a, int b)
    {
        return a + b;
    }
};

int main()
{
    std::function<int(int, int)> f = add;
    std::cout << f(10, 8) << std::endl;

    //std::function<int(int, int)> f2 = CAdd();
    std::cout << f(11, 9) << std::endl;

    int(*fp)(int, int) = add;
    //std::function<int(int, int)> f3 = fp;
    std::cout << f(12, 10) << std::endl;

    std::function<void(int)> f1;
    if (!f1)
    {
        std::cout << "f1 can't callable" << std::endl;
    }
    
    f1(18);

}