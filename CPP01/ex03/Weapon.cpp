#include "Weapon.hpp"

const std::string Weapon::getType(void)
{
	return (m_weapon_type); 
};

void Weapon::setType(std::string w)
{
	m_weapon_type = w;
};
