#include "FragTrap.hpp"

int main()
{
	FragTrap t("Cat");
	t.attack("Fish");
	t.takeDamage(5);
	t.beRepaired(5);
	t.highFiveGuys();
};
