/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:39:28 by sokim             #+#    #+#             */
/*   Updated: 2022/07/06 12:04:54 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl	harl;

	if (argc != 2) {
		std::cout << "<ERROR> Please input: ./harl [level]" << std::endl;
		std::cout << "[level] : DEBUG, INFO, WARNING, ERROR" << std::endl;
	}
	else
		harl.complain(argv[1]);
	return (0);
}
