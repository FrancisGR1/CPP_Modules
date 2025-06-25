/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:37:34 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/25 16:37:35 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool is_num(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			return (false);
		}
	}
	return (true);
}

bool get_num(Info& contact)
{
	while (true)
	{
		std::cout << "Phone Number: ";
		if (!std::getline(std::cin, contact.phonenumber))
			return (false);
		if (is_num(contact.phonenumber))
		{
			break ;
		}
		else
		{
			std::cout << "Invalid number" << std::endl;
		}
	}
	return (true);
}

bool is_alpha(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isalpha(str[i]))
		{
			return (false);
		}
	}
	return (true);
}

bool get_name(std::string& name, const std::string& prompt)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, name))
			return (false);
		if (is_alpha(name))
		{
			break ;
		}
		else
		{
			std::cout << "Invalid name" << std::endl;
		}
	}
	return (true);
}

void print_format(const std::string& str)
{
	std::cout 
		<< std::setw(10) << std::right 
		<< (str.length() > 10 ? str.substr(0,9) + "." : str)
		<< "|";
}

std::string to_string(size_t i)
{
	std::ostringstream oss;
	oss << i;
	return oss.str();
}

int string_to_int(const std::string& str)
{
	std::istringstream iss(str);
	int num;
	iss >> num;
	return (num);
}
