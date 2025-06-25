#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap d("Cat");
	std::cout << "stats:" << std::endl 
		<< "hp: " << d.getHp() << std::endl
		<< "energy: " << d.getEnergy() << std::endl
		<< "ad: " << d.getAtkDamage() << std::endl;
	d.attack("Fish");
	d.takeDamage(5);
	d.beRepaired(5);
	d.highFiveGuys();
	d.guardGate();
	d.whoAmI();
};
