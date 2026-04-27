#include<iostream>

class test
{
public:
	test()
	{
		std::cout << "test()" << std::endl;
	}

	~test()
	{
		std::cout << "~test()" << std::endl;
	}
};

class CRAII
{
public:
	CRAII(test* p)
	{
		m_pTest = p;
	}

	~CRAII()
	{
		delete m_pTest;
		m_pTest = NULL;
	}
private:
	test *m_pTest;
};

void function()
{
	test* p = new test();
	CRAII r(p);
	//ÒµÎñ´úÂë
	.....

	delete p;
	p = NULL;
}

int main()
{
	/*{
		test* p = new test();
		CRAII r(p);
	}*/

	function();


	std::system("pause");
}