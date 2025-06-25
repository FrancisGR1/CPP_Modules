#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: m_name(name)
	, m_hitpoint(10)
	, m_energy(10)
	, m_attack_damage(9)
{
	std::cout << "Constructed: " << name << std::endl;
};

ClapTrap::~ClapTrap()
{
	std::cout << "Destructed: " << m_name << std::endl;
};

void ClapTrap::setName(std::string name) {m_name = name;}
void ClapTrap::setHp(int n) {m_hitpoint = n;}
void ClapTrap::setEnergy(int n) {m_energy = n;} 
void ClapTrap::setAtkDamage(int n) {m_attack_damage = n;}

std::string ClapTrap::getName() {return m_name;}
int ClapTrap::getHp() {return m_hitpoint;}
int ClapTrap::getEnergy() {return m_energy;}
int ClapTrap::getAtkDamage() {return m_attack_damage;}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_attack_damage << " points of damage!" << std::endl;
};

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << m_name << " has taken " << amount << " points of damage!" << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << m_name << " has repaired " << amount << " points" << std::endl;
};

