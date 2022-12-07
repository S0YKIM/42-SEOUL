/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:08:07 by sokim             #+#    #+#             */
/*   Updated: 2022/12/07 14:21:17 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat default constructor called." << std::endl;
	setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &origin) {
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = origin;
}

WrongCat &WrongCat::operator=(const WrongCat &origin) {
	if (this == &origin)
		return (*this);
	setType(origin.getType());
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called." << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
