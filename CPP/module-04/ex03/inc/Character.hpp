/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:26:49 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 19:35:10 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#define INVENTORY_SIZE 4

class Character : public ICharacter {
private :
	std::string	name_;
	AMateria	*inventory_[4];

public :
	Character(std::string name);
	Character(const Character &origin);
	Character &operator=(const Character &origin);
	~Character();

	const std::string	&getName() const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);
	void				displayInventory() const;
};

#endif
