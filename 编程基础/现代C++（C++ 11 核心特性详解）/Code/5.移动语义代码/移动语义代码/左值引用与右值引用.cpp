#include<iostream>

int f()
{
    int i = 118;
    return i;
}

int main()
{
    int i = 18;//i是左值，18就是右值
    int &r = i;
    //int &rr = 18;//左值引用不能引用右值
    int &&r1 = 18;
    //int &r2 = i * 18;

    int &&r3 = i * 18;

    //int &r4 = f();
    int &&r5 = f();

    int &&r6 = i++;
    int &r7 = ++i;

    //万能引用，即可以引用左值，又可以引用右值
    const int &c = 18;
}