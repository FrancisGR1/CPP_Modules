#include <sstream>
#include <iostream>
#include <vector>
#include <string>

#include "Player.hpp"

namespace utils 
{
	bool is_valid_number(const std::string& s)
	{
		std::istringstream iss(s);
		double d;
		return iss >> std::noskipws >> d && iss.eof() && d >= 0;
	};

	void print_argv(int argc, char **argv)
	{
		for (int i = 1; i < argc; ++i)
		{
			std::cout << argv[i] << " ";
		}
		std::cout << "\n";
	}
}
