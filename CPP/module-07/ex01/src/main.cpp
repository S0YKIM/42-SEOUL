/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:01:31 by sokim             #+#    #+#             */
/*   Updated: 2022/07/13 11:27:07 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void	print_c(char c) {
	std::cout << c << " ";
}

static void	print_d(double &d) {
	std::cout << d << " ";
}

static void	print_i(const int &num) {
	std::cout << num << " ";
}

int	main() {
	char	array_c[5] = {'a', 'b', 'c', 'd', 'e'};
	double	array_d[5] = {1.5, 2.5, 3.5, 4.5, 5.5};
	int		array_i[5] = {1, 2, 3, 4, 5};

	std::cout << "*******************************************" << std::endl;
	std::cout << "*                    T                    *" << std::endl;
	std::cout << "*******************************************" << std::endl;
	std::cout << "c : ";
	iter(array_c, 5, print_c);
	std::cout << std::endl << std::endl;

	std::cout << "*******************************************" << std::endl;
	std::cout << "*                   T &                   *" << std::endl;
	std::cout << "*******************************************" << std::endl;
	std::cout << "d : ";
	iter(array_d, 5, print_d);
	std::cout << std::endl << std::endl;

	std::cout << "*******************************************" << std::endl;
	std::cout << "*                const T &                *" << std::endl;
	std::cout << "*******************************************" << std::endl;
	std::cout << "i : ";
	iter(array_i, 5, print_i);
	std::cout << std::endl << std::endl;

	return (0);
}
