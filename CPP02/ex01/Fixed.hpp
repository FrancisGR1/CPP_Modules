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
