#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	setHp(100);
	setEnergy(50);
	setAtkDamage(20);
	std::cout << "<ScavTrap> Constructed: " << getName() << std::endl;
};

ScavTrap::~ScavTrap()
{
	std::cout << "<ScavTrap> Destructed: " << getName() << std::endl;
};

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap have enterred in Gate keeper mode" << std::endl;
};
