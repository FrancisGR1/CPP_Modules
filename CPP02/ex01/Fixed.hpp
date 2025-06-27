/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:29:15 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 16:35:32 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(int);
		Fixed(float);
		~Fixed();
		Fixed( const Fixed& );
		int getRawBits( void );
		void setRawBits( int const );
		float toFloat(void) const;
		int toInt(void) const;

		Fixed operator=(Fixed const& point);
	private:
		int m_value;
		static const int m_fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& point);

#endif /*FIXED_HPP*/
