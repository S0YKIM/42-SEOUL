/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:11:29 by sokim             #+#    #+#             */
/*   Updated: 2022/07/13 15:15:35 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main() {
	{
		std::cout << "*******************************************" << std::endl;
		std::cout << "*               INT ARRAY                 *" << std::endl;
		std::cout << "*******************************************" << std::endl;

		Array<int>	test(10);
		Array<int>	mirror;

		for (int i = 0; i < 10; i++)
			test[i] = i;
		
		mirror = test;
		for (int i = 0; i < 10; i++)
			mirror[i] += 10;
		
		std::cout << "test: ";
		for (int i = 0; i < 10; i++)
			std::cout << test[i] << " ";
		std::cout << std::endl;

		std::cout << "mirror: ";
		for (int i = 0; i < 10; i++)
			std::cout << mirror[i] << " ";
		std::cout << std::endl << std::endl;

		std::cout << "*******************************************" << std::endl;
		std::cout << "*               OUT OF RANGE              *" << std::endl;
		std::cout << "*******************************************" << std::endl;

		try {
			std::cout << test[-1];
		}
		catch (std::exception &e) {
			std::cout << "[-1] : " << e.what() << std::endl;
		}

		try {
			std::cout << test[100];
		}
		catch (std::exception &e) {
			std::cout << "[100] : " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "*******************************************" << std::endl;
		std::cout << "*              STRING ARRAY               *" << std::endl;
		std::cout << "*******************************************" << std::endl;

		Array<std::string>	test(10);
		Array<std::string>	mirror;

		for (int i = 0; i < 10; i++)
			test[i] = "Hello";

		mirror = test;
		for (int i = 0; i < 10; i++)
			mirror[i] += "World";

		std::cout << "test: ";
		for (int i = 0; i < 10; i++)
			std::cout << test[i] << " ";
		std::cout << std::endl;

		std::cout << "mirror: ";
		for (int i = 0; i < 10; i++)
			std::cout << mirror[i] << " ";
		std::cout << std::endl << std::endl;

		std::cout << "*******************************************" << std::endl;
		std::cout << "*               OUT OF RANGE              *" << std::endl;
		std::cout << "*******************************************" << std::endl;

		try {
			std::cout << test[-1];
		}
		catch (std::exception &e) {
			std::cout << "[-1] : " << e.what() << std::endl;
		}

		try {
			std::cout << test[100];
		}
		catch (std::exception &e) {
			std::cout << "[100] : " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}
