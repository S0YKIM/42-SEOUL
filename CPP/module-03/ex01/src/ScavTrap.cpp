/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:11:37 by sokim             #+#    #+#             */
/*   Updated: 2022/07/07 16:50:03 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called." << std::endl;
	this->name = "";
	this->maxHitPoints = 100;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " constructed." << std::endl;
	this->name = name;
	this->maxHitPoints = 100;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &origin) {
	std::cout << "ScavTrap " << origin.name << " copied." << std::endl;
	*this = origin;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &origin) {
	std::cout << "ClapTrap " << origin.name << " assigned." << std::endl;
	if (this == &origin)
		return (*this);
	this->name = origin.name;
	this->maxHitPoints = origin.maxHitPoints;
	this->hitPoints = origin.hitPoints;
	this->energyPoints = origin.energyPoints;
	this->attackDamage = origin.attackDamage;
	return (*this);
}

ScavTrap:: ~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destructed." << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (this->hitPoints <= 0 || this->energyPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " can't attack anyone. It seems to be broken!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->attackDamage;
	std::cout << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints <= 0) {
		std::cout << "ScavTrap " << this->name << "'s HP is already zero!" << std::endl;
		return ;
	}
	else if (this->hitPoints - (int)amount < 0)
		amount = this->hitPoints;
	this->hitPoints -= amount;
	std::cout << "ScavTrap " << this->name << " takes damage, losing ";
	std::cout << amount << " points of HP!" << std::endl;
	std::cout << "ScavTrap " << this->name << "'s HP is now " << this->hitPoints << "." << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints <= 0 || this->energyPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " can't be repaired. It seems to be broken." << std::endl;
		return ;
	}
	else if (this->hitPoints == this->maxHitPoints) {
		std::cout << "ScavTrap " << this->name << "'s HP is already full." << std::endl;
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

void	ScavTrap::displayStatus() {
	std::cout << "******************** " << this->name << "'s status " << "********************" << std::endl;
	std::cout << "- Hit Points: " << this->hitPoints << std::endl;
	std::cout << "- Energy Points: " << this->energyPoints << std::endl;
	std::cout << "- Attack Damage: " << this->attackDamage << std::endl;
	std::cout << "**********************************************************" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " entered in Gate keeper mode." << std::endl;
}
