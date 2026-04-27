#include <memory>
#include <iostream>

class CTest
{
public:
	CTest(int i)
	{

	}

	CTest(int i, int j)
	{

	}
};

int Prcoess2()
{
	return 0;
}

void Process(std::shared_ptr<CTest> sp, int Ret)
{

}

int main()
{
	std::shared_ptr<int> sp = std::make_shared<int>(18);

	std::shared_ptr<CTest> sp1 = std::make_shared<CTest>(18);
	std::shared_ptr<CTest> sp2 = std::make_shared<CTest>(18, 18);

	//隐藏了3个执行语句
	/*1.new CTest(18);
	2.执行Process2()
	3.构造一个shared_ptr对象*/

	Process(std::shared_ptr<CTest>(new CTest(18)), Prcoess2());

	/*1.调用make_shared
    2.Prcoess2()*/
	Process(std::make_shared<CTest>(18), Prcoess2());
}