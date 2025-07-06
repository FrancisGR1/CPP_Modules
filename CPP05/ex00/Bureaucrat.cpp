#include "Bureaucrat.hpp"

int *global_var;

Bureaucrat::Bureaucrat()
	: m_name("default")
	, m_grade(150)
{
	std::cout << "<Bureaucrat> " << m_name << " constroyed" << std::endl;
};

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: m_name(name)
	, m_grade(grade)
{
	//global_var = new(int);
	if (grade < MAX_GRADE)
		throw (GradeTooHighException(std::to_string(grade)));
	if (grade > MIN_GRADE)
		throw (GradeTooLowException(std::to_string(grade)));
	std::cout << "<Bureaucrat> " << m_name << " constroyed" << std::endl;
};

Bureaucrat::Bureaucrat(Bureaucrat& other)
	: m_name(other.m_name)
	, m_grade(other.m_grade)
{
	if (m_grade < MAX_GRADE)
		throw (GradeTooHighException(std::to_string(m_grade)));
	if (m_grade > MIN_GRADE)
		throw (GradeTooLowException(std::to_string(m_grade)));
	std::cout << "<Bureaucrat> " << m_name << "copied" << std::endl;
};

Bureaucrat::~Bureaucrat()
{
	std::cout << "<Bureaucrat> " << m_name <<  " destroyed" << std::endl;
	//delete global_var;
};

void Bureaucrat::incrementGrade()
{
	if (m_grade - 1 < MAX_GRADE)
		throw (GradeTooHighException("if incremented"));
	m_grade--;
};

void Bureaucrat::decrementGrade()
{
	if (m_grade + 1 > MIN_GRADE)
		throw (GradeTooLowException("if decremented"));
	m_grade++;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() + ", bureaucrat grade " + std::to_string(bureaucrat.getGrade()) + "." << std::endl;
	return os;
};
