#ifndef HUMANB_HPP_
#define HUMANB_HPP_

#include "Weapon.hpp"
#include <iostream>

class HumanB {
	private:
		std::string m_name;
		Weapon* m_weapon;
	public:
		HumanB(std::string name)
			: m_name(name)
			, m_weapon(NULL)
		{}
		void attack(void);
		void setWeapon(Weapon& w);
};
#endif /*HUMANB_HPP_*/
