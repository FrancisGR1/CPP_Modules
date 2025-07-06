#include "Bureaucrat.hpp"

void log_bureaucrat(std::string_view name, std::string_view action, int grade)
{
	std::cout << "Intention: to " << action << " " << name << ": " << grade << std::endl;
}

int main(void)
{
	std::cout << "===== Normal Bureaucrat =====" << std::endl;
	Bureaucrat bur_normal("Franc", 140);
	std::cout << bur_normal << std::endl;

	std::cout << "===== ERRORS: =====" << std::endl;
	std::cout << "===== Grade Too Low  =====" << std::endl;
	try
	{
		log_bureaucrat("John", "constroy", 160);
		Bureaucrat bur_wrong("John", 160);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n===== Grade Too High  =====" << std::endl;
	try
	{
		log_bureaucrat("John", "constroy", 0);
		Bureaucrat bur_wrong("John", 0);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n===== Increment Grade =====" << std::endl;
	try
	{
		log_bureaucrat("John", "increment", 1);
		Bureaucrat bur_wrong("John", 1);
		bur_wrong.incrementGrade();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n===== Decrement Grade =====" << std::endl;
	try
	{
		log_bureaucrat("John", "decrement", 150);
		Bureaucrat bur_wrong("John", 150);
		bur_wrong.decrementGrade();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n===== Destruction Log =====" << std::endl;
};
