#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

#define SC_SIGN 145
#define SC_EXEC 137

class ShrubberyCreationForm : public AForm 
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
		~ShrubberyCreationForm();

		void execute(const Bureaucrat& executor) const;

	private:
		const std::string m_target;
};

#endif /*SHRUBBERYCREATIONFORM_HPP*/
