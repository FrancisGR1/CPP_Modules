#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

const int MAX_GRADE = 1;
const int MIN_GRADE = 150;

class Bureaucrat
{
	public: 
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat& other);
		Bureaucrat& operator=(Bureaucrat&) = delete;
		~Bureaucrat();

		const std::string& getName() const { return m_name; }
		int getGrade() const { return m_grade; }

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
	{
		public:
			explicit GradeTooHighException(const std::string& msg)
				: m_msg("Caught Error: " + msg + "\n") {}

			const char* what() const noexcept override { return m_msg.c_str(); }

		private: 
			const std::string m_msg;
	};

		class GradeTooLowException : public std::exception
	{
		public:
			explicit GradeTooLowException(const std::string& msg)
				: m_msg("Caught Error: " + msg + "\n") {}

			const char* what() const noexcept override { return m_msg.c_str(); }

		private: 
			const std::string m_msg;
	};


	private:
		const std::string m_name;
		int m_grade;
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif /*BUREAUCRAT_HPP*/
