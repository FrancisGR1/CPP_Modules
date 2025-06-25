#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	setHp(100);
	setEnergy(100);
	setAtkDamage(30);
	std::cout << "<FragTrap> Constructed: " << getName() << std::endl;
};

FragTrap::~FragTrap()
{
	std::cout << "<FragTrap> Destructed: " << getName() << std::endl;
};

void FragTrap::highFiveGuys()
{
	std::cout << "FragTrap wants a high five!" << std::endl;
};
