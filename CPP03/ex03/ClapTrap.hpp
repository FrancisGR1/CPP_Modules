/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:33:52 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/28 10:40:20 by frmiguel         ###   ########.fr       */
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

		void setName(std::string name);
		void setHp(int n);
		void setEnergy(int n);
		void setAtkDamage(int n);

		std::string getName();
		int getHp();
		int getEnergy();
		int getAtkDamage();

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string m_name;
		int m_hitpoint;
		int m_energy;
		int m_attack_damage;
};

#endif /*CLAPTRAP_HPP*/
