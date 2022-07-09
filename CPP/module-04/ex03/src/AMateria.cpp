/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:27:22 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 20:55:14 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type_(type) {
}

AMateria::AMateria(const AMateria &origin) {
	*this = origin;
}

AMateria &AMateria::operator=(const AMateria &origin) {
	if (this == &origin)
		return (*this);
	type_ = origin.getType();
	return (*this);
}

AMateria::~AMateria() {
}

const std::string	&AMateria::getType() const {
	return (type_);
}

void	AMateria::use(ICharacter &target) {
	std::cout << "* use " << type_ << " to " << target.getName() << " *" << std::endl;
}
