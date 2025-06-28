/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:33:46 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/28 11:18:59 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() 
{
	DiamondTrap d("Diamond");

	std::cout << "I am " << d.getName() << std::endl
		<< "HitPoints: " << d.getHp() << std::endl
		<< "EnergyPoints: " << d.getEnergy() << std::endl
		<< "AttackDamage: " << d.getAtkDamage() << std::endl;
	d.attack("Pigeon");
	d.highFiveGuys();
	d.whoAmI();
	return 0;
}
