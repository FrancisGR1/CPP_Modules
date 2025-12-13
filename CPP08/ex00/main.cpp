#include <vector>
#include <list>
#include <iostream>

#include "easyfind.hpp"

int main()
{
	std::cout << "VECTOR\n"; 

	std::vector<int> nums_vector;
	std::cout << "filling with 1-5\n";
	nums_vector.push_back(1);
	nums_vector.push_back(2);
	nums_vector.push_back(3);
	nums_vector.push_back(4);
	nums_vector.push_back(5);

	std::vector<int>::iterator it;
	it = easyfind(nums_vector, 3);
	std::cout << "found: " << *it << "\n";


	std::cout << "\nLIST\n"; 
	std::list<int> nums_list;
	std::cout << "filling with 1-5\n";
	nums_list.push_back(1);
	nums_list.push_back(2);
	nums_list.push_back(3);
	nums_list.push_back(4);
	nums_list.push_back(5);

	std::list<int>::iterator it2;
	it2 = easyfind(nums_list, 3);
	std::cout << "found: " << *it2 << "\n";
}
