#include <iostream>
#include <vector>
#include <deque>

#include "utils.hpp"
#include "PmergeMe.hpp"
#include "Matches.hpp"
#include "Player.hpp"

int main(int argc, char **argv)
{

	try
	{
		std::cout << "Before: "; utils::print_argv(argc, argv);

		PmergeMe<std::vector<Matches>, std::vector<Player*> > fj1;
		fj1.sort(argc, argv);
		//PmergeMe<std::deque<Matches>, std::deque<Player*> > fj2;
		//fj2.sort(argc, argv);

		std::cout << "After:  "; fj1.print_ranking();
		//fj1.print_matches();

		std::cout << "Elements: " << fj1.size() << " | Time Elapsed: " << fj1.time() << "us" << std::boolalpha << " | Sorted: " << utils::is_sorted(fj1.get()) << " | Container: std::vector\n" ;
		//std::cout << "Elements: " << fj2.size() << " | Time Elapsed: " << fj2.time() << "us" << std::boolalpha << " | Sorted: " << utils::is_sorted(fj2.get()) << " | Container: std::deque\n" ;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}
