/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:33:37 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/27 14:57:31 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Default")
	, FragTrap("Default")
	, ScavTrap("Default")
{
	m_name = "Default";
	setHp(100);
	setEnergy(50);
	setAtkDamage(30);
	std::cout << "<DiamondTrap> Default Constructed: " << getName() << std::endl;
};

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name")
	, FragTrap(name) 
	  , ScavTrap(name)
{
	setName(name);
	setHp(100);
	setEnergy(50);
	setAtkDamage(30);
	std::cout << "<DiamondTrap> Constructed: " << getName() << std::endl;
};

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "<DiamondTrap> Assignment operator called" << std::endl;

	ClapTrap::operator=(other);
	m_name = other.m_name;
	return (*this);
};

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other)
	, FragTrap(other)
	, ScavTrap(other)
{
	m_name = other.m_name;

	std::cout << "<DiamondTrap> Copy Constructed: " << getName() << std::endl;
};

DiamondTrap::~DiamondTrap()
{
	std::cout << "<DiamondTrap> Destructed: " << getName() << std::endl;
};

void DiamondTrap::whoAmI()
{
	std::cout << "My name is: " << getName() << " and my parent: " << ClapTrap::getName() << std::endl;
};

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
};

void DiamondTrap::setName(const std::string& name) { m_name = name; }

std::string DiamondTrap::getName() { return m_name; }
