/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:11:59 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 14:18:19 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called." << std::endl;
	setType("Cat");
}

Cat::Cat(const Cat &origin) {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = origin;
}

Cat &Cat::operator=(const Cat &origin) {
	if (this == &origin)
		return (*this);
	setType(origin.getType());
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "🐈 Meow 🐈" << std::endl;
}
