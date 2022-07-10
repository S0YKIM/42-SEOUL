/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:26:14 by sokim             #+#    #+#             */
/*   Updated: 2022/07/10 17:10:57 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << "******************************************" << std::endl;
	Bureaucrat	a("Anna", 1);
	std::cout << a << std::endl;
	try {
		a.incrementGrade();
		std::cout << "This will not be printed because incrementing should fail." << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "******************************************" << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	try {
		a.decrementGrade();
		std::cout << a << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "This will not be printed because decrementing should succeed." << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << "******************************************" << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	Bureaucrat	b("Brian", 150);
	std::cout << b << std::endl;
	try {
		b.decrementGrade();
		std::cout << "This will not be printed because decrementing should fail." << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "******************************************" << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	try {
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "This will not be printed because incrementing should succeed." << std::endl;
		std::cerr << e.what() << std::endl;
	}
	std::cout << "******************************************" << std::endl << std::endl;
}
