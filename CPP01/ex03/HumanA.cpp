#include "HumanA.hpp"
#include "Weapon.hpp"

void HumanA::attack(void)
{
	std::cout << m_name << " attacks with his " 
		<< m_weapon.getType() << std::endl;
};

