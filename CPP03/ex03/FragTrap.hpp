/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:33:59 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/28 10:18:25 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

const unsigned int FRAG_HP = 100;
const unsigned int FRAG_ENERGY = 100;
const unsigned int FRAG_ATK = 30;

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap&);
		FragTrap& operator=(const FragTrap&);
		~FragTrap();
		void highFiveGuys();
};

#endif /*FRAGTRAP_HPP*/
