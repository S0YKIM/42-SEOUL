/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:00:28 by sokim             #+#    #+#             */
/*   Updated: 2022/12/07 14:20:40 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
	std::string	type_;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &origin);
	WrongAnimal &operator=(const WrongAnimal &origin);
	~WrongAnimal();

	std::string		getType() const;
	void			setType(std::string type);

	void	makeSound() const;
};

#endif
