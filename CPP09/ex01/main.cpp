#include <iostream>

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "./RPN \"<expression>\"\n";
		return 1;
	}

	try
	{
		RPN calculator;
		const std::string expr(argv[1]);
		std::cout << calculator.compute(expr) << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
};

//$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
//$> ./RPN "2 2 / 2 * 2 4 - +"
//$> ./RPN "1 2 * 2 4 - +"
//$> ./RPN "2 2 4 - +"
//$> ./RPN "2 -2 +"
//$> ./RPN "0"
