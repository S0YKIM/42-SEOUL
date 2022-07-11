/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:54:15 by sokim             #+#    #+#             */
/*   Updated: 2022/07/11 12:18:13 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", SHRUBERRY_SIGN_GRADE, SHRUBERRY_EXEC_GRADE), target_("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", SHRUBERRY_SIGN_GRADE, SHRUBERRY_EXEC_GRADE), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &origin) : Form(origin), target_(origin.getTarget()) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &origin) {
	Form::operator=(origin);
	target_ = origin.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string	ShrubberyCreationForm::getTarget() const {
	return (target_);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw NotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	
	std::ofstream	treefile;
	treefile.open(getTarget() + "_shruberry");
	if (treefile.fail()) {
		std::cerr << "Failed to open the file." << std::endl;
		return ;
	}

	treefile << "       _-_" << std::endl;
	treefile << "    /~~   ~~\\" << std::endl;
	treefile << " /~~         ~~\\" << std::endl;
	treefile << "{               }" << std::endl;
	treefile << " \\  _-     -_  /" << std::endl;
	treefile << "   ~  \\\\ //  ~" << std::endl;
	treefile << "_- -   | | _- _" << std::endl;
	treefile << "  _ -  | |   -_" << std::endl;
	treefile << "      // \\\\" << std::endl;
	treefile.close();

	std::cout << "Shruberry has been successfully planted on " << target_ << std::endl;
}
