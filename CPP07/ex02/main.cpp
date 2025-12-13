#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int>nums(10);
	for (size_t i = 0; i < nums.size(); ++i)
		nums[i] = i;

	std::cout << "Print array elements:\n";
	for (size_t i = 0; i < nums.size(); ++i)
	{
		std::cout << i;
		if (i < nums.size() - 1)
			std::cout << ", ";
	}
	std::cout << "\n";

	std::cout << "Try to access out of bounds element:\n";
	try
	{
		nums[20202];
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
}
