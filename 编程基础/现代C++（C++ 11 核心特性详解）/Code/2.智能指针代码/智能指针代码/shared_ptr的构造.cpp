#include <memory>
#include <iostream>

class test
{
public:
	test(int i):m_i(i)
	{
		std::cout << "test()" << m_i <<std::endl;
	}

	~test()
	{
		std::cout << "~test()" <<  std::endl;
	}

private:
	int m_i;
};

int main()
{

	//通过一个裸指针构造
	test *p = new test(1);
	std::shared_ptr<test> sp(p);
	//std::shared_ptr<test> sp1(new test());

	//{
	//	//通过一个shared_ptr对象构造
	//	std::shared_ptr<test> sp2(sp);
	//	std::cout << "use count " << sp2.use_count() << std::endl;
	//}


	//std::cout << "use count " << sp.use_count();
	test* p2 = new test(2);
	sp.reset(p2);

	std::system("pause");
}