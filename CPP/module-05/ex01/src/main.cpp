/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:26:14 by sokim             #+#    #+#             */
/*   Updated: 2022/07/10 20:25:58 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void) {
	Bureaucrat	a("Anna", 1);
	Bureaucrat	b("Brian", 150);
	Form		f("Form1", 1, 1);

	std::cout << "******************************************" << std::endl;
	std::cout << "*                TEST 1                  *" << std::endl;
	std::cout << "******************************************" << std::endl;
	std::cout << a << std::endl;
	try {
		std::cout << f << std::endl;
		a.signForm(f);
		std::cout << f << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "This will not be printed because all of above may succeed." << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	std::cout << "*                TEST 2                  *" << std::endl;
	std::cout << "******************************************" << std::endl;
	try {
		a.decrementGrade();
		std::cout << a << std::endl;
		a.signForm(f);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	std::cout << "*                TEST 3                  *" << std::endl;
	std::cout << "******************************************" << std::endl;
	std::cout << b << std::endl;
	try {
		Form	wrongForm("Wrong", 0, 0);
		std::cout << "This will not be printed because grade is invalid." << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	return (0);
}
