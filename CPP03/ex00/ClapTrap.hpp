/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:28:24 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/27 23:42:19 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

const unsigned int DEFAULT_HP = 10;
const unsigned int DEFAULT_ENERGY = 10;
const unsigned int DEFAULT_ATK = 0;

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap& operator=(const ClapTrap&);
		ClapTrap(const ClapTrap&);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName() const;
		int getHitpoint() const;
		int getEnergy() const;
		int getAtkDamage() const;

	private:
		std::string m_name;
		int m_hitpoint;
		int m_energy;
		int m_attack_damage;
};

#endif /*CLAPTRAP_HPP*/
