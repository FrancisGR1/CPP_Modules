/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:33:15 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/27 13:54:39 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() 
{
	std::cout << "\n--- Default Constructor Test ---" << std::endl;
	FragTrap f1;
	f1.attack("Enemy");
	f1.takeDamage(20);
	f1.beRepaired(10);
	f1.highFiveGuys();

	std::cout << "\n--- Named Constructor Test ---" << std::endl;
	FragTrap f2("Terminator");
	f2.attack("Target");
	f2.highFiveGuys();

	std::cout << "\n--- Copy Constructor Test ---" << std::endl;
	FragTrap f3(f2);
	f3.attack("Another Target");

	std::cout << "\n--- Assignment Operator Test ---" << std::endl;
	FragTrap f4;
	f4 = f2;
	f4.attack("Yet Another Target");

	std::cout << "\n--- Energy Exhaustion Test ---" << std::endl;
	for (int i = 0; i < 101; ++i)
		f2.attack("Dummy");

	std::cout << "\n--- Destructor Trigger ---" << std::endl;
	return 0;
}
