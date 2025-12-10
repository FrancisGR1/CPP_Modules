#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <sstream>

const int MAX_GRADE = 1;
const int MIN_GRADE = 150;

class Bureaucrat
{
	public: 
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string& getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::runtime_error
		{
			public:
				explicit GradeTooHighException(const std::string& msg)
					: std::runtime_error(msg) {}
		};

		class GradeTooLowException : public std::runtime_error
		{
			public:
				explicit GradeTooLowException(const std::string& msg)
					: std::runtime_error(msg) {}
		};


	private:
		const std::string m_name;
		int m_grade;
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif /*BUREAUCRAT_HPP*/
