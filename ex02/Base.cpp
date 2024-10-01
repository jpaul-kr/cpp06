#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base*	generate()
{
	int	f = rand() % 3;
	Base*	base[3] = {new A, new B, new C};

	//std::cout << f << std::endl;

	for (int i = 0; i < 3; i++)
	{
		if (i != f)
			delete base[i];
	}

	return base[f];
}

void	identify(Base* p)
{
	A*	a;
	B*	b;
	C*	c;

	a = dynamic_cast<A *>(p);
	b = dynamic_cast<B *>(p);
	c = dynamic_cast<C *>(p);

	std::cout << "ptr: ";
	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
	else
		std::cout << "none" << std::endl;
}

void	identify(Base& p)
{
	std::cout << "ref: ";
	try
	{
		A&	a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(std::exception& e) {}

	try
	{
		B&	b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(std::exception& e) {}
	
	try
	{
		C&	c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(std::exception& e) {}
}
