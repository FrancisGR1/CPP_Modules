#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
	 inline static constexpr int k_grade_to_sign = 145;
	 inline static constexpr int k_grade_to_exec = 137;

  explicit ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(ShrubberyCreationForm&) = default;
  ShrubberyCreationForm& operator=(ShrubberyCreationForm&) = delete;
  ~ShrubberyCreationForm();

  void execute(const Bureaucrat& executor) const override;

 private:
  const std::string m_target;
};

#endif /*SHRUBBERYCREATIONFORM_HPP*/
