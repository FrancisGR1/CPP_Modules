/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:10:11 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/25 17:13:50 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: m_name(name)
	  , m_weapon(NULL)
{};

void HumanB::attack(void)
{
	std::cout << m_name << " attacks with his " 
		<< (m_weapon != NULL ? m_weapon->getType() : "hands")
		<< std::endl;
};

void HumanB::setWeapon(Weapon& w)
{
	m_weapon = &w;
}
