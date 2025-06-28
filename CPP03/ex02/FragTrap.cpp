/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:33:10 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/28 10:43:57 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap()
{
	setHp(FRAG_HP);
	setEnergy(FRAG_ENERGY);
	setAtkDamage(FRAG_ATK);
	std::cout << "<FragTrap> Default Constructed: " << getName() << std::endl;
};

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	setHp(FRAG_HP);
	setEnergy(FRAG_ENERGY);
	setAtkDamage(FRAG_ATK);
	std::cout << "<FragTrap> Constructed: " << getName() << std::endl;
};

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{

	std::cout << "<FragTrap> Copy Constructed: " << getName() << std::endl;
};

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "<FragTrap> Assignment operator called" << std::endl;

	ClapTrap::operator=(other);

	return (*this);
};

FragTrap::~FragTrap()
{
	std::cout << "<FragTrap> Destroyed: " << getName() << std::endl;
};

void FragTrap::highFiveGuys()
{
	std::cout << "FragTrap (" << getName() << ") wants a high five!" << std::endl;
};
