/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:10:21 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/25 17:12:58 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP_
#define HUMANA_HPP_

#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string m_name;
		Weapon& m_weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		void attack(void);
};

#endif /*HUMANA_HPP_*/
