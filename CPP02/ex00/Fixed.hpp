/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmiguel <frmiguel>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:11:41 by frmiguel          #+#    #+#             */
/*   Updated: 2025/06/26 12:11:41 by frmiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed( const Fixed& );
		Fixed operator=(Fixed const& point);
		~Fixed();

		int getRawBits( void );
		void setRawBits( int const );

	private:
		int m_value;
		static const int m_fractional_bits = 8;
};

#endif /*FIXED_HPP*/
