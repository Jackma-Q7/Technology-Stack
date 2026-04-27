#include <memory>
#include <iostream>
#include <thread>
#include <chrono>

//std::shared_ptr<int> gInt = std::make_shared<int>(18);
int *gInt = new int(18);
void t1()
{
	/*std::shared_ptr<int> pInt = gInt;*/
	int* pInt = gInt;
	/*std::cout << "pInt use_count " << pInt.use_count() << std::endl;*/

	std::this_thread::sleep_for(std::chrono::seconds(1));
	delete pInt;
	pInt = nullptr;
}

void t2()
{
	/*std::weak_ptr<int> wInt(gInt);*/
	int *wInt = gInt;
	//std::this_thread::sleep_for(std::chrono::seconds(3));
	if (wInt)
	{
		std::this_thread::sleep_for(std::chrono::seconds(3));
		...
	}

	/*std::shared_ptr<int> sp = wInt.lock();
	if (sp)
	{
		std::cout << "sp use_count " << sp.use_count()<<std::endl;
	}
	else
	{
		std::cout << "invalid " << std::endl;
	}*/
}

int main()
{
	std::thread th1(t2);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::thread th2(t1);

	gInt.reset();

	th1.join();
	th2.join();
}