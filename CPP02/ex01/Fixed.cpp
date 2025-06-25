#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	m_value = 0;
};

Fixed::Fixed(int n)
{
	std::cout << "Int constructor called" << std::endl;
	m_value = n << m_fractional_bits;
};

Fixed::Fixed(float n)
{
	std::cout << "Float constructor called" << std::endl;
	m_value = static_cast<int>(roundf(n * (1 <<  m_fractional_bits)));
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed& point)
{
	std::cout << "Copy constructor called" << std::endl;
	m_value = point.m_value;
};

//TODO:
//porque é que isto funciona mas não:
//return (Fixed(point))
//???
Fixed Fixed::operator=(const Fixed& point)
{
	std::cout << "Assignment operator called" << std::endl;
	m_value = point.m_value;
	return *this;
};

std::ostream& operator<<(std::ostream& out, const Fixed& point)
{
	return out << point.toFloat();
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

float Fixed::toFloat(void) const
{
	return (static_cast<float>(m_value) / (1 << m_fractional_bits));
};

int Fixed::toInt(void) const
{
	return (static_cast<int>(m_value / (1 << m_fractional_bits)));
};
