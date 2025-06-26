/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:10:55 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 11:05:17 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <iostream>

class Weapon 
{
	private:
		std::string m_weapon_type;
	public:
		Weapon(std::string w);
		const std::string& getType(void);
		void setType(std::string w);
};

#endif /*WEAPON_HPP_*/
