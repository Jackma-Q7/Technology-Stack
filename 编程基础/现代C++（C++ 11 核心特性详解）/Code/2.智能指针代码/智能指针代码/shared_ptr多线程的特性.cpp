#include <memory>
#include <thread>
#include <mutex>

std::shared_ptr<int> gInt;
std::mutex gMutex;
void read()
{
	std::shared_ptr<int> localPtr;
	
	{
		std::lock_guard<std::mutex> lock(gMutex);
		//对gInt来说是读操作
		localPtr = gInt;
	}

	do(localPtr);
}

void write()
{
	std::shared_ptr<int> newPtr = std::make_shared<int>(18);
	
	{
		std::lock_guard<std::mutex> lock(gMutex);
		//对gInt来说是写操作
		gInt = newPtr;
	}

	do(newPtr);

}