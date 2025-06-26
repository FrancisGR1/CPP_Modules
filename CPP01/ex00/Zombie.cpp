/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:52:52 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 10:50:51 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	m_name = name;
}

void Zombie::announce(void)
{
	std::cout << m_name << ": " 
		<< "BraiiiiiiinnnzzzZ..." 
		<< std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroyed: " << m_name << std::endl;
}
