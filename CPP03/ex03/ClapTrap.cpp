/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:33:34 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/28 10:53:28 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: m_name("Default")
	, m_hitpoint(DEFAULT_HP)
	, m_energy(DEFAULT_ENERGY)
	, m_attack_damage(DEFAULT_ATK)
{
	std::cout << "<ClapTrap> Default Constructed: " << m_name << std::endl;
};

ClapTrap::ClapTrap(std::string name)
	: m_name(name)
	, m_hitpoint(DEFAULT_HP)
	, m_energy(DEFAULT_ENERGY)
	, m_attack_damage(DEFAULT_ATK)
{
	std::cout << "<ClapTrap> Constructed: " << m_name << std::endl;
};


ClapTrap::ClapTrap(const ClapTrap& other)
	: m_name(other.m_name)
	, m_hitpoint(other.m_hitpoint)
	, m_energy(other.m_energy)
	, m_attack_damage(other.m_attack_damage)
{
	std::cout << "<ClapTrap> Copy Constructed: " << m_name << std::endl;
};

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "<ClapTrap> Assignment operator called" << std::endl;
	m_name = other.m_name;
	m_hitpoint = other.m_hitpoint;
	m_energy = other.m_energy;
	m_attack_damage = other.m_attack_damage;
	return (*this);
};

ClapTrap::~ClapTrap()
{
	std::cout << "<ClapTrap> Destroyed: " << m_name << std::endl;
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
	if (m_energy > 0 && m_hitpoint > 0)
	{
		std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_attack_damage << " points of damage!" << std::endl;
		m_energy--;
	}
	else
	{
		std::cout << "ClapTrap " << m_name << " cannot attack" << std::endl;
	}
};

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << m_name << " has taken " << amount << " points of damage!" << std::endl;
		m_hitpoint -= static_cast<int>(amount);
};

void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_energy > 0 && m_hitpoint > 0)
	{
		std::cout << "ClapTrap " << m_name << " has repaired " << amount << " points" << std::endl;
		m_hitpoint += static_cast<int>(amount);
	}
	else
	{
		std::cout << "ClapTrap " << m_name << " cannot be repaired" << std::endl;
	}
};
