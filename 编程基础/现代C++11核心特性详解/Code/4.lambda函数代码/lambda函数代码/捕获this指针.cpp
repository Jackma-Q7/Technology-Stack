#include<iostream>
#include <vector>
#include <functional>

typedef std::function<void()> Func;
class CTest
{
public:
    CTest()
    {
        _vecValue.push_back(18);
        _vecValue.push_back(118);
    }


public:
    void Print()
    {
        [this] (){
            for (auto i : _vecValue)
            {
                std::cout << i << std::endl;
            }
        }();
    }

    Func Get()
    {
        return [this]() {
            for (auto i : _vecValue)
            {
                std::cout << i << std::endl;
            }
        };
    }
private:
    std::vector<int> _vecValue;
};

int main()
{
    CTest t1;
    t1.Print();

    auto f = t1.Get();
    f();

    CTest *t2 = new CTest();
    auto f1 = t2->Get();
    delete t2;
    t2 = nullptr;

    f1();

}