#include "Bureaucrat.hpp"

static std::string to_string(const int& value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

Bureaucrat::Bureaucrat()
	: m_name("default")
	, m_grade(MIN_GRADE)
{
	std::cout << "<Bureaucrat> " << m_name << " constroyed" << std::endl;
};

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: m_name(name)
	, m_grade(grade)
{
	if (m_grade < MAX_GRADE)
		throw (GradeTooHighException(m_name, "Grade too high: " + to_string(m_grade)));
	if (m_grade > MIN_GRADE)
		throw (GradeTooLowException(m_name, "Grade too low: " + to_string(m_grade)));
	std::cout << "<Bureaucrat> " << m_name << " constroyed" << std::endl;
};

Bureaucrat::Bureaucrat(Bureaucrat& other)
	: m_name(other.m_name)
	, m_grade(other.m_grade)
{
	if (m_grade < MAX_GRADE)
		throw (GradeTooHighException(m_name, "Grade too high: " + to_string(m_grade)));
	if (m_grade > MIN_GRADE)
		throw (GradeTooLowException(m_name, "Grade too low: " + to_string(m_grade)));
	std::cout << "<Bureaucrat> " << m_name << "copied" << std::endl;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	m_grade = other.m_grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "<Bureaucrat> " << m_name <<  " destroyed" << std::endl;
};

const std::string& Bureaucrat::getName() const 
{ 
	return m_name; 
}

int Bureaucrat::getGrade() const 
{ 
	return m_grade; 
}

void Bureaucrat::incrementGrade()
{
	if (m_grade - 1 < MAX_GRADE)
		throw (GradeTooHighException(m_name, "Error: Cannot increment"));
	m_grade--;
};

void Bureaucrat::decrementGrade()
{
	if (m_grade + 1 > MIN_GRADE)
		throw (GradeTooLowException(m_name, "Error: Cannot decrement"));
	m_grade++;
};

void Bureaucrat::signForm(Form& f)
{
	f.beSigned(*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() + ", bureaucrat grade " + to_string(bureaucrat.getGrade()) + "." << std::endl;
	return os;
};

