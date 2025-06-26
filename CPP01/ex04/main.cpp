/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:21:17 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 11:12:42 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream> 
#include <sstream> 

int main(int argc, char  **argv)
{

	if (argc != 4) 
	{
		std::cerr << "Format: ./sed <FILE> <TARGET> <TO_REPLACE>" << std::endl;
		return 1;
	}

	std::ifstream f(argv[1]);
	if (f.fail()) 
	{
		std::cerr << "Error: Failed to open file " << argv[1] << std::endl;
		return 1;
	}

	std::string target(argv[2]);
	std::string to_replace(argv[3]);
	if (target.empty() || to_replace.empty())
	{
		std::cerr << "Error: One or both strings are empty" << std::endl;
		return 1;
	}

	std::stringstream buf;
	buf << f.rdbuf();

	std::string new_str(buf.str());
	size_t pos = 0;
	while ((pos = new_str.find(argv[2], pos)) != std::string::npos)
	{
		size_t pos_end = pos + target.length();
		std::string substr_start = new_str.substr(0, pos);
		std::string substr_end = new_str.substr(pos_end, new_str.length());
		new_str = substr_start + to_replace + substr_end;
		pos = pos_end;
	}

	std::ofstream out("new_string.REPLACE");
	out << new_str << std::endl;

	f.close();
	out.close();
	return (0);
}
