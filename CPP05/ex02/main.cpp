#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	{
		std::cout << "\n===== Not signed =====" << std::endl;
		PresidentialPardonForm form("Oscar");
		Bureaucrat random("Oscar", 5);
		std::cout << form << std::endl << random << std::endl;
		random.executeForm(form);
	}
	{
		std::cout << "\n===== Can't sign =====" << std::endl;
		PresidentialPardonForm form("Oscar");
		Bureaucrat random("Oscar", 40);
		std::cout << form << std::endl << random << std::endl;
		random.signForm(form);
		random.executeForm(form);
	}
	{
		std::cout << "\n===== Can't execute =====" << std::endl;
		PresidentialPardonForm form("Oscar");
		Bureaucrat random("Oscar", 15);
		std::cout << form << std::endl << random << std::endl;
		random.signForm(form);
		random.executeForm(form);
	}
	{
		std::cout << "\n===== Sucess: Pardon =====" << std::endl;
		PresidentialPardonForm form("Oscar");
		Bureaucrat random("Oscar", 5);
		std::cout << form << std::endl << random << std::endl;
		random.signForm(form);
		random.executeForm(form);
	}
	{	
		std::cout << "\n===== Sucess: Robotomy =====" << std::endl;
		RobotomyRequestForm form("Sofia");
		Bureaucrat random("Maria", 5);
		std::cout << form << std::endl << random << std::endl;
		random.signForm(form);
		random.executeForm(form);
	}
	{
		std::cout << "\n===== Sucess: Shrubbery =====" << std::endl;
		ShrubberyCreationForm form("Sofia");
		Bureaucrat random("Maria", 5);
		std::cout << form << std::endl << random << std::endl;
		random.signForm(form);
		random.executeForm(form);
	}
};
