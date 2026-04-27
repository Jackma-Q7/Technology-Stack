#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
std::vector<int> vecValue = { 1,2,3,4,5,6 };

void Print()
{
    std::for_each(vecValue.begin(), vecValue.end(), [=] (int i){
        std::cout << " "<<i << " ";
    });
}
void AddValue(int Value)
{
    std::for_each(vecValue.begin(), vecValue.end(), std::bind2nd(std::plus<int>(), Value));
    Print();

    std::transform(vecValue.begin(), vecValue.end(), vecValue.begin(), std::bind2nd(std::plus<int>(), Value));
    Print();

    std::for_each(vecValue.begin(), vecValue.end(), [=](int &i) {
        i += Value;
    });

    Print();
}

int main()
{
    AddValue(10);
}