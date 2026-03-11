#include <iostream>
#include "Span.hpp"

int main()
{
	try
	{
		std::cout << "Test span\n";
		Span span(3);
		span.fillRandom(10);
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
		std::cout << "\n\n10 sample size\n";
		Span span(10);
		span.fillRandom(10);
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
		std::cout << "\n\n10,000 sample size\n";
		Span span(10000);
		span.fillRandom(100);
		//span.print();
		std::cout << "shortest span: " << span.shortestSpan() << "\n";
		std::cout << "longest  span: " << span.longestSpan() << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
}
