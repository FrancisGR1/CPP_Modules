/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:28:20 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/28 00:34:11 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//@TODO: takeDamage(9) correto?
int main()
{
	ClapTrap t("Cat");
	ClapTrap f("Fish");

	std::cout << "\n--- ROUND 1 ---\n";
	t.attack("Fish");
	f.takeDamage(9);
	f.beRepaired(5);
	std::cout << "Cat Energy: " << t.getEnergy() << "\n";
	std::cout << "Fish HP: " << f.getHitpoint() << ", Energy: " << f.getEnergy() << "\n";

	std::cout << "\n--- ROUND 2 ---\n";
	t.attack("Fish");
	f.takeDamage(9);
	f.beRepaired(5);
	std::cout << "Cat Energy: " << t.getEnergy() << "\n";
	std::cout << "Fish HP: " << f.getHitpoint() << ", Energy: " << f.getEnergy() << "\n";

	std::cout << "\n--- ENERGY EXHAUSTION TEST ---\n";
	for (int i = 0; i < 12; ++i)
		t.attack("Fish");

	std::cout << "\n--- ZERO HP TEST ---\n";
	for (int i = 0; i < 5; ++i)
		f.takeDamage(3);
	f.attack("Cat");

	std::cout << "\n--- ZERO ENERGY REPAIR TEST ---\n";
	for (int i = 0; i < 11; ++i)
		f.beRepaired(1);


	std::cout << "\n--- Assignment Operator ---\n";
	ClapTrap assigned;
	assigned = t;
	assigned.attack("Cat");

	std::cout << "\n--- Copy Constructor ---\n";
	ClapTrap copy(f);
	copy.attack("Fish");
}
