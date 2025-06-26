/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:09:59 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 10:28:59 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"


HumanA::HumanA(std::string name, Weapon& weapon)
			: m_name(name)
			, m_weapon(weapon)
{};

void HumanA::attack(void)
{
	std::cout << m_name << " attacks with his " 
		<< m_weapon.getType() << std::endl;
};

