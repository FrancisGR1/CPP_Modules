#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#define PP_SIGN 25
#define PP_EXEC 5

class PresidentialPardonForm : public AForm 
{
	public:

		PresidentialPardonForm();
		explicit PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);
		~PresidentialPardonForm();

		void execute(const Bureaucrat& executor) const;

	private:
		const std::string m_target;
};

#endif /*PRESIDENTIALPARDONFORM_HPP*/
