#include <memory>
#include <iostream>
class CTest
{
public:
    CTest(int i) :m_iValue(i)
    {
        std::cout << "CTest " << i << std::endl;
    }

    ~CTest()
    {
        std::cout << "~CTest " << m_iValue << std::endl;
    }
private:
    int m_iValue;
};
int main()
{
    /*int *p = new int(18);
    std::unique_ptr<int> p1(p);
    std::unique_ptr<int> p2(new int(118));

    std::unique_ptr<int> p3(p1);
    p1 = p2;*/

    std::unique_ptr<CTest> p1(new CTest(1));
    std::unique_ptr<CTest> p2(new CTest(2));

    p1 = std::move(p2);

    if (!p2)
    {
        std::cout << "p2 is empty" << std::endl;
    }


    std::system("pause");
}