#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(k_default_name, k_grade_to_sign, k_grade_to_exec), m_target(target) 
{
	std::cout << "<ShrubberyCreationForm> " << getName() << " constroyed" << std::endl;
};

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "<ShrubberyCreationForm> " << getName() << " destroyed" << std::endl;
};

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!isSigned())
		throw(GradeNotSignedException());
	else if (!hasRequiredGrades(executor))
		throw(GradeTooLowException());
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
