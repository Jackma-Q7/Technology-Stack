#include <memory>
#include <iostream>
#include <vector>
class CTest:public std::enable_shared_from_this<CTest>
{
public:
	CTest()
	{
		std::cout << "CTest" << std::endl;
	}

	~CTest()
	{
		std::cout << "~CTest" << std::endl;
	}

	void Process()
	{
		vecCTest.emplace_back(shared_from_this());
	}

private:
	typedef std::shared_ptr<CTest> pCTest;

	std::vector<pCTest> vecCTest;
};


int main()
{
	/*{
		int *p = new int(18);
		std::shared_ptr<int> sp1(p);
		std::cout << sp1.use_count() << std::endl;
		std::shared_ptr<int> sp2(p);
		std::cout << sp2.use_count() << std::endl;

	}*/
	
	{
		CTest* p1 = new CTest();
		std::shared_ptr<CTest> sp3(p1);
		sp3->Process();
	}
	
	std::system("pause");
}