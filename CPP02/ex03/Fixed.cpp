#include "Fixed.hpp"

Fixed const& Fixed::max(Fixed const& p1, Fixed const& p2)
{
	return (p1 > p2 ? p1 : p2);
};

Fixed& Fixed::max(Fixed& p1, Fixed& p2)
{
	return (p1 > p2 ? p1 : p2);
};

Fixed const& Fixed::min(Fixed const& p1, Fixed const& p2)
{
	return (p1 < p2 ? p1 : p2);
};

Fixed& Fixed::min(Fixed& p1, Fixed& p2)
{
	return (p1 < p2 ? p1 : p2);
};

Fixed::Fixed()
{
	m_value = 0;
};

Fixed::Fixed(int n)
{
	m_value = n << m_fractional_bits;
};

Fixed::Fixed(float n)
{
	m_value = static_cast<int>(roundf(n * (1 <<  m_fractional_bits)));
};

Fixed::~Fixed()
{
};

Fixed::Fixed(const Fixed& point)
{
	m_value = point.m_value;
};

//TODO:
//porque é que isto funciona mas não:
//return (Fixed(point))
//???
Fixed Fixed::operator=(const Fixed& point)
{
	m_value = point.m_value;
	return *this;
};

std::ostream& operator<<(std::ostream& out, const Fixed& point)
{
	return out << point.toFloat();
};

bool Fixed::operator<(Fixed const& point) const
{
	return (m_value < point.m_value);
};

bool Fixed::operator>(Fixed const& point) const
{
	return (m_value > point.m_value);
};

bool Fixed::operator<=(Fixed const& point) const
{
	return (m_value <= point.m_value);
};

bool Fixed::operator>=(Fixed const& point) const
{
	return (m_value >= point.m_value);
};

bool Fixed::operator==(Fixed const& point) const
{
	return (m_value == point.m_value);
};

bool Fixed::operator!=(Fixed const& point) const
{
	return (m_value != point.m_value);
};

Fixed Fixed::operator+(Fixed const& point)
{
	return (Fixed(this->toFloat() + point.toFloat()));
};

Fixed Fixed::operator-(Fixed const& point)
{
	return (Fixed(this->toFloat() - point.toFloat()));
};

Fixed Fixed::operator*(Fixed const& point)
{
	return (Fixed(this->toFloat() * point.toFloat()));
};

Fixed Fixed::operator/(Fixed const& point)
{
	return (Fixed(this->toFloat() / point.toFloat()));
};

Fixed Fixed::operator++()
{
	return (Fixed(++m_value));
};

Fixed Fixed::operator--()
{
	return (Fixed(--m_value));
};

Fixed Fixed::operator++(int)
{
	return (Fixed(m_value++));
};

Fixed Fixed::operator--(int)
{
	return (Fixed(m_value--));
};
int Fixed::getRawBits(void) const
{
	return (m_value);
};

void Fixed::setRawBits(int const raw)
{
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
