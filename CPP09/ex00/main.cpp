#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "./btc <prices_database_path>\n";
		return 1;
	}
	try
	{
		const char *prices_database_path = "data.csv";
		BitcoinExchange btc(prices_database_path);
		btc.evaluate(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
}
