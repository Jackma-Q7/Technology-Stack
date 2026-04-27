#include <memory>
#include <iostream>

int main()
{
	std::shared_ptr<int> sp1 = std::make_shared<int>(18);
	std::weak_ptr<int> wp(sp1);

	//在多线程环境会有问题
	/*if (!wp.expired())
	{
		std::shared_ptr<int> sp2(wp);
		std::cout << sp2.use_count() << std::endl;
	}*/

	std::shared_ptr<int> sp2 = wp.lock();
	if (sp2)
	{
		std::cout << sp2.use_count() << std::endl;
	}
}