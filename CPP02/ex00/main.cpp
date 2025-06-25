#include "Fixed.hpp"

//https://web.archive.org/web/20191105112934/http://www-inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html

int main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
