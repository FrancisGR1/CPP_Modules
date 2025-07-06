#include "Bureaucrat.hpp"

void log_bureaucrat(std::string_view name, std::string_view action, int grade)
{
	std::cout << "Intention: to " << action << " " << name << ": " << grade << std::endl;
}

int main(void)
{
	{
		std::cout << "===== Form Construction =====" << std::endl;
		Form f("form1", 40, 50);
		std::cout << f << std::endl;

		std::cout << "\n===== Try to Sign - Success =====" << std::endl;
		{
			Bureaucrat person("franc", 30);
			std::cout << person << std::endl;
			person.signForm(f);
		}
		std::cout << std::boolalpha << "Form is signed: " << f.isSigned() << std::endl;
	}

	{
		std::cout << "===== Form Construction 2=====" << std::endl;
		Form f("form1", 40, 50);
		std::cout << f << std::endl;
		std::cout << "\n===== Try to Sign - Failure =====" << std::endl;
		{
			Bureaucrat person("john", 50);
			std::cout << person << std::endl;
			person.signForm(f);
		}
		std::cout << std::boolalpha << "Form is signed: " << f.isSigned() << std::endl;
	}
	std::cout << "\n===== Destruction Log =====" << std::endl;
};
