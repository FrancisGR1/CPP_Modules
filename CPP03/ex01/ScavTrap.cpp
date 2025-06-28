/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:32:49 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/28 09:44:54 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap("Default")
{
	setHp(SCAV_HP);
	setEnergy(SCAV_ENERGY);
	setAtkDamage(SCAV_ATK);
	std::cout << "<ScavTrap> Default Constructed: " << getName() << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap& st)
	: ClapTrap(st)
{
	setHp(SCAV_HP);
	setEnergy(SCAV_ENERGY);
	setAtkDamage(SCAV_ATK);
	std::cout << "<ScavTrap> Copy Constructed: " << getName() << std::endl;
};

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	setHp(SCAV_HP);
	setEnergy(SCAV_ENERGY);
	setAtkDamage(SCAV_ATK);
	std::cout << "<ScavTrap> Constructed: " << getName() << std::endl;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "<ScavTrap> Assignment operator called" << std::endl;

	ClapTrap::operator=(other);
	return (*this);
};

ScavTrap::~ScavTrap()
{
	std::cout << "<ScavTrap> Destroyed: " << getName() << std::endl;
};

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap have enterred in Gate keeper mode" << std::endl;
};

void ScavTrap::attack(const std::string& target)
{
	if (m_energy > 0 && m_hitpoint > 0)
	{
		std::cout << "ScavTrap " << m_name << " attacks " << target << ", causing " << m_attack_damage << " points of damage!" << std::endl;
		m_energy--;
	}
	else
	{
		std::cout << "ScavTrap " << m_name << " cannot attack" << std::endl;
	}
};

