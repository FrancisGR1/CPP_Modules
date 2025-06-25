/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:37:29 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/25 16:37:30 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string cmd;
	PhoneBook pb;
		
	while (true)
	{
		std::cout << "Command: ";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << std::endl;
			break ;
		}
		else if (cmd == "EXIT")
		{
			break ;
		}
		else if (cmd == "ADD")
		{
			if (!pb.add())
			{
				std::cout << std::endl;
				break ;
			}
		}
		else if (cmd == "SEARCH")
		{
			if (!pb.display())
			{
				std::cout << std::endl;
				break ;
			}
		}
		else
		{
			std::cout << "Wrong format" << std::endl;
		}
	}
	return 0;
}
