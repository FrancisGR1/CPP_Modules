#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(k_default_name, k_grade_to_sign, k_grade_to_exec)
	, m_target(target)
{
	std::cout << "<RobotymRequestForm> " << getName() << " constroyed" << std::endl;
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
		throw(GradeTooLowException());
	}
	else
		std::cout << "TREARARRERRARATATRARARARARARARARA "
			<< std::endl
			<< m_target << " has been robotomized successfully 50% of the time "
			<< std::endl;
};
