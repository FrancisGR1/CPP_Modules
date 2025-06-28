/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:33:31 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/28 09:43:14 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

const unsigned int SCAV_HP = 100;
const unsigned int SCAV_ENERGY = 50;
const unsigned int SCAV_ATK = 20;

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap& operator=(const ScavTrap&);
		ScavTrap(const ScavTrap&);
		~ScavTrap();
		void guardGate();
		void attack(const std::string& name);
};

#endif /*SCAVTRAP_HPP */
