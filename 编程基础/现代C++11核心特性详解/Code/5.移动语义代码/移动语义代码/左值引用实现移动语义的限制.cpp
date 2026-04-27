#include <iostream>
class CPointTest
{
public:
    //默认构造函数
    CPointTest()
    {
        m_size = 1024;
        m_pInts = new int[1024];
        memset(m_pInts, 0, 1024);
    }

    //构造函数
    CPointTest(int* pData, int size) :m_pInts(pData), m_size(size)
    {

    }

    //析构函数
    ~CPointTest()
    {
        std::cout << "~CPointTest()" << std::endl;
        delete[] m_pInts;
        m_pInts = NULL;
    }

    //CPointTest，其包含指针，要实现正确的复制语义，拷贝构造函数及赋值函数必须对指针进行深拷贝
    CPointTest(const CPointTest& t)
    {
        std::cout << "CPointTest(const CPointTest& t)" << std::endl;
        m_size = t.m_size;
        m_pInts = new int[m_size];
        memcpy(m_pInts, t.m_pInts, m_size);
    }
    
    CPointTest(CPointTest&& t) noexcept
    {
        std::cout << "CPointTest(CPointTest&& t)" << std::endl;
        m_size = t.m_size;
        m_pInts = t.m_pInts;
        t.m_pInts = nullptr;

    }

    CPointTest& operator=(CPointTest&& t) noexcept
    {
        std::cout << "CPointTest& operator=(CPointTest&& t)" << std::endl;
        if (this != &t)
        {
            if (NULL != m_pInts)
            {
                delete[] m_pInts;
                m_pInts = NULL;
            }

            m_size = t.m_size;
            m_pInts = t.m_pInts;
            t.m_pInts = nullptr;
        }

        return *this;
    }

    //深拷贝
    CPointTest& operator=(const CPointTest& t)
    {
        if (this != &t)
        {
            if (NULL != m_pInts)
            {
                delete[] m_pInts;
                m_pInts = NULL;
            }

            m_size = t.m_size;
            m_pInts = new int[m_size];
            memcpy(m_pInts, t.m_pInts, m_size);
        }

        return *this;
    }

private:
    int *m_pInts = nullptr;
    int m_size = 0;
};

CPointTest GetPointTest()
{
    CPointTest t;
    //通过t的拷贝构造函数产生临时变量，会进行资源的拷贝
    return t;
}

CPointTest f()
{
    CPointTest t;
    return t;
}

int main()
{
    CPointTest t1(f());

    CPointTest t2;
    //通过复制构造函数构造t3
    CPointTest t3 = t2;

    t3 = t1;
    t3 = CPointTest();

    std::string str = "123";

    std::cout << str.c_str() << std::endl;
    std::string str1(std::move(str));

    std::cout << str.c_str() << std::endl;
    std::cout << str1.c_str() << std::endl;
    std::system("pause");
}