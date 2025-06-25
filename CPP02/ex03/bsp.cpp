#include "Point.hpp"

//http://totologic.blogspot.com/2014/01/accurate-point-in-triangle-test.html
//https://www.youtube.com/watch?v=HYAgJN3x4GA
//https://www.youtube.com/watch?v=vQciREU7Olg

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed s1 = c.getY() - a.getY();
	Fixed s2 = c.getX() - a.getX();
	Fixed s3 = b.getY() - a.getY();
	Fixed s4 = point.getY() - a.getY();

	Fixed w1 = (a.getX() * s1 + s4 * s2 - point.getX() * s1) / (s3 * s2 - (b.getX() - a.getX()) * s1);
	Fixed w2 = (s4 - w1 * s3) / s1;
	return (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1);
};
