/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:30:30 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 15:53:48 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://web.archive.org/web/20191105112934/http://www-inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html
//
//https://en.wikipedia.org/wiki/Single-precision_floating-point_format
//
//https://electronics.stackexchange.com/questions/591263/is-there-a-standard-way-to-convert-from-a-fixed-point-notation-to-a-floating-poi
//https://vanhunteradams.com/FixedPoint/FixedPoint.html

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a(19);
	Fixed b( Fixed( 5.05f )   * Fixed(2) );
	std::cout << std::boolalpha;
	std::cout << "Fixed: b(5.05f * 2), b(19)" << std::endl;
	std::cout << "b < a: " << (b < a) << std::endl;
	std::cout << "add: " << (b + a) << std::endl;
	std::cout << "subtract: " << (b - a) << std::endl;
	std::cout << "multiply: " << (b * a) << std::endl;
	std::cout << "division: " << (b / a) << std::endl;
	std::cout << "incrementing a: ";
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "min: " << Fixed::min( a, b ) << std::endl;
	return 0;
}
