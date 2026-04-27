#include <memory>
#include <iostream>
#include <string>
class CTest
{
public:
    CTest()
    {
        std::cout << "CTest" << std::endl;
    }

    ~CTest()
    {
        std::cout << "~CTest" << std::endl;
    }
};


class CTest1 :public CTest
{
public:
    CTest1()
    {
        std::cout << "CTest1" << std::endl;
    }

    ~CTest1()
    {
        std::cout << "~CTest1" << std::endl;
    }
};

class CTest2 :public CTest
{
public:
    CTest2()
    {
        std::cout << "CTest1" << std::endl;
    }

    ~CTest2()
    {
        std::cout << "~CTest1" << std::endl;
    }
};

std::unique_ptr<CTest> CTestMake(const std::string& str)
{
    std::unique_ptr<CTest> p;
    if ("Test1" == str)
    {
        p.reset(new CTest1);
    }
    else if ("Test2" == str)
    {
        p.reset(new CTest2);
    }
    else
    {
        p.reset(new CTest);
    }

    return p;
}

int main()
{
    std::unique_ptr<CTest> p = CTestMake("Test1");
    std::shared_ptr<CTest> p1 = CTestMake("Test2");
}