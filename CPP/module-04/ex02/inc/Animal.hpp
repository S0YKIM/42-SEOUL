/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:12:08 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 16:51:58 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {
protected:
	std::string	type_;

public:
	Animal();
	Animal(const Animal &origin);
	Animal &operator=(const Animal &origin);
	virtual ~Animal();

	std::string		getType() const;
	void			setType(std::string type);

	virtual void	makeSound() const;
	virtual Brain*	getBrain() const = 0;
};

#endif
