/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:08:56 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 14:20:11 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void) {
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	std::cout << "******************************************" << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* j = new WrongCat();

		std::cout << j->getType() << " " << std::endl;

		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
	}
	return (0);
}
