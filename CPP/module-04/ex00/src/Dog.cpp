/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:12:01 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 14:18:32 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called." << std::endl;
	setType("Dog");
}

Dog::Dog(const Dog &origin) {
	std::cout << "Dog copy constructor called." << std::endl;
	*this = origin;
}

Dog &Dog::operator=(const Dog &origin) {
	if (this == &origin)
		return (*this);
	setType(origin.getType());
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "🐶 Bark 🐶" << std::endl;
}
