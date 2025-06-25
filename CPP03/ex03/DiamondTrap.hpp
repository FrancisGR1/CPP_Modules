#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string m_name;
	public:
		DiamondTrap(std::string name);
		~DiamondTrap();

		void whoAmI();
		void attack(const std::string& target);

		void setName(const std::string& target);
		std::string getName();
};

#endif /*DIAMONDTRAP_HPP*/
