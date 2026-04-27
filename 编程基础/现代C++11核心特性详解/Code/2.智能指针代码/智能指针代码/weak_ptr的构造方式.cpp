#include <memory>
#include <iostream>

int main()
{
	/*weak_ptr的构造方式*/
	std::shared_ptr<int> sp = std::make_shared<int>(18);
	std::cout << sp.use_count() << std::endl;

	std::weak_ptr<int> wp(sp);
	std::cout << wp.use_count() << std::endl;

	std::weak_ptr<int> wp1;
	wp1 = sp;

	std::cout << wp1.use_count() << std::endl;
}