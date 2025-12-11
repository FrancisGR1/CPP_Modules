#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm()
	, m_target("default target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", SC_SIGN, SC_EXEC), m_target(target) 
{
	std::cout << "<ShrubberyCreationForm> " << getName() << " constroyed" << std::endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return *this;
};

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	std::cout << "<ShrubberyCreationForm> " << getName() << " destroyed" << std::endl;
};

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const 
{
	if (!isSigned())
		throw(GradeNotSignedException());
	else if (!hasRequiredGrades(executor))
	{
		throw(GradeTooLowException(executor.getName(), "doesn't have the required grades"));
	}
	else
	{
		std::ofstream file((m_target + "_shrubbery").c_str());
		if (!file) {
			std::cerr << "Failed to create shrubbery file" << std::endl;
			return ;
		}
		file << "ascii tree lol";
		file.close();
	}
};
