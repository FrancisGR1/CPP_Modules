/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:52:54 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/25 16:52:55 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie* z1 = newZombie("Frederico");
	z1->announce();
	randomChump("Joana");
	delete z1;
}

