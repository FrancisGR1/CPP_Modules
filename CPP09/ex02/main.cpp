#include <iostream>
#include <vector>
#include <deque>

#include "PmergeMeVector.hpp"

int main(int argc, char **argv)
{

	//@TODO proteger contra argc - não pode ser mais do que max unsigned int
	try
	{
	//	std::cout << "Before: "; utils::print_argv(argc, argv);

		PmergeMeVector fj1;
		fj1.sort(argc, argv);
		//PmergeMe<std::deque<Matches>, std::deque<Player*> > fj2;
		//fj2.sort(argc, argv);

		//std::cout << "After:  "; fj1.print_ranking();
		//fj1.print_matches();

		//std::cout << "Elements: " << fj1.size() << " | Time Elapsed: " << fj1.time() << "us" << std::boolalpha << " | Sorted: " << utils::is_sorted(fj1.get()) << " | Container: std::vector\n" ;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}
