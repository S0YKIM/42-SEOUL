/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:12:03 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 15:14:20 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type_("") {
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal &origin) {
	std::cout << "Animal copy constructor called." << std::endl;
	*this = origin;
}

Animal &Animal::operator=(const Animal &origin) {
	std::cout << "Animal assignment operator called." << std::endl;
	if (this == &origin)
		return (*this);
	setType(origin.getType());
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

std::string	Animal::getType() const {
	return (type_);
}

void	Animal::setType(std::string type) {
	type_ = type;
}

void	Animal::makeSound() const {
	std::cout << "Animal can't make sound yet." << std::endl;
}
