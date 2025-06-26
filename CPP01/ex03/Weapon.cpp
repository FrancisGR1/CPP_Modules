/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:10:14 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 11:04:56 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string w)
	: m_weapon_type(w)
{};

const std::string& Weapon::getType(void)
{
	return (m_weapon_type); 
};

void Weapon::setType(std::string w)
{
	m_weapon_type = w;
};
