#include "Bureaucrat.hpp"

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
	if (grade < MAX_GRADE)
		throw (GradeTooHighException());
	if (grade > MIN_GRADE)
		throw (GradeTooLowException());
	std::cout << "<Bureaucrat> " << m_name << " constroyed" << std::endl;
};

Bureaucrat::Bureaucrat(Bureaucrat& other)
	: m_name(other.m_name)
	, m_grade(other.m_grade)
{
	if (m_grade < MAX_GRADE)
		throw (GradeTooHighException());
	if (m_grade > MIN_GRADE)
		throw (GradeTooLowException());
	std::cout << "<Bureaucrat> " << m_name << "copied" << std::endl;
};

Bureaucrat::~Bureaucrat()
{
	std::cout << "<Bureaucrat> " << m_name <<  " destroyed" << std::endl;
};

void Bureaucrat::incrementGrade()
{
	if (m_grade - 1 < MAX_GRADE)
		throw (GradeTooHighException());
	m_grade--;
};

void Bureaucrat::decrementGrade()
{
	if (m_grade + 1 > MIN_GRADE)
		throw (GradeTooLowException());
	m_grade++;
};

void Bureaucrat::signForm(Form& document)
{
	try
	{
		document.beSigned(*this);
		std::cout << m_name << " signed " << document.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << m_name << " couldn't sign " << document.getName() << " because " << e.what() << std::endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() + ", bureaucrat grade " + std::to_string(bureaucrat.getGrade()) + ".";
	return os;
};
