/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:27:41 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 18:30:26 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice &origin) : AMateria(origin) {
}

Ice &Ice::operator=(const Ice &origin) {
	if (this == &origin)
		return (*this);
	type_ = origin.getType();
	return (*this);
}

Ice::~Ice() {
}

AMateria	*Ice::clone() const {
	Ice	*clone = new Ice(*this);
	return (clone);
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
