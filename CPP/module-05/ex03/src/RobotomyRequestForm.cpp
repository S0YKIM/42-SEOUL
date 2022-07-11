/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:54:04 by sokim             #+#    #+#             */
/*   Updated: 2022/07/11 12:13:32 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE), target_("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &origin) : Form(origin), target_(origin.getTarget()) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &origin) {
	Form::operator=(origin);
	target_ = origin.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string	RobotomyRequestForm::getTarget() const {
	return (target_);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw NotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::cout << "* Drrrrrrrrrrrrrrrriiiiiiillllllllllll... *" << std::endl;
	if (std::rand() % 2)
		std::cout << target_ << " failed to be robotomized!" << std::endl;
	else
		std::cout << target_ << " has been successfully robotomized!" << std::endl;
}
