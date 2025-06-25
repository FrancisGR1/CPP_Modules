#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed( const Fixed& );
		int getRawBits( void );
		void setRawBits( int const );

		Fixed operator=(Fixed const& point);
	private:
		int m_value;
		static const int m_fractional_bits = 8;
};

#endif /*FIXED_HPP*/
