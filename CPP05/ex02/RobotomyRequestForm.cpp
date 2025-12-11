#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm()
	, m_target("default target")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request", RR_SIGN, RR_EXEC)
	, m_target(target)
{
	std::cout << "<RobotymRequestForm> " << getName() << " constroyed" << std::endl;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	return *this;
};

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "<RobotymRequestForm> " << getName() << " destroyed" << std::endl;
};

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!isSigned())
	{
		std::cout << "Roboty failed!" << std::endl;
		throw(GradeNotSignedException());
	}
	else if (!hasRequiredGrades(executor))
	{
		std::cout << "Roboty failed!" << std::endl;
		throw(GradeTooLowException(executor.getName(), "doesn't have the required grades"));
	}
	else
	{
		std::cout << "TREARARRERRARATATRARARARARARARARA\n" << m_target << " has been robotomized successfully 50% of the time\n";
	}
};
