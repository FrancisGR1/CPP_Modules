/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:30:07 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 10:30:08 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "./karen <LEVEL>" << std::endl;
		return 1;
	}
	Karen k;
	k.complain(std::string(argv[1]));
} 
