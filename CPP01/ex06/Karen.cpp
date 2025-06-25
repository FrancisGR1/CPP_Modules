#include "Karen.hpp"

void Karen::complain(std::string s)
{
	static std::string lvls[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int i = 0;
	for (; i < LEVELS; i++)
	{
		if (s == lvls[i])
			break ;
	}
	switch (i) {
		case DEBUG:
			debug();
			info();
			warning();
			error();
			break;
		case INFO:
			info();
			warning();
			error();
			break;
		case WARNING:
			warning();
			error();
			break;
		case ERROR:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
};

void Karen::debug(void)
{
	std::cout << "[ DEBUG ]\nI love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"
		<< std::endl << std::endl;
};

void Karen::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!"
		<< std::endl << std::endl;
};

void Karen::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month."
		<< std::endl << std::endl;
};
void Karen::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable, I want to speak to the manager now."
		<< std::endl << std::endl;
};
