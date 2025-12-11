#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm()
	, m_target("default target")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    	: AForm("Presidential Pardon", PP_SIGN, PP_EXEC)
	, m_target(target) 
{
	std::cout << "<PresidentialPardonForm> " << getName() << " constroyed\n";
};


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	AForm::operator=(other);
	return *this;
};

PresidentialPardonForm::~PresidentialPardonForm() 
{
	std::cout << "<PresidentialPardonForm> " << getName() << " destroyed\n";
};

void PresidentialPardonForm::execute(const Bureaucrat& executor) const 
{
	if (!isSigned())
		throw(GradeNotSignedException());
	else if (!hasRequiredGrades(executor))
		throw(GradeTooLowException(executor.getName(), "doesn't have the required grades"));
	else
		std::cout << m_target << " has been pardoned by Zaphod Beeblebox\n";

};
