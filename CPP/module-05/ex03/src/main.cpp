/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:26:14 by sokim             #+#    #+#             */
/*   Updated: 2022/07/22 18:14:23 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void) {
	Bureaucrat				a("Anna", 1);
	Intern					intern;

	{
		std::cout << "******************************************" << std::endl;
		std::cout << "*                TEST 1                  *" << std::endl;
		std::cout << "******************************************" << std::endl;
		
		Form	*form;
		try {
			form = intern.makeForm("unknown", "target");
			delete form;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "******************************************" << std::endl;
		std::cout << "*                TEST 2                  *" << std::endl;
		std::cout << "******************************************" << std::endl;
		
		Form	*form;
		try {
			form = intern.makeForm("shrubbery creation", "city");
			std::cout << *form << std::endl;
			a.signForm(*form);
			a.executeForm(*form);
			delete form;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "******************************************" << std::endl;
		std::cout << "*                TEST 3                  *" << std::endl;
		std::cout << "******************************************" << std::endl;

		Form	*form;
		try {
			form = intern.makeForm("robotomy request", "robot");
			std::cout << *form << std::endl;
			a.signForm(*form);
			a.executeForm(*form);
			delete form;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "******************************************" << std::endl;
		std::cout << "*                TEST 4                  *" << std::endl;
		std::cout << "******************************************" << std::endl;

		Form	*form;
		try {
			form = intern.makeForm("presidential pardon", "president");
			std::cout << *form << std::endl;
			a.signForm(*form);
			a.executeForm(*form);
			delete form;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl << std::endl;
	}
	return (0);
}
