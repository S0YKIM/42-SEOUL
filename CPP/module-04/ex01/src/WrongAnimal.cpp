/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:03:22 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 14:05:21 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("") {
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &origin) {
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = origin;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &origin) {
	std::cout << "WrongAnimal assignment operator called." << std::endl;
	if (this == &origin)
		return (*this);
	setType(origin.getType());
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called." << std::endl;
}

std::string	WrongAnimal::getType() const {
	return (type_);
}

void	WrongAnimal::setType(std::string type) {
	type_ = type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal can't make sound yet." << std::endl;
}
