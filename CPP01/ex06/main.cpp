#include "Karen.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "./karen <LEVEL>" << std::endl;
		return 1;
	}
	Karen k;
	k.complain(std::string(argv[1]));
} 
