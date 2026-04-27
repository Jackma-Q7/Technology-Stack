#include <utility>
#include <iostream>
#include <vector>
class CTest
{
public:
    CTest() { std::cout << "CTest()" << std::endl; }
    CTest(const CTest& t) { std::cout << "CTest(const CTest& t)" << std::endl; }
    CTest(CTest &&t) { std::cout << "CTest(CTest &&t)" << std::endl; }

};
int main()
{
    std::string s = "abc";
    std::string s1 = std::move(s);
    std::cout << s.c_str() << s1.c_str()<<std::endl;
    //已被移动的对象，不应该再使用
    //std::string s2 = std::move(s);
    //std::cout << s2.c_str() << std::endl;

    CTest t;
    CTest t1 = std::move(t);

    std::vector<std::string> vec;
    vec.push_back(std::move(s1));
    vec.push_back(s1);
}