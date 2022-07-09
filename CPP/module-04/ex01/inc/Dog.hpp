/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:12:13 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 15:01:29 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
private:
	Brain *brain;

public:
	Dog();
	Dog(std::string type);
	Dog(const Dog &origin);
	Dog &operator=(const Dog &origin);
	~Dog();

	void	makeSound() const;
	Brain	*getBrain() const;
};

#endif
