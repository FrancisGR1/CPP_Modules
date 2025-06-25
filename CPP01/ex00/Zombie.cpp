#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	m_name = name;
}
void Zombie::announce(void)
{
	std::cout << "<" << m_name << "> " 
		<< "BraiiiiiiinnnzzzZ..." 
		<< std::endl;
}

Zombie*	newZombie( std::string name)
{
	return new Zombie(name);
}

void	randomChump( std::string name)
{
	Zombie z(name);
	z.announce();
}

Zombie::~Zombie(void)
{
	std::cout << "Destroyed: " << m_name << std::endl;
}
