/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:43 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 18:57:43 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	public:
		Zombie(std::string);
		void announce(void) ;
		~Zombie(void) ;
	private:
		std::string m_name;
};

Zombie*	newZombie( std::string name);
void	randomChump( std::string name);

#endif /*ZOMBIE_HPP*/
