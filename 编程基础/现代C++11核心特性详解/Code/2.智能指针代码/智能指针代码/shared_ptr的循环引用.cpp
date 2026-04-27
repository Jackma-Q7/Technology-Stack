#include<memory>
#include<iostream>

class B;
class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}

	~A()
	{
		std::cout << "~A()" << std::endl;
	}

	void SetB(const std::shared_ptr<B> &pb)
	{
		m_pB = pb;
	}
private:
	std::shared_ptr<B> m_pB;
};

class B
{
public:
	B()
	{
		std::cout << "B()" << std::endl;
	}

	~B()
	{
		std::cout << "~B()" << std::endl;
	}

	void SetA(const std::shared_ptr<A>& pA)
	{
		m_pA = pA;
	}
private:
	//std::shared_ptr<A> m_pA;
	std::weak_ptr<A> m_pA;
};

int main()
{
	{
		std::shared_ptr<A> pA = std::make_shared<A>();
		std::shared_ptr<B> pB = std::make_shared<B>();

		pA->SetB(pB);
		pB->SetA(pA);

		std::cout << pA.use_count() << std::endl;
		std::cout << pB.use_count() << std::endl;
	}
}