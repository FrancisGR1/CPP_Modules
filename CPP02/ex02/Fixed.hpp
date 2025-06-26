/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:30:21 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 15:53:03 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		static Fixed const& max(Fixed const& p1, Fixed const& p2);
		static Fixed& max(Fixed& p1, Fixed& p2);
		static Fixed const& min(Fixed const& p1, Fixed const& p2);
		static Fixed& min(Fixed& p1, Fixed& p2);

		Fixed();
		Fixed(int);
		Fixed(float);
		Fixed( const Fixed& );
		~Fixed();

		void setRawBits( int const );
		int getRawBits( void ) const;

		float toFloat(void) const;
		int toInt(void) const;

		Fixed operator=(Fixed const& point);

		bool operator<(Fixed const& point) const;
		bool operator>(Fixed const& point) const;
		bool operator<=(Fixed const& point) const;
		bool operator>=(Fixed const& point) const;
		bool operator==(Fixed const& point) const;
		bool operator!=(Fixed const& point) const;

		Fixed operator+(Fixed const& point);
		Fixed operator-(Fixed const& point);
		Fixed operator*(Fixed const& point);
		Fixed operator/(Fixed const& point);

		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);


	private:
		int m_value;
		static const int m_fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& point);

#endif /*FIXED_HPP*/
