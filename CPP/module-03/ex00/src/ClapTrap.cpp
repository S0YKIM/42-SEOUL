/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:56:13 by sokim             #+#    #+#             */
/*   Updated: 2022/07/07 15:59:13 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called." << std::endl;
	this->name = "";
	this->maxHitPoints = 10;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap " << name << " constructed." << std::endl;
	this->name = name;
	this->maxHitPoints = 10;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &origin) {
	std::cout << "ClapTrap " << origin.name << " copied." << std::endl;
	*this = origin;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &origin) {
	std::cout << "ClapTrap " << origin.name << " assigned." << std::endl;
	if (this == &origin)
		return (*this);
	this->name = origin.name;
	this->hitPoints = origin.hitPoints;
	this->energyPoints = origin.energyPoints;
	this->attackDamage = origin.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destructed." << std::endl;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->hitPoints <= 0 || this->energyPoints <= 0) {
		std::cout << this->name << " can't attack anyone. It seems to be broken!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->attackDamage;
	std::cout << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints <= 0) {
		std::cout << "ClapTrap " << this->name << "'s HP is already zero!" << std::endl;
		return ;
	}
	this->hitPoints -= amount;
	if (this->hitPoints <= 0)
		this->hitPoints = 0;
	std::cout << "ClapTrap " << this->name << " takes damage, losing ";
	std::cout << amount << " points of HP!" << std::endl;
	std::cout << "ClapTrap " << this->name << "'s HP is now " << this->hitPoints << "." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints <= 0 || this->energyPoints <= 0) {
		std::cout << "ClapTrap " << this->name << " can't be repaired. It seems to be broken." << std::endl;
		return ;
	}
	else if (this->hitPoints == this->maxHitPoints) {
		std::cout << "ClapTrap " << this->name << "'s HP is already full." << std::endl;
		return ;
	}
	else if (this->hitPoints + (int)amount > this->maxHitPoints) {
		amount = this->maxHitPoints - this->hitPoints;
	}
	this->energyPoints -= 1;
	if (this->hitPoints > this->maxHitPoints)
		amount = this->maxHitPoints - this->hitPoints;
	this->hitPoints += amount;
	std::cout << this->name << " got " << amount << " HP points back from repair." << std::endl;
}

void	ClapTrap::displayStatus() {
	std::cout << "******************** " << this->name << "'s status " << "********************" << std::endl;
	std::cout << "- Hit Points: " << this->hitPoints << std::endl;
	std::cout << "- Energy Points: " << this->energyPoints << std::endl;
	std::cout << "- Attack Damage: " << this->attackDamage << std::endl;
	std::cout << "**********************************************************" << std::endl;
}
