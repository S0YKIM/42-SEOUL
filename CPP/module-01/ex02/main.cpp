/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:38:50 by sokim             #+#    #+#             */
/*   Updated: 2022/07/05 16:07:35 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int	main(void) {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "*********************************" << std::endl;
	std::cout << "&string: \t" << &string << std::endl;
	std::cout << "stringPTR: \t" << stringPTR << std::endl;
	std::cout << "&stringREF: \t" << &stringREF << std::endl;
	std::cout << "*********************************" << std::endl;

	std::cout << "&stringPTR: \t" << &stringPTR << std::endl;
	std::cout << "*********************************" << std::endl;

	std::cout << "string: \t" << string << std::endl;
	std::cout << "*stringPTR: \t" << *stringPTR << std::endl;
	std::cout << "stringREF: \t" << stringREF << std::endl;
	std::cout << "*********************************" << std::endl;
}
