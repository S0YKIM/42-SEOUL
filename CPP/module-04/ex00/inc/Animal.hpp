/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:12:08 by sokim             #+#    #+#             */
/*   Updated: 2022/07/08 17:45:03 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
	std::string	type;

public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &origin);
	Animal &operator=(const Animal &origin);
	~Animal();
};

#endif
