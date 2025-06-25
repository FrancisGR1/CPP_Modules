#include <iostream>  
#include <cctype>  

int main(int argc, char *argv[])
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (size_t i = 1; i < (size_t)argc; i++)
		{
			std::string s(argv[i]);
			for (size_t j = 0; j < s.length(); j++)
			{
				std::cout << static_cast<char>(toupper(s.at(j)));
			}
			if (i != (size_t)argc)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
