/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:28:17 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/27 11:46:36 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: m_name("Default")
	, m_hitpoint(10)
	, m_energy(10)
	, m_attack_damage(9)
{
	std::cout << "<ClapTrap> Default Constructed" << std::endl;
};

ClapTrap::ClapTrap(std::string name)
	: m_name(name)
	, m_hitpoint(10)
	, m_energy(10)
	, m_attack_damage(9)
{
	std::cout << "<ClapTrap> Constructed" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other)
	: m_name(other.m_name)
	, m_hitpoint(other.m_hitpoint)
	, m_energy(other.m_energy)
	, m_attack_damage(other.m_attack_damage)
{
	std::cout << "<ClapTrap> Copied: " << m_name << std::endl;
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
	std::cout << "<ClapTrap> Destructed: " << m_name << std::endl;
};

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

std::string ClapTrap::getName() const { return m_name; }
int ClapTrap::getHitpoint() const { return m_hitpoint; }
int ClapTrap::getEnergy() const { return m_energy; }
int ClapTrap::getAtkDamage() const { return m_attack_damage; }
