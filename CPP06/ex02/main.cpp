#include "Base.hpp"

int main() 
{
	std::srand(std::time(NULL));

	std::cout << "Identify by pointer\n";
	Base* random = Base::generate();
	Base::identify(random);

	std::cout << "Identify by reference\n";
	Base* random2 = Base::generate();
	Base::identify(*random2);

	delete random;
	delete random2;

	return 0;
};
