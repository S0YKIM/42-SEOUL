/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:56:31 by sokim             #+#    #+#             */
/*   Updated: 2022/07/14 11:49:06 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main() {
	{
		std::cout << "*******************************************" << std::endl;
		std::cout << "*               BASIC TEST                *" << std::endl;
		std::cout << "*******************************************" << std::endl;
		Span	test = Span(5);
		test.addNumber(10);
		test.addNumber(5);
		test.addNumber(15);
		test.addNumber(0);
		test.addNumber(20);

		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl << std::endl;
	}
	{
		std::cout << "*******************************************" << std::endl;
		std::cout << "*               MASSIVE TEST              *" << std::endl;
		std::cout << "*******************************************" << std::endl;
		Span	test = Span(10000);

		for (int i = 1; i <= 10000; i++) {
			test.addNumber(i);
		}

		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl << std::endl;
	}
	{
		std::cout << "*******************************************" << std::endl;
		std::cout << "*                ERROR TEST               *" << std::endl;
		std::cout << "*******************************************" << std::endl;
		Span	test = Span(1);

		try {
			test.addNumber(1);
			test.addNumber(2); // 불가능
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << "Shortest span: " << test.shortestSpan() << std::endl; // 불가능
			std::cout << "Longest span: " << test.longestSpan() << std::endl; // 위에서 이미 예외가 나와서 호출도 안 됨
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
