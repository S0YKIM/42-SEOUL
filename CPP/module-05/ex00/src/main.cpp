/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:26:14 by sokim             #+#    #+#             */
/*   Updated: 2022/07/10 19:44:42 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << "******************************************" << std::endl;
	Bureaucrat	a("Anna", 1);
	std::cout << a << std::endl;
	a.incrementGrade();
	a.decrementGrade();
	std::cout << "******************************************" << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	Bureaucrat	b("Brian", 150);
	std::cout << b << std::endl;
	b.decrementGrade();
	b.incrementGrade();
	std::cout << "******************************************" << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	Bureaucrat	wrong1("Wrong1", 0);
	Bureaucrat	wrong2("Wrong2", 151);
	std::cout << "*****************************************" << std::endl << std::endl;

	return (0);
}
