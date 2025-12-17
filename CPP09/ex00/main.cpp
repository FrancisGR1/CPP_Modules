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
		const char *prices = "data.csv";
		BitcoinExchange btc(prices);
		const std::string evaluation = argv[1];
		btc.evaluate(evaluation);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Database: " << e.what() << "\n";
	}
}
