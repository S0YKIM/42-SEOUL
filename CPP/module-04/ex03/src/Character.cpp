/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:27:33 by sokim             #+#    #+#             */
/*   Updated: 2022/07/09 20:55:04 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : name_(name) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		inventory_[i] = NULL;
	}
}

Character::Character(const Character &origin) {
	*this = origin;
}

Character &Character::operator=(const Character &origin) {
	if (this == &origin)
		return (*this);
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (inventory_[i])
			delete inventory_[i];
		if (origin.inventory_[i])
			inventory_[i] = origin.inventory_[i]->clone();
		else
			inventory_[i] = NULL;
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (inventory_[i])
			delete inventory_[i];
	}
}

const std::string	&Character::getName() const {
	return (name_);
}

void	Character::equip(AMateria *m) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (!inventory_[i]) {
			inventory_[i] = m;
			return ;
		}
	}
	std::cout << "You can't equip " << m->getType() << ". Inventory is full." << std::endl;
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < INVENTORY_SIZE)
		inventory_[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < INVENTORY_SIZE) {
		if (inventory_[idx])
			inventory_[idx]->use(target);
	}
}

void	Character::displayInventory() const {
	std::cout << std::endl << "******************************************" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (inventory_[i])
			std::cout << "Slot [" << i << "] : " << inventory_[i]->getType() << std::endl;
		else
			std::cout << "Slot [" << i << "] is empty." << std::endl;
	}
	std::cout << "******************************************" << std::endl << std::endl;
}
