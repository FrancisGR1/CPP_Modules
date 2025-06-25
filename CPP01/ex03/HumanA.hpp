#ifndef HUMANA_HPP_
#define HUMANA_HPP_

#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string m_name;
		Weapon& m_weapon;
	public:
		HumanA(std::string name, Weapon& weapon)
			: m_name(name)
			, m_weapon(weapon)
		{}
		void attack(void);
};

#endif /*HUMANA_HPP_*/
