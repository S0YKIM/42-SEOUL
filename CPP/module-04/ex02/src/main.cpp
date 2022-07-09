/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:08:56 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 16:55:44 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define ANIMALS_LEN 10

int	main(void) {
	Animal* animals[ANIMALS_LEN];

	for (int i = 0; i < 10; i++) {
		if (i < ANIMALS_LEN / 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << "******************************************" << std::endl;
	std::cout << "*                 ANIMALS                *" << std::endl;
	std::cout << "******************************************" << std::endl;
	for (int i = 0; i < 10; i++) {
		animals[i]->makeSound();
	}
	std::cout << "******************************************" << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	std::cout << "*                   IDEA                 *" << std::endl;
	std::cout << "******************************************" << std::endl;
	animals[4]->getBrain()->setIdea(0, "Hey");
	animals[4]->getBrain()->setIdea(1, "I'm bored");
	animals[4]->getBrain()->setIdea(2, "Play with me!");
	animals[4]->makeSound();
	std::cout << "animals[4] 0💬: " << animals[4]->getBrain()->getIdea(0) << std::endl;
	std::cout << "animals[4] 1💬: " << animals[4]->getBrain()->getIdea(1) << std::endl;
	std::cout << "animals[4] 2💬: " << animals[4]->getBrain()->getIdea(2) << std::endl;
	std::cout << "******************************************" << std::endl << std::endl;

	std::cout << "******************************************" << std::endl;
	std::cout << "*                DEEP COPY               *" << std::endl;
	std::cout << "******************************************" << std::endl;
	Cat *temp = dynamic_cast<Cat*>(animals[4]);
	if (!temp) {
		for (int i = 0; i < 10; i++)
			delete animals[i];
		return (0);
	}
	Cat	*copycat = new Cat(*temp);
	copycat->getBrain()->setIdea(2, "Grrrrrrrrr");
	copycat->makeSound();
	std::cout << "copycat 0💬: " << copycat->getBrain()->getIdea(0) << std::endl;
	std::cout << "copycat 1💬: " << copycat->getBrain()->getIdea(1) << std::endl;
	std::cout << "copycat 2💬: " << copycat->getBrain()->getIdea(2) << std::endl;
	std::cout << "animals[4] 2💬: " << animals[4]->getBrain()->getIdea(2) << std::endl;
	std::cout << "******************************************" << std::endl << std::endl;

	delete copycat;

	for (int i = 0; i < 10; i++)
		delete animals[i];

	std::cout << "******************************************" << std::endl;
	std::cout << "*              ABSTRACT CLASS            *" << std::endl;
	std::cout << "******************************************" << std::endl << std::endl;
	// This must not work!
	// Animal animal;
	return (0);
}
