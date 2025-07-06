#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {

	Intern new_guy;
	Bureaucrat important_guy("Roy", 5);

	std::cout << "\n========== RobotomyRequest ==========" << std::endl;
	AForm *robo = new_guy.makeForm("robotomy request", "Fred");
	important_guy.signForm(*robo);
	robo->execute(important_guy); 
	delete robo;

	std::cout << "\n========== PresidentialPardon ==========" << std::endl;
	AForm *pres = new_guy.makeForm("presidentialPardon", "Sadie");
	important_guy.signForm(*pres);
	pres->execute(important_guy); 
	delete pres;

	std::cout << "\n========== ShrubberyCreation ==========" << std::endl;
	AForm *shrub = new_guy.makeForm("shrubbery creation", "Madelyn");
	important_guy.signForm(*shrub);
	shrub->execute(important_guy); 
	delete shrub;

	std::cout << "\n========== Wrong Form ==========" << std::endl;
	std::string wrong_type = "blablabla";
	try {
	AForm *wrong = new_guy.makeForm(wrong_type, "Hector");
	important_guy.signForm(*wrong);
	wrong->execute(important_guy); 
	delete wrong;
	} catch (const std::exception& e) {
		std::cout << e.what() << ": " << wrong_type << " is not a type" << std::endl;
	}

	std::cout << "\n========== Destruction Log ==========" << std::endl;
};
