/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:27:18 by sokim             #+#    #+#             */
/*   Updated: 2022/07/25 19:28:09 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_("Default"), isSigned_(false), gradeToSign_(LOWEST_GRADE), gradeToExecute_(LOWEST_GRADE) {}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
	if (gradeToSign_ < HIGHEST_GRADE || gradeToExecute_ < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (gradeToSign_ > LOWEST_GRADE || gradeToExecute_ > LOWEST_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form &origin) : name_(origin.getName()), isSigned_(origin.getIsSigned()), gradeToSign_(origin.getGradeToSign()), gradeToExecute_(origin.getGradeToExecute()) {
	if (gradeToSign_ < HIGHEST_GRADE || gradeToExecute_ < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (gradeToSign_ > LOWEST_GRADE || gradeToExecute_ > LOWEST_GRADE)
		throw GradeTooLowException();
}

Form &Form::operator=(const Form &origin) {
	if (this == &origin)
		return (*this);
	*(const_cast<std::string *>(&name_)) = origin.getName();
	*(const_cast<int *>(&gradeToSign_)) = origin.getGradeToSign();
	*(const_cast<int *>(&gradeToExecute_)) = origin.getGradeToExecute();
	isSigned_ = origin.getIsSigned();
	return (*this);
}

Form::~Form() {}

const std::string	&Form::getName() const {
	return (name_);
}

const bool	&Form::getIsSigned() const {
	return (isSigned_);
}

const int	&Form::getGradeToSign() const {
	return (gradeToSign_);
}

const int	&Form::getGradeToExecute() const {
	return (gradeToExecute_);
}

void	Form::beSigned(const Bureaucrat &signer) {
	if (signer.getGrade() > gradeToSign_)
		throw GradeTooLowException();
	isSigned_ = true;
}

const char	*Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

const char	*Form::NotSignedException::what() const throw() {
	return ("Form is not signed yet.");
}

std::ostream	&operator<<(std::ostream &out, const Form &form) {
	out << "- Form name: " << form.getName() << std::endl;
	out << "- Grade needed to sign: " << form.getGradeToSign() << std::endl;
	out << "- Grade needed to execute: " << form.getGradeToExecute() << std::endl;
	out << "- Is it signed?: " << form.getIsSigned() << std::endl;
	return (out);
}
