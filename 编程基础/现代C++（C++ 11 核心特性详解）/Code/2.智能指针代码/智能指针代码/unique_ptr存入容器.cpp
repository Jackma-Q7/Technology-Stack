#include <memory>
#include <iostream>
#include <vector>
int main()
{
    std::unique_ptr<int> p(new int(18));
    std::vector < std::unique_ptr<int>> v;
    v.push_back(std::move(p));

    if (!p)
    {
        std::cout << "is empty" << std::endl;
    }
}