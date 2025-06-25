#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string* stringPTR = &s;
	std::string& stringREF = s;
	std::cout << "PTR: " << *stringPTR << std::endl;
	std::cout << "REF: " << stringREF << std::endl;
}
