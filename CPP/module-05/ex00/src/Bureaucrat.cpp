/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:26:17 by sokim             #+#    #+#             */
/*   Updated: 2022/07/10 17:03:48 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Default"), grade_(LOWEST_GRADE) {
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name) {
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	grade_ = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &origin) {
	*this = origin;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &origin) {
	if (this != &origin)
		grade_ = origin.grade_;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

std::string	Bureaucrat::getName() const {
	return (name_);
}

int	Bureaucrat::getGrade() const {
	return (grade_);
}

void	Bureaucrat::incrementGrade() {
	if (grade_ - 1 < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	grade_ -= 1;
}

void	Bureaucrat::decrementGrade() {
	if (grade_ + 1 > LOWEST_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
	grade_ += 1;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &origin) {
	out << origin.getName() << ", bureaucrat grade " << origin.getGrade();
	return (out);
}
