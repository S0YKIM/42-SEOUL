/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:03:55 by sokim             #+#    #+#             */
/*   Updated: 2022/07/12 16:08:50 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main() {
	Base	*base = generate();

	std::cout << "*******************************************" << std::endl;
	std::cout << "*                  Pointer                *" << std::endl;
	std::cout << "*******************************************" << std::endl;
	identify(base);
	std::cout << std::endl;

	std::cout << "*******************************************" << std::endl;
	std::cout << "*                 Reference               *" << std::endl;
	std::cout << "*******************************************" << std::endl;
	identify(*base);
	std::cout << std::endl;

	delete base;

	return (0);
}
