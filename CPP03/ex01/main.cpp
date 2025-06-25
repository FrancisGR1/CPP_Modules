#include "ScavTrap.hpp"

int main()
{
	ScavTrap t("Cat");
	t.attack("Fish");
	t.takeDamage(5);
	t.beRepaired(5);
	t.guardGate();
};
