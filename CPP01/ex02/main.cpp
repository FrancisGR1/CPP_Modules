/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:09:39 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 10:59:39 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string* stringPTR = &s;
	std::string& stringREF = s;

	std::cout << "---MEMORY ADDRESSES" << std::endl;
	std::cout << "STR: " << &s << std::endl;
	std::cout << "PTR: " << &stringPTR << std::endl;
	std::cout << "REF: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "---VALUES" << std::endl;
	std::cout << "STR: " << s << std::endl;
	std::cout << "PTR: " << *stringPTR << std::endl;
	std::cout << "REF: " << stringREF << std::endl;
}
