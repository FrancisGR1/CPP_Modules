#include "Brain.hpp"

Brain::Brain()  { std::cout << "<Brain> constructed " << std::endl; }

Brain::Brain(const Brain& other)
{
	for(size_t i = 0; i < IDEAS; i++)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << "<Brain> copied " << std::endl; 
}

Brain::~Brain() { std::cout << "<Brain> destructed " << std::endl; }
