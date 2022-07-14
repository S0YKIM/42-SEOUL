/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:46:25 by sokim             #+#    #+#             */
/*   Updated: 2022/07/14 10:54:22 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>

const char	*NotFoundException::what() const throw() {
		return ("Couldn't find the target.");
}

int	main() {
	std::vector<int> v;
	std::vector<int>::iterator it_v;
	std::deque<int> d;
	std::deque<int>::iterator it_d;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		d.push_back(i);
	}

	std::cout << "*******************************************" << std::endl;
	std::cout << "*                 FOUND                   *" << std::endl;
	std::cout << "*******************************************" << std::endl;
	it_v = easyfind(v, 5);
	it_d = easyfind(d, 7);
	std::cout << "easyfind(v, 5) : " << *it_v << std::endl;
	std::cout << "easyfind(d, 7) : " << *it_d << std::endl << std::endl;

	std::cout << "*******************************************" << std::endl;
	std::cout << "*                NOT FOUND                *" << std::endl;
	std::cout << "*******************************************" << std::endl;
	try {
			std::cout << "easyfind(v, 100) : ";
			it_v = easyfind(v, 100);
			std::cout << *it_v << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	return (0);
}
