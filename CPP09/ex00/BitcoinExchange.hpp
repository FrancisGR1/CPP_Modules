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

		void evaluate(const std::string& evaluation_path);



	private:
		std::string m_exchange_rate_db_path;
		std::map<Date, ExchangeRate> m_database;

		void load_database();

		//utils for parsing
		void skip_whitespaces(const std::string& line, size_t& idx);
		Date to_date(const std::string& line, size_t& idx);
		ExchangeRate to_exchange_rate(const std::string& line, size_t& idx);
		void expect(const std::string& str, const std::string& line, size_t& idx);
};
