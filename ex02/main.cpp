#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base*	base1 = generate();
	//Base*	base2 = generate();
	//Base*	base3 = generate();

	identify(base1);
	//identify(base2);
	//identify(base3);

	//identify(*base1);
	//identify(*base2);
	//identify(*base3);

	delete base1;	
	//delete base2;	
	//delete base3;	
}
