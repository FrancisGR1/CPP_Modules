/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:37:26 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/27 18:31:28 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
	: idx(0) {}

bool PhoneBook::add()
{
	if (!get_name(contacts[idx].first_name, "First Name: "))
		return (false);
	if (!get_name(contacts[idx].last_name, "Last Name: "))
		return (false);
	std::cout << "Nickname: ";
	if (!std::getline(std::cin, contacts[idx].nickname))
		return (false);
	if (!get_num(contacts[idx]))
		return (false);
	std::cout << "Dark Secret: ";
	if (!std::getline(std::cin, contacts[idx].secret))
		return (false);
	idx = (idx + 1) % MAX;
	return (true);
}

bool PhoneBook::display() const
{
	//Column names
	print_format("Index");
	print_format("First Name");
	print_format("Last Name");
	print_format("Nickname");
	std::cout << std::endl;
	std::cout << "----------|----------|----------|----------|" <<  std::endl;

	//Indexed table of all contacts
	for (size_t i = 0; i < MAX; i++)
	{
		print_format(to_string(i));
		print_format(contacts[i].first_name);
		print_format(contacts[i].last_name);
		print_format(contacts[i].nickname);
		std::cout << std::endl;
	}

	//Prompt for index
	int idx = 0;
	while (true)
	{
		std::cout << "Type index: ";
		std::string input;
		if (!std::getline(std::cin, input))
		{
			std::cin.clear();
			return (false);
		}; 
		if (!is_num(input))
		{
			std::cout << "Invalid - Only digits" << std::endl;
			continue;
		}
		idx = string_to_int(input);
		if (idx < 0 || idx > static_cast<int>(MAX - 1))
		{
			std::cout << "Invalid - Outside range (0 - 7)" << std::endl;
			continue;
		}
		break ;
	}
	
	//Index info 
	std::cout << "First Name: " << contacts[idx].first_name  << std::endl
		<< "Last Name: "    << contacts[idx].last_name   << std::endl
		<< "Nickname: "     << contacts[idx].nickname    << std::endl
		<< "Phone number: " << contacts[idx].phonenumber << std::endl
		<< "Dark secret: "  << contacts[idx].secret      << std::endl;

	return (true);
}

