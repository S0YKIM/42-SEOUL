/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:35:51 by sokim             #+#    #+#             */
/*   Updated: 2022/07/11 15:39:19 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &origin) {
	*this = origin;
}

Intern& Intern::operator=(const Intern &) {
	return (*this);
}

Intern::~Intern() {}

static Form	*makeShruberry(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static Form	*makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

static Form	*makePresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

static int	selectOption(std::string type) {
	std::string	forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	int	option = -1;
	for (int i = 0; i < 3; i++) {
		if (type == forms[i])
			option = i;
	}
	return (option);
}

Form	*Intern::makeForm(std::string type, std::string target)
{
	Form	*form;
	Form	*(*func[3])(std::string target) = {
		&makeShruberry,
		&makeRobotomy,
		&makePresidential
	};

	int	option;
	option = selectOption(type);
	switch (option) {
	case 0:
		form = (*func[0])(target);
		break ;
	case 1:
		form = (*func[1])(target);
		break ;
	case 2:
		form = (*func[2])(target);
		break ;
	default:
		throw NoMatchTypeException();
		break ;
	}
	return (form);
}

const char* Intern::NoMatchTypeException::what() const throw()
{
	return "Intern couldn't find matching form.";
}
