#include <iostream>

#include "PmergeMeVector.hpp"
#include "PmergeMeDeque.hpp"

int main(int argc, char **argv)
{

	try
	{

		std::cout << "\n============\n";
		std::cout << "std::vector:\n";
		PmergeMeVector fj1;
		fj1.sort(argc, argv);

		std::cout << "\n============\n";
		std::cout << "std::deque:\n";
		PmergeMeDeque fj2;
		fj2.sort(argc, argv);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}
