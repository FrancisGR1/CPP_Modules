#include <iostream>
#include <vector>
#include <deque>

#include "PMergeMe.hpp"
#include "Time.hpp"
#include "Matches.hpp"
#include "Player.hpp"

int main(int argc, char **argv)
{

	try
	{
		std::cout << "Before: "; utils::print_argv(argc, argv);

		PMergeMe<std::vector<Matches>, std::vector<Player*> > fj1;
		fj1.sort(argc, argv);
		PMergeMe<std::deque<Matches>, std::deque<Player*> > fj2;
		fj2.sort(argc, argv);

		std::cout << "After:  "; fj1.print_ranking();
		//fj1.print_matches();

		std::cout << "Elements: " << fj1.size() << " | Time Elapsed: " << fj1.time() << "us | Container: std::vector\n";
		std::cout << "Elements: " << fj2.size() << " | Time Elapsed: " << fj2.time() << "us | Container: std::deque\n";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}
