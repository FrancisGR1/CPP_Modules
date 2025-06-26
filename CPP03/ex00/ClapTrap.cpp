/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:28:17 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 16:29:11 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
