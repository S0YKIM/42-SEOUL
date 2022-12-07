/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:53:51 by sokim             #+#    #+#             */
/*   Updated: 2022/07/25 19:28:37 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", PRESIDENTIAL_SIGN_GRADE, PRESIDENTIAL_EXEC_GRADE), target_("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", PRESIDENTIAL_SIGN_GRADE, PRESIDENTIAL_EXEC_GRADE), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &origin) : Form(origin), target_(origin.getTarget()) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &origin)
{
	Form::operator=(origin);
	target_ = origin.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string	&PresidentialPardonForm::getTarget() const {
	return (target_);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!getIsSigned())
		throw NotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
