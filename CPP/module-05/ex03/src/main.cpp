/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:26:14 by sokim             #+#    #+#             */
/*   Updated: 2022/07/11 13:06:54 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void) {
	Bureaucrat				a("Anna", 1);
	Intern					intern;
	Form					*form;

	std::cout << "******************************************" << std::endl;
	std::cout << "*                TEST 1                  *" << std::endl;
	std::cout << "******************************************" << std::endl;
	
	try {
		form = intern.makeForm("unknown", "target");
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	std::cout << "*                TEST 2                  *" << std::endl;
	std::cout << "******************************************" << std::endl;
	
	try {
		form = intern.makeForm("shrubbery creation", "city");
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *form << std::endl;
	a.signForm(*form);
	a.executeForm(*form);
	std::cout << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	std::cout << "*                TEST 3                  *" << std::endl;
	std::cout << "******************************************" << std::endl;

	try {
		form = intern.makeForm("robotomy request", "robot");
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *form << std::endl;
	a.signForm(*form);
	a.executeForm(*form);
	std::cout << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	std::cout << "*                TEST 4                  *" << std::endl;
	std::cout << "******************************************" << std::endl;

	try {
		form = intern.makeForm("presidential pardon", "president");
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *form << std::endl;
	a.signForm(*form);
	a.executeForm(*form);
	std::cout << std::endl << std::endl;

	return (0);
}
