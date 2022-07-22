/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:11:37 by sokim             #+#    #+#             */
/*   Updated: 2022/07/08 15:47:00 by sokim            ###   ########.fr       */
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
	std::cout << "ScavTrap " << origin.name << " assigned." << std::endl;
	if (this == &origin)
		return (*this);
	this->name = origin.name;
	this->maxHitPoints = origin.maxHitPoints;
	this->hitPoints = origin.hitPoints;
	this->energyPoints = origin.energyPoints;
	this->attackDamage = origin.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap() {
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

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " entered in Gate keeper mode." << std::endl;
}
