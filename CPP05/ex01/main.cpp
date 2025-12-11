#include "Bureaucrat.hpp"
#include "Form.hpp"

void log(const std::string& name, const std::string& action, int grade)
{
	std::cout << "Objective: " << action << " " << name << ": " << grade << std::endl;
}

int main(void)
{
	try
	{
		std::cout << "===== Form Construction =====\n";
		Form f("form1", 40, 50);
		std::cout << f << std::endl;

		std::cout << "\n***Sign - Success***\n";
		Bureaucrat person("franc", 30);
		std::cout << person << std::endl;
		person.signForm(f);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "\n\n\n";

	try
	{
		std::cout << "\n===== Form Construction 2=====\n";
		Form f2("form2", 40, 50);
		std::cout << f2 << std::endl;
		std::cout << "\n***Sign - Failure***\n";
		Bureaucrat person2("john", 50);
		std::cout << person2 << std::endl;
		person2.signForm(f2);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "\n\n\n";

	try
	{
		std::cout << "\n===== Form Construction 3=====\n";  
		std::cout << "Create form with a signature requirement of 0\n";  
		Form f3("form3", 0, 50);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "\n\n\n";

	try
	{
		std::cout << "\n===== Form Construction 4=====\n";
		std::cout << "Create form with an execution requirement of 160\n";  
		Form f4("form4", 10, 160);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
};
