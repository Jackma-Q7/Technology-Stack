#include <iostream>
#include <algorithm>
#include <vector>
void PrintValue(int i)
{
    if (i < 6)
    {
        std::cout << i << std::endl;
    }
}

class CPrintValue
{
public:
    CPrintValue(int i) :_value(i)
    {

    }

    void operator()(int i)
    {
        if (i < _value)
        {
            std::cout << i << std::endl;
        }
    }
private:
    int _value;
};

void check(int iCheck)
{
    std::vector<int> vecAllInfo = { 1,2,3,4,5,10,100 };
    //std::for_each(vecAllInfo.begin(), vecAllInfo.end(), PrintValue);

    /*CPrintValue t(6);
    std::for_each(vecAllInfo.begin(), vecAllInfo.end(), t);
    CPrintValue t1(100);
    std::for_each(vecAllInfo.begin(), vecAllInfo.end(), t1);*/

    std::for_each(vecAllInfo.begin(), vecAllInfo.end(), [=](int i) {
        if (i < iCheck)
        {
            std::cout << i << std::endl;
        }
    });
}

int main()
{
    check(100);
}