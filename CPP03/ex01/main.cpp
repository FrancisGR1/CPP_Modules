/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:32:52 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/27 12:59:07 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{

	std::cout << "\n=== ScavTrap Test ===\n";
	ScavTrap s1("Scavy");
	std::cout << "Scavy HP: " << s1.getHp() << ", Energy: " << s1.getEnergy() << "\n";
	s1.attack("Bandit");
	s1.takeDamage(10);
	s1.beRepaired(9);
	s1.guardGate();

	std::cout << "Scavy HP: " << s1.getHp() << ", Energy: " << s1.getEnergy() << "\n";

	std::cout << "\n=== Destructor Order Check ===\n";
	//...
}
