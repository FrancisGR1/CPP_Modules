#include "Brain.hpp"

Brain::Brain()  
{ 
	std::cout << "<Brain> constructed " << std::endl; 
}

Brain::Brain(const Brain& other)
{
	copyIdeas(other);
	std::cout << "<Brain> copied " << std::endl; 
};

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "<Brain> Assignment operator called" << std::endl;
	copyIdeas(other);
	return (*this);
};

Brain::~Brain() 
{ 
	std::cout << "<Brain> destructed " << std::endl; 
}

void Brain::copyIdeas(const Brain& other)
{
	for(size_t i = 0; i < IDEAS; i++)
	{
		std::cout << "copying " << i << std::endl;
		ideas[i] = other.ideas[i];
	}
};
