/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:38:02 by sokim             #+#    #+#             */
/*   Updated: 2022/07/12 15:11:08 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Wrong input! Please try again." << std::endl;
		std::cout << "Usage: ./convert [argument]" << std::endl;
		std::cout << "Type of arguments: char, int, float, double" << std::endl;
		return (1);
	}

	Convert	converter(argv[1]);
	converter.printAll();

	return (0);
}
