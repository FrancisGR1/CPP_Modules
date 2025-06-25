#include "Zombie.hpp"

Zombie::Zombie(void)
{}

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

Zombie::~Zombie(void)
{
	std::cout << "Destroyed: " << m_name << std::endl;
}
