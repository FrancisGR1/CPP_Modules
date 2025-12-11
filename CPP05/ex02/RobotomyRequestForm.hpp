#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#define RR_SIGN 72
#define RR_EXEC 45

class RobotomyRequestForm : public AForm 
{
	public:

		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm& operator=(const RobotomyRequestForm&);
		~RobotomyRequestForm();

		void execute(const Bureaucrat& executor) const;

	private:
		const std::string m_target;
};

#endif /*ROBOTOMYREQUESTFORM_HPP*/
