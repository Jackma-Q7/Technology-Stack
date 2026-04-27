#include <iostream>

int main()
{
    int a = 118;

    {
        int i = 0;
        int j = 18;
        //[i, j,a] {std::cout << i + j << std::endl; }();

        [=] {std::cout << i + j + a << std::endl; }();
        //[&] {i = 118; }();
        [&i] {i = 118; }();
        std::cout << i << std::endl;
    }
}