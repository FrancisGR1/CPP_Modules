#include "Point.hpp"

Point::Point() 
	: x(Fixed(0)), y(Fixed(0))
{};


Point::Point(const float x, const float y)
	: x(Fixed(x)), y(Fixed(y))
{};

Point::Point(const Point& p) 
	: x(Fixed(p.getX())), y(Fixed(p.getY()))
{};

Point::~Point(){}

Point Point::operator=(const Point& p)
{
	Point new_p(p);
	return new_p;
};

Fixed Point::getX() const { return x; }

Fixed Point::getY() const { return y; }
