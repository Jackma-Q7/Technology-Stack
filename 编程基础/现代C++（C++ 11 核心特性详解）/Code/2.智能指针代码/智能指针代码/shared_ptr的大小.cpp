#include <memory>
#include <iostream>

int main()
{
	int *p = new int(18);
	std::shared_ptr<int> sp(p);

	std::cout << "p " << sizeof(p) << " sp " << sizeof(sp);
}