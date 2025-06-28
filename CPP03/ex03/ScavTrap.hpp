/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:34:05 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/28 10:18:33 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

const unsigned int SCAV_HP = 100;
const unsigned int SCAV_ENERGY = 50;
const unsigned int SCAV_ATK = 20;

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap& operator=(const ScavTrap&);
		ScavTrap(const ScavTrap&);
		~ScavTrap();
		void guardGate();
		void attack(const std::string& target);
};

#endif /*SCAVTRAP_HPP */
