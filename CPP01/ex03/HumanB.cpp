#include "HumanB.hpp"

void HumanB::attack(void)
{
	std::cout << m_name << " attacks with his " 
		<< (m_weapon != NULL ? m_weapon->getType() : "hands")
		<< std::endl;
};

void HumanB::setWeapon(Weapon& w)
{
	m_weapon = &w;
}
