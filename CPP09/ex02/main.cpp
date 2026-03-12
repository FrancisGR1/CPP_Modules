#include <iostream>

#include "PmergeMeVector.hpp"
#include "PmergeMeDeque.hpp"

int main(int argc, char **argv)
{

	try
	{
		if (argc == 1)
		{
			std::cerr << "./PmergeMe <numbers...>\n";
			return 1;
		}

		std::cout << "\n======= std::vector =======\n";
		PmergeMeVector fj1;
		fj1.sort(argc, argv);

		std::cout << "\n======= std::deque =======\n";
		PmergeMeDeque fj2;
		fj2.sort(argc, argv);

		std::cout << "\n======= Statistics ======= \n";
		std::cout << "std::vector: ";
		fj1.info();
		std::cout << "std::deque:  ";
		fj2.info();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}
