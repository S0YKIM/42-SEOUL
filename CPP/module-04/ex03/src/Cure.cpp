/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:27:37 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 18:23:07 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure &origin) : AMateria(origin) {
}

Cure &Cure::operator=(const Cure &origin) {
	if (this == &origin)
		return (*this);
	type_ = origin.getType();
	return (*this);
}

Cure::~Cure() {
}

AMateria	*Cure::clone() const {
	Cure	*clone = new Cure(*this);
	return (clone);
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
