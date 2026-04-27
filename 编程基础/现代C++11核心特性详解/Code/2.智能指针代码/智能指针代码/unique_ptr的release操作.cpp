#include <memory>
#include <iostream>

class CTest
{
public:
    CTest(int i):m_iValue(i)
    {
        std::cout << "CTest" << i<<std::endl;
    }

    ~CTest()
    {
        std::cout << "~CTest()" << m_iValue<<std::endl;
    }
private:
    int m_iValue;
};
int main()
{
    {
        std::unique_ptr<CTest> p(new CTest(1));
        /* std::unique_ptr<CTest> p2(new CTest(2));*/

         //p2.reset(p.release());

        //release只是释放所有权，并不会释放对象
        //CTest* p3 = p.release();
        /*if (!p)
        {
            std::cout << "p is empty" << std::endl;
        }*/

        CTest* p4 = p.get();
    }
   

    std::system("pause");
}