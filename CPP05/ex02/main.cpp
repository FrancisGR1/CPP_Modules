#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

	std::cout << "\n===== NOT SIGNED =====" << std::endl;
	try
	{

		std::cout << "\n*Construction Log*" << std::endl;

		PresidentialPardonForm form("Javier");
		Bureaucrat random("Oscar", 5);
		std::cout << form << std::endl << random << std::endl;
		random.executeForm(form);

		std::cout << "\n*Destruction Log*" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "\n\nError: " << e.what() << "\n";
	}



	std::cout << "\n\n\n===== CAN'T SIGN =====" << std::endl;
	try
	{
		std::cout << "\n*Construction Log*" << std::endl;

		PresidentialPardonForm form("Javier");
		Bureaucrat random("Oscar", 40);
		std::cout << form << std::endl << random << std::endl;
		random.signForm(form);
		random.executeForm(form);

		std::cout << "\n*Destruction Log*" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "\n\nError: " << e.what() << "\n";
	}



	std::cout << "\n\n\n===== CAN'T EXECUTE =====" << std::endl;
	try
	{
		std::cout << "\n*Construction Log*" << std::endl;

		PresidentialPardonForm form("Javier");
		Bureaucrat random("Oscar", 15);
		std::cout << form << std::endl << random << std::endl;
		random.signForm(form);
		random.executeForm(form);

		std::cout << "\n*Destruction Log*" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "\n\nError: " << e.what() << "\n";
	}



	std::cout << "\n\n\n===== SUCESS: PARDON =====" << std::endl;
	try
	{
		std::cout << "\n*Construction Log*" << std::endl;

		PresidentialPardonForm form("Javier");
		Bureaucrat random("Oscar", 5);
		std::cout << form << std::endl << random << std::endl;
		random.signForm(form);
		random.executeForm(form);

		std::cout << "\n*Destruction Log*" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "\n\nError: " << e.what() << "\n";
	}



	std::cout << "\n===== SUCESS: ROBOTOMY =====" << std::endl;
	try
	{	
		std::cout << "\n*Construction Log*" << std::endl;

		RobotomyRequestForm form("Javier");
		Bureaucrat random("Maria", 45);
		std::cout << form << std::endl << random << std::endl;
		random.signForm(form);
		random.executeForm(form);

		std::cout << "\n*Destruction Log*" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "\n\nError: " << e.what() << "\n";
	}



	std::cout << "\n===== SUCESS: SHRUBBERY =====" << std::endl;
	try
	{
		std::cout << "\n*Construction Log*" << std::endl;

		ShrubberyCreationForm form("Javier");
		Bureaucrat random("Maria", 139);
		std::cout << form << std::endl << random << std::endl;
		random.signForm(form);
		random.executeForm(form);

		std::cout << "\n*Destruction Log*" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "\n\nError: " << e.what() << "\n";
	}
};
