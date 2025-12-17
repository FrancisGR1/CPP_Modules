#include <map>
#include <string>

class BitcoinExchange
{
	public:
		typedef int Date;
		typedef float ExchangeRate;

		BitcoinExchange();
		BitcoinExchange(const char *prices_database_path);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void evaluate(const char *evaluation_path);



	private:
		std::string m_prices_database_path;
		std::map<Date, ExchangeRate> m_database;

		void load_database(const std::string& m_prices_database_path);

		//utils for parsing
		void skip_whitespaces(const std::string& line, size_t& idx);
		Date str_to_date(const std::string& line, size_t& idx);
		ExchangeRate str_to_exchange_rate(const std::string& line, size_t& idx);
		void expect(const std::string& str, const std::string& line, size_t& idx);
};
