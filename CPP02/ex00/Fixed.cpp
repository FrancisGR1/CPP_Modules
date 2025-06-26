/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:11:33 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 14:22:39 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	m_value = 0;
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed& point)
{
	m_value = point.m_value;
	std::cout << "Copy constructor called" << std::endl;
};

Fixed Fixed::operator=(const Fixed& point)
{
	std::cout << "Assignment operator called" << std::endl;
	return (Fixed(point));
};

int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_value);
};

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	m_value = raw;
};
