/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:24:17 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 19:39:34 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_CHARACTER_HPP
#define I_CHARACTER_HPP

#include "AMateria.hpp"

class AMateria;

class ICharacter {
public:
	virtual ~ICharacter() {}

	virtual std::string const	&getName() const = 0;
	virtual void				equip(AMateria *m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void				use(int idx, ICharacter& target) = 0;

	virtual void				displayInventory() const = 0;
};

#endif
