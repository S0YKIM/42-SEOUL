/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:11:59 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 15:47:41 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called." << std::endl;
	setType("Cat");
	brain = new Brain;
}

Cat::Cat(const Cat &origin) {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = origin;
}

Cat &Cat::operator=(const Cat &origin) {
	if (this == &origin)
		return (*this);
	setType(origin.getType());
	if (brain)
		delete brain;
	brain = new Brain(*origin.getBrain());
	return (*this);
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called." << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "🐈 Meow 🐈" << std::endl;
}

Brain	*Cat::getBrain() const {
	return (brain);
}
