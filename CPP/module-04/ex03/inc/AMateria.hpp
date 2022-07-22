/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:21:35 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 20:57:12 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
	std::string type_;

public :
	AMateria(std::string const &type);
	AMateria(const AMateria &origin);
	AMateria &operator=(const AMateria &origin);
	virtual ~AMateria();

	const std::string	&getType() const;

	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);
};

#endif
