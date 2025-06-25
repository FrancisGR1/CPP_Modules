/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:37:15 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/25 16:37:16 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>  
#include <cctype>  

int main(int argc, char *argv[])
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (size_t i = 1; i < (size_t)argc; i++)
		{
			std::string s(argv[i]);
			for (size_t j = 0; j < s.length(); j++)
			{
				std::cout << static_cast<char>(toupper(s.at(j)));
			}
			if (i != (size_t)argc)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
