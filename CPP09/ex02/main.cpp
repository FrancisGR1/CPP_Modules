#include <iostream>
#include "PMergeMe.hpp"
#include "CmpCounter.hpp"

int main(int argc, char **argv)
{

	try
	{
		PMergeMe ford_johnson(argc, argv);
		std::cout << "Comparisons: " << CmpCounter::comparisons << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}
