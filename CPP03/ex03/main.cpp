/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:33:46 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/27 15:01:44 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() 
{
	std::cout << "\n--- DiamondTrap Tests ---\n" << std::endl;

	DiamondTrap d("Mega");

	d.attack("TargetBot");       // from ScavTrap
	d.takeDamage(20);            // from ClapTrap
	d.beRepaired(15);            // from ClapTrap
	d.whoAmI();                  // special

	std::cout << "\n--- Copy Constructor ---\n";
	DiamondTrap d2(d);
	d2.whoAmI();

	std::cout << "\n--- Assignment Operator ---\n";
	DiamondTrap d3;
	d3 = d2;
	d3.whoAmI();

	std::cout << "\n--- Destruction Sequence ---\n";
	return 0;
}
