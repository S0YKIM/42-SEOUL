/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:26:14 by sokim             #+#    #+#             */
/*   Updated: 2022/07/11 12:21:50 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	Bureaucrat				a("Anna", 1);
	Bureaucrat				b("Brian", 70);
	Bureaucrat				c("Charlie", 150);
	ShrubberyCreationForm	shruberry("city");
	RobotomyRequestForm		robotomy("robot");
	PresidentialPardonForm	president("president");
	Form					*form;

	std::cout << "******************************************" << std::endl;
	std::cout << "*                TEST 1                  *" << std::endl;
	std::cout << "******************************************" << std::endl;
	
	form = &shruberry;
	std::cout << a << std::endl;
	std::cout << *form << std::endl;
	a.executeForm(*form); // Fail
	a.signForm(*form); // Success
	a.executeForm(*form); // Success
	std::cout << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	std::cout << "*                TEST 2                  *" << std::endl;
	std::cout << "******************************************" << std::endl;
	
	form = &robotomy;
	std::cout << b << std::endl;
	std::cout << *form << std::endl;
	b.signForm(*form); // Success
	b.executeForm(*form); // Fail
	a.executeForm(*form); // Success
	std::cout << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	std::cout << "*                TEST 3                  *" << std::endl;
	std::cout << "******************************************" << std::endl;

	form = &president;
	std::cout << c << std::endl;
	std::cout << *form << std::endl;
	c.signForm(*form); // Fail
	a.signForm(*form); // Success
	a.executeForm(*form); // Success
	std::cout << std::endl << std::endl;

	return (0);
}
