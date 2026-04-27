#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    auto f = [](int i)->int {std::cout << i << std::endl; return 18; };
    std::cout << f(118) << std::endl;

    auto f1 = [](int i) {std::cout << i << std::endl; return 18; };
    std::cout << f1(1118) << std::endl;

    auto f2 = [] {std::cout << "lambda" << std::endl; return 18; };
    std::cout << f2() << std::endl;

    std::vector<int> ints = { 1,2,3,4,5,6 };

    std::for_each(ints.begin(), ints.end(), [](const int& v) {std::cout << v << " " << std::endl; });
}