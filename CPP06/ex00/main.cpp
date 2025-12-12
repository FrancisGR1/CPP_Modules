#include "ScalarConverter.hpp"

int main(int argc, char** argv) 
{
	if (argc != 2) 
	{
		std::cerr << argv[0] << " <literal>\n";
		return 1;
	}

	ScalarConverter::convert(argv[1]);
}
