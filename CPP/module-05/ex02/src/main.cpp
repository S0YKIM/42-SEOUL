/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:26:14 by sokim             #+#    #+#             */
/*   Updated: 2022/07/10 19:44:31 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void) {
	std::cout << "******************************************" << std::endl;
	Bureaucrat	a("Anna", 1);
	Form		f("Form1", 1, 1);
	std::cout << a << std::endl;
	std::cout << f << std::endl;
	a.signForm(f);
	std::cout << f << std::endl;
	std::cout << "******************************************" << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	a.decrementGrade();
	std::cout << a << std::endl;
	a.signForm(f);
	std::cout << "******************************************" << std::endl << std::endl;
	
	std::cout << "******************************************" << std::endl;
	Form		wrongForm1("Wrong1", 0, 0);
	Form		wrongForm2("Wrong2", 151, 151);
	std::cout << "******************************************" << std::endl << std::endl;
	return (0);
}
