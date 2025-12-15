#include <iostream>
#include "Span.hpp"

int main()
{
	try
	{
		std::cout << "10 sample size\n";
		Span span(10);
		span.fillRandom();
		span.print();
		std::cout << "shortest span: " << span.shortestSpan() << "\n";
		std::cout << "longest  span: " << span.longestSpan() << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	try
	{
		std::cout << "\n\n1000 sample size\n";
		Span span(1000);
		span.fillRandom();
		//span.print();
		std::cout << "shortest span: " << span.shortestSpan() << "\n";
		std::cout << "longest  span: " << span.longestSpan() << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
}
