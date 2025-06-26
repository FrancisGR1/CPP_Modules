/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:10:24 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 11:06:04 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP_
#define HUMANB_HPP_

#include "Weapon.hpp"
#include <iostream>

class HumanB 
{
	private:
		std::string m_name;
		Weapon* m_weapon;
	public:
		HumanB(std::string name);
		void attack(void);
		void setWeapon(Weapon& w);
};
#endif /*HUMANB_HPP_*/
