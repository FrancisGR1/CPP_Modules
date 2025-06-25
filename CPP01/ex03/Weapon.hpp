#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <iostream>

class Weapon {
	private:
		std::string m_weapon_type;
	public:
		Weapon(std::string w)
			: m_weapon_type(w)
		{}
		const std::string getType(void);
		void setType(std::string w);

};

#endif /*WEAPON_HPP_*/
