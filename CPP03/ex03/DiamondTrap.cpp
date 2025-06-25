#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name")
	, FragTrap(name) 
	, ScavTrap(name)
{
	setName(name);
	setHp(100);
	setEnergy(50);
	setAtkDamage(30);
	std::cout << "<DiamondTrap> Constructed: " << getName() << std::endl;
};

DiamondTrap::~DiamondTrap()
{
	std::cout << "<DiamondTrap> Destructed: " << getName() << std::endl;
};

void DiamondTrap::whoAmI()
{
	std::cout << "My name is: " << getName() << " and my parent: " << ClapTrap::getName() << std::endl;
};

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
};

void DiamondTrap::setName(const std::string& name) { m_name = name; }
std::string DiamondTrap::getName() { return m_name; }
