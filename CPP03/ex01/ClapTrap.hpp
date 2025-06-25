#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		~ClapTrap();

		void setName(std::string name);
		void setHp(int n);
		void setEnergy(int n);
		void setAtkDamage(int n);

		std::string getName();
		int getHp();
		int getEnergy();
		int getAtkDamage();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		std::string m_name;
		int m_hitpoint;
		int m_energy;
		int m_attack_damage;
};

#endif /*CLAPTRAP_HPP*/
