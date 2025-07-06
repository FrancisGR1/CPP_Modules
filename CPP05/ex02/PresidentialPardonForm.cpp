#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(k_default_name, k_grade_to_sign, k_grade_to_exec), m_target(target) 
{
	std::cout << "<PresidentialPardonForm> " << getName() << " constroyed" << std::endl;
};

PresidentialPardonForm::~PresidentialPardonForm() 
{
	std::cout << "<PresidentialPardonForm> " << getName() << " destroyed" << std::endl;
};

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!isSigned())
		throw(GradeNotSignedException());
	else if (!hasRequiredGrades(executor))
		throw(GradeTooLowException());
	else
		std::cout << m_target << " has been pardoned by Zaphod Beeblebox"
			<< std::endl;
};

