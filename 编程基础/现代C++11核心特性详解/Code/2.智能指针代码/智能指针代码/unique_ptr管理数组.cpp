#include <memory>
#include <iostream>
int main()
{
    std::unique_ptr<int[]> p1(new int[3]);
}